#include "Save.h"


Save::Save() : Menu(NULL, NULL)
{
	//addButton(new UIButton("MenuOptionsSave"));
	

	addButton(new UIButton("Slot1"));	
	addButton(new UIButton("Slot2"));
	addButton(new UIButton("Slot3"));
	addButton(new UIButton("Slot4"));
	addButton(new UIButton("Slot5"));
	addButton(new UIButton("Back"));

	m_Level = new Level(false);
}

Save::~Save()
{
	if(m_Level != NULL)
	{
		delete m_Level;
		m_Level = NULL;
	}
}

const char* Save::getName()
{
	return SAVE_SCREEN_NAME;
}

void Save::buttonAction(UIButton* button)
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

    if(index == 1)
    {
        ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);
    }

	if(index == 0)
	{
		m_Level->save("Slot2.bin");
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
