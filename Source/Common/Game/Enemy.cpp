//
//  Enemy.cpp
//  GAM-1514 OSX Game
//
//  Created by Joel Cright on 2013-11-21.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "Enemy.h"
#include "Level.h"
#include "Tile.h"
#include "Hero.h"
#include "../Constants/Constants.h"

Enemy::Enemy(Level* level, float speed) : Player(level)
{
    m_Speed = speed;
}

Enemy::~Enemy()
{
    
}

void Enemy::reset()
{
    Player::reset();
    
    //Set the destination tile
    setDestinationTile(m_Level->getTileForPlayer(m_Level->getHero()));

}

const char* Enemy::getType()
{
    return ENEMY_TYPE;
}

void Enemy::update(double delta)
{
    Player::update(delta);
    
    //Set the destination tile based on the player's current tile
    setDestinationTile(m_Level->getTileForPlayer(m_Level->getHero()));
}

void Enemy::paint()
{
    OpenGLRenderer::getInstance()->setForegroundColor(OpenGLColorRed());
	OpenGLRenderer::getInstance()->drawCircle(getX() + (getWidth() / 2), getY() + (getHeight() / 2), getWidth() / 2, 90);
	OpenGLRenderer::getInstance()->setForegroundColor(PLAYER_OUTLINE_COLOR);
	OpenGLRenderer::getInstance()->drawCircle(getX() + (getWidth() / 2), getY() + (getHeight() / 2), getWidth() / 2, 90, false);
}