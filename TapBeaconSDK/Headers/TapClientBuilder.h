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

- (TapClient *) build;

@end
