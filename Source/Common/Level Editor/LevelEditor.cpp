//
//  LevelEditor.cpp
//  GAM-1514 OSX Game
//
//  Created by Bradley Flood on 2013-10-25.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "LevelEditor.h"
#include "../Constants/Constants.h"
#include "../Game/Level.h"
#include "../Screen Manager/ScreenManager.h"
#include "../UI/UIButton.h"
#include "../UI/UIToggle.h"


LevelEditor::LevelEditor() :
m_TilesMenu(NULL),
	m_OptionsMenu(NULL),
	m_Level(NULL),
	m_IsMouseDown(false),
	m_SelectedTileIndex(-1)
{
	//Create the Tiles menu items
	m_TilesMenu = new UISideMenu(this, SideMenuRight);
	m_TilesMenu->addButton(new UIToggle("MenuTileGround"));
	m_TilesMenu->addButton(new UIToggle("MenuTileWater"));
	m_TilesMenu->addButton(new UIToggle("MenuTileTree"));
	m_TilesMenu->addButton(new UIToggle("MenuTileWall"));
	m_TilesMenu->addButton(new UIToggle("MenuTileTower"));
	m_TilesMenu->addButton(new UIToggle("MenuTileChest"));

	m_OptionsMenu = new UISideMenu(this, SideMenuLeft);	//FOR CLEAR< DO A FOREACH(INDEX IN TILE AND SET IT ALL TO GROUND)
	m_OptionsMenu->addButton(new UIToggle("MenuOptionSave"));
	m_OptionsMenu->addButton(new UIToggle("MenuOptionSave"));	//WTF WHY DOESNT LOAD WORK
	m_OptionsMenu->addButton(new UIToggle("MenuOptionClear"));
	m_OptionsMenu->addButton(new UIToggle("MenuOptionExit"));

	//Create the level object
	m_Level = new Level(true);

	//Reset everything
	reset();
}

LevelEditor::~LevelEditor()
{
	if(m_Level != NULL)
	{
		delete m_Level;
		m_Level = NULL;
	}

	if(m_TilesMenu != NULL)
	{
		delete m_TilesMenu;
		m_TilesMenu = NULL;
	}

	if(m_OptionsMenu != NULL)
	{
		delete m_OptionsMenu;
		m_OptionsMenu = NULL;
	}
}

const char* LevelEditor::getName()
{
	return LEVEL_EDITOR_SCREEN_NAME;
}

void LevelEditor::update(double delta)
{
	if(m_Level != NULL)
	{
		m_Level->update(delta);
	}

	if(m_TilesMenu != NULL)
	{
		m_TilesMenu->update(delta);
	}

	if(m_OptionsMenu != NULL)
	{
		m_OptionsMenu->update(delta);
	}
}

void LevelEditor::paint()
{
	if(m_Level != NULL)
	{
		m_Level->paint();
	}

	if(m_TilesMenu != NULL)
	{
		m_TilesMenu->paint();
	}

	if(m_OptionsMenu != NULL)
	{
		m_OptionsMenu->paint();
	}
}

void LevelEditor::reset()
{
	if(m_Level != NULL)
	{
		m_Level->reset();
	}
}

void LevelEditor::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{    
	if(m_TilesMenu != NULL)
	{
		m_TilesMenu->mouseMovementEvent(deltaX, deltaY, positionX, positionY);
	}

	if(m_OptionsMenu != NULL)
	{
		m_OptionsMenu->mouseMovementEvent(deltaX, deltaY, positionX, positionY);
	}

	if(m_Level != NULL)
	{        
		if(m_SelectedTileIndex != -1 && m_IsMouseDown == true && m_TilesMenu->isShowing() == false && m_OptionsMenu->isShowing() == false)
		{
			m_Level->setTileTypeAtPosition((TileType)m_SelectedTileIndex, positionX, positionY);
		}
	}
}

void LevelEditor::mouseLeftClickDownEvent(float positionX, float positionY)
{
	//Set the mouse down flag
	m_IsMouseDown = true;
}

void LevelEditor::mouseLeftClickUpEvent(float positionX, float positionY)
{
	//Set the mouse up flag
	m_IsMouseDown = false;

	//Safety check the level pointer, then set the new tile type in the index
	if(m_Level != NULL)
	{
		if(m_SelectedTileIndex != -1 && m_TilesMenu->isShowing() == false && m_OptionsMenu->isShowing() == false)
		{
			m_Level->setTileTypeAtPosition((TileType)m_SelectedTileIndex, positionX, positionY);
		}
	}

	//Notify the tiles menu of the mouse event
	if(m_TilesMenu != NULL)
	{
		m_TilesMenu->mouseLeftClickUpEvent(positionX, positionY);
	}

	if(m_OptionsMenu != NULL)
	{
		m_OptionsMenu->mouseLeftClickUpEvent(positionX, positionY);
	}
}

void LevelEditor::keyUpEvent(int keyCode)
{
	if(keyCode == KEYCODE_TAB)
	{
		if(m_TilesMenu != NULL)
		{
			m_TilesMenu->isShowing() == true ? m_TilesMenu->hide() : m_TilesMenu->show();
		}
	}

	else if(keyCode == KEYCODE_ESCAPE)
	{
		m_OptionsMenu->isShowing() == true ? m_OptionsMenu->hide() : m_OptionsMenu->show();
	}

	else
	{
		if(m_Level != NULL)
		{
			m_Level->keyUpEvent(keyCode);
		}
	}

	if(keyCode == KEYCODE_C)
	{
		m_Level->randomizeLevel();
	}
}

void LevelEditor::sideMenuButtonAction(UISideMenu* sideMenu, UIButton* button, int buttonIndex)
{

}

void LevelEditor::sideMenuToggleAction(UISideMenu* sideMenu, UIToggle* toggle, int toggleIndex)
{
	if(sideMenu == m_TilesMenu)
	{
		//Un-toggled the previously selected toggle
		UIToggle* previousToggle = (UIToggle*)m_TilesMenu->getButtonForIndex(m_SelectedTileIndex);
		if(previousToggle != NULL)
		{
			previousToggle->setIsToggled(false);
		}

		//Set the selected tile index
		m_SelectedTileIndex = toggle->isToggled() == true ? toggleIndex : -1;

		//Hide the options and tiles menus
		m_TilesMenu->hide();
		m_OptionsMenu->hide();
	}

	if(sideMenu == m_OptionsMenu)
	{
		//Set the selected tile index
		m_SelectedTileIndex = toggle->isToggled() == true ? toggleIndex : -1;		

		//Hide the options and tiles menus
		if(m_SelectedTileIndex == 3)
		{
			m_SelectedTileIndex;
			m_Level->load(NULL);
		}

		if(m_SelectedTileIndex == 4)
		{
			ScreenManager::getInstance()->switchScreen(MAIN_MENU_SCREEN_NAME);
		}

		toggle->setIsToggled(false);

		m_OptionsMenu->hide();
		m_TilesMenu->hide();
	}
}


