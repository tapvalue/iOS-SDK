//
//  ActionManager.h
//  TapBeaconSDK
//
//  Copyright (c) 2014 Tapvalue. All rights reserved.
//

@import Foundation;
@import UIKit;

typedef NS_ENUM(NSUInteger, TapBeaconDiscoveredResult) {
    TapBeaconDiscoveredResultAccept,
    TapBeaconDiscoveredResultDeny
};

typedef void (^TapBeaconDiscoveredCompletionBlock)(TapBeaconDiscoveredResult result);
typedef void (^CustomActionCompletionBlock)();
typedef void (^LoadingBeginHandlerBlock)();
typedef void (^LoadingEndHandlerBlock)();
typedef void (^CustomBeaconDiscoveredHandlerBlock)(NSString *message, TapBeaconDiscoveredCompletionBlock completionHandler);
typedef void (^CustomPictureDisplayHandlerBlock)(UIImage *image, CustomActionCompletionBlock completionHandler);
typedef void (^CustomOpenBrowserHandlerBlock)(NSURL *url);
typedef void (^CustomMessageDisplayHandlerBlock)(NSString *message);

@interface TapActionManager : NSObject

/**
 * Defines a custom handler that is called whenever a beacon is discovered.
 * The message can be handled as you wish as long as the application is currently in foreground.
 * Defining this block will override default SDK behavior, which is to display the message in an alert view.
 * The corresponding action will be executed once you have called the completion handler with the TapBeaconDiscoveredResultAccept parameter.
 * Be sure to call the completion handler, as otherwise, it will leave the SDK in an inconsistent state.
 */
@property (nonatomic, copy) CustomBeaconDiscoveredHandlerBlock customBeaconDiscoveredHandlerBlock;

/**
 * Defines a custom handler to manage the display of images picture actions.
 * Pictures can be handled as you wish.
 * Defining this block will override default SDK behavior, which is to display an image in a custom alert view.
 * Other beacon notifications will be disabled until the completion handler is called.
 * Be sure to call the completion handler, as otherwise, it will leave the SDK in an inconsistent state.
 */
@property (nonatomic, copy) CustomPictureDisplayHandlerBlock customPictureDisplayHandlerBlock;

/**
 * Defines a custom handler to manage the opening of a browser for URL actions.
 * You can manage the url as you wish.
 * Defining this block will override default SDK behavior which is to open the url in the default browser.
 */
@property (nonatomic, copy) CustomOpenBrowserHandlerBlock customOpenBrowserHandlerBlock;

/**
 * Defines a custom handler to manage a message display for simple message actions.
 * You can manage the message as you wish.
 * Defining this block will override default SDK behavior.
 */
@property (nonatomic, copy) CustomMessageDisplayHandlerBlock customMessageDisplayHandlerBlock;

/**
 * Defines a custom handler to handle begin of a loading (such as a picture download).
 * Defining this block will override default SDK behavior which is to open a loading alert.
 */
@property (nonatomic, copy) LoadingBeginHandlerBlock customLoadingBeginHandlerBlock;

/**
 * Defines a custom handler to handle begin of a loading (such as a picture download).
 * Defining this block will override default SDK behavior.
 */
@property (nonatomic, copy) LoadingEndHandlerBlock customLoadingEndHandlerBlock;

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
