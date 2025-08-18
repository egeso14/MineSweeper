#pragma once

#include <SFML/Graphics.hpp>
#include <random>
#include "Cell.h"
#include <memory>


namespace Gameplay
{
    class Board
    {
    private:

        const float boardWidth = 866.f;
        const float boardHeight = 1080.f;
        const float boardPosition = 530.f;

        const std::string boardTexturePath = "assets/textures/board.png";
        sf::Texture boardTexture;
        sf::Sprite boardSprite;

        void initializeBoardImage();
        void initialize();
        void createBoard();

        std::unique_ptr<Cell> cell;

    public:

        Board();

        void render(sf::RenderWindow& window);
    };
}