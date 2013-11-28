//
//  Player.cpp
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "Player.h"
#include "Level.h"
#include "Tiles/Tile.h"
#include "../Pickups/AmmoPickup.h"
#include "../OpenGL/OpenGL.h"
#include "../Constants/Constants.h"
#include "../PathFinding/PathNode.h"
#include "../Utils/Utils.h"
#include "Projectile.h"
#include <stdlib.h>
#include <algorithm>
#include <math.h>

Player::Player(Level* aLevel)
{
    m_Level = aLevel;
    
    //Create the PathFinder object
    m_PathFinder = new PathFinder(aLevel, this);
    //Initialize the current and destination tiles to NULL
    m_CurrentTile = NULL;
    m_DestinationTile = NULL;
    
    //Initialize the animation member variables
    m_CanAnimate = false;
    m_AbortAnimation = false;
    m_AnimationPathNodeIndex = -1;
    
    //Set the player speed
    m_Speed = PLAYER_SPEED;
    
    //Initialize the ammo and the health
    m_Ammo = 10;
    m_Health = 3;
    
    //Initialize the player's size
    setSize(PLAYER_SIZE, PLAYER_SIZE);
}

Player::~Player()
{
    if(m_PathFinder != NULL)
    {
        delete m_PathFinder;
        m_PathFinder = NULL;
    }
    
    //Set the current and desination tiles to NULL
	m_CurrentTile = NULL;
	m_DestinationTile = NULL;
}

