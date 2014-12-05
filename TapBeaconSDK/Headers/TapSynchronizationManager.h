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
typedef void (^SyncFailedHanler)(NSError *);

+ (id) sharedManager;

- (void) smartSync;
- (void) forceSync;
- (void) syncWithCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler forceUpdate:(BOOL) force;
- (void) syncWithSuccessHandler:(SyncSuccessHandler) successHandler fail:(SyncFailedHanler) failHandler forceUpdate:(BOOL) force;

@end
