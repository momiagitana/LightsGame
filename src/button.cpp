#include "button.h"
#include "globals.h"


Button::Button(sf::Vector2f loc)
{
	m_texture.loadFromFile("next.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(loc);
		m_sprite.scale((NEXT_SIZE / m_sprite.getGlobalBounds().width), (NEXT_SIZE / m_sprite.getGlobalBounds().height));
}

void Button::drawButton(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}		

bool Button::clickOnMe(const sf::Vector2f mouseLoc) const
{
	if (m_sprite.getGlobalBounds().contains(mouseLoc))
		return true;

	return false;
}

