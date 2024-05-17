BadvpnTun2socks for iOS Xcode project

## usage

- Include the header file in your project
```objc
#import <BadvpnTun2socks/TunnelInterface.h>
```

- In method `startTunnelWithOptions:completionHandler:` of your NEPacketTunnelProvider subclass,
  start the tunnel interface
```objc
    NSError* error2 = [[TunnelInterface sharedInterface] setupWithPacketTunnelFlow:self.packetFlow];
    if (error2) {
        completionHandler(error2);
        return;
    }
    NSNotificationCenter* nc = [NSNotificationCenter defaultCenter];
    [nc addObserver:self selector:@selector(onBadvpnTun2SocksFinished) name:kTun2SocksStoppedNotification object:nil];

    [[TunnelInterface sharedInterface] startTun2Socks:(int)self->_s5_port];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.5 * NSEC_PER_SEC)), dispatch_get_main_queue(),
        ^{ [[TunnelInterface sharedInterface] processPackets]; });
```

- In method `stopTunnelWithReason:completionHandler:` of your NEPacketTunnelProvider subclass, stop the tunnel interface
```objc
    [[TunnelInterface sharedInterface] stop];
```
