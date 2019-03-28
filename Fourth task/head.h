#pragma once

#include <SFML/Graphics.hpp>
#include <random>
#include <math.h>
#include <vector>

#define HIGHT 720
#define WIDTH 1380
#define RADIUS 20

#define DELTA_X 	(balls[i].position.x - balls[j].position.x)
#define DELTA_Y		(balls[i].position.y - balls[j].position.y)

#define V_I 		(balls[i].vel.x * d.x + balls[i].vel.y * d.y)
#define V_J 		(balls[j].vel.x * d.x + balls[j].vel.y * d.y)
#define NORMAL_V_I	(balls[i].vel.x * norm.x + balls[i].vel.y * norm.y)
#define NORMAL_V_J	(balls[j].vel.x * norm.x + balls[j].vel.y * norm.y)

class Ball
{
public:
	sf::Vector2f	position;
	sf::Vector2f	vel;
	int 			colour;
	float			mass;

	Ball();
	Ball(int x, int y);

	void Update(float time);
};

Ball::Ball(int x, int y)
{
	position.x = x;
	position.y = y;
	vel.x	= rand() % 20 - 10;
	vel.y	= rand() % 20 - 10;
	mass	= rand() % 5 + 1;
	colour	= rand() % 3;
}

void Ball::Update(float time)
{
	position.x += vel.x * time;
	position.y += vel.y * time;

	if (((position.x > WIDTH - RADIUS) && (vel.x > 0)) \
			|| ((position.x < RADIUS) && (vel.x < 0)))
		vel.x = -vel.x;

	if (((position.y > HIGHT - RADIUS) && (vel.y > 0)) \
			|| ((position.y < RADIUS) && (vel.y < 0)))
		vel.y = -vel.y;

}
