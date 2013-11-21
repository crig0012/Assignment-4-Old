//
//  Player.h
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "PathFinder.h"
#include <vector>

class Level;
class Tile;

class Player : public GameObject, public PathFinderListener
{
public:
	Player(Level* level);
	virtual ~Player();

  //Update, paint and reset methods
	void update(double delta);
	void paint();
    void reset();
  
  //Implementing GameObject's pure virtual method
  virtual const char* getType() = 0;
  
  //Setter methods for the current and destination tiles
	void setCurrentTile(Tile* tile);
	void setDestinationTile(Tile* tile);

protected:
    //PathFinder Listener method
    void pathFinderFinishedSearching(PathFinder* pathFinder, bool pathWasFound);
    
    //PathFinder methods
    PathFinder* getPathFinder();
    void findPath();
    
    //Animation methods
    float animate(float current, float target, double delta, float speed);
	void startAnimating();
	void stopAnimating();
    bool isAnimating();
    
    //Friend class Level so that it can access the protected members
    friend class Level;

    Level* m_Level;
    PathFinder* m_PathFinder;
	Tile* m_CurrentTile;
	Tile* m_DestinationTile;
	bool m_CanAnimate;
    bool m_AbortAnimation;
	int m_AnimationPathNodeIndex;
    float m_Speed;
};

#endif