#include "Board.h"
#include <iostream>

namespace Gameplay
{
	Board::Board()
	{
		initialize();
	}
	void Board::initialize()
	{
		initializeBoardImage();
		boardSprite.setPosition(boardPosition, 0.f);
        createBoard();
	}
    void Board::createBoard()
    {
        cell = std::make_unique<Cell>(83, 83, sf::Vector2i(0, 0));
    }
    void Board::initializeBoardImage() {
        if (!boardTexture.loadFromFile(boardTexturePath)) {
            std::cerr << "Failed to load board texture!" << std::endl;
            return;
        }

        boardSprite.setTexture(boardTexture);
        boardSprite.setPosition(boardPosition, 0);
        boardSprite.setScale(boardWidth / boardTexture.getSize().x,
            boardHeight / boardTexture.getSize().y);
    }

    void Board::render(sf::RenderWindow& window)
    {
        window.draw(boardSprite);
        cell->render(window);
    }
} 