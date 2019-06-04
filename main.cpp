#include <iostream>
#include "cPalma.h"
#include "cPas.h"
#include <SFML\Graphics.hpp>

using namespace sf;


int main()
{
	RenderWindow okno(VideoMode(800, 600, 32), "Street Traffic Game");


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
		cPalma palm1;
		cPas pas1;
		okno.draw(mapa);
		palm1.update();
		pas1.update();
	
		okno.draw(pas1);
		okno.draw(palm1);
		
		okno.display();
		
	}
	return 0;
}
