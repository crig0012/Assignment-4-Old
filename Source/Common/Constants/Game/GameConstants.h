#ifndef GAME_CONSTANTS_H
#define GAME_CONSTANTS_H

#include "../../OpenGL/OpenGLColor.h"

//Game Constants
extern const char* GAME_SCREEN_NAME;

//Tile Constants
extern const char* TILE_WATER_TYPE;
extern const char* TILE_SPAWN_HERO_TYPE;
extern const char* TILE_SPAWN_ENEMY_TYPE;
extern const char* TILE_TREE_TYPE;
extern const char* TILE_CHEST_TYPE;
extern const char* TILE_WALL_TYPE;
extern const char* TILE_GROUND_TYPE;
extern const char* TILE_TOWER_TYPE;
extern const int TILE_PADDING;

//Player Constants
extern const int PLAYER_SIZE;
extern const float PLAYER_SPEED;
extern const OpenGLColor PLAYER_INSIDE_COLOR;
extern const OpenGLColor PLAYER_OUTLINE_COLOR;

//Hero Constants
extern const char* HERO_TYPE;

//Tower Constants
extern const char* TOWER_TYPE;
extern const char* BULLET_TOWER_TYPE;
extern const int TOWER_COUNT;

//Enemy Constants
extern const char* ENEMY_TYPE;
extern const int ENEMY_COUNT;

//Pickup Constants
extern const char* AMMO_PICKUP_TYPE;
#endif 
