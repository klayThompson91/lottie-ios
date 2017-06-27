//
//  LOTColorValue.h
//  Lottie
//
//  Created by Abhay Curam on 6/27/17.
//  Copyright © 2017 Airbnb. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LOTPlatformCompat.h"

@interface LOTColorValue : NSObject

- (instancetype)initWithColorValue:(UIColor *)color;

@property (nonatomic, strong) UIColor *initialColor;

@end
