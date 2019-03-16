#ifndef HEADER_H_
#define HEADER_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#define HIGHT 1200
#define LENGHT 800

#define RADIUS 5

void CreatePositive(sf::RenderWindow&, std::vector<sf::Vertex>&, std::vector<sf::CircleShape>&);
void CreateNegative(sf::RenderWindow&, std::vector<sf::Vertex>&, std::vector<sf::CircleShape>&); 
void MakeForce();
void CreateLine();

#endif

