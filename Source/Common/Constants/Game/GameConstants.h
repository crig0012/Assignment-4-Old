#ifndef GAME_CONSTANTS_H
#define GAME_CONSTANTS_H

#include "../../OpenGL/OpenGLColor.h"

//Game Constants
extern const char* GAME_SCREEN_NAME;

//Tile Constants
extern const char* TILE_WALL_TYPE;
extern const char* TILE_GROUND_TYPE;
extern const char* TILE_WATER_TYPE;
extern const char* TILE_CARPET_TYPE;
extern const char* TILE_FLOOR_TYPE;
extern const char* TILE_TREE_TYPE;
extern const int TILE_PADDING;
extern const OpenGLColor TILE_PADDING_COLOR;
extern const OpenGLColor TILE_WALL_COLOR;
extern const OpenGLColor TILE_GROUND_COLOR;
extern const OpenGLColor TILE_SELECTED_COLOR;
extern const OpenGLColor TILE_PATH_COLOR;

//Player Constants
extern const char* PLAYER_TYPE;
extern const int PLAYER_SIZE;
extern const float PLAYER_SPEED;
extern const OpenGLColor PLAYER_INSIDE_COLOR;
extern const OpenGLColor PLAYER_OUTLINE_COLOR;

#endif 