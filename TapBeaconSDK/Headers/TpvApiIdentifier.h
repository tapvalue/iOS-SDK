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

+ (TpvApiIdentifier *) identifierWithUserId:(NSString *)userId token:(NSString *)token;

@end
