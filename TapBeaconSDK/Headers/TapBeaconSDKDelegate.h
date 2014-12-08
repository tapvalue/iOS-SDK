//
//  TapClientDelegate.h
//  TapBeaconSDK
//
//  Copyright (c) 2014 Tapvalue. All rights reserved.
//

@import CoreLocation;

@class TapBeaconSDKClient;

/**
 * Defines the optional delegate methods used to receive SDK informations on errors and synchronizations.
 */
@protocol TapBeaconSDKDelegate <NSObject>

@required
@optional
/**
 * Tells the delegate that a synchronization did occur flawlessly.
 *
 * @param client The client SDK instance.
 */
- (void)tapClientDidSync:(TapBeaconSDKClient *)client;

/**
 * Tells the delegate that a synchronization failed.
 *
 * @param client The client SDK instance.
 * @param error The error object describing why the synchronization failed.
 */
- (void)tapClient:(TapBeaconSDKClient *)client syncFailWithError:(NSError *) error;

/**
 * Tells the delegate that the SDK has encountered an error.
 *
 * @param client The client SDK instance.
 * @param error The error object describing why the SDK has encountered an error.
 */
- (void)tapClient:(TapBeaconSDKClient *)client didFailWithError:(NSError *)error;

/**
 * Tells the delegate that the CoreLocation authorization has changed.
 *
 * @param client The client SDK instance.
 * @param status The new CoreLocation authorization status.
 */
- (void)tapClient:(TapBeaconSDKClient *)client didChangeAuthorizationStatus:(CLAuthorizationStatus)status;

@end
