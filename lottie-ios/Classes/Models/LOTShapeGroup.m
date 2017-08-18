//
//  LOTShape.m
//  LottieAnimator
//
//  Created by Brandon Withrow on 12/14/15.
//  Copyright © 2015 Brandon Withrow. All rights reserved.
//

#import "LOTShapeGroup.h"
#import "LOTShapeFill.h"
#import "LOTShapePath.h"
#import "LOTShapeCircle.h"
#import "LOTShapeStroke.h"
#import "LOTShapeTransform.h"
#import "LOTShapeRectangle.h"
#import "LOTShapeTrimPath.h"

@implementation LOTShapeGroup

- (instancetype)initWithJSON:(NSDictionary *)jsonDictionary frameRate:(NSNumber *)frameRate compBounds:(CGRect)compBounds customColor:(UIColor *)customColor {
  self = [super init];
  if (self) {
    [self _mapFromJSON:jsonDictionary frameRate:frameRate compBounds:compBounds customColor:customColor];
  }
  return self;
}

- (instancetype)initWithJSON:(NSDictionary *)jsonDictionary frameRate:(NSNumber *)frameRate compBounds:(CGRect)compBounds {
    return [self initWithJSON:jsonDictionary frameRate:frameRate compBounds:compBounds customColor:nil];
}

- (void)_mapFromJSON:(NSDictionary *)jsonDictionary frameRate:(NSNumber *)frameRate compBounds:(CGRect)compBounds customColor:(UIColor *)customColor {
  NSArray *itemsJSON = jsonDictionary[@"it"];
  NSMutableArray *items = [NSMutableArray array];
  for (NSDictionary *itemJSON in itemsJSON) {
    id newItem = [LOTShapeGroup shapeItemWithJSON:itemJSON frameRate:frameRate compBounds:compBounds customColor:customColor];
    if (newItem) {
      [items addObject:newItem];
    }
  }
  _items = items;
}

+ (id)shapeItemWithJSON:(NSDictionary *)itemJSON frameRate:(NSNumber *)frameRate compBounds:(CGRect)compBounds {
  return [LOTShapeGroup shapeItemWithJSON:itemJSON frameRate:frameRate compBounds:compBounds customColor:nil];
}

+ (id)shapeItemWithJSON:(NSDictionary *)itemJSON frameRate:(NSNumber *)frameRate compBounds:(CGRect)compBounds customColor:(UIColor *)customColor {
  NSString *type = itemJSON[@"ty"];
  if ([type isEqualToString:@"gr"]) {
    LOTShapeGroup *group = [[LOTShapeGroup alloc] initWithJSON:itemJSON frameRate:frameRate compBounds:compBounds customColor:customColor];
    return group;
  } else if ([type isEqualToString:@"st"]) {
    if (customColor) {
        return [[LOTShapeStroke alloc] initWithJSON:itemJSON frameRate:frameRate customColor:customColor];
    } else {
        return [[LOTShapeStroke alloc] initWithJSON:itemJSON frameRate:frameRate];
    }
  } else if ([type isEqualToString:@"fl"]) {
    if (customColor) {
        return [[LOTShapeFill alloc] initWithJSON:itemJSON frameRate:frameRate customColor:customColor];
    } else {
        return [[LOTShapeFill alloc] initWithJSON:itemJSON frameRate:frameRate];
    }
  } else if ([type isEqualToString:@"tr"]) {
    LOTShapeTransform *transform = [[LOTShapeTransform alloc] initWithJSON:itemJSON frameRate:frameRate compBounds:compBounds];
    return transform;
  } else if ([type isEqualToString:@"sh"]) {
    LOTShapePath *path = [[LOTShapePath alloc] initWithJSON:itemJSON frameRate:frameRate];
    return path;
  } else if ([type isEqualToString:@"el"]) {
    LOTShapeCircle *circle = [[LOTShapeCircle alloc] initWithJSON:itemJSON frameRate:frameRate];
    return circle;
  } else if ([type isEqualToString:@"rc"]) {
    LOTShapeRectangle *rectangle = [[LOTShapeRectangle alloc] initWithJSON:itemJSON frameRate:frameRate];
    return rectangle;
  } else if ([type isEqualToString:@"tm"]) {
    LOTShapeTrimPath *trim = [[LOTShapeTrimPath alloc] initWithJSON:itemJSON frameRate:frameRate];
    return trim;
  } 
  return nil;
}

- (NSString*)description {
    NSMutableString *text = [[super description] mutableCopy];
    [text appendFormat:@" items: %@", self.items];
    return text;
}

@end
