#include "button.hpp"
using namespace sf;

Button::Button(sf::Texture* normal, sf::Texture* clicked, sf::Texture* hovered, sf::Vector2f location, float scale) {
	this->normal.setTexture(*normal);
	this->clicked.setTexture(*clicked);
	this->hovered.setTexture(*hovered);
	this->currentSpr = &this->normal;
	this->current = state::state_normal;
	this->normal.setPosition(location);
	this->clicked.setPosition(location);
	this->hovered.setPosition(location);
	this->scale = scale;
	this->normal.setScale(scale, scale);
	this->clicked.setScale(scale, scale);
	this->hovered.setScale(scale, scale);
}

void Button::checkHover(sf::Vector2f mousePos) {
	if (mousePos.x > currentSpr->getPosition().x && mousePos.x < (currentSpr->getPosition().x + currentSpr->getTexture()->getSize().x*scale)) {
		if (mousePos.y > currentSpr->getPosition().y && mousePos.y < (currentSpr->getPosition().y + currentSpr->getTexture()->getSize().y*scale)) {
			if (this->currentSpr == &normal) {
				setState(state::state_hovered);
			}
		}
	}
}

void Button::checkNormal(sf::Vector2f mousePos) {
	if (mousePos.x < currentSpr->getPosition().x || mousePos.x >(currentSpr->getPosition().x + currentSpr->getTexture()->getSize().x*scale)) {
		if (this->currentSpr == &hovered) {
			setState(state::state_normal);
		}
	}

	if (mousePos.y < currentSpr->getPosition().y || mousePos.y >(currentSpr->getPosition().y + currentSpr->getTexture()->getSize().y*scale)) {
		if (this->currentSpr == &hovered) {
			setState(state::state_normal);
		}
	}
	
}

bool Button::checkClicked(sf::Vector2f mousePos) {
	if (mousePos.x > currentSpr->getPosition().x && mousePos.x < (currentSpr->getPosition().x + currentSpr->getTexture()->getSize().x*scale)) {
		if (mousePos.y > currentSpr->getPosition().y && mousePos.y < (currentSpr->getPosition().y + currentSpr->getTexture()->getSize().y*scale)) {
			if (this->currentSpr == &hovered) {
				setState(state::state_clicked);
				return true;
			}
			else if (this->currentSpr == &clicked) {
				setState(state::state_hovered);
				return true;
			}
		}
	}
	return false;
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
	return this->current;
}
sf::Sprite* Button::getSprite() {
	return currentSpr;
}

bool Button::isClicked()
{
	if (this->currentSpr == &clicked) {
		return true;
	}

	return false;
}


