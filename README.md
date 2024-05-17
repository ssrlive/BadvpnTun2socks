BadvpnTun2socks for iOS Xcode project

## usage

- Include the header file in your project
```objc
#import <BadvpnTun2socks/TunnelInterface.h>
```

- In method `startTunnelWithOptions:completionHandler:` of your `NEPacketTunnelProvider` subclass,
  start the tunnel interface
```objc
    NSError* error2 = [[TunnelInterface sharedInterface] startTun2Socks:(int)self->_s5_port withPacketTunnelFlow:self.packetFlow];
    if (error2) {
        completionHandler(error2);
        return;
    }
```

- In method `stopTunnelWithReason:completionHandler:` of your `NEPacketTunnelProvider` subclass, stop the tunnel interface
```objc
    [[TunnelInterface sharedInterface] stopTun2Socks];
```
