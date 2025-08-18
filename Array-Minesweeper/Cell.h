
#pragma once

#include <SFML/Graphics.hpp>
#include "Button.h"
#include "../../header/Event/EventPollingManager.h"

using namespace UIElements;

namespace Gameplay
{
    
    enum CellState
    {
        Hidden,
        Open,
        Flagged
    };

    enum CellType
    {
        EMPTY,
        ONE,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        MINE,
    };


    class Cell
    {
    private:
        sf::Vector2i position;


        CellState currentState;
        CellType type;
        const int tile_size = 128;
        const int slice_count = 12;
        const std::string cell_texture_path = "assets/textures/cells.jpeg";
        
        Button* cell_button;

        void initialize(float width, float height, sf::Vector2i position);

    public:
        Cell(float width, float height, sf::Vector2i position);
        ~Cell() = default;

        void setCellTexture();
        void render(sf::RenderWindow& window);

        CellState getCellState() const { return currentState;  }
        void setCellState(CellState state) { currentState = state; }
        CellType getCellType() const { return type; }
        void setCellType(CellType type) { type = type; }

    };
}