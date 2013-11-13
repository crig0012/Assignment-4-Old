#include "Game.h"
#include "GameObject.h"
#include "Level.h"
#include "../OpenGL/OpenGL.h"
#include "../Constants/Constants.h"
#include "../Utils/Utils.h"
#include "../Screen Manager/ScreenManager.h"
#include "../UI/UIFont.h"


Game::Game()
{
    //Create the level object
    m_Level = new Level();
    
    m_Font = new UIFont("BitmapFont");
    m_Font->setText("TEXTY TEXT");
    
    //Reset everything
    reset();
}

Game::~Game()
{
    //Delete the level object
    if(m_Level != NULL)
    {
        delete m_Level;
        m_Level = NULL;
    }
    
    if(m_Font != NULL)
    {
        delete m_Font;
        m_Font = NULL;
    }
}

void Game::update(double delta)
{
    if(m_Level != NULL)
    {
        m_Level->update(delta);
    }
}

void Game::paint()
{
    if(m_Level != NULL)
    {
        m_Level->paint();
    }
    
    if(m_Font != NULL)
    {
        m_Font->draw(100.0f, 100.0f);
    }
}

void Game::reset()
{
    if(m_Level != NULL)
    {
        m_Level->reset();
    }
}

const char* Game::getName()
{
	return GAME_SCREEN_NAME;
}

Level* Game::getLevel()
{
    return m_Level;
}

void Game::mouseLeftClickUpEvent(float positionX, float positionY)
{
    if(m_Level != NULL)
    {
        m_Level->mouseLeftClickUpEvent(positionX, positionY);
    }
}

void Game::keyUpEvent(int keyCode)
{
    if(m_Level != NULL)
    {
        m_Level->keyUpEvent(keyCode);
    }  
}
