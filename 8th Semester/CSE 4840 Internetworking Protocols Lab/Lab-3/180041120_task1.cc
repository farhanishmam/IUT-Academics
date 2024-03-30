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
/*The diagram is given below
      0
      |
      1
    /   \
   2     3
  / \   / \
 4   5 6   7
*/
int
main(int argc, char* argv[])
{

    Config::SetDefault("ns3::CsmaNetDevice::EncapsulationMode", StringValue("Dix"));
    CommandLine cmd(__FILE__);
    cmd.Parse(argc, argv);

    NS_LOG_INFO("Create nodes.");
    NodeContainer c; //create a mode container containing 8 nodes
    c.Create(8);
   
	NodeContainer cArr[7]; //We create the subcontainers that represent all the edges or links
	
	cArr[0] = NodeContainer(c.Get(0), c.Get(1));
	cArr[1] = NodeContainer(c.Get(1), c.Get(2));
	cArr[2] = NodeContainer(c.Get(1), c.Get(3));
	cArr[3] = NodeContainer(c.Get(2), c.Get(4));
	cArr[4] = NodeContainer(c.Get(2), c.Get(5));
	cArr[5] = NodeContainer(c.Get(3), c.Get(6));
	cArr[6] = NodeContainer(c.Get(3), c.Get(7));
	
    NS_LOG_INFO("Build Topology.");
    //We establish a p2p channel with data rate and delay
	PointToPointHelper p2p;
	p2p.SetChannelAttribute("DataRate", DataRateValue(DataRate(5000000)));
    p2p.SetChannelAttribute("Delay", TimeValue(MilliSeconds(2)));

    // We will use these NetDevice containers later, for IP addressing
	NetDeviceContainer nd[7];
	for(int i = 0; i<7; i++)
	{
		nd[i] = p2p.Install(cArr[i]); //A single netdevice for every subcontainer i.e. link
	}
	
    NS_LOG_INFO("Add IP Stack.");
    InternetStackHelper internet;
    internet.Install(c);

    NS_LOG_INFO("Assign IP Addresses.");
    Ipv4AddressHelper ipv4Addr;
	
	//This loop will put an ip-address for every netdevice 
	for(int i = 0; i<7; i++)
	{
		std::string ipAddress = "10.1." + std::to_string(i+1)+".0";
		ipv4Addr.SetBase(ipAddress, "255.255.255.0");
		ipv4Addr.Assign(nd[i]);
	}
	
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
    Ptr<Node> multicastRouter1 = c.Get(1); 
    Ptr<NetDevice> inputIf1 = nd[0].Get(1); 
    NetDeviceContainer outputDevices1;    
    outputDevices1.Add(nd[1].Get(0));
    outputDevices1.Add(nd[2].Get(0));       
    
    
    multicast.AddMulticastRoute(multicastRouter1,
                                multicastSource,
                                multicastGroup,
                                inputIf1,
                                outputDevices1);
                                
    Ptr<Node> multicastRouter2 = c.Get(2); 
    Ptr<NetDevice> inputIf2 = nd[1].Get(1); 
    NetDeviceContainer outputDevices2;     
    outputDevices2.Add(nd[3].Get(0));
    outputDevices2.Add(nd[4].Get(0));       
    
    
    multicast.AddMulticastRoute(multicastRouter2,
                                multicastSource,
                                multicastGroup,
                                inputIf2,
                                outputDevices2);
                                
    Ptr<Node> multicastRouter3 = c.Get(3); 
    Ptr<NetDevice> inputIf3 = nd[2].Get(1);  
    NetDeviceContainer outputDevices3;     
    outputDevices3.Add(nd[5].Get(0));
    outputDevices3.Add(nd[6].Get(0));      
    
    
    multicast.AddMulticastRoute(multicastRouter3,
                                multicastSource,
                                multicastGroup,
                                inputIf3,
                                outputDevices3);
      
    // 2) Set up a default multicast route on the sender n0
    Ptr<Node> sender = c.Get(0);
    Ptr<NetDevice> senderIf = nd[0].Get(0);
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

	//Only the root node is the source
    ApplicationContainer srcC = onoff.Install(cArr[0].Get(0)); //Node n0

    //
    // Tell the application when to start and stop.
    //
    srcC.Start(Seconds(1.));
    srcC.Stop(Seconds(10.));

    // Create an optional packet sink to receive these packets
    PacketSinkHelper sink("ns3::UdpSocketFactory",
                          InetSocketAddress(Ipv4Address::GetAny(), multicastPort));

	//All the leaf nodes need to be the sink
    ApplicationContainer sinkC[4];
	
	sinkC[0] = sink.Install(cArr[3].Get(1)); // Node n4
    // Start the sink
    sinkC[0].Start(Seconds(1.0));
    sinkC[0].Stop(Seconds(10.0));
	
	sinkC[1] = sink.Install(cArr[4].Get(1)); // Node n5
    // Start the sink
    sinkC[1].Start(Seconds(1.0));
    sinkC[1].Stop(Seconds(10.0));
	
	sinkC[2] = sink.Install(cArr[5].Get(1)); // Node n6
    // Start the sink
    sinkC[2].Start(Seconds(1.0));
    sinkC[2].Stop(Seconds(10.0));
	
	sinkC[3] = sink.Install(cArr[6].Get(1)); // Node n7
    // Start the sink
    sinkC[3].Start(Seconds(1.0));
    sinkC[3].Stop(Seconds(10.0));
	
	

    NS_LOG_INFO("Configure Tracing.");
    //
    // Configure tracing of all enqueue, dequeue, and NetDevice receive events.
    // Ascii trace output will be sent to the file "csma-multicast.tr"
    //
    AsciiTraceHelper ascii;
    p2p.EnableAsciiAll(ascii.CreateFileStream("p2p-multicast.tr"));

    p2p.EnablePcapAll("p2p-multicast", false);

    //
    // Now, do the actual simulation.
    //
    
    AnimationInterface anim("180041120_task1.xml");
    
    
    NS_LOG_INFO("Run Simulation.");
    Simulator::Run();
    Simulator::Destroy();
    NS_LOG_INFO("Done.");
}
