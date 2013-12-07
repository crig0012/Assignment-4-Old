//
//  Tower.h
//  GAM-1514 OSX Game
//
//  Created by Joel Cright on 2013-12-05.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef __GAM_1514_OSX_Game__Tower__
#define __GAM_1514_OSX_Game__Tower__

#include "Player.h"
#include "../../Constants/Constants.h"

class Enemy;

class Tower : public Player
{
public:
    Tower(Level* level, TowerType towerType);
    virtual ~Tower();
    
    virtual const char* getType();
    virtual TowerType getTowerType() = 0;
    
    virtual void update(double delta);
    virtual void paint();
    virtual void reset();
    
protected:
    void handlePlayerCollision(Projectile* projectile);
    void handleBoundsCollision(Projectile* projectile);
    TowerType m_TowerType;
    
private:
    std::vector<Enemy*> m_EnemyArray;
};


#endif /* defined(__GAM_1514_OSX_Game__Tower__) */

