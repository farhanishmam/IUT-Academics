/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

// Network topology
//
//                     Lan1
//                 ================
//                 |    |    |    |
//       n0   n1   n2   n3   n4	  n5
//       |    |    |
//       ===========
//           Lan0
//
// - Multicast source is at node n0 and n1;
// - Multicast forwarded by node n2 onto LAN1;
// - Nodes n0, n1, n2, n3, n4, n5 receive the multicast frame.
// - Node n4 listens for the data from n0
// - Node n5 listens for the data from n1
// - n4 and n5 are members of different multicast groups

#include "ns3/applications-module.h"
#include "ns3/core-module.h"
#include "ns3/csma-module.h"
#include "ns3/internet-module.h"
#include "ns3/network-module.h"
#include "ns3/netanim-module.h"
#include <fstream>
#include <iostream>

using namespace ns3;

NS_LOG_COMPONENT_DEFINE("CsmaMulticastExample");

int
main(int argc, char* argv[])
{
    //
    // Users may find it convenient to turn on explicit debugging
    // for selected modules; the below lines suggest how to do this
    //
    // LogComponentEnable ("CsmaMulticastExample", LOG_LEVEL_INFO);

    //
    // Set up default values for the simulation.
    //
    // Select DIX/Ethernet II-style encapsulation (no LLC/Snap header)
    Config::SetDefault("ns3::CsmaNetDevice::EncapsulationMode", StringValue("Dix"));

    // Allow the user to override any of the defaults at
    // run-time, via command-line arguments
    CommandLine cmd(__FILE__);
    cmd.Parse(argc, argv);

    NS_LOG_INFO("Create nodes.");
    NodeContainer c;
    c.Create(6); // Modified - added a new node
    // We will later want two subcontainers of these nodes, for the two LANs
    NodeContainer c0 = NodeContainer(c.Get(0), c.Get(1), c.Get(2));
    NodeContainer c1 = NodeContainer(c.Get(2), c.Get(3), c.Get(4), c.Get(5)); // Modified - added new nodes

    NS_LOG_INFO("Build Topology.");
    CsmaHelper csma;
    csma.SetChannelAttribute("DataRate", DataRateValue(DataRate(5000000)));
    csma.SetChannelAttribute("Delay", TimeValue(MilliSeconds(2)));

    // We will use these NetDevice containers later, for IP addressing
    NetDeviceContainer nd0 = csma.Install(c0); // First LAN
    NetDeviceContainer nd1 = csma.Install(c1); // Second LAN

    NS_LOG_INFO("Add IP Stack.");
    InternetStackHelper internet;
    internet.Install(c);

    NS_LOG_INFO("Assign IP Addresses.");
    Ipv4AddressHelper ipv4Addr;
    ipv4Addr.SetBase("10.1.1.0", "255.255.255.0");
    ipv4Addr.Assign(nd0);
    ipv4Addr.SetBase("10.1.2.0", "255.255.255.0");
    ipv4Addr.Assign(nd1);

    NS_LOG_INFO("Configure multicasting.");
    //
    // Now we can configure multicasting.  As described above, the multicast
    // source is at node zero, which we assigned the IP address of 10.1.1.1
    // earlier.  We need to define a multicast group to send packets to.  This
    // can be any multicast address from 224.0.0.0 through 239.255.255.255
    // (avoiding the reserved routing protocol addresses).
    //

    // Modified - added a new multicast source and multicast group address
    Ipv4Address multicastSource1("10.1.1.1");
    Ipv4Address multicastSource2("10.1.1.2");
    
    Ipv4Address multicastGroup1("225.1.2.4");
    Ipv4Address multicastGroup2("225.1.2.5");


    // Now, we will set up multicast routing.  We need to do three things:
    // 1) Configure a (static) multicast route on node n2
    // 2) Set up a default multicast route on the sender n0
    // 3) Have node n4 join the multicast group
    // We have a helper that can help us with static multicast
    Ipv4StaticRoutingHelper multicast1;
    Ipv4StaticRoutingHelper multicast2; //Modified - added a new multicast helper
    
    
    // 1) Configure a (static) multicast route on node n2 (multicastRouter)
    Ptr<Node> multicastRouter = c.Get(2); // The node in question
    Ptr<NetDevice> inputIf = nd0.Get(2);  // The input NetDevice
    NetDeviceContainer outputDevices;     // A container of output NetDevices
    outputDevices.Add(nd1.Get(0));        // (we only need one NetDevice here)

    //Added multicast route for both multicast helpers
    multicast1.AddMulticastRoute(multicastRouter,
                                multicastSource1,
                                multicastGroup1,
                                inputIf,
                                outputDevices);
                                
    multicast2.AddMulticastRoute(multicastRouter,
                                multicastSource2,
                                multicastGroup2,
                                inputIf,
                                outputDevices);                           
                                

    // 2) Set up a default multicast route on the sender n0
    Ptr<Node> sender1 = c.Get(0);
    Ptr<NetDevice> senderIf1 = nd0.Get(0);
    multicast1.SetDefaultMulticastRoute(sender1, senderIf1);

    // Modified - Set up a default multicast route on the sender n1
    Ptr<Node> sender2 = c.Get(1);
    Ptr<NetDevice> senderIf2 = nd0.Get(1);
    multicast2.SetDefaultMulticastRoute(sender2, senderIf2);

    //
    // Create an OnOff application to send UDP datagrams from node zero to the
    // multicast group (node four will be listening).
    //
    NS_LOG_INFO("Create Applications.");

    uint16_t multicastPort = 9; // Discard port (RFC 863)

    // Configure a multicast packet generator that generates a packet
    // every few seconds
    OnOffHelper onoff1("ns3::UdpSocketFactory",
                      Address(InetSocketAddress(multicastGroup1, multicastPort)));
    onoff1.SetConstantRate(DataRate("255b/s"));
    onoff1.SetAttribute("PacketSize", UintegerValue(128));

    ApplicationContainer srcC1 = onoff1.Install(c0.Get(0));

    //
    // Tell the application when to start and stop.
    //
    srcC1.Start(Seconds(1.));
    srcC1.Stop(Seconds(10.));
	
    //modified - added another on/off application
    
    // Configure a multicast packet generator that generates a packet
    // every few seconds
    OnOffHelper onoff2("ns3::UdpSocketFactory",
                      Address(InetSocketAddress(multicastGroup2, multicastPort)));
    onoff2.SetConstantRate(DataRate("255b/s"));
    onoff2.SetAttribute("PacketSize", UintegerValue(128));

    ApplicationContainer srcC2 = onoff2.Install(c0.Get(1));

    //
    // Tell the application when to start and stop.
    //
    srcC2.Start(Seconds(1.));
    srcC2.Stop(Seconds(10.));


    // Create an optional packet sink to receive these packets
    PacketSinkHelper sink("ns3::UdpSocketFactory",
                          InetSocketAddress(Ipv4Address::GetAny(), multicastPort));

    ApplicationContainer sinkC1 = sink.Install(c1.Get(2)); // Node n4
    // Start the sink
    sinkC1.Start(Seconds(1.0));
    sinkC1.Stop(Seconds(10.0));

	//modified - added another sink
    ApplicationContainer sinkC2 = sink.Install(c1.Get(3)); // Node n5
    // Start the sink
    sinkC2.Start(Seconds(1.0));
    sinkC2.Stop(Seconds(10.0));



    NS_LOG_INFO("Configure Tracing.");
    //
    // Configure tracing of all enqueue, dequeue, and NetDevice receive events.
    // Ascii trace output will be sent to the file "csma-multicast.tr"
    //
    AsciiTraceHelper ascii;
    csma.EnableAsciiAll(ascii.CreateFileStream("csma-multicast.tr"));

    // Also configure some tcpdump traces; each interface will be traced.
    // The output files will be named:
    //     csma-multicast-<nodeId>-<interfaceId>.pcap
    // and can be read by the "tcpdump -r" command (use "-tt" option to
    // display timestamps correctly)
    csma.EnablePcapAll("csma-multicast", false);

    //
    // Now, do the actual simulation.
    //
    AnimationInterface anim("180041120_task4.xml");
    NS_LOG_INFO("Run Simulation.");
    Simulator::Run();
    Simulator::Destroy();
    NS_LOG_INFO("Done.");
}
