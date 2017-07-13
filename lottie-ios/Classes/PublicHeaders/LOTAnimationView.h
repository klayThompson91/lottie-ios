//
//  LOTAnimationView
//  LottieAnimator
//
//  Created by Brandon Withrow on 12/14/15.
//  Copyright © 2015 Brandon Withrow. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LOTAnimationView_Compat.h"
#import "LOTPlatformCompat.h"

typedef void (^LOTAnimationCompletionBlock)(BOOL animationFinished);
typedef NSDictionary<NSString *, UIColor *> * LOTLayerColorMap;

@interface LOTAnimationView : LOTView

+ (instancetype)animationNamed:(NSString *)animationName NS_SWIFT_NAME(init(name:));
+ (instancetype)animationNamed:(NSString *)animationName
               withLayerColors:(LOTLayerColorMap)layerColors NS_SWIFT_NAME(init(name:layerColors:));

+ (instancetype)animationNamed:(NSString *)animationName inBundle:(NSBundle *)bundle NS_SWIFT_NAME(init(name:bundle:));
+ (instancetype)animationNamed:(NSString *)animationName
                      inBundle:(NSBundle *)bundle
               withLayerColors:(LOTLayerColorMap)layerColors NS_SWIFT_NAME(init(name:bundle:layerColors:));

+ (instancetype)animationFromJSON:(NSDictionary *)animationJSON NS_SWIFT_NAME(init(json:));
+ (instancetype)animationFromJSON:(NSDictionary *)animationJSON
                  withLayerColors:(LOTLayerColorMap)layerColors NS_SWIFT_NAME(init(json:layerColors:));

- (instancetype)initWithContentsOfURL:(NSURL *)url;

@property (nonatomic, readonly) BOOL isAnimationPlaying;
@property (nonatomic, assign) BOOL loopAnimation;
@property (nonatomic, assign) CGFloat animationProgress;
@property (nonatomic, assign) CGFloat animationSpeed;
@property (nonatomic, readonly) CGFloat animationDuration;

- (void)playWithCompletion:(LOTAnimationCompletionBlock)completion;
- (void)play;
- (void)pause;

- (void)addSubview:(LOTView *)view
      toLayerNamed:(NSString *)layer;

#if !TARGET_OS_IPHONE && !TARGET_IPHONE_SIMULATOR
@property (nonatomic) LOTViewContentMode contentMode;
#endif

@end
