#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Game.h"


Game::Game()
    : window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Kind Cat"),
        cat(),
        mouse() {

    backgroundTexture.loadFromFile("assets/background.png");
    backgroundSprite.setTexture(backgroundTexture);

    font.loadFromFile("assets/Arial.ttf");
    gameOverText.setFont(font);
    gameOverText.setString("GAME OVER");
    gameOverText.setCharacterSize(48);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition(WINDOW_WIDTH/2 - 150, WINDOW_HEIGHT/2 - 80);

    restartText.setFont(font);
    restartText.setString("Press R to restart");
    restartText.setCharacterSize(30);
    restartText.setFillColor(sf::Color::White);
    restartText.setPosition(WINDOW_WIDTH/2 - 160, WINDOW_HEIGHT/2 + 10);
}

void Game::run() {
            while (window.isOpen()) {
                processEvents();
                update();
                render();
            }
        }

void Game::processEvents() {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Escape) {
                        window.close();
                        return;
                    }
                }
                if (state == GameState::Playing) {
                    if (event.type == sf::Event::KeyPressed) {
                        if (event.key.code == sf::Keyboard::Left)
                            cat.setDirection(-1, 0);
                        if (event.key.code == sf::Keyboard::Right)
                            cat.setDirection(1, 0);
                        if (event.key.code == sf::Keyboard::Up)
                            cat.setDirection(0, -1);
                        if (event.key.code == sf::Keyboard::Down)
                            cat.setDirection(0, 1);
                    }
                }
                else if (state == GameState::GameOver) {
                    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R) {
                        restart();
                    }
                }
            }
        }

void Game::update() {
            if (state == GameState::GameOver)
                return;
            cat.update();
            if (cat.isDead()) {
                gameover();
                return;
            }
            if (cat.eats(mouse)) {
                cat.grow();
                mouse.respawn();
            }
        }

void Game::render() {
            window.clear();
            window.draw(backgroundSprite);

            cat.draw(window);
            mouse.draw(window);

            if (state == GameState::GameOver) {
                window.draw(gameOverText);
                window.draw(restartText);
            }

            window.display();
        }

void Game::gameover() {
    state = GameState::GameOver;
}

void Game::restart() {
    cat.reset();
    mouse.respawn();
    state = GameState::Playing;
}
