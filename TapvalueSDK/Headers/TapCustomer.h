//
//  CurrentUser.h
//  TapBeaconSDK
//
//  Copyright (c) 2014 Tapvalue. All rights reserved.
//

@import Foundation;

@class TapCustomerBuilder;

typedef void (^TapCustomerBuilderBlock)(TapCustomerBuilder *builder);

@interface TapCustomer : NSObject

@property(nonatomic, strong) NSString *clientId;
@property(nonatomic, strong) NSString *clientEmail;
@property(nonatomic, strong) NSString *clientFirstName;
@property(nonatomic, strong) NSString *clientLastName;

/**
 * Initializes a TapClient using the builder pattern.
 *
 * @return A new TapClient instance.
 */
+ (instancetype) tapCustomerWithBlock:(TapCustomerBuilderBlock) block;

/*
 * Initializes a TapClient with a Builder.
 *
 * @return A new TapClient instance.
 */
- (id)initWithBuilder:(TapCustomerBuilder *)builder;

@end
