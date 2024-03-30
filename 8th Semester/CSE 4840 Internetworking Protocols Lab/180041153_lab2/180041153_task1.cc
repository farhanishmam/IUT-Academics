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
    c.Create(6); 
    // We will later want two subcontainers of these nodes, for the two LANs
    NodeContainer c0 = NodeContainer(c.Get(0), c.Get(1), c.Get(2));
    NodeContainer c1 = NodeContainer(c.Get(2), c.Get(3), c.Get(4), c.Get(5)); 

    NS_LOG_INFO("Build Topology.");
    CsmaHelper csma;
    csma.SetChannelAttribute("DataRate", DataRateValue(DataRate(5000000)));
    csma.SetChannelAttribute("Delay", TimeValue(MilliSeconds(2)));

   
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
   
    Ipv4Address multicastSource("10.1.1.1");
    Ipv4Address multicastGroup("225.1.2.4");

    // Now, we will set up multicast routing.  We need to do three things:
    // 1) Configure a (static) multicast route on node n2
    // 2) Set up a default multicast route on the sender n0
    // 3) Have node n4 join the multicast group
    // We have a helper that can help us with static multicast
    Ipv4StaticRoutingHelper multicast;

    // 1) Configure a (static) multicast route on node n2 (multicastRouter)
    Ptr<Node> multicastRouter = c.Get(2);
    Ptr<NetDevice> inputIf = nd0.Get(2); 
    NetDeviceContainer outputDevices;     
    outputDevices.Add(nd1.Get(0));      

    multicast.AddMulticastRoute(multicastRouter,
                                multicastSource,
                                multicastGroup,
                                inputIf,
                                outputDevices);

    // 2) Set up a default multicast route on the sender n0
    Ptr<Node> sender = c.Get(0);
    Ptr<NetDevice> senderIf = nd0.Get(0);
    multicast.SetDefaultMulticastRoute(sender, senderIf);

    //
    // Create an OnOff application to send UDP datagrams from node zero to the
    // multicast group (node four will be listening).
    //
    NS_LOG_INFO("Create Applications.");

    uint16_t multicastPort = 9; // Discard port (RFC 863)

    // Configure a multicast packet generator that generates a packet
    // every few seconds
    OnOffHelper onoff("ns3::UdpSocketFactory",
                      Address(InetSocketAddress(multicastGroup, multicastPort)));
    onoff.SetConstantRate(DataRate("255b/s"));
    onoff.SetAttribute("PacketSize", UintegerValue(128));

    ApplicationContainer srcC = onoff.Install(c0.Get(0));

    //
    // Tell the application when to start and stop.
    //
    srcC.Start(Seconds(1.));
    srcC.Stop(Seconds(10.));

    // Create an optional packet sink to receive these packets
    PacketSinkHelper sink("ns3::UdpSocketFactory",
                          InetSocketAddress(Ipv4Address::GetAny(), multicastPort));

    ApplicationContainer sinkC = sink.Install(c1.Get(2)); // Node n4
    // Start the sink
    sinkC.Start(Seconds(1.0));
    sinkC.Stop(Seconds(10.0));
    
    ApplicationContainer sinkD = sink.Install(c1.Get(3)); 

    sinkD.Start(Seconds(1.0));
    sinkD.Stop(Seconds(10.0));
    

    NS_LOG_INFO("Configure Tracing.");
   
    AsciiTraceHelper ascii;
    csma.EnableAsciiAll(ascii.CreateFileStream("csma-multicast.tr"));

    
    csma.EnablePcapAll("csma-multicast", false);

    //
    // Now, do the actual simulation.
    //
    AnimationInterface anim("180041153.xml");
    NS_LOG_INFO("Run Simulation.");
    Simulator::Run();
    Simulator::Destroy();
    NS_LOG_INFO("Done.");
}
