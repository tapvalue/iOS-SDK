//
//  TpvApiIdentifier.h
//  TapBeaconSDK
//
//  Copyright (c) 2014 Tapvalue. All rights reserved.
//

@import Foundation;

@interface TpvApiIdentifier : NSObject

@property (nonatomic, strong) NSString *token;
@property (nonatomic, strong) NSString *userId;
@property (nonatomic, strong) NSString *appId;

/**
 * Initializes a new API Identifier.
 *
 * @param userId Your API user ID.
 * @param token Your API user token.
 */
+ (TpvApiIdentifier *) identifierWithUserId:(NSString *)userId token:(NSString *)token appId:(NSString *)appId;

@end
