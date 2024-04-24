#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Capitulo 2");
	window.setFramerateLimit(60);

	//Primer while

	while (window.isOpen())
	{
		//ancho y alto;
		const unsigned int kWidth = 5, kHeight = 5;

		//array size = width * heigth * 4 (rgba)
		sf::Uint8 pixels[kWidth * kHeight * 4] =
		{
			255,255,255,255, //White
			0,0,0,255, //Black
			255,0,0, 255, //RED
			128,128,128,255 //Gris
		};

		sf::Image image;
		image.create(kWidth, kHeight, pixels);

		sf::Image image2;
		image2.loadFromFile("img.png");

		if (!image2.loadFromFile("img.png")) {
			std::cout << "opa" << std::endl;
			return-1;
		}

		//Cargamos una textura de una imágen
		//Textura de la torre.
		sf::Texture textureTorre;
		textureTorre.loadFromFile("img.png");
		//Textura random de prueba.
		sf::Texture texture2;
		texture2.loadFromImage(image);
		//Textura del fueguito
		sf::Texture textureFuego;
		textureFuego.loadFromFile("Flame_D.png");
		//Textura del enemigo.
		Texture textureEnemigo;
		textureEnemigo.loadFromFile("enemigo.png");

		RectangleShape cuadrado(Vector2f(200,200));
		cuadrado.setTexture(&texture2);
		cuadrado.setPosition(Vector2f(300, 300));

		

		//Hacemos un cuadrado y le setearle uan textura.
		sf::RectangleShape recTorre(sf::Vector2f(300, 300));
		recTorre.setTexture(&textureTorre);
		//posicion torre
		recTorre.setPosition(sf::Vector2f(300, 300));

		//Lo inicializamos, pero por ahora no lo usamos.


		//inicializamos enemigo
		sf::RectangleShape recEnemigo(sf::Vector2f(150, 150));
		recEnemigo.setTexture(&textureEnemigo);
		recEnemigo.setPosition(300, 300);

		//Segundowhile eventlistener
		sf::Event ev;
		while(window.pollEvent(ev))
		{
			if (ev.type == sf::Event::EventType::Closed)
				window.close();
			if (ev.key.code == sf::Keyboard::Key::Escape)
				window.close();

			if (ev.key.code == sf::Keyboard::Key::Space)
			{
				sf::RectangleShape recFuego(sf::Vector2f(150, 100));
				recFuego.setTexture(&textureFuego);
				recFuego.setTexture(&textureFuego);
				
				// Position recFuego slightly to the right of recTorre
				recFuego.setPosition(recTorre.getPosition() + sf::Vector2f(300, 0));
			}

		}

		//Update

		//Render Cycle
		window.clear();
		//RenderOjbects
		window.draw(recTorre);
		window.draw(cuadrado);
		window.draw(recFuego); 
		window.draw(recEnemigo);

		window.display();
	}

	return 0;
}