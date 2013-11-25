#include "Settings.h"


Settings::Settings() : Menu(NULL, NULL)
{
	addButton(new UIButton("Back"));
}


Settings::~Settings()
{

}

const char* Settings::getName()
{
	return SETTINGS_SCREEN_NAME;
}

void Settings::buttonAction(UIButton* button)
{
    int index = getIndexForButton(button);
    
    if(index == 0)
    {
        ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);
    }
	if(index == 1)
    {
        ScreenManager::getInstance()->switchScreen(LEVEL_EDITOR_SCREEN_NAME);
    }
	if(index == 2)
	{
		ScreenManager::getInstance()->switchScreen(SETTINGS_SCREEN_NAME);
	}
    else if (index == 3)
    {
        exit(1);
    }
}