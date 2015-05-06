//
//  TapClient.h
//  TapBeaconSDK
//
//  Copyright (c) 2014 Tapvalue. All rights reserved.
//

@import Foundation;

@protocol TapvalueSDKDelegate;
@class TpvApiIdentifier;
@class TpvBeacon;
@class TapCustomer;

typedef NSString *(^DeviceIdHandlerBlock)();

@interface TapvalueSDKClient : NSObject

typedef NS_ENUM(NSInteger, PushNotificationServiceType) {
    PushNotificationServiceTypeApnsSandbox = 0,
    PushNotificationServiceTypeApns = 1
};

/**
 * Set a block to allow the SDK to retrieve the Device ID / IDFA if you have it in your application
 */
@property (nonatomic, copy) DeviceIdHandlerBlock deviceIdHandlerBlock;


@property (nonatomic, strong) TpvApiIdentifier *identifier;
@property (nonatomic, assign) id<TapvalueSDKDelegate> delegate;

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
+ (instancetype) clientWithApiIdentifier:(TpvApiIdentifier *) identifier withDelegate:(id<TapvalueSDKDelegate>) delegate;

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
 * Sends a Transaction event
 *
 * @param transactionId The transaction identifier
 * @param transactionAmount The amount of the transaction
 * @param productIds The list of product ids in this transaction
 */
- (void) sendTransactionEventWithTransactionId:(NSString *) transactionId amount:(NSNumber *) transactionAmount withProductIds:(NSArray *) productIds;

/**
 * Sends a Product event
 *
 * @param productId The product identifier viewed by your customer.
 */
- (void) sendProductEventWithProductId:(NSString *) productId;

/**
 * Sends a Shopping Cart event
 *
 * @param productId The product identifier added by your customer in his shopping cart.
 */
- (void) sendShoppingCartEventWithProductId:(NSString *) productId;

/**
 * Sends a Shopping Cart event
 *
 * @param productIds The product ids added by your customer in his shopping cart.
 */
- (void) sendShoppingCartEventWithProductIds:(NSArray *) productIds;

/**
 * Updates the current connected customer
 *
 * @param tapCustomer Represent a connected user inside your application.
 */
- (void) updateCustomer:(TapCustomer *) tapCustomer;

/**
 * Enables SDK debug logs.
 *
 * @param enableLog Flag indicating if SDK debug logs should be enabled.
 */
- (void) enableSDKLogs:(BOOL) enableLog;

/**
 * Sends the device token to Tapvalue servers
 *
 * @param deviceToken The device token
 */
- (void) handlePushRegistration:(NSData *) deviceToken;

/**
 * Set the push provider in order to associate the device token with corresponding APNS Server in Tapvalue server
 *
 * @param notificationService APNS or APNS Sandbox
 */
- (void) setPushNotificationService:(PushNotificationServiceType) notificationServiceType;

@end
