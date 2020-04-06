#include "pch.h"
#include "Game.h"
#include "Units.h"
#include "Warlock.h"
#include "Archer.h"
#include "Warrior.h"
#include <string>
#include <iomanip>
#include "Map.h"
#include <Windows.h>
#include "Bases.h"
#include "Landscape.h"
#include "Neutral.h"

using namespace std;

Game::Game()
{
	choice_map();
	Map *field = new Map(x_max, y_max);
	Grass grass(x_max, y_max);
	Water water(x_max, y_max);
	Stones stones(x_max, y_max);
	grass.generation(field);
	stones.generation(field);
	water.generation(field);
	Bases *base = new Bases('B', 1000, 100);
	(*field).add_on_map(base->X, base->Y, base);
	Pab *pab = new Pab(x_max, y_max);
	(*field).add_on_map(pab->getX(), pab->getY(), pab);
	Tablet *tablet = new Tablet(x_max, y_max);
	(*field).add_on_map(tablet->getX(), tablet->getY(), tablet);
	Cave *cave = new Cave(x_max, y_max);
	(*field).add_on_map(cave->getX(), cave->getY(), cave);
	Ruin *ruin = new Ruin(x_max, y_max);
	(*field).add_on_map(ruin->getX(), ruin->getY(), ruin);
	while (true)
	{
		system("cls");
		(*field).print_map();
		int ch = management();
		cout << endl;
		switch (ch)
		{
		case 1: { base->functional(field); }
		break;
		case 2: {
			int un;
			base->showAllUnits();
			cout << endl << "�������� ����� �� ��� ID: ";
			cin >> un; } break;
		default:
			cout << "������������ ����!";
			break;
		}
	}
}


int Game::management()
{
	using namespace std;
	int chois;
	cout << "1 - ���������� �����" << endl << "2 - ���������� ������";
	cout << endl <<"�����: "; cin >> chois;
	return chois;
}



void Game::choice_map()
{
	char choice = ' ';
	cout << "����� �������� ����:\n1-���� ������������ ������� 20�20\n2-������������ ����\n0-�����\n";
	cin >> choice;
	cin.clear();
	while (cin.get() != '\n');
	switch (choice) {
	case '1':
		x_max = y_max = 20;
		break;
	case '2':
		cout << "������� ������ ����: ";
		cout << "x_max: ";
		cin >> x_max;
		cout << "y_max: ";
		cin >> y_max;
		break;
	case '0':
		exit;
	default:
		cout << "������������ ����. ���������� ��� ���.\n����� �������� ����:\n1-���� ������������ ������� 20�20\n2-������� ���������� ����: \n0-�����\n";
		cin >> choice;
	}
}

/*Map* Game::makeLandscape(int x_max, int y_max, Map* field)
{
	Grass grass(x_max, y_max);
	Water water(x_max, y_max);
	Stones stones(x_max, y_max);
	grass.generation(field);
	stones.generation(field);
	water.generation(field);
	return field;
}*/

