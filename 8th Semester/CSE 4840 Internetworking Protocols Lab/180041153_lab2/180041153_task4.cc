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

    Config::SetDefault("ns3::CsmaNetDevice::EncapsulationMode", StringValue("Dix"));

    CommandLine cmd(__FILE__);
    cmd.Parse(argc, argv);

    NS_LOG_INFO("Create nodes.");
    NodeContainer c;
    c.Create(6); 
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
    Ipv4StaticRoutingHelper multicast2; 
    
    
    // 1) Configure a (static) multicast route on node n2 (multicastRouter)
    Ptr<Node> multicastRouter = c.Get(2); 
    Ptr<NetDevice> inputIf = nd0.Get(2);  
    NetDeviceContainer outputDevices;     // A container of output NetDevices
    outputDevices.Add(nd1.Get(0));        

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

    ApplicationContainer sinkC2 = sink.Install(c1.Get(3));
   
    sinkC2.Start(Seconds(1.0));
    sinkC2.Stop(Seconds(10.0));



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
