#pragma once
#include "../UI/UIButton.h"
#include "../Screen Manager/Screen.h"
#include "../Constants/Constants.h"
#include "../Screen Manager/ScreenManager.h"
#include "Menu.h"
#include "../Game/Level.h"
#include "../Level Editor/LevelEditor.h"

class LevelEditor;

class Save : public Menu
{
public:
	Save();
	~Save();

	const char* getName();

private:
	void buttonAction(UIButton* button);
	
	Level* m_Level;
};

