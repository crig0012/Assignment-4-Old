#pragma once

#include "Menu.h"
#include "../Screen Manager/ScreenManager.h"

class Settings : public Menu
{
public:
	Settings();
	~Settings();

	const char* getName();

private:
    void buttonAction(UIButton* button);
};