void Player::update(double aDelta)
{
    //Update the projectiles
    for(int i = 0; i < m_Projectiles.size(); i++)
    {
        if(m_Projectiles.at(i)->getIsActive() == true)
        {
            m_Projectiles.at(i)->update(aDelta);
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
    
    //Update the path finder
    if(m_PathFinder->isSearchingPath() == true)
    {
        m_PathFinder->update(aDelta);
    }
    
    //Handle Player animation
    if(isAnimating() == true && m_AnimationPathNodeIndex > -1)
    {
        PathNode * pathNode = m_PathFinder->getPathNodeAtIndex(m_AnimationPathNodeIndex);
        Tile* tile = pathNode != NULL ? pathNode->getTile() : NULL;
        
        //Saftey check that tile isn't NULL
        if(tile != NULL)
        {
            //Calculate the center of the tile
            float centerX = tile->getX() + (tile->getWidth() - getWidth()) / 2.0f;
            float centerY = tile->getY() + (tile->getHeight() - getHeight()) / 2.0f;
            
            //Get the tile speed for the tilw the player is on
            Tile* playerTile = m_Level->getTileForPosition(getX(), getY());
            float speed = playerTile->getTileSpeed();
            
            //Next calculate how much the player should animate this update() call,
            //use the animate() method to help calculate
            float playerX = animate(getX(), centerX, aDelta, speed);
            float playerY = animate(getY(), centerY, aDelta, speed);
            
            setPosition(playerX, playerY);
            
            //Has the player reached the center of the tile?
            if(playerX == centerX && playerY == centerY)
            {
                m_AnimationPathNodeIndex++;
                
                //Set the current tile's flag to false
                m_CurrentTile->setIsPath(false);
                
                //Set the new current tile
                setCurrentTile(tile);
                
                //Does the tile have a pickup on it
                if(tile->getPickup() != NULL)
                {
                    handlePickup(tile->getPickup());
                    
                    //Set the tile's pick to NULL, since it was picked up
                    tile->setPickup(NULL);
                }
                
                //Are we done animating completely?
                if(m_AnimationPathNodeIndex >= m_PathFinder->getPathSize())
                {
                    stopAnimating();
                    m_CurrentTile->setIsPath(false);
                }
                
                //Is the abort animation flag set?
                if(m_AbortAnimation == true)
                {
                    //Reset the flag to false
                    m_AbortAnimation = false;
                    
                    //Begin searching the new path
                    findPath();
                }
            }
        }
    }
}

void Player::paint()
{
	OpenGLRenderer::getInstance()->setForegroundColor(PLAYER_INSIDE_COLOR);
	OpenGLRenderer::getInstance()->drawCircle(getX() + (getWidth() / 2), getY() + (getHeight() / 2), getWidth() / 2, 90);
	OpenGLRenderer::getInstance()->setForegroundColor(PLAYER_OUTLINE_COLOR);
	OpenGLRenderer::getInstance()->drawCircle(getX() + (getWidth() / 2), getY() + (getHeight() / 2), getWidth() / 2, 90, false);
    
    //Cycle through and paint all the 'active' projectiles
    for(int i = 0; i < m_Projectiles.size(); i++)
    {
        if(m_Projectiles.at(i)->getIsActive() == true)
        {
            m_Projectiles.at(i)->paint();
        }
    }
}

void Player::reset()
{
    //Stop animating the player
    stopAnimating();
    
    //Reset the pathFinder
    m_PathFinder->reset();
    
    //Set the destination tile to null
    m_DestinationTile = NULL;
    
    //Set the player's state to 'active'
    setIsActive(true);
}

void Player::fireProjectile(float x, float y)
{
    //Safety check that there is ammo left
    if(m_Ammo > 0)
    {
        m_Ammo--;
        
        //Create a new projectile object
        Projectile* projectile = new Projectile(this, 1, 10.0f);
        projectile->setPosition(getX() + (getWidth() / 2.0f), getY() + (getHeight() / 2.0f));
        projectile->setTarget(x, y);
        m_Projectiles.push_back(projectile);
        
        Log::debug("Fired projectile, %i ammo left", m_Ammo);
    }
    
    else
    {
        Log::debug("Can't fire projectile, %i ammo left", m_Ammo);
    }
}

void Player::applyDamage(int damage)
{
    m_Health -= damage;
    
    if(m_Health <= 0)
    {
        m_Health = 0;
        setIsActive(false);
        
        Log::debug("Player is dead");
    }
    
    else
    {
        Log::debug("Player os hit, %i health remaining", m_Health);
    }
}

void Player::setCurrentTile(Tile* tile)
{
	//Set the current tile pointer
	m_CurrentTile = tile;
    
	//Center the player's position on the tile
	setPosition(tile->getX() + ((tile->getWidth() - getWidth()) / 2), tile->getY() + ((tile->getHeight() - getHeight()) / 2));
}

void Player::setDestinationTile(Tile* tile)
{
	//Set the destination tile pointer
	m_DestinationTile = tile;
    
    //TODO: Check if removing this will allow the player to constantly change their destination
    //Start pathfinding
    if(isAnimating() == false)
    {
        findPath();
    }
    
    else
    {
        m_AbortAnimation = true;
    }
}

void Player::handleBoundsCollision(Projectile* projectile)
{
    Tile* tile = m_Level->getTileForPosition(projectile->getX(), projectile->getY());
    if(tile == NULL)
    {
        //If the tile onject is null, it means the projectile is no longer in the level
        projectile->setIsActive(false);
        
        Log::debug("Projectile went off screen");
    }
}

void Player::handlePickup(Pickup *pickup)
{
    switch (pickup->getPickupType())
    {
        case PickupTypeAmmo:
            m_Ammo += ((AmmoPickup*)pickup)->getAmmoCount();
            break;
            
        default:
            break;
    }
}

void Player::pathFinderFinishedSearching(PathFinder* pathFinder, bool pathWasFound)
{
    if(pathFinder == m_PathFinder)
    {
        if(pathWasFound == true)
        {
            startAnimating();
        }
    
        else
        {
        
        }
    }
}

PathFinder* Player::getPathFinder()
{
    return m_PathFinder;
}
 
void Player::findPath()
{
    m_PathFinder->reset();
    m_PathFinder->findPath(m_CurrentTile, m_DestinationTile);
}

float Player::animate(float aCurrent, float aTarget, double aDelta, float speed)
{
    float increment = aDelta * m_Speed * (aTarget < aCurrent ? -1 : 1) * speed;
    if(fabs(increment) > fabs(aTarget - aCurrent))
    {
        return aTarget;
    }
    else
    {
        aCurrent += increment;
    }
    return aCurrent;
}

void Player::startAnimating()
{
	m_CanAnimate = true;
	m_AnimationPathNodeIndex = 0;
}

void Player::stopAnimating()
{
	m_CanAnimate = false;
	m_AnimationPathNodeIndex = -1;
}

bool Player::isAnimating()
{
    return m_CanAnimate;
}
