//
//  Tower.cpp
//  GAM-1514 OSX Game
//
//  Created by Joel Cright on 2013-12-05.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "Tower.h"
#include "Hero.h"
#include "Level.h"
#include "../../Game/Tiles/Tile.h"
#include "../../Input/Input.h"
#include "../../Utils/Utils.h"
#include "Enemy.h"

Tower::Tower(Level* level, TowerType towerType) : Player(level),
    m_TowerType(towerType)
{
    m_Ammo = 10000;
}

Tower::~Tower()
{
    
}

void Tower::update(double delta)
{
    MathUtils mathUtils;
    m_EnemyArray = m_Level->getEnemies();
    
    //Update the projectiles
    for(int i = 0; i < m_Projectiles.size(); i++)
    {
        if(m_Projectiles.at(i)->getIsActive() == true)
        {
            m_Projectiles.at(i)->update(delta);
        }
    }
    
    //Remove any inactive projectiles from the projectiles vector
    int index = 0;
    while(index != m_Projectiles.size())
    {
        if(m_Projectiles.at(index)->getIsActive() == false)
        {
            Log::debug("Deleting projectile");
            
            //delete the projectile and remove it from the vector
            delete m_Projectiles.at(index);
            m_Projectiles.erase(m_Projectiles.begin() + index);
        }
        
        else
        {
            index++;
        }
    }
    
    for(int i = 0; i < m_EnemyArray.size(); i++)
    {
        if(m_EnemyArray.at(i)->getIsActive() == false)
        {
            continue;
        }
        
        if(mathUtils.withinRange(m_Level, m_Level->getTileIndexForPlayer(this), m_Level->getTileIndexForPlayer(m_EnemyArray.at(i)), 60))
        {
            Tile* targetTile = m_Level->getTileForPlayer(m_EnemyArray.at(i));
            float centerX = targetTile->getX() + (targetTile->getWidth() / 2.0f);
            float centerY = targetTile->getY() + (targetTile->getHeight() / 2.0f);
            
            //Fire the projectiles
            fireProjectile(centerX, centerY);
        }
    }
}

void Tower::paint()
{
    OpenGLRenderer::getInstance()->setForegroundColor(OpenGLColorGreen());
	OpenGLRenderer::getInstance()->drawCircle(getX() + (getWidth() / 2), getY() + (getHeight() / 2), getWidth() / 2, 90);
	OpenGLRenderer::getInstance()->setForegroundColor(PLAYER_OUTLINE_COLOR);
	OpenGLRenderer::getInstance()->drawCircle(getX() + (getWidth() / 2), getY() + (getHeight() / 2), getWidth() / 2, 90, false);
}

void Tower::reset()
{
    
}

const char* Tower::getType()
{
    return TOWER_TYPE;
}

TowerType Tower::getTowerType()
{
    return  m_TowerType;
}

void Tower::handlePlayerCollision(Projectile *projectile)
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
                Log::debug("Tower projectile hit an enemy at index %i", i);
                
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

void Tower::handleBoundsCollision(Projectile* projectile)
{
    Tile* tile = m_Level->getTileForPosition(projectile->getX(), projectile->getY());
    if(tile == NULL)
    {
        projectile->setIsActive(false);
    }
}