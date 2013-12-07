//
//  BulletTower.cpp
//  GAM-1514 OSX Game
//
//  Created by Joel Cright on 2013-12-06.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "BulletTower.h"
#include "../../Constants/Constants.h"

BulletTower::BulletTower(Level* level) : Tower(level, this)
{
    
}

TowerType BulletTower::getTowerType()
{
    return BULLET_TOWER_TYPE;
}