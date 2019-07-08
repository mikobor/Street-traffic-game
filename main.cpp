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

using namespace sf;


int main()
{
    RenderWindow okno(VideoMode(800, 800, 32), "Street Traffic Game");
	okno.setFramerateLimit(60);

    srand(time(NULL));
    cMenu menu;
    Sprite startpage;
    Texture startpage_tex;
    Texture menu_tex;
    menu_tex.loadFromFile("D:/Projekty QT++/build-STG_test-Desktop_Qt_5_12_3_MSVC2017_32bit-Debug/debug/menu1.png");
    startpage_tex.loadFromFile("D:/Projekty QT++/build-STG_test-Desktop_Qt_5_12_3_MSVC2017_32bit-Debug/debug/startpage.jpg");
    startpage.setTexture(startpage_tex);
    int licznik=1;




	while (okno.isOpen())
	{
        /*
		Event zdarzenie;
		while (okno.pollEvent(zdarzenie))
		{

			if (zdarzenie.type == Event::Closed)
				okno.close();

			if (zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::Escape)
				okno.close();

			if (zdarzenie.type == Event::MouseButtonPressed && zdarzenie.mouseButton.button == Mouse::Middle)
				soundtrack_ini.play();

            if (zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::P)
            {
                gracz.setHp(gracz.getHp()-1);
                gracz.setScore(gracz.getScore()-100);
            }
        }*/


        if(licznik<180)
        {
            okno.draw(startpage);
            licznik++;
            okno.display();
        }
        else
        {
            startpage.setTexture(menu_tex);
            Event zdarzenie1;
            while (okno.pollEvent(zdarzenie1))
            {

                if (zdarzenie1.type == Event::Closed)
                 okno.close();

                if (zdarzenie1.type == Event::KeyReleased && zdarzenie1.key.code == Keyboard::Up)
                    menu.up();

                if (zdarzenie1.type == Event::KeyReleased && zdarzenie1.key.code == Keyboard::Down)
                    menu.down();

                if (zdarzenie1.type == Event::KeyReleased && zdarzenie1.key.code == Keyboard::Return)
                {
                    switch(menu.getWybrany())
                    {
                    case 0:
                    {
                        Sprite mapa;
                        Texture tex_map;
                        tex_map.loadFromFile("D:/Projekty QT++/build-STG_test-Desktop_Qt_5_12_3_MSVC2017_32bit-Debug/debug/mapa.png");
                        mapa.setTexture(tex_map);
                        cPalma palm1(0), palm2(300), palm3(600);
                        cPas pas1(0), pas2(200), pas3(400), pas4(600), pas5(-200);
                        vector<cPalma> palmy{ palm1,palm2,palm3};
                        vector<cPas> pasy{ pas1,pas2,pas3,pas4,pas5 };
                        Sound soundtrack_ini;
                        SoundBuffer soundtrack1;
                        soundtrack1.loadFromFile("D:/Projekty QT++/build-STG_test-Desktop_Qt_5_12_3_MSVC2017_32bit-Debug/debug/Soundtrack.wav");
                        soundtrack_ini.setBuffer(soundtrack1);
                        soundtrack_ini.play();
                        cGracz gracz(360,605);
                        cPrzeszkoda przeszkoda(-550);
                        cMoneta moneta;

                        while (okno.isOpen())
                        {
                            okno.draw(mapa);
                            Event zdarzenie;
                            while (okno.pollEvent(zdarzenie))
                            {

                                if (zdarzenie.type == Event::Closed)
                                    okno.close();

                                if (zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::Escape)
                                    okno.close();

                                if (zdarzenie.type == Event::MouseButtonPressed && zdarzenie.mouseButton.button == Mouse::Middle)
                                    soundtrack_ini.play();

                                if (zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::P)
                                {
                                    gracz.setHp(gracz.getHp()-1);
                                    gracz.setScore(gracz.getScore()-100);
                                }
                            }

                                //wyswietlanie oraz przesowanie palm

                                for (auto itr = palmy.begin(); itr != palmy.end(); itr++)
                                {

                                    itr->update(gracz);
                                    okno.draw(*itr);

                                }

                                //wyswietlanie oraz przesowanie pasow
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
                                soundtrack_ini.stop();
                                okno.display();
                            }
                            break;
                        }
                        case 1:
                        {
                            break;
                        }
                        case 2:
                        {
                            return 0;
                        }
                    }
                }

                okno.draw(startpage);
                menu.draw(okno);
                okno.display();
            }
        }
    }
	return 0;
}

