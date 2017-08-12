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

/**
    LOTAnimationView's go through a pre-processing step to convert afterEffects JSON
    into animation models. This can be costly so the CacheStrategy allows you to define
    whether to cache these animation models or not.
*/
typedef NS_ENUM(NSInteger, LOTCacheStrategy) {
    
    /// Cache the underlying animation model for the current view.
    LOTCacheStrategyAlwaysCache,
    
    /// Do not cache the underlying animation model for the current view.
    LOTCacheStrategyNeverCache
};

@interface LOTAnimationView : LOTView

/**
    LOTAnimationView has a diverse array of initializers to suit a large breadth of needs
    such as loading a view from a URL, the file system, custom bundles, and etc.
    Please review the initializers to find the one appropriate for your use case.
*/

/**
    Basic initializers that can create a LOTAnimationView from the main bundle, 
    passed in custom bundle, a url, or at a specific location on the file system.
    All of these initializers will cache LOTAnimationView's underlying animation model 
    by default for better performance.
*/
+ (nonnull instancetype)animationNamed:(nonnull NSString *)animationName NS_SWIFT_NAME(init(name:));
+ (nonnull instancetype)animationNamed:(nonnull NSString *)animationName
                              inBundle:(nonnull NSBundle *)bundle NS_SWIFT_NAME(init(name:bundle:));
- (nonnull instancetype)initWithContentsOfURL:(nonnull NSURL *)url NS_SWIFT_NAME(init(url:));
+ (nonnull instancetype)animationWithFilePath:(nonnull NSString *)filePath NS_SWIFT_NAME(init(filePath:));

/**
    Use these initializers if you want to specify a caching strategy for your LOTAnimationView.
*/
+ (nonnull instancetype)animationNamed:(nonnull NSString *)animationName
                    usingCacheStrategy:(LOTCacheStrategy)cacheStrategy NS_SWIFT_NAME(init(name:cacheStrategy:));
+ (nonnull instancetype)animationNamed:(nonnull NSString *)animationName
                              inBundle:(nonnull NSBundle *)bundle
                    usingCacheStrategy:(LOTCacheStrategy)cacheStrategy NS_SWIFT_NAME(init(name:bundle:cacheStrategy:));
- (nonnull instancetype)initWithContentsOfURL:(nonnull NSURL *)url
                           usingCacheStrategy:(LOTCacheStrategy)cacheStrategy NS_SWIFT_NAME(init(url:cacheStrategy:));
+ (nonnull instancetype)animationWithFilePath:(nonnull NSString *)filePath
                           usingCacheStrategy:(LOTCacheStrategy)cacheStrategy NS_SWIFT_NAME(init(filePath:cacheStrategy:));

/**
    These initializers allow you to color each distinct layer of your LOTAnimationView.
    When using these initializers, the underlying animation model is NEVER cached. This can not be changed.
*/
+ (nonnull instancetype)animationNamed:(nonnull NSString *)animationName
                       withLayerColors:(nullable LOTLayerColorMap)layerColors NS_SWIFT_NAME(init(name:layerColors:));
+ (nonnull instancetype)animationNamed:(nonnull NSString *)animationName
                              inBundle:(nonnull NSBundle *)bundle
                       withLayerColors:(nullable LOTLayerColorMap)layerColors NS_SWIFT_NAME(init(name:bundle:layerColors:));
+ (nonnull instancetype)animationFromJSON:(nonnull NSDictionary *)animationJSON
                          withLayerColors:(nullable LOTLayerColorMap)layerColors NS_SWIFT_NAME(init(json:layerColors:));

/**
    Use this initializer to create a LOTAnimationView from a AfterEffects Dictionary.
    No caching is applied when using this initializer.
*/
+ (nonnull instancetype)animationFromJSON:(nonnull NSDictionary *)animationJSON NS_SWIFT_NAME(init(json:));

@property (nonatomic, readonly) BOOL isAnimationPlaying;
@property (nonatomic, assign) BOOL loopAnimation;
@property (nonatomic, assign) CGFloat animationProgress;
@property (nonatomic, assign) CGFloat animationSpeed;
@property (nonatomic, readonly) CGFloat animationDuration;

- (void)playWithCompletion:(nullable LOTAnimationCompletionBlock)completion;
- (void)play;
- (void)pause;

- (void)addSubview:(nonnull LOTView *)view
      toLayerNamed:(nonnull NSString *)layer;

#if !TARGET_OS_IPHONE && !TARGET_IPHONE_SIMULATOR
@property (nonatomic) LOTViewContentMode contentMode;
#endif

@end
