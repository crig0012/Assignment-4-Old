#pragma once

#include "../Game/Tiles/Tile.h"
#include "../OpenGL/OpenGL.h"

class PathNode
{
public:
	PathNode(Tile* tile);
	~PathNode();
	
	void paintScore(OpenGLColor color);
    
	Tile* getTile();

	int getGScore();
	void setGScore(int score);

	int getHScore();
	void setHScore(int score);

	PathNode* getParentNode();
	void setParent(PathNode* parent);

	int getFScore();

	static bool compareNodes(PathNode* nodeA, PathNode* nodeB);

private:
	Tile* m_Tile;
	int m_ScoreG;
	int m_ScoreH;
	PathNode* m_ParentNode;
};