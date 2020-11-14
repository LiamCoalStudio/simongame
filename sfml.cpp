#include "simongame.h"
#include <iostream>

RenderWindow* window;
Keyboard::Key current_key;
Vector2i pos(0, 0);
Mouse::Button current_mouse_button;

int main()
{
    window = static_cast<RenderWindow *>(malloc(sizeof(RenderWindow)));
    init();
    sf::Clock clock;
    while(window->isOpen())
    {
        clock.restart();
        Event event{};
        while(window->pollEvent(event))
        {
            if(event.type == sf::Event::KeyPressed)
                current_key = event.key.code;
            if(event.type == sf::Event::KeyReleased)
                current_key = {};
            if(event.type == sf::Event::MouseButtonPressed)
                current_mouse_button = event.mouseButton.button;
            if(event.type == sf::Event::MouseButtonReleased)
                current_mouse_button = {};
            if(event.type == sf::Event::Closed)
                window->close();
        }
        window->clear();
        loop();
        window->display();
        auto end = clock.getElapsedTime();
        sf::sleep(sf::seconds((1.f / 60.f) - end.asSeconds()));
    }
}

RectangleShape mkrect(float x, float y, float width, float height, Color color)
{
    RectangleShape rect(Vector2f(width, height));
    rect.setFillColor(color);
    rect.setPosition(x, y);
    return rect;
}
RectangleShape draw_rectangle(float x, float y, float width, float height, const Texture& texture)
{
    auto rect = mkrect(x, y, width, height, Color::White);
    rect.setTexture(&texture);
    window->draw(rect);
    return rect;
}
RectangleShape draw_rectangle(float x, float y, float width, float height, Color color)
{
    auto rect = mkrect(x, y, width, height, color);
    window->draw(rect);
    return rect;
}

CircleShape mkcircle(float x, float y, float radius, Color color)
{
    CircleShape circle(radius);
    circle.setPosition(x, y);
    circle.setFillColor(color);
    return circle;
}
CircleShape draw_circle(float x, float y, float radius, Color color)
{
    CircleShape circle = mkcircle(x, y, radius, color);
    window->draw(circle);
    return circle;
}
CircleShape draw_circle(float x, float y, float radius, const Texture& texture)
{
    CircleShape circle = mkcircle(x, y, radius, Color::White);
    circle.setTexture(&texture);
    window->draw(circle);
    return circle;
}
