#ifndef SIMONGAME_SIMONGAME_H
#define SIMONGAME_SIMONGAME_H

#include <SFML/Graphics.hpp>

#ifndef NO_NAMESPACE_SF
using namespace sf;
#endif

/*
 * => /sfml.cpp
 *
 *    SFML bindings for simon.
 */

extern RenderWindow* window;
extern Keyboard::Key current_key;
extern Vector2i pos;
extern Mouse::Button current_mouse_button;

inline void new_window(std::string title, int width, int height)
{ window = new RenderWindow(VideoMode(width, height), title); }

inline void close_window()
{ window->close(); }

extern RectangleShape mkrect(float x, float y, float width, float height, Color color);
extern RectangleShape draw_rectangle(float x, float y, float width, float height, const Texture& texture);
extern RectangleShape draw_rectangle(float x, float y, float width, float height, Color color);

extern CircleShape mkcircle(float x, float y, float radius, Color color);
extern CircleShape draw_circle(float x, float y, float radius, Color color);
extern CircleShape draw_circle(float x, float y, float radius, const Texture& texture);

void init();
void loop();

#endif //SIMONGAME_SIMONGAME_H
