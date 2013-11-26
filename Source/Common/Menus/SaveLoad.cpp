#include "SaveLoad.h"


SaveLoad::SaveLoad() : Menu(NULL, NULL)//,
	//m_Level()
{
	addButton(new UIButton("Slot1"));	
	addButton(new UIButton("Slot3"));
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

void SaveLoad::setOrigin(int origin)
{
	m_Origin = origin;
}

//setOrigin(int origin) this takes in an int which is sent by the orderer. So, main menu has //SaveLoad->setOrigin(0), loading from the editor will be //SaveLoad->setOrigin(2), etc
//Then have a switch(index(of the button, so slot 1 is index 0)) nested in an if(origin != 1(because 1 is save))
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

	if(m_Origin != 1)
	{
		//load
	}

	else
	{
		//save
	}

    if(index == 0)
    {
		m_LevelEditor.getLevel()->save("Slot1.bin");
		//m_Level.save("Slot1.bin");
    }
	else if(index == 1)
	{
		m_LevelEditor.getLevel()->load("Slot1.bin");
		//m_Level.load("Slot1.bin");
	}
	else if(index == 2)
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
