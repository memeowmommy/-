#include "menu.h"
#include "locale.h"



Menu::Menu(float width, float height)
{
	setlocale(LC_ALL, "RUS");
	if (!font.loadFromFile("assets/pixy.ttf")) { cout << L"Файл не найден :(" << endl; }
	//start game
	menu[0].setFont(font);
	menu[0].setFillColor(Color{ 255,0,148 });
	menu[0].setString(L"Начать игру");
	menu[0].setCharacterSize(120);
	menu[0].setPosition(1410,195);
	//about game
	menu[1].setFont(font);
	menu[1].setFillColor(Color{ 255,0,148 });
	menu[1].setString(L"Об игре");
	menu[1].setCharacterSize(120);
	menu[1].setPosition(1410, 350);
	//exit
	menu[2].setFont(font);
	menu[2].setFillColor(Color{ 255,0,148 });
	menu[2].setString(L"Выход");
	menu[2].setCharacterSize(100);
	menu[2].setPosition(1750, 0);

	selected = 0;
}

Menu::~Menu(){}
//draw menu
void Menu::setSelected(int n) {
	selected = n;
}

void Menu::draw(RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; ++i)
	{
		window.draw(menu[i]);
	}
}

//move up
void Menu::MoveUp()
{
	if (selected - 1 >= -1)
	{
		menu[selected].setFillColor(Color{255,0,148});
		selected--;
		if (selected == -1) { selected = 2; }
		menu[selected].setFillColor(Color::White);
	}
}

//move down
void Menu::MoveDown()
{
	if (selected + 1 <= MAX_NUMBER_OF_ITEMS)
	{
		menu[selected].setFillColor(Color{ 255,0,148 });
		selected++;
		if (selected == 3) { selected = 0; }

		menu[selected].setFillColor(Color::White);
	}
}
