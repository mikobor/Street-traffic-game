#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>

using namespace sf;
using namespace std;

class cHighscore
{
    string nicki_[10];
    int punkty_[10];
    Text wyniki_[10];
    Font font;

public:
    cHighscore();
    void draw(RenderWindow& okno);
    void read();
    void update(int punkt,string nick);
    ~cHighscore()=default;
};
