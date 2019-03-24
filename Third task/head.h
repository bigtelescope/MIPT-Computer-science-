#ifndef HEAD_H_
#define HEAD_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>

#define HIGHT 			800
#define LENGHT			1200

#define RADIUS 			7
#define POINT_RADIUS 	1
#define STEP			200
#define SPACE			15

#define NEXT_TO_POS_X			abs(backward_points[i].position.x - centres_positive[k].position.x) < SPACE
#define NEXT_TO_POS_Y			abs(backward_points[i].position.y - centres_positive[k].position.y) < SPACE
#define NEXT_TO_NEG_X			abs(forward_points[i].position.x - forward_points[k].position.x) < SPACE
#define NEXT_TO_NEG_Y			abs(forward_points[i].position.y - forward_points[k].position.y) < SPACE

#define BACK_X_NOT_ON_SCREEN	backward_points.back().position.x < 1 || backward_points.back().position.x > LENGHT
#define BACK_Y_NOT_ON_SCREEN	backward_points.back().position.y < 1 || backward_points.back().position.y > HIGHT
#define FRONT_X_NOT_ON_SCREEN	forward_points.back().position.x < 1 || forward_points.back().position.x > LENGHT
#define FRONT_Y_NOT_ON_SCREEN	forward_points.back().position.y < 1 || forward_points.back().position.y > HIGHT

void CreatePositive(sf::RenderWindow&, std::vector<sf::Vertex>&, std::vector<sf::CircleShape>&);
void CreateNegative(sf::RenderWindow&, std::vector<sf::Vertex>&, std::vector<sf::CircleShape>&);
void CalculateForce(sf::RenderWindow&, std::vector<sf::Vertex>&, std::vector<sf::Vertex>&, std::vector<sf::Vertex>&, std::vector<sf::Vertex>&);
void CreateLine(std::vector<sf::CircleShape>&, std::vector<sf::Vertex>&, std::vector<sf::Vertex>&);

#endif

