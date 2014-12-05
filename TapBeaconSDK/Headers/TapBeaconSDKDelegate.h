//
//  TapClientDelegate.h
//  TapBeaconSDK
//
//  Copyright (c) 2014 Tapvalue. All rights reserved.
//

@import CoreLocation;

@class TapBeaconSDKClient;

@protocol TapBeaconSDKDelegate <NSObject>

@required
@optional
- (void)tapClientDidSync:(TapBeaconSDKClient *)client;
- (void)tapClient:(TapBeaconSDKClient *)client syncFailWithError:(NSError *) error;
- (void)tapClient:(TapBeaconSDKClient *)client didFailWithError:(NSError *)error;
- (void)tapClient:(TapBeaconSDKClient *)client didChangeAuthorizationStatus:(CLAuthorizationStatus)status;

@end
