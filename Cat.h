#ifndef KIND_CAT_CAT_H
#define KIND_CAT_CAT_H
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Mouse.h"

struct Segment {
    int x;
    int y;
    int dx;
    int dy;
};

class Cat {
public:
    Cat();
    void move();
    void grow();
    void draw(sf::RenderWindow& window);
    void update();
    void reset();
    void setDirection(int dx, int dy);
    bool eats(const Mouse& mouse) const;
    sf::Clock moveClock;
    bool isDead() const;

private:
    bool justGrew = false;
    std::vector<Segment> tail;
    Segment head;
    int dx = 1;
    int dy = 0;
    sf::Texture cat_up;
    sf::Sprite sprite_cat_up;
    sf::Texture cat_left;
    sf::Sprite sprite_cat_left;
    sf::Texture cat_down;
    sf::Sprite sprite_cat_down;
    sf::Texture cat_right;
    sf::Sprite sprite_cat_right;

    sf::Texture tail_up;
    sf::Sprite sprite_tail_up;
    sf::Texture tail_left;
    sf::Sprite sprite_tail_left;
    sf::Texture tail_down;
    sf::Sprite sprite_tail_down;
    sf::Texture tail_right;
    sf::Sprite sprite_tail_right;
};

#endif //KIND_CAT_CAT_H