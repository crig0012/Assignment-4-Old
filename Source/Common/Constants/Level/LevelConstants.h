//
//  LevelConstants.h
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef LEVEL_CONSTANTS_H
#define LEVEL_CONSTANTS_H

//Global enum for the Level's tile types,
//add additional tile types in this enum
enum TileType
{
  TileTypeGround = 0,
  TileTypeTree,
  TileTypeWater,
  TileTypeWall,
  TileTypeFloor,
  TileTypeCarpet,
  TileTypeUnknown,
  TileTypeCount
};

//Level editor screen name
extern const char* LEVEL_EDITOR_SCREEN_NAME;

//Level slot filenames
#define NUMBER_OF_LEVEL_SLOTS 6
extern const char* LEVEL_SLOT_FILENAMES[NUMBER_OF_LEVEL_SLOTS];

//Empty Level Constants
extern const int EMPTY_LEVEL_TILE_SIZE;
extern const int EMPTY_LEVEL_STARTING_PLAYER_TILE_INDEX;

#endif
