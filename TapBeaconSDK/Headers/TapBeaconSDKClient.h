//
//  TapClient.h
//  TapBeaconSDK
//
//  Copyright (c) 2014 Tapvalue. All rights reserved.
//

@import Foundation;

@protocol TapBeaconSDKDelegate;
@class TpvApiIdentifier;
@class TapBeacon;
@class TapClient;

typedef void (^CustomMonitoringHandlerBlock)(TapBeacon *beacon, NSDictionary *parameters);

@interface TapBeaconSDKClient : NSObject

@property (nonatomic, strong) TpvApiIdentifier *identifier;
@property (nonatomic, assign) id<TapBeaconSDKDelegate> delegate;

+ (instancetype) getInstance;
+ (BOOL) isInitialized;
+ (instancetype) clientWithApiIdentifier:(TpvApiIdentifier *) identifier withDelegate:(id<TapBeaconSDKDelegate>) delegate;
+ (instancetype) clientWithApiIdentifier:(TpvApiIdentifier *) identifier;
- (void) start;
- (void) stop;
- (void) registerCustomMonitoringHandlerWithActionId:(NSString *) actionId handler:(CustomMonitoringHandlerBlock) handler;
- (void) unregisterCustomMonitoringHandlerWithActionId:(NSString *) actionId;
- (void) sendNavigationEventWithIdentifier:(NSString *) identifier;
- (void) updateClient:(TapClient *) client;
- (void) enableSDKLogs:(BOOL) enableLog;

@end
