//
//  CurrentUser.h
//  TapBeaconSDK
//
//  Copyright (c) 2014 Tapvalue. All rights reserved.
//

@import Foundation;

@class TapClientBuilder;

typedef void (^TapClientBuilderBlock)(TapClientBuilder *builder);

@interface TapClient : NSObject

@property(nonatomic, strong) NSString *clientId;
@property(nonatomic, strong) NSString *clientEmail;

+ (instancetype) tapClientWithBlock:(TapClientBuilderBlock) block;

- (id)initWithBuilder:(TapClientBuilder *)builder;

@end
