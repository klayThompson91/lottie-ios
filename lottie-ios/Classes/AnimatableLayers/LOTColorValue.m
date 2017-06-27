//
//  LOTColorValue.m
//  Lottie
//
//  Created by Abhay Curam on 6/27/17.
//  Copyright © 2017 Airbnb. All rights reserved.
//

#import "LOTColorValue.h"

@implementation LOTColorValue

- (instancetype)initWithColorValue:(UIColor *)color {
    if (self = [super init]) {
        _initialColor = color;
    }
    
    return self;
}

@end
