#include <iostream>
#include "cPalma.h"
#include "cPas.h"
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <vector>
#include "cGracz.h"
#include "cPrzeszkoda.h"
#include "cMoneta.h"
#include "cMenu.h"
#include "chighscore.h"

using namespace sf;


int main()
{
    RenderWindow okno(VideoMode(800, 800, 32), "Street Traffic Game");
	okno.setFramerateLimit(60);
    srand(time(NULL));
    Font font;
    font.loadFromFile("Resources/font.otf");
    Sprite background;
    Texture background_tex;
    background_tex.loadFromFile("Resources/startpage.jpg");
    background.setTexture(background_tex);
    int licznik=1;
    cMenu menu;


	while (okno.isOpen())
	{
        if(licznik<180)
        {
            okno.draw(background);
            licznik++;
            okno.display();
        }
        else
        {
            przykry_przyklad_uzycia_goto:
            string nick;
            cGracz gracz(360,605);
            cPalma palm1(0), palm2(300), palm3(600);
            cPas pas1(0), pas2(200), pas3(400), pas4(600), pas5(-200);
            vector<cPalma> palmy{ palm1,palm2,palm3};
            vector<cPas> pasy{ pas1,pas2,pas3,pas4,pas5 };
            cPrzeszkoda przeszkoda(-550);
            cMoneta moneta;

            okno.clear();
            background_tex.loadFromFile("Resources/menu1.png");
            background.setTexture(background_tex);
            Event zdarzenie;

            while (okno.pollEvent(zdarzenie))
            {

                if (zdarzenie.type == Event::Closed)
                 okno.close();

                if (zdarzenie.type == Event::KeyReleased && zdarzenie.key.code == Keyboard::Up)
                    menu.up();

                if (zdarzenie.type == Event::KeyReleased && zdarzenie.key.code == Keyboard::Down)
                    menu.down();

                if (zdarzenie.type == Event::KeyReleased && zdarzenie.key.code == Keyboard::Return)
                {
                    switch(menu.getWybrany())
                    {
                    case 0:
                    {
                        background_tex.loadFromFile("Resources/mapa.png");
                        background.setTexture(background_tex);
                        Sound soundtrack;
                        SoundBuffer soundtrack_;
                        soundtrack_.loadFromFile("Resources/soundtrack_taxi.wav");
                        soundtrack.setBuffer(soundtrack_);
                        soundtrack.play();
                        soundtrack.setLoop(true);

                        while (okno.isOpen())
                        {
                            okno.draw(background);
                            new Event (zdarzenie);
                            Event zdarzenie1;
                            while (okno.pollEvent(zdarzenie))
                            {
                                if (zdarzenie.type == Event::Closed)
                                    okno.close();

                                if (zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::Escape)
                                    okno.close();

                                if (zdarzenie.type == Event::MouseButtonPressed && zdarzenie.mouseButton.button == Mouse::Middle)
                                    soundtrack.stop();
                            }

                            for (auto itr = palmy.begin(); itr != palmy.end(); itr++)
                            {
                                itr->update(gracz);
                                okno.draw(*itr);
                            }

                            for (auto itr = pasy.begin(); itr != pasy.end(); itr++)
                            {
                                itr->update(gracz);
                                okno.draw(*itr);
                            }

                            przeszkoda.update(gracz);
                            okno.draw(przeszkoda);
                            moneta.update(przeszkoda,gracz);
                            okno.draw(moneta);
                            gracz.update();
                            okno.draw(gracz);

                            if(gracz.getHp()<=0)
                            {
                                okno.clear();
                                background_tex.loadFromFile("Resources/podaj_nick.png");
                                background.setTexture(background_tex);
                                soundtrack.stop();
                                Text nick_;

                                nick_.setCharacterSize(30);
                                nick_.setFillColor(Color::White);
                                nick_.setFont(font);
                                while(okno.isOpen())
                                {

                                    while (okno.pollEvent(zdarzenie1))
                                    {

                                        if (zdarzenie1.type == Event::Closed)
                                            okno.close();

                                        if (zdarzenie1.type == Event::TextEntered)
                                        {
                                            if (zdarzenie1.text.unicode <= 126&&zdarzenie1.text.unicode>=33)
                                                nick+=static_cast<char>(zdarzenie1.text.unicode);
                                            else if(zdarzenie1.text.unicode==8)
                                                nick=nick.substr(0,nick.length()-1);
                                        }
                                        if(zdarzenie1.type==Event::KeyPressed && zdarzenie1.key.code==Keyboard::Return)
                                        {
                                            okno.clear();
                                            background_tex.loadFromFile("Resources/highscore.png");
                                            background.setTexture(background_tex);
                                            cHighscore highscore1;
                                            highscore1.update(gracz.getScore()/6,nick);
                                            while(okno.isOpen())
                                            {
                                                new Event (zdarzenie);
                                                while (okno.pollEvent(zdarzenie))
                                                {

                                                    if (zdarzenie.type == Event::Closed)
                                                        okno.close();

                                                    if (zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::Escape)
                                                        goto przykry_przyklad_uzycia_goto;
                                                }
                                                okno.draw(background);
                                                highscore1.draw(okno);
                                                okno.display();
                                            }
                                        }
                                    }
                                    nick_.setPosition(400-static_cast<float>((nick.length()*8)),450);
                                    nick_.setString(nick);
                                    okno.draw(background);
                                    okno.draw(nick_);
                                    okno.display();
                                }
                            }
                            okno.display();
                        }

                        break;

                    }
                     case 1:
                    {
                        okno.clear();
                        background_tex.loadFromFile("Resources/highscore.png");
                        background.setTexture(background_tex);
                        cHighscore highscore;
                        highscore.read();
                        while(okno.isOpen())
                        {
                            Event zdarzenie;
                            while (okno.pollEvent(zdarzenie))
                            {

                                if (zdarzenie.type == Event::Closed)
                                    okno.close();

                                if (zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::Escape)
                                    goto przykry_przyklad_uzycia_goto;
                            }
                            okno.draw(background);
                            highscore.draw(okno);
                            okno.display();
                        }
                        break;
                    }
                    case 2:
                    {
                        return 0;
                    }
                }
            }

                okno.draw(background);
                menu.draw(okno);
                okno.display();
            }
        }
    }

	return 0;
}

