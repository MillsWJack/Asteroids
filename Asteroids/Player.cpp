#include "Player.h"

Player::Player(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f velocity):
	Entity(size, pos, velocity)
{

	GetImage().loadFromFile("ShipSheet.png");
	GetImage().createMaskFromColor(sf::Color(255, 0, 255));
	GetTexture().loadFromImage(GetImage());
	GetSprite().setTexture(GetTexture());

	//Set what sprite to show
	SetSpriteType(GetSpriteNum());

	//Set sprite origin point and scale
	GetSprite().setOrigin(GetSprite().getTextureRect().width / 2,
						  GetSprite().getTextureRect().height / 2);
	GetSprite().setScale(1.5, 1.5);

}

Player::~Player()
{
}

void Player::SetSpriteType(int spriteNum)
{
	switch (spriteNum)
	{
	case 0:
		//Engine Off
		GetSprite().setTextureRect(sf::IntRect(42, 3, 39, 36));
		break;
	case 1:
		//Engine On 1
		GetSprite().setTextureRect(sf::IntRect(42, 43, 39, 43));
		break;
	case 2:
		//Engine On 2
		GetSprite().setTextureRect(sf::IntRect(42, 89, 39, 40));
		break;
	}
}