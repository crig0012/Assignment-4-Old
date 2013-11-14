#include "PathNode.h"


PathNode::PathNode(Tile* tile) :
	m_Tile(tile),
	m_ScoreG(0),
	m_ScoreH(0),
	m_ParentNode(NULL)
{

}


PathNode::~PathNode()
{
	m_Tile = NULL;
	m_ParentNode = NULL;
}

void PathNode::paintScore(OpenGLColor color)
{
	if(m_Tile != NULL)
	{
		if(getGScore() != 0 && getHScore() != 0)
		{
			m_Tile->paintListColor(color);
			m_Tile->paintScoreF(getFScore());
			m_Tile->paintScoreG(getGScore());
			m_Tile->paintScoreH(getHScore());
		}
	}
}

Tile* PathNode::getTile()
{
	return m_Tile;
}

int PathNode::getGScore()
{
	return m_ScoreG;
}

void PathNode::setGScore(int score)
{
	m_ScoreG = score;
}

int PathNode::getHScore()
{
	return m_ScoreH;
}

void PathNode::setHScore(int score)
{
	m_ScoreH = score;
}

PathNode* PathNode::getParentNode()
{
	return m_ParentNode;
}

void PathNode::setParent(PathNode* parent)
{
	m_ParentNode = parent;
}

int PathNode::getFScore()
{
	return getGScore() + getHScore();
}

bool PathNode::compareNodes(PathNode* nodeA, PathNode* nodeB)
{
	return nodeA->getFScore() < nodeB->getFScore();
}