//
//  Hero.cpp
//  GAM-1514 OSX Game
//
//  Created by Joel Cright on 2013-11-21.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "Hero.h"
#include "Level.h"
#include "../../Game/Tiles/Tile.h"
#include "../../Constants/Constants.h"
#include "../../Input/Input.h"
#include "../../Utils/Utils.h"
#include "Enemy.h"


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
    }
}

void Hero::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{
    Tile* tile = m_Level->getTileForPosition(positionX, positionY);
    if(tile != NULL && tile->isWalkableTile() == true)
    {
        //Set the level's selected tile, this call is optional
        //Don't put it in if you don't want the red reticle
        m_Level->setSelectedTileIndex(m_Level->getTileIndexForTile(tile));
    }
}

void Hero::keyUpEvent(int keyCode)
{
    if(keyCode == KEYCODE_SPACE)
    {
        Tile* targetTile = m_Level->getTileForIndex((m_Level->getSelectedTileIndex()));
        float centerX = targetTile->getX() + (targetTile->getWidth() / 2.0f);
        float centerY = targetTile->getY() + (targetTile->getHeight() / 2.0f);
        
        //Fire the projectiles
        fireProjectile(centerX, centerY);
    }
}

void Hero::handlePlayerCollision(Projectile *projectile)
{
    Tile* tile = m_Level->getTileForPosition(projectile->getX(), projectile->getY());
    
    //Cycle through all the enemies and check for collision with the projectile
    for(int i = 0; i < m_Level->getEnemies().size(); i++)
    {
        Enemy* enemy = m_Level->getEnemies().at(i);
        if(enemy != NULL && enemy->getIsActive() == true)
        {
            //Get the tile the enemy is on
            Tile* enemyTile = m_Level->getTileForPlayer(enemy);
            
            //Is the projectile on the same tile as the enemy?
            if(tile == enemyTile)
            {
                Log::debug("Hero projectile hit an enemy at index %i", i);
                
                if(m_Level != NULL)
                {
                    m_Level->setPickupTypeAtIndex(PickupTypeAmmo, m_Level->getTileIndexForPlayer(enemy));
                }
                
                //Apply damage to the enemy AND set the projectile to inactive
                enemy->applyDamage(projectile->getDamage());
                projectile->setIsActive(false);
            }
        }
    }
}

void Hero::handleBoundsCollision(Projectile* projectile)
{
    Tile* tile = m_Level->getTileForPosition(projectile->getX(), projectile->getY());
    if(tile == NULL)
    {
        projectile->setIsActive(false);
    }
}