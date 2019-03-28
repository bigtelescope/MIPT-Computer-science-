#include "head.h"

void BumpBalls(std::vector<Ball> &balls, int i, int j);

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HIGHT), "My window");
	window.setFramerateLimit(80);

	sf::Clock clock;
	
	std::vector<sf::Color> colours;
	colours.push_back(sf::Color::Red);
	colours.push_back(sf::Color::Blue);
	colours.push_back(sf::Color::Green);

	std::vector<Ball> balls;

	sf::CircleShape circle(RADIUS);
	circle.setOrigin(RADIUS, RADIUS);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Button::Left)
				{
					sf::Vector2i mouse_position= sf::Mouse::getPosition(window);
					Ball ball(mouse_position.x, mouse_position.y);
					balls.push_back(ball);
				}
			}
		}
		
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();

		for (auto &it : balls)
			it.Update(time * 50);
		
		for (int i = 0; i < balls.size(); i++)
			for (int j = i + 1; j < balls.size(); j++)
				BumpBalls(balls, i, j);
		
		window.clear();
		for (auto it : balls)
		{
			circle.setFillColor(colours[it.colour]);
			circle.setPosition(it.position.x, it.position.y);
			window.draw(circle);
		}
		window.display();
	 }

	return 0;
}

void BumpBalls(std::vector<Ball> &balls, int i, int j)
{
	float len = sqrt((pow(DELTA_X, 2) + pow(DELTA_Y, 2)));
	if (len <= 2 * RADIUS)
	{
		sf::Vector2f d(DELTA_X, DELTA_Y);
		if ((V_J - V_I) > 0)
		{
			sf::Vector2f norm(d.x / len, d.y / len);
			sf::Vector2f delta = (2 * (NORMAL_V_J - NORMAL_V_I) / (1 / balls[i].mass + 1 / balls[j].mass)) * norm;
			balls[i].vel += delta / balls[i].mass;
			balls[j].vel -= delta / balls[j].mass;
		}
	}
}
