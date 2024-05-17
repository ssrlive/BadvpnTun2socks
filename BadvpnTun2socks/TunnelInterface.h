//
//  TunnelInterface.h
//

#import <Foundation/Foundation.h>

#import <NetworkExtension/NetworkExtension.h>

#define TunnelMTU 1600
#define kTun2SocksStoppedNotification @"kTun2SocksStoppedNotification"

@interface TunnelInterface : NSObject
+ (TunnelInterface*)sharedInterface;
- (instancetype)init NS_UNAVAILABLE;
- (NSError*)startTun2Socks:(int)serverPort withPacketTunnelFlow:(NEPacketTunnelFlow*)packetFlow;
- (void)stopTun2Socks;
@end
