//
//  ActionManager.h
//  TapBeaconSDK
//
//  Copyright (c) 2014 Tapvalue. All rights reserved.
//

@import Foundation;
@import UIKit;

@interface TapActionManager : NSObject

+ (id) sharedManager;

- (BOOL) isTapNotification:(UILocalNotification *) notification;

- (BOOL) isApplicationLaunchedFromTapNotification:(NSDictionary *) launchOptions;

- (void) processActionForTapNotificationInfo:(NSDictionary *) info;

@end
