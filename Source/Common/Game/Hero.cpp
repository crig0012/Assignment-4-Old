//
//  Hero.cpp
//  GAM-1514 OSX Game
//
//  Created by Joel Cright on 2013-11-21.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "Hero.h"
#include "Level.h"
#include "Tile.h"
#include "../Constants/Constants.h"

Hero::Hero(Level* level) : Player(level)
{
    
}

Hero::~Hero()
{
    
}

const char* Hero::getType()
{
    return HERO_TYPE;
}

void Hero::mouseLeftClickUpEvent(float positionX, float positionY)
{
    Tile* tile = m_Level->getTileForPosition(positionX, positionY);
    if(tile != NULL && tile->isWalkableTile() == true)
    {
        //Set the destination tile
        setDestinationTile(tile);
        
        //Set the level's selected tile, this call is optional
        //Don't put it in if you don't want the red reticle
        m_Level->setSelectedTileIndex(m_Level->getTileIndexForTile(tile));
    }
}