#pragma once
#include <SFML/Graphics.hpp>

class Button
{
public:

	Button(sf::Vector2f);

	bool clickOnMe(const sf::Vector2f mouseLoc) const;

	void drawButton(sf::RenderWindow& window);

private:

	sf::Texture m_texture;
	sf::Sprite m_sprite;
};