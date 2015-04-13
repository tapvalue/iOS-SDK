//
//  TapClientBuilder.h
//  TapBeaconSDK
//
//  Copyright (c) 2014 Tapvalue. All rights reserved.
//

@import Foundation;

@class TapCustomer;

@interface TapCustomerBuilder : NSObject

@property(nonatomic, strong) NSString *clientId;
@property(nonatomic, strong) NSString *clientEmail;
@property(nonatomic, strong) NSString *clientFirstName;
@property(nonatomic, strong) NSString *clientLastName;

/**
 * Create a TapClient from the builder properties.
 *
 * @return a new TapClient instance.
 */
- (TapCustomer *) build;

@end
