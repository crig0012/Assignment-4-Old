//
//  Tower.h
//  GAM-1514 OSX Game
//
//  Created by Joel Cright on 2013-12-05.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef __GAM_1514_OSX_Game__Tower__
#define __GAM_1514_OSX_Game__Tower__

#include <iostream>
#include "Player.h"

class Enemy;

class Tower : public Player
{
public:
    Tower(Level* level);
    ~Tower();
    
    const char* getType();
    
    void update(double delta);
    void paint();
    void reset();    
    
protected:
    void handlePlayerCollision(Projectile* projectile);
    void handleBoundsCollision(Projectile* projectile);
    
private:
    std::vector<Enemy*> m_EnemyArray;
};


#endif /* defined(__GAM_1514_OSX_Game__Tower__) */

