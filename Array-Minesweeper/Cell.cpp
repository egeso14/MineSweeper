#include "Cell.h"


namespace Gameplay{
	
	void Cell::initialize(float width, float height, sf::Vector2i position)
	{
		this->position = position;
		sf::Vector2f button_position(position.x * tile_size, position.y * tile_size);
		cell_button = new Button(cell_texture_path, button_position, width * slice_count, height);
	}

	Cell::Cell(float width, float height, sf::Vector2i position)
	{
		initialize(width, height, position);
	}
	
	void Cell::setCellTexture()
	{
		sf::IntRect textureRectangle;
		switch (currentState) {
		case CellState::Hidden:
			textureRectangle = sf::IntRect::Rect(10 * tile_size, 0, tile_size, tile_size);
			break;
		case CellState::Flagged:
			textureRectangle = sf::IntRect::Rect(11 * tile_size, 0, tile_size, tile_size);
			break;
		case CellState::Open:
			int index = static_cast<int>(type);
			textureRectangle = sf::IntRect::Rect(index * tile_size, 0, tile_size, tile_size);
			break;
		default:
			break;
		}

		cell_button->setTextureRect(textureRectangle);
	}

	void Cell::render(sf::RenderWindow& window)
	{
		if (cell_button)
		{
			cell_button->render(window);
		}
	}



}

