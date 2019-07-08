#include "cMenu.h"

cMenu::cMenu()
{

    font_.loadFromFile("D:/Projekty QT++/build-STG_test-Desktop_Qt_5_12_3_MSVC2017_32bit-Debug/debug/font.otf");
    menu_[0].setFont(font_);
    menu_[0].setCharacterSize(30);
    menu_[0].setFillColor(Color::Red);
    //menu_[0].setOutlineColor(Color::Black);
    menu_[0].setPosition(Vector2f(560,400));
    menu_[0].setString("PLAY");

    menu_[1].setCharacterSize(30);
    menu_[1].setFont(font_);
    menu_[1].setFillColor(Color::White);
    //menu_[1].setOutlineColor(Color::White);
    menu_[1].setPosition(Vector2f(510,475));
    menu_[1].setString("HIGHSCORE");

    menu_[2].setCharacterSize(30);
    menu_[2].setFont(font_);
    menu_[2].setFillColor(Color::White);
    //menu_[2].setOutlineColor(Color::White);
    menu_[2].setPosition(Vector2f(560,550));
    menu_[2].setString("EXIT");
    wybrany=0;

}

void cMenu::draw(RenderWindow &okno)
{
    for (int i=0;i<3;i++)
    {
        okno.draw(menu_[i]);
    }
}

void cMenu::up()
{
    if(wybrany-1>=0)
    {
        menu_[wybrany].setFillColor(Color::White);
        menu_[0].setOutlineColor(Color::Black);
       // menu_[wybrany].setOutlineColor(Color::White);
        wybrany--;
        menu_[wybrany].setFillColor(Color::Red);
        menu_[0].setOutlineColor(Color::Black);
       // menu_[wybrany].setOutlineColor(Color::Red);
    }
}

int cMenu::getWybrany()
{
    return wybrany;
}


void cMenu::down()
{
    if(wybrany+1<=2)
    {
        menu_[wybrany].setFillColor(Color::White);
        menu_[0].setOutlineColor(Color::Black);
       // menu_[wybrany].setOutlineColor(Color::White);
        wybrany++;
        menu_[wybrany].setFillColor(Color::Red);
        menu_[0].setOutlineColor(Color::Black);
       // menu_[wybrany].setOutlineColor(Color::Red);
    }
}


