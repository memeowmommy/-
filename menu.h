#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
using namespace std;
using namespace sf;

#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
public:
	
	Menu(float width, float height);
	void draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();
	void setSelected(int n);
	int pressed() { return selected; }
	~Menu();

private:
	int selected;
	Font font;
	Text menu[MAX_NUMBER_OF_ITEMS];
};
