#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
using namespace std;



class cMenu
{
    int wybrany;
    Font font_;
    Text menu_[3];

public:
    cMenu();
    void draw(RenderWindow &okno);
    void down();
    void up();
    int getWybrany();
    ~cMenu()=default;
};


