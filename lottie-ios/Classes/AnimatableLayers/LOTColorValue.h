//
//  LOTColorValue.h
//  Lottie
//
//  Created by Abhay Curam on 6/27/17.
//  Copyright © 2017 Airbnb. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LOTPlatformCompat.h"
#import "LOTAnimatableValue.h"

@interface LOTColorValue : NSObject <LOTAnimatableValue>

- (instancetype)initWithColorValue:(UIColor *)color;

@property (nonatomic, strong) UIColor *initialColor;

@end
