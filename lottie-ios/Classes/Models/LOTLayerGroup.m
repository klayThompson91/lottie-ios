//
//  LOTLayerGroup.m
//  Pods
//
//  Created by Brandon Withrow on 2/16/17.
//
//

#import "LOTLayerGroup.h"
#import "LOTLayer.h"
#import "LOTAssetGroup.h"

@implementation LOTLayerGroup {
  CGRect _bounds;
  NSNumber *_framerate;
  NSDictionary *_modelMap;
  NSDictionary *_referenceIDMap;
}

- (instancetype)initWithLayerJSON:(NSArray *)layersJSON
                       withBounds:(CGRect)bounds
                    withFramerate:(NSNumber * _Nullable)framerate
                   withAssetGroup:(LOTAssetGroup * _Nullable)assetGroup
                  withLayerColors:(LOTLayerColorMap _Nullable)layerColors {
  self = [super init];
  if (self) {
    _framerate = framerate;
    _bounds = bounds;
    [self _mapFromJSON:layersJSON withAssetGroup:assetGroup withLayerColors:layerColors];
  }
  return self;
}

- (instancetype)initWithLayerJSON:(NSArray *)layersJSON
                       withBounds:(CGRect)bounds
                    withFramerate:(NSNumber *)framerate
                   withAssetGroup:(LOTAssetGroup * _Nullable)assetGroup {
  return [self initWithLayerJSON:layersJSON withBounds:bounds withFramerate:framerate withAssetGroup:assetGroup withLayerColors:nil];
}

- (void)_mapFromJSON:(NSArray *)layersJSON withAssetGroup:(LOTAssetGroup * _Nullable)assetGroup withLayerColors:(LOTLayerColorMap _Nullable)layerColors {
  NSMutableArray *layers = [NSMutableArray array];
  NSMutableDictionary *modelMap = [NSMutableDictionary dictionary];
  NSMutableDictionary *referenceMap = [NSMutableDictionary dictionary];
  
  for (NSDictionary *layerJSON in layersJSON) {
    LOTLayer *layer = (layerColors) ? [[LOTLayer alloc] initWithJSON:layerJSON withCompBounds:_bounds withFramerate:_framerate withAssetGroup:assetGroup withLayerColors:layerColors] : [[LOTLayer alloc] initWithJSON:layerJSON withCompBounds:_bounds withFramerate:_framerate withAssetGroup:assetGroup];
    [layers addObject:layer];
    modelMap[layer.layerID] = layer;
    if (layer.referenceID) {
      referenceMap[layer.referenceID] = layer;
    }
  }
  
  _referenceIDMap = referenceMap;
  _modelMap = modelMap;
  _layers = layers;
}

- (LOTLayer *)layerModelForID:(NSNumber *)layerID {
  return _modelMap[layerID];
}

- (LOTLayer *)layerForReferenceID:(NSString *)referenceID {
  return _referenceIDMap[referenceID];
}

@end
