//
//  SynchronizationManager.h
//  TapBeaconSDK
//
//  Copyright (c) 2014 Tapvalue. All rights reserved.
//

@import Foundation;
@import UIKit;

@interface TapSynchronizationManager : NSObject

typedef void (^SyncSuccessHandler)();
typedef void (^SyncFailedHandler)(NSError *);

/**
 * Returns the singleton instance.
 *
 * @return The TapSynchronizationManager instance.
 */
+ (instancetype) sharedManager;

/**
 * Starts API synchronization only if necessary based on the last synchronization date.
 */
- (void) smartSync;

/**
 * Starts API synchronization immediatly, ignoring last synchronization date.
 */
- (void) forceSync;

/**
 * Starts synchronization with a UIBackgroundFetchResult automatically called inside the method.
 *
 * The purpose of this method is to be used with the Background Fetch API.
 *
 * @return completionHandler The UIBackgroundFetchResult completion handler.
 * @return force Flag indicating if the synchronization has to be forced.
 */
- (void) syncWithCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler forceUpdate:(BOOL) force;

/**
 * Starts synchronization with a Success and a Fail handler.
 *
 * @return successHandler An handler called if the synchronization was successful.
 * @return failHandler An handler called if the synchronization failed.
 * @return force Flag indicating if the synchronization has to be forced.
 */
- (void) syncWithSuccessHandler:(SyncSuccessHandler) successHandler fail:(SyncFailedHandler) failHandler forceUpdate:(BOOL) force;

@end
