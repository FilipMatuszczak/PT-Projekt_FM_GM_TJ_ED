#include "button.hpp"
using namespace sf;

Button::Button(sf::Texture* normal, sf::Texture* clicked, sf::Texture* hovered, sf::Vector2f location) {
	this->normal.setTexture(*normal);
	this->clicked.setTexture(*clicked);
	this->hovered.setTexture(*hovered);
	this->currentSpr = &this->normal;
	current = state::state_normal;
	this->normal.setPosition(location);
	this->clicked.setPosition(location);
	this->hovered.setPosition(location);
}
void Button::checkHover(sf::Vector2f mousePos) {
	if (mousePos.x > currentSpr->getPosition().x && mousePos.x < (currentSpr->getPosition().x + currentSpr->getTexture()->getSize().x)) {
		if (mousePos.y > currentSpr->getPosition().y && mousePos.y < (currentSpr->getPosition().y + currentSpr->getTexture()->getSize().y)) {
			if (current == state::state_normal) {
				setState(state::state_hovered);
				std::cout << "HOVER";
			}
		}
	}
}

void Button::checkNormal(sf::Vector2f mousePos) {
	if (mousePos.x < currentSpr->getPosition().x || mousePos.x >(currentSpr->getPosition().x + currentSpr->getTexture()->getSize().x)) {

			setState(state::state_normal);
		
	}

	if (mousePos.y < currentSpr->getPosition().y || mousePos.y >(currentSpr->getPosition().y + currentSpr->getTexture()->getSize().y)) {

	
			setState(state::state_normal);
		
	}
	
}

void Button::setState(state which) {

	switch (which) {
	case state::state_clicked:
		currentSpr = &clicked;
		break;

	case state::state_hovered:
		currentSpr = &hovered;
		break;

	case state::state_normal:
		currentSpr = &normal;
		break;
	}

}

Button::state Button::getState()
{
	return current;
}
sf::Sprite* Button::getSprite() {
	return currentSpr;
}
