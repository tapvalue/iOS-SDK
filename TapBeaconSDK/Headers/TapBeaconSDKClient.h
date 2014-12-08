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

@interface TapBeaconSDKClient : NSObject

@property (nonatomic, strong) TpvApiIdentifier *identifier;
@property (nonatomic, assign) id<TapBeaconSDKDelegate> delegate;

/**
 * Returns current instance if the client has been initialized.
 *
 * Only a single TapBeaconSDKClient instance can be active at the same time.
 *
 * @warning Ensure that the client has been initialized before calling this method
 * @return The TapBeaconSDKClient instance
 */
+ (instancetype) getInstance;

/**
 * Indicates the current state of the client.
 *
 * @return Flag that indicating if the client is initialized
 */
+ (BOOL) isInitialized;

/**
 * Initializes the client with a TpvApiIdentifier and a TapBeaconSDKDelegate.
 *
 * Once initialized, the SDK reports any encoutered errors and synchronization problems to its delegate.
 *
 * @param identifier The API identifier
 * @param delegate The SDK delegate
 */
+ (instancetype) clientWithApiIdentifier:(TpvApiIdentifier *) identifier withDelegate:(id<TapBeaconSDKDelegate>) delegate;

/**
 * Initializes the client with a TpvApiIdentifier and no delegate.
 *
 * @param identifier The API identifier.
 */
+ (instancetype) clientWithApiIdentifier:(TpvApiIdentifier *) identifier;

/**
 * Starts beacon scanning.
 *
 * This method register all regions to CoreLocation and starts the monitoring and ranging scan.
 */
- (void) start;

/**
 * Stops beacon scanning.
 *
 * This method unregister all regions from CoreLocation and stops the monitoring and ranging scan.
 */
- (void) stop;

/**
 * Sends a navigation event
 *
 * @param identifier A new navigation identifier for your navigation context.
 */
- (void) sendNavigationEventWithIdentifier:(NSString *) identifier;

/**
 * Updates the current connected client
 *
 * @param tapClient Represent a connected user inside your application.
 */
- (void) updateClient:(TapClient *) tapClient;

/**
 * Enables SDK debug logs.
 *
 * @param enableLog Flag indicating if SDK debug logs should be enabled.
 */
- (void) enableSDKLogs:(BOOL) enableLog;

@end
