#ifndef KIND_CAT_GAME_H
#define KIND_CAT_GAME_H

#include <SFML/Graphics.hpp>
#include "Cat.h"
#include "Mouse.h"

enum class GameState {
    Playing,
    GameOver
};

class Game {
public:
    Game();
    void run();
private:
    GameState state = GameState::Playing;
    sf::RenderWindow window;
    Cat cat;
    Mouse mouse;
    void processEvents();
    void update();
    void render();
    void restart();
    void drawGameOver();
    sf::Font font;
    sf::Text gameOverText;
    sf::Text restartText;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    void gameover();
};


#endif //KIND_CAT_GAME_H