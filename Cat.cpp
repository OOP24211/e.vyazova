#include "Cat.h"
#include "Constants.h"
#include "Game.h"

Cat::Cat() {
    head.x = 5;
    head.y = 5;

    cat_up.loadFromFile("assets/cat_up.png");
    sprite_cat_up.setTexture(cat_up);
    cat_left.loadFromFile("assets/cat_left.png");
    sprite_cat_left.setTexture(cat_left);
    cat_down.loadFromFile("assets/cat_down.png");
    sprite_cat_down.setTexture(cat_down);
    cat_right.loadFromFile("assets/cat_right.png");
    sprite_cat_right.setTexture(cat_right);


    tail_up.loadFromFile("assets/tail_up.png");
    sprite_tail_up.setTexture(tail_up);
    tail_left.loadFromFile("assets/tail_left.png");
    sprite_tail_left.setTexture(tail_left);
    tail_down.loadFromFile("assets/tail_down.png");
    sprite_tail_down.setTexture(tail_down);
    tail_right.loadFromFile("assets/tail_right.png");
    sprite_tail_right.setTexture(tail_right);

    tail.clear();
}

void Cat::move() {
    Segment lastSegment = head;
    lastSegment.dx = dx;
    lastSegment.dy = dy;

    head.x += dx;
    head.y += dy;

    if (!justGrew && !tail.empty()) {
        tail.erase(tail.begin());
    }
    tail.push_back(lastSegment);
    justGrew = false;
}

void Cat::grow() {
    justGrew = true;
}

void Cat::draw(sf::RenderWindow& window) {
    sf::Sprite* spriteToCatDraw = nullptr;
    if (dx == 1) spriteToCatDraw = &sprite_cat_right;
    else if (dx == -1) spriteToCatDraw = &sprite_cat_left;
    else if (dy == -1) spriteToCatDraw = &sprite_cat_up;
    else if (dy == 1) spriteToCatDraw = &sprite_cat_down;
    spriteToCatDraw->setPosition(head.x * CELL_SIZE, head.y*CELL_SIZE);
    window.draw(*spriteToCatDraw);

    for (auto &segment : tail) {
        sf::Sprite* spriteToDraw = nullptr;

        if (segment.dx == 1) spriteToDraw = &sprite_tail_right;
        else if (segment.dx == -1) spriteToDraw = &sprite_tail_left;
        else if (segment.dy == -1) spriteToDraw = &sprite_tail_up;
        else if (segment.dy == 1) spriteToDraw = &sprite_tail_down;

        if (spriteToDraw) {
            spriteToDraw->setPosition(segment.x * CELL_SIZE, segment.y * CELL_SIZE);
            window.draw(*spriteToDraw);
        }
    }
}

void Cat::update() {
    if (moveClock.getElapsedTime().asMilliseconds() > 150) {
        move();
        moveClock.restart();
    }
}

void Cat::setDirection(int newDx, int newDy) {
    if (dx == -newDx && dy == -newDy)
        return;
    dx = newDx;
    dy = newDy;
}

bool Cat::eats(const Mouse& mouse) const {
    return head.x == mouse.x && head.y == mouse.y;
}

bool Cat::isDead() const {
    if (head.x < 0 || head.y < 0 || head.x >= GRID_WIDTH || head.y >= GRID_HEIGHT) {
        return true;
    }
    for (const auto& segment : tail) {
        if (head.x == segment.x && head.y == segment.y) {
            return true;
        }
    }
    return false;
}

void Cat::reset() {
    head.x = 5;
    head.y = 5;
    dx = 1;
    dy = 0;
    tail.clear();
    justGrew = false;
    moveClock.restart();
}
