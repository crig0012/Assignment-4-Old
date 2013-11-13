//
//  UIFont.h
//  GAM-1514 OSX Game
//
//  Created by Joel Cright on 2013-11-13.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef __GAM_1514_OSX_Game__UIFont__
#define __GAM_1514_OSX_Game__UIFont__

#include <iostream>
#include "../OpenGL/OpenGL.h"
#include "../Libraries/jsoncpp/json.h"
#include "../Utils/Utils.h"
#include <fstream>
#include <algorithm>
#include <ctype.h>
#include <math.h>

//class OpenGL;

class UIFont
{
public:
    UIFont(const char* fontName, float spaceAmount = 10.0f);
    ~UIFont();
    
    void draw(float x, float y);
    
    void setText(const char* text);
    const char* getText();
    
    float getWidth();
    float getHeight();
    
private:
    void parseFontData(const char* fontName);
    void calculateSize();
    
    struct UIFontFrame
    {
        unsigned int x;
        unsigned int y;
        unsigned int width;
        unsigned int height;
    };
    
    UIFontFrame* getFontFrame(std::string character);
    
    //Member Variables
    OpenGLTexture* m_Font;
    std::map<std::string, UIFontFrame*> m_FontData;
    std::string m_Text;
    float m_Width;
    float m_Height;
    float m_SpaceAmount;
};
#endif /* defined(__GAM_1514_OSX_Game__UIFont__) */