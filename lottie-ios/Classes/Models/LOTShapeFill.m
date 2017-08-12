//
//  LOTShapeFill.m
//  LottieAnimator
//
//  Created by Brandon Withrow on 12/15/15.
//  Copyright © 2015 Brandon Withrow. All rights reserved.
//

#import "LOTShapeFill.h"
#import "LOTAnimatableNumberValue.h"
#import "LOTAnimatableColorValue.h"

@implementation LOTShapeFill

- (instancetype)initWithJSON:(NSDictionary *)jsonDictionary frameRate:(NSNumber *)frameRate customColor:(UIColor *)color {
  self = [super init];
  if (self) {
    [self _mapFromJSON:jsonDictionary frameRate:frameRate customColor:color];
  }
  return self;
}

- (instancetype)initWithJSON:(NSDictionary *)jsonDictionary frameRate:(NSNumber *)frameRate {
    return [self initWithJSON:jsonDictionary frameRate:frameRate customColor:nil];
}

- (void)_mapFromJSON:(NSDictionary *)jsonDictionary frameRate:(NSNumber *)frameRate customColor:(UIColor *)customColor {
  NSDictionary *color = jsonDictionary[@"c"];
  if (color) {
    if (customColor) {
        _color = [[LOTAnimatableColorValue alloc] initWithCustomColor:customColor];
    } else {
        _color = [[LOTAnimatableColorValue alloc] initWithColorValues:color frameRate:frameRate];
    }
  }
  
  NSDictionary *opacity = jsonDictionary[@"o"];
  if (opacity) {
    _opacity = [[LOTAnimatableNumberValue alloc] initWithNumberValues:opacity frameRate:frameRate];
    [_opacity remapValuesFromMin:@0 fromMax:@100 toMin:@0 toMax:@1];
  }
  
  NSNumber *fillEnabled = jsonDictionary[@"fillEnabled"];
  _fillEnabled = fillEnabled.boolValue;
}

@end
