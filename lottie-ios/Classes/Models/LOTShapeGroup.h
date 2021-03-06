//
//  LOTShape.h
//  LottieAnimator
//
//  Created by Brandon Withrow on 12/14/15.
//  Copyright © 2015 Brandon Withrow. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import "LOTPlatformCompat.h"

@interface LOTShapeGroup : NSObject

- (instancetype)initWithJSON:(NSDictionary *)jsonDictionary frameRate:(NSNumber *)frameRate compBounds:(CGRect)compBounds;
- (instancetype)initWithJSON:(NSDictionary *)jsonDictionary frameRate:(NSNumber *)frameRate compBounds:(CGRect)compBounds customColor:(UIColor *)customColor;

@property (nonatomic, readonly) NSArray *items;

+ (id)shapeItemWithJSON:(NSDictionary *)itemJSON frameRate:(NSNumber *)frameRate compBounds:(CGRect)compBounds;
+ (id)shapeItemWithJSON:(NSDictionary *)itemJSON frameRate:(NSNumber *)frameRate compBounds:(CGRect)compBounds customColor:(UIColor *)customColor;

@end
