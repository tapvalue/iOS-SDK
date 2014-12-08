//
//  ActionManager.h
//  TapBeaconSDK
//
//  Copyright (c) 2014 Tapvalue. All rights reserved.
//

@import Foundation;
@import UIKit;

@interface TapActionManager : NSObject

/**
 * Returns the singleton instance.
 *
 * @return The TapActionManager instance.
 */
+ (id) sharedManager;

/**
 * Checks if the notification was triggered by the SDK.
 *
 * @param notification The notification to check.
 *
 * @return Flag indicating if the notification is a TapNotification.
 */
- (BOOL) isTapNotification:(UILocalNotification *) notification;

/**
 * Checks if the application has been launched from a touch on a TapNotification.
 *
 * @param launchOptions The application launch options.
 *
 * @return Flag indicating if the application has been launched from a TapNotification.
 */
- (BOOL) isApplicationLaunchedFromTapNotification:(NSDictionary *) launchOptions;

/**
 * Executes the action for the given notification informations.
 *
 * @param info The notification informations to process.
 */
- (void) processActionForTapNotificationInfo:(NSDictionary *) info;

@end
