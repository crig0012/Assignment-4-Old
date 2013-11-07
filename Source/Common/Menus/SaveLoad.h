#pragma once
#include "../UI/UIButton.h"
#include "../Screen Manager/Screen.h"
#include "../Constants/Constants.h"
#include "../Screen Manager/ScreenManager.h"
#include "Menu.h"


class SaveLoad : public Menu
{
public:
	SaveLoad();
	~SaveLoad();

	const char* getName();

private:
	void buttonAction(UIButton* button);
};

