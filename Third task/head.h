#ifndef HEADER_H_
#define HEADER_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>

#define HIGHT 			1200
#define LENGHT			800

#define RADIUS 			10
#define POINT_RADIUS 		1
#define STEP			900

void CreatePositive(sf::RenderWindow&, std::vector<sf::Vertex>&, std::vector<sf::CircleShape>&);
void CreateNegative(sf::RenderWindow&, std::vector<sf::Vertex>&, std::vector<sf::CircleShape>&);
void CalculateForce(sf::RenderWindow&, std::vector<sf::Vertex>&, std::vector<sf::Vertex>&, std::vector<sf::Vertex>&, std::vector<sf::Vertex>&);
void CreateLine();

#endif

