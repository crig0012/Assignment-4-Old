//
//  BulletTower.h
//  GAM-1514 OSX Game
//
//  Created by Joel Cright on 2013-12-06.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef __GAM_1514_OSX_Game__BulletTower__
#define __GAM_1514_OSX_Game__BulletTower__

#include <iostream>
#include "Tower.h"

class BulletTower : Tower
{
    BulletTower(Level* level);
    TowerType getTowerType();
};

#endif /* defined(__GAM_1514_OSX_Game__BulletTower__) */
