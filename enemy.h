#pragma once
#include"AllHeader.h"
#include"player.h"

class Enemy
{
private:
	RectangleShape shape;
	Vector2f direction;
	float speed;
	bool aggro;

	Player* player;

public:
	//constructor
	inline Enemy(Vector2f size, Vector2f position, float spd)
	{
		shape.setSize(size);
		shape.setPosition(position);
		shape.setFillColor(Color::Green);
		speed = spd;
		aggro = false;
		player = nullptr;
	}

	inline void update(float deltaTime)
	{
		if (player != nullptr)
		{
			direction = nomalize(player->getPosition() - shape.getPosition());
			shape.move(direction * speed * deltaTime);
		}
	}

	inline void render(RenderWindow& window)
	{
		window.draw(shape);
	}

	inline FloatRect getGlobalBounds()
	{
		return shape.getGlobalBounds();
	}

	inline void	collision(Player* player)
	{
		if (shape.getGlobalBounds().intersects(player->getGlobalBounds()))
		{
			this->player = player;
			setAggressive(true);
		}
	}

	inline void setPlayer(Player* player)
	{
		this->player = player;
	}

	inline void setAggressive(bool aggress)
	{
		aggro = aggress;
		if (aggro)
		{
			shape.setFillColor(Color::Red);
		}
		else
		{
			shape.setFillColor(Color::Green);
		}
	}

	inline Vector2f getPosition()
	{
		return shape.getPosition();
	}
};

