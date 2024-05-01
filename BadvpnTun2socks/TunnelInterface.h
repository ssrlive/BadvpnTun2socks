//
//  TunnelInterface.h
//

#import <Foundation/Foundation.h>

#import <NetworkExtension/NetworkExtension.h>

#define TunnelMTU 1600
#define kTun2SocksStoppedNotification @"kTun2SocksStoppedNotification"

@interface TunnelInterface : NSObject
+ (TunnelInterface *)sharedInterface;
- (instancetype)init NS_UNAVAILABLE;
- (NSError *)setupWithPacketTunnelFlow:(NEPacketTunnelFlow *)packetFlow;
- (void)processPackets;
- (void)writePacket:(NSData *)packet;
- (void)startTun2Socks:(int)socksServerPort;
- (void)stop;
@end
