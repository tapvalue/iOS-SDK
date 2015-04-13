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
typedef void (^CustomBeaconDiscoveredHandlerBlock)(NSString *message, TapBeaconDiscoveredCompletionBlock completionHandler);
typedef void (^CustomPictureDisplayHandlerBlock)(NSURL *imageUrl, CustomActionCompletionBlock completionHandler);
typedef void (^CustomOpenBrowserHandlerBlock)(NSURL *url);
typedef void (^CustomHTMLDisplayHandlerBlock)(NSString *url, CustomActionCompletionBlock completionHandler);
typedef void (^CustomVideoDisplayHandlerBlock)(NSURL *url, CustomActionCompletionBlock completionHandler);
typedef void (^CustomMessageDisplayHandlerBlock)(NSString *message);

@interface TapActionManager : NSObject

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
 * Defines a custom handler that is called whenever a beacon is discovered.
 * The message can be handled as you wish as long as the application is currently in foreground.
 * If the application detect a beacon in background, the SDK automatically use Local notifications to present a message to the user.
 * Defining this block will override default SDK behavior, which is to display the message in an alert view.
 * The corresponding action will be executed once you have called the completion handler with the TapBeaconDiscoveredResultAccept parameter.
 * Be sure to call the completion handler, as otherwise, it will leave the SDK in an inconsistent state.
 */
@property (nonatomic, copy) CustomBeaconDiscoveredHandlerBlock customBeaconDiscoveredHandlerBlock;

/**
 * Defines a custom handler to manage the display of images picture actions.
 * Pictures can be handled as you wish.
 * Defining this block will override default SDK behavior, which is to display the image in a full screen view.
 * Be sure to call the completion handler, as otherwise, it will leave the SDK in an inconsistent state.
 */
@property (nonatomic, copy) CustomPictureDisplayHandlerBlock customPictureDisplayHandlerBlock;

/**
 * Defines a custom handler to manage the display of images picture actions.
 * Pictures can be handled as you wish.
 * Defining this block will override default SDK behavior, which is to display the html content rendered in a full screen view.
 * Be sure to call the completion handler, as otherwise, it will leave the SDK in an inconsistent state.
 */
@property (nonatomic, copy) CustomHTMLDisplayHandlerBlock customHTMLDisplayHandlerBlock;

/**
 * Defines a custom handler to manage the display of videos actions.
 * Video URLs can be handled as you wish.
 * Defining this block will override default SDK behavior, which is to display the video in a full screen view.
 * Be sure to call the completion handler, as otherwise, it will leave the SDK in an inconsistent state.
 */
@property (nonatomic, copy) CustomVideoDisplayHandlerBlock customVideoDisplayHandlerBlock;

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

/**
 * Add or replace an Action variable in the SDK.
 *
 * @param name The variable name.
 * @param value The variable value.
 */
- (void) addActionVariable:(NSString *) name withValue:(NSString *) value;

/**
 * Delete the action variable with the given key.
 *
 * @param name The variable name to remove
 */
- (void) deleteActionVariableWithName:(NSString *) name;

/**
 * Get the action variable with the given key.
 *
 * @param name The variable name to remove
 */
- (NSString *) findActionVariableWithName:(NSString *) name;

@end
