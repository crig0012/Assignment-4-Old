//
//  Hero.h
//  GAM-1514 OSX Game
//
//  Created by Joel Cright on 2013-11-21.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef __GAM_1514_OSX_Game__Hero__
#define __GAM_1514_OSX_Game__Hero__

#include <iostream>
#include "Player.h"

class Hero : public Player
{
public:
    Hero(Level* level);
    ~Hero();
    
    const char* getType();
    
    void mouseLeftClickUpEvent(float positionX, float positionY);
};


#endif /* defined(__GAM_1514_OSX_Game__Hero__) */
