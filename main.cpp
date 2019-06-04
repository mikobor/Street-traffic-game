#include <iostream>
#include "cPalma.h"
#include "cPas.h"
#include <SFML\Graphics.hpp>

using namespace sf;


int main()
{
	RenderWindow okno(VideoMode(800, 600, 32), "Street Traffic Game");
	okno.setFramerateLimit(60);
	cPalma palm1(0), palm2(-300), palm3(-600), palm4(-1200), palm5(-900);
	cPas pas1(-0), pas2(-200), pas3(-400), pas4(-600), pas5(-800), pas6(-1000);
	
	while (okno.isOpen())
	{
		
		Event zdarzenie;
		while (okno.pollEvent(zdarzenie))
		{

			if (zdarzenie.type == Event::Closed)
				okno.close();

			if (zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::Escape)
				okno.close();

			if (zdarzenie.type == Event::MouseButtonPressed && zdarzenie.mouseButton.button == Mouse::Middle)
				okno.close();
		
		}
		Sprite mapa;
		Texture tex_map;
		tex_map.loadFromFile("mapa.png");
		mapa.setTexture(tex_map);
		okno.draw(mapa);


		palm1.update();    //wyswietlanie oraz przesowanie palm
		okno.draw(palm1);
		palm2.update();
		okno.draw(palm2);
		palm3.update();
		okno.draw(palm3);
		palm4.update();
		okno.draw(palm4);
		palm5.update();
		okno.draw(palm5);

		
		pas1.update();    //wyswietlanie oraz przesowanie pasow
		okno.draw(pas1);
		pas2.update();
		okno.draw(pas2);
		pas3.update();
		okno.draw(pas3);
		pas4.update();
		okno.draw(pas4);
		pas5.update();
		okno.draw(pas5);
		pas6.update();
		okno.draw(pas6);
		
		
		okno.display();
		
	}
	return 0;
}
