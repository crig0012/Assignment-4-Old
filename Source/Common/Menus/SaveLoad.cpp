#include "SaveLoad.h"


SaveLoad::SaveLoad() : Menu(NULL, NULL)
{
	addButton(new UIButton("Slot1"));	
	addButton(new UIButton("Slot2"));
	addButton(new UIButton("Slot3"));
	addButton(new UIButton("Slot4"));
	addButton(new UIButton("Slot5"));
	addButton(new UIButton("Back"));
}


SaveLoad::~SaveLoad()
{

}

const char* SaveLoad::getName()
{
	return SAVE_LOAD_SCREEN_NAME;
}

void SaveLoad::buttonAction(UIButton* button)
{
	/*
	slot1
	slot2
	slot3
	slot4
	slot5
	back
	*/
    int index = getIndexForButton(button);
    if(index == 0)
    {
        ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);
    }
    else if(index == 4)
    {
        ScreenManager::getInstance()->switchScreen(LEVEL_EDITOR_SCREEN_NAME);
    }
    else if (index == 5)
    {
        exit(1);
    }
}
