#pragma once
#include "../UI/UIButton.h"
#include "../Game/Level.h"
#include "../Level Editor/LevelEditor.h"
#include "../Screen Manager/Screen.h"
#include "../Constants/Constants.h"
#include "../Screen Manager/ScreenManager.h"
#include "Menu.h"

class Level;

class SaveLoad : public Menu
{
public:
	SaveLoad();
	~SaveLoad();

	const char* getName();

	void setOrigin(int origin);

private:
	void buttonAction(UIButton* button);
	LevelEditor m_LevelEditor;
	int m_Origin;
	//Level m_Level;
};

