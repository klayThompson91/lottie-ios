//
//  LOTShapeFill.h
//  LottieAnimator
//
//  Created by Brandon Withrow on 12/15/15.
//  Copyright © 2015 Brandon Withrow. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LOTAnimationView.h"

@class LOTAnimatableNumberValue;
@class LOTAnimatableColorValue;

@interface LOTShapeFill : NSObject

- (instancetype)initWithJSON:(NSDictionary *)jsonDictionary frameRate:(NSNumber *)frameRate;
- (instancetype)initWithJSON:(NSDictionary *)jsonDictionary frameRate:(NSNumber *)frameRate customColor:(UIColor *)color;

@property (nonatomic, readonly) BOOL fillEnabled;
@property (nonatomic, readonly) LOTAnimatableColorValue *color;
@property (nonatomic, readonly) LOTAnimatableNumberValue *opacity;

@end
