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

/**
 * Initializes a TapClient using the builder pattern.
 *
 * @return A new TapClient instance.
 */
+ (instancetype) tapClientWithBlock:(TapClientBuilderBlock) block;

/*
 * Initializes a TapClient with a Builder.
 *
 * @return A new TapClient instance.
 */
- (id)initWithBuilder:(TapClientBuilder *)builder;

@end
