#include "../header/hud.h"

#include "../header/graphics.h"

HUD::HUD() {}

HUD::HUD(Graphics& graphics, Player& player) {
	// Character Quote
	this->_player = player;
	// Health Sprites
	this->_healthBarSprite = Sprite(graphics, "content/sprites/TextBox.png", 0, 40, 64, 8, 35, 70);
	this->_healthNumber1 = Sprite(graphics, "content/sprites/TextBox.png", 0, 56, 8, 8, 66, 70);
	this->_currentHealthBar = Sprite(graphics, "content/sprites/TextBox.png", 0, 25, 39, 5, 83, 72);
	// Exp Sprites
	this->_expBar = Sprite(graphics, "content/sprites/TextBox.png", 0, 72, 40, 8, 83, 52);
	this->_lvlWord = Sprite(graphics, "content/sprites/TextBox.png", 81, 81, 11, 7, 38, 55);
	this->_lvNumber = Sprite(graphics, "content/sprites/TextBox.png", 0, 56, 8, 8, 66, 52);
	// Weapon Info
	this->_slash = Sprite(graphics, "content/sprites/TextBox.png", 72, 48, 8, 8, 100, 36);
	this->_dashes = Sprite(graphics, "content/sprites/TextBox.png", 81, 51, 15, 11, 132, 26);
}

void HUD::update(int elapsedTime, Player &player) {
	this->_player = player;

	this->_healthNumber1.setSourceRectX(8 * this->_player.getCurrentHealth());


	// Calculate the width of the health bar
	// 100% = 39px
	float num = (float)this->_player.getCurrentHealth() / this->_player.getMaxHealth();
	this->_currentHealthBar.setSourceRectW(std::floor(num * 39));


}

void HUD::draw(Graphics& graphics) {
	// Health Sprites
	this->_healthBarSprite.draw(graphics, this->_healthBarSprite.getX(),
		this->_healthBarSprite.getY());
	this->_healthNumber1.draw(graphics, this->_healthNumber1.getX(), 
		this->_healthNumber1.getY());
	this->_currentHealthBar.draw(graphics, this->_currentHealthBar.getX(), this->_currentHealthBar.getY());
	// Exp Sprites
	this->_lvlWord.draw(graphics, this->_lvlWord.getX(), this->_lvlWord.getY());
	this->_lvNumber.draw(graphics, this->_lvNumber.getX(), this->_lvNumber.getY());
	this->_expBar.draw(graphics, this->_expBar.getX(), this->_expBar.getY());
	// Weapon Info
	this->_slash.draw(graphics, this->_slash.getX(), this->_slash.getY());
	this->_dashes.draw(graphics, this->_dashes.getX(), this->_dashes.getY());
}