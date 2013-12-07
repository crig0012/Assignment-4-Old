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
  TileTypeGround = 1,   //(0000 0001)
  TileTypeWater = 2,    //(0000 0010)
  TileTypeTree = 4,     //(0000 0100)
  TileTypeWall = 8,     //(0000 1000)
  TileTypeTower = 16,   //(0001 0000)
  TileTypeChest = 32,   //(0010 0000)
    
    //This Count value MUST now be manually updated when a new tile is added 
  TileTypeCount = 6,   
  TileTypeSpawnHero,
  TileTypeSpawnEnemy,
  TileTypeUnknown = -1
};


enum PickupType
{
    PickupTypeAmmo = 64,    //(0100 0000)
    
    //This Count value MUST now be manually updated when a new tile is added
	PickupTypeCount = 1,
	PickupTypeUnkown = -1
};

enum TowerType
{
    BulletTower = 128
};

//Level editor screen name
extern const char* LEVEL_EDITOR_SCREEN_NAME;
extern const char* SETTINGS_SCREEN_NAME;
extern const char* SAVE_SCREEN_NAME;
extern const char* LOAD_SCREEN_NAME;

//Empty Level Constants
extern const int EMPTY_LEVEL_TILE_SIZE;
extern const int EMPTY_LEVEL_STARTING_PLAYER_TILE_INDEX;

#endif
