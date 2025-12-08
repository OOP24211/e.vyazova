#ifndef KIND_CAT_MOUSE_H
#define KIND_CAT_MOUSE_H
#pragma once
#include <random>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Constants.h"

struct Mouse {
    int x;
    int y;

    sf::Texture mouseTexture;
    sf::Sprite mouseSprite;

    Mouse() : x(0), y(0) {
        mouseTexture.loadFromFile("assets/mouse.png");
        mouseSprite.setTexture(mouseTexture);

        respawn();
    }

    void respawn() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> distX(0, GRID_WIDTH - 1);
        std::uniform_int_distribution<> distY(0, GRID_HEIGHT - 1);

        x = distX(gen);
        y = distY(gen);

        mouseSprite.setPosition(x * CELL_SIZE, y * CELL_SIZE);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(mouseSprite);
    }
};

#endif //KIND_CAT_MOUSE_H