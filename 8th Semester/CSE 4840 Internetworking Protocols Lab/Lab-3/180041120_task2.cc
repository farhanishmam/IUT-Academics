// Network topology contains both csma and p2p
//
//                     
//                 n3
//                 |      
//       n0   n1   n2-n4   
//       |    |    |
//       ===========
//        Lan(csma)


#include "ns3/applications-module.h"
#include "ns3/core-module.h"
#include "ns3/csma-module.h"
#include "ns3/internet-module.h"
#include "ns3/network-module.h"
#include "ns3/netanim-module.h"
#include "ns3/point-to-point-module.h"

#include <fstream>
#include <iostream>

using namespace ns3;

NS_LOG_COMPONENT_DEFINE("CsmaMulticastExample");

int
main(int argc, char* argv[])
{
  
    Config::SetDefault("ns3::CsmaNetDevice::EncapsulationMode", StringValue("Dix"));

    CommandLine cmd(__FILE__);
    cmd.Parse(argc, argv);

    NS_LOG_INFO("Create nodes.");
    NodeContainer c;
    c.Create(5);
    // We will later want two subcontainers of these nodes, for the two LANs
    NodeContainer c0 = NodeContainer(c.Get(0), c.Get(1), c.Get(2));
    NodeContainer c1 = NodeContainer(c.Get(2), c.Get(3));
	NodeContainer c2 = NodeContainer(c.Get(3), c.Get(4));
	
    NS_LOG_INFO("Build Topology.");
	
	//The 5Mbps is enough datarate to transfer 10 MB or 80Mb file in 5 mins
	//Time required is 80Mb/5Mbps = 16 seconds
    CsmaHelper csma;
    csma.SetChannelAttribute("DataRate", DataRateValue(DataRate(5000000)));
    csma.SetChannelAttribute("Delay", TimeValue(MilliSeconds(2)));

	PointToPointHelper p2p;
	p2p.SetChannelAttribute("DataRate", DataRateValue(DataRate(5000000)));
    p2p.SetChannelAttribute("Delay", TimeValue(MilliSeconds(2)));
	
    // We will use these NetDevice containers later, for IP addressing
    NetDeviceContainer nd0 = csma.Install(c0); //First 3 nodes are connected using csma
    NetDeviceContainer nd1 = p2p.Install(c1);  //Connected using p2p
	NetDeviceContainer nd2 = p2p.Install(c2); //Connected using p2p

    NS_LOG_INFO("Add IP Stack.");
    InternetStackHelper internet;
    internet.Install(c);

    NS_LOG_INFO("Assign IP Addresses.");
    Ipv4AddressHelper ipv4Addr;
    ipv4Addr.SetBase("10.1.1.0", "255.255.255.0");
    ipv4Addr.Assign(nd0);
    ipv4Addr.SetBase("10.1.2.0", "255.255.255.0");
    ipv4Addr.Assign(nd1);
	ipv4Addr.SetBase("10.1.3.0", "255.255.255.0");
    ipv4Addr.Assign(nd3);

    NS_LOG_INFO("Configure multicasting.");
    //
    // Now we can configure multicasting.  As described above, the multicast
    // source is at node zero, which we assigned the IP address of 10.1.1.1
    // earlier.  We need to define a multicast group to send packets to.  This
    // can be any multicast address from 224.0.0.0 through 239.255.255.255
    // (avoiding the reserved routing protocol addresses).
    //

    Ipv4Address multicastSource("10.1.1.1");
    Ipv4Address multicastGroup("225.1.2.4");

    // Now, we will set up multicast routing.  We need to do three things:
    // 1) Configure a (static) multicast route on node n2
    // 2) Set up a default multicast route on the sender n0
    // 3) Have node n4 join the multicast group
    // We have a helper that can help us with static multicast
    Ipv4StaticRoutingHelper multicast;

    // 1) Configure a (static) multicast route on node n2 (multicastRouter)
    Ptr<Node> multicastRouter = c.Get(2); // The node in question,the student who has the file
    Ptr<NetDevice> inputIf = nd0.Get(2);  // The input NetDevice
    NetDeviceContainer outputDevices;     // A container of output NetDevices
    outputDevices.Add(nd1.Get(0));        // (we only need one NetDevice here)
	outputDevices.Add(nd2.Get(0));
	
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

    ApplicationContainer sinkC1 = sink.Install(c0.Get(1)); // Node n1
    // Start the sink
    sinkC1.Start(Seconds(1.0));
    sinkC1.Stop(Seconds(10.0));

	ApplicationContainer sinkC2 = sink.Install(c0.Get(2)); // Node n2
    // Start the sink
    sinkC2.Start(Seconds(1.0));
    sinkC2.Stop(Seconds(10.0));
	
	ApplicationContainer sinkC3 = sink.Install(c1.Get(1)); // Node n3
    // Start the sink
    sinkC3.Start(Seconds(1.0));
    sinkC3.Stop(Seconds(10.0));
	
	ApplicationContainer sinkC4 = sink.Install(c2.Get(1)); // Node n4
    // Start the sink
    sinkC4.Start(Seconds(1.0));
    sinkC4.Stop(Seconds(10.0));

    NS_LOG_INFO("Configure Tracing.");
    //
    // Configure tracing of all enqueue, dequeue, and NetDevice receive events.
    // Ascii trace output will be sent to the file "csma-multicast.tr"
    //
    AsciiTraceHelper ascii;
	
    csma.EnableAsciiAll(ascii.CreateFileStream("csma-multicast.tr"));

    csma.EnablePcapAll("csma-multicast", false);
	
	p2p.EnableAsciiAll(ascii.CreateFileStream("p2p-multicast.tr"));

    p2p.EnablePcapAll("p2p-multicast", false);

    //
    // Now, do the actual simulation.
    //
	AnimationInterface anim("180041120_task2.xml");
    NS_LOG_INFO("Run Simulation.");
    Simulator::Run();
    Simulator::Destroy();
    NS_LOG_INFO("Done.");
}
