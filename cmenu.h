#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;



class cMenu
{
    Font font;
    int wybrany=0;
    Text menu_[3];

public:
    cMenu();
    void draw(RenderWindow& okno);
    void down();
    void up();
    int getWybrany();
    ~cMenu()=default;
};


