#include "lib.hpp"


int main(void)
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML PANDA!");
    sf::CircleShape shape(250.f);
    shape.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
