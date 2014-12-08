//
//  TapClientBuilder.h
//  TapBeaconSDK
//
//  Copyright (c) 2014 Tapvalue. All rights reserved.
//

@import Foundation;

@class TapClient;

@interface TapClientBuilder : NSObject

@property(nonatomic, strong) NSString *clientId;
@property(nonatomic, strong) NSString *clientEmail;

/**
 * Create a TapClient from the builder properties.
 *
 * @return a new TapClient instance.
 */
- (TapClient *) build;

@end
