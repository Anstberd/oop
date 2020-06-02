#include "pch.h"
#include "Bases.h"
#include "ctime"
#include "Map.h"
#include "Error.h"
#include <iostream>
#include <conio.h>


enum allClasses
{
	magician = 1,
	healer,
	archer,
	arbalester,
	swordsman,
	spear
};

Units* Bases::getLink(int pos)
{
	return iterat->getLinkUnit(pos);
}

Bases* Bases::getBase()
{
	return this;
}

Bases::Bases(int pos_x, int pos_y, char N, int col, int health, int res, int move_count, Adapter *adapter) : name(N), health(health), _resources(res), _move_count(move_count)
{ 
	iterat = new Iterator();
	_move_count_max = _move_count;
	object = name;
	color = col;
	X = pos_x;
	Y = pos_y;
	initialization(res, adapter);
	if (pos_x == 1 && pos_y == 1)
	{
		XY.x = X + 1;
		XY.y = Y + 1;
	}
	else
	{
		XY.x = X - 1;
		XY.y = Y - 1;
	}
	ester = 100;
}

int rand(int &res)
{
	srand(time(0));
	int pers = int(res*0.1) + rand() % int(res - res*0.1);
	if (pers == 0 && res >= 10)
		pers += 10;
	if (pers > res*0.5)
		pers -= pers * 0.2;
	res -= pers;
	return pers;
}

void Bases::setColor(int c)
{
	color = c;
}

void Bases::setEster(int est)
{
	ester = est;
}

void Bases::setHealth(int h)
{
	health = h;
}

void Bases::setLoc(int x, int y)
{
	X = x;
	Y = y;
	XY.x = X + 1;
	XY.y = Y + 1;
}

void Bases::setName(char n)
{
	name = n;
}

void Bases::initialization(int resources, Adapter *adapter)
{
	int res = resources;
	adapter->request("���� ���������� ������� �� �������� ������");
	list.count_warrior[0] = rand(res);
	adapter->request("���� ���������� ������� �� �������� ��������");
	list.count_archer[0] = rand(res);
	adapter->request("���� ���������� ������� �� �������� �����������");
	list.count_warlock[0] = rand(res);
}

Swordsman* Bases::createSwordsman(Map *field, Creating *neutral, Adapter *adapter, int x, int y) {
	Swordsman *sword = new Swordsman(XY.x, XY.y);
	sword->color = this->color;
	adapter->request("���� ������� �������");
	if (x == 0 && y == 0)
	(*field).addOnMap(XY.x, XY.y, sword);
	else
	{
		(*field).addOnMap(x, y, sword);
	}
	adapter->request("���� �������� ������� �� �����");
	iterat->setLinksUnit(sword, count_units);
	system("cls");
	(*field).printMap();
	sword->message= units[allClasses::swordsman] + "_" + std::to_string(this->list.count_warrior[1]) + '\t' + " ID :: " + std::to_string(this->list.count_unit[0] + this->list.count_unit[1] + this->list.count_unit[2]) + "\n";
	sword->managment(field, iterat->getAllUnits(), neutral, adapter);
	return sword;
}
Spear* Bases::createSpear(Map *field, Creating *neutral, Adapter *adapter, int x, int y) {
	Spear *sp = new Spear(XY.x, XY.y);
	sp->color = this->color;
	adapter->request("���� ������� ���������");
	if (x == 0 && y == 0)
	(*field).addOnMap(XY.x, XY.y, sp);
	adapter->request("���� �������� ��������� �� �����");
	iterat->setLinksUnit(sp, count_units);
	system("cls");
	(*field).printMap();
	sp->message = units[allClasses::spear] + "_" + std::to_string(this->list.count_warrior[2]) + '\t' + " ID :: " + std::to_string(this->list.count_unit[0] + this->list.count_unit[1] + this->list.count_unit[2]) + "\n";
	sp->managment(field, iterat->getAllUnits(), neutral, adapter);
	return sp;
}

Magician* Bases::createMagician(Map *field, Creating *neutral, Adapter *adapter, int x, int y) {
	Magician *mag = new Magician(XY.x, XY.y);
	mag->color = this->color;;
	adapter->request("���� ������� ����");
	if (x == 0 && y == 0)
	(*field).addOnMap(XY.x, XY.y, mag);
	else
	{
		(*field).addOnMap(x, y, mag);
	}
	iterat->setLinksUnit(mag, count_units);
	system("cls");
	(*field).printMap();
	mag->message = units[allClasses::magician] + "_" + std::to_string(this->list.count_warlock[2]) + '\t' + " ID :: " + std::to_string(this->list.count_unit[0] + this->list.count_unit[1] + this->list.count_unit[2]) + "\n";
	mag->managment(field, iterat->getAllUnits(), neutral, adapter);
	return mag;
}


Healer* Bases::createHealer(Map *field, Creating *neutral, Adapter *adapter, int x, int y) {
	Healer *heal = new Healer(XY.x, XY.y);
	heal->color = this->color;
	adapter->request("���� ������� ��������");
	if (x == 0 && y == 0)
	(*field).addOnMap(XY.x, XY.y, heal);
	else
	{
		(*field).addOnMap(x, y, heal);
	}
	adapter->request("���� �������� �������� �� �����");
	iterat->setLinksUnit(heal, count_units);
	system("cls");
	(*field).printMap();
	heal->message = units[allClasses::healer] + "_" + std::to_string(this->list.count_warlock[1]) + '\t' + " ID :: " + std::to_string(this->list.count_unit[0] + this->list.count_unit[1] + this->list.count_unit[2]) + "\n";
	heal->managment(field, iterat->getAllUnits(), neutral, adapter);
	return heal;
}
Archer* Bases::createArcher(Map *field, Creating *neutral, Adapter *adapter, int x, int y) {
	Archer *arh = new Archer(XY.x, XY.y);
	arh->color = this->color;
	adapter->request("���� ������� �������");
	if (x == 0 && y == 0)
	(*field).addOnMap(XY.x, XY.y, arh);
	else
	{
		(*field).addOnMap(x, y, arh);
	}
	adapter->request("���� �������� ������� �� �����");
	iterat->setLinksUnit(arh, count_units);
	system("cls");
	(*field).printMap();
	arh->message= units[allClasses::archer] + "_" + std::to_string(this->list.count_archer[2]) + '\t' + " ID :: " + std::to_string(this->list.count_unit[0] + this->list.count_unit[1] + this->list.count_unit[2]) + "\n";
	arh->managment(field, iterat->getAllUnits(), neutral, adapter);
	return arh;
}
Arbalester* Bases::createArbalester(Map *field, Creating *neutral, Adapter *adapter, int x, int y) {
	Arbalester *arb = new Arbalester(XY.x, XY.y);
	arb->color = this->color;
	adapter->request("���� ������� �����������");
	if(x == 0 && y== 0)
	(*field).addOnMap(XY.x, XY.y, arb);
	else
	{
		(*field).addOnMap(x, y, arb);
	}
	adapter->request("���� �������� ����������� �� �����");
	iterat->setLinksUnit(arb, count_units);
	system("cls");
	(*field).printMap();
	arb->message = units[allClasses::arbalester] + "_" + std::to_string(this->list.count_archer[1]) + '\t' + " ID :: " + std::to_string(this->list.count_unit[0] + this->list.count_unit[1] + this->list.count_unit[2]) + "\n";
	arb->managment(field, iterat->getAllUnits(), neutral, adapter);
	return arb;
}

void Bases::production(int selsect, Map *field, Creating *neutral, Adapter *adapter)
{
	if ((*field).isUnit(XY.x, XY.y))
	{
		
		cout << endl << "���� ������ ������ ������!";
		cout << endl << endl << "������� �� ����� ������, ����� ���������� ����";
		adapter->request("���� �������� �������� �����, �.�. ������ ������ ������ ������");
		_getch();
		adapter->request("������������ ����� �� ����� �������");
		return;
	}
	switch(selsect)
	{
	case  allClasses::arbalester:
		{
		if (_cost_arbalester <= list.count_archer[0]) {
			list.count_archer[0] -= _cost_arbalester;
			string message = "���� ������������ " + to_string(_cost_arbalester) + " �������� �� �������� ������������";
			adapter->request(message);
			list.count_archer[1]++;
			adapter->request("���� ��������� ����������� ������������");
			list.count_unit[0]++;
			adapter->request("���� ��������� ���������� �������� ������ ����");
			count_units++;
			adapter->request("���� ��������� ����� ���������� ������");
			adapter->request("���� ���������� � �������� �����������");
			createArbalester(field, neutral, adapter);
		}
		else
		{
			adapter->request("���� �������� �������� �����������, ������������ ��������");
			cout << endl << "������������ �������� ��� ���������� �����!";
			cout << endl << endl << "������� �� ����� ������, ����� ���������� ����";
			_getch();
			adapter->request("������������ ����� �� ����� �������");
		}
	} break;
	case allClasses::archer:
	{
		if (_cost_archer <= list.count_archer[0]) {
			list.count_archer[0] -= _cost_archer;
			string message = "���� ������������ " + to_string(_cost_archer) + " �������� �� �������� ��������";
			adapter->request(message);
			list.count_archer[2] ++;
			adapter->request("���� ��������� ����������� ��������");
			list.count_unit[0]++;
			adapter->request("���� ��������� ���������� �������� ������ ����");
			count_units++;
			adapter->request("���� ��������� ����� ���������� ������");
			adapter->request("���� ���������� � �������� �������");
			createArcher(field, neutral, adapter);
		}
		else
		{
			adapter->request("���� �������� �������� �������, ������������ ��������");
			cout << endl << "������������ �������� ��� ���������� �����!";
			cout << endl << endl << "������� �� ����� ������, ����� ���������� ����";
			_getch();
			adapter->request("������������ ����� �� ����� �������");
		}
	} break;
	case allClasses::swordsman:
	{
		if (_cost_swordsman <= list.count_warrior[0]) {
			list.count_warrior[0] -= _cost_swordsman;
			string message = "���� ������������ " + to_string(_cost_swordsman) + " �������� �� �������� ��������";
			list.count_warrior[1] ++;
			adapter->request("���� ��������� ����������� ��������");
			list.count_unit[1]++;
			adapter->request("���� ��������� ���������� ������");
			count_units++;
			adapter->request("���� ��������� ����� ���������� ������");
			adapter->request("���� ���������� � �������� �������");
			createSwordsman(field, neutral, adapter);
		}
		else
		{
			adapter->request("���� �������� �������� �������, ������������ ��������");
			cout << endl << "������������ �������� ��� ���������� �����!";
			cout << endl << endl << "������� �� ����� ������, ����� ���������� ����";
			_getch();
			adapter->request("������������ ����� �� ����� �������");
		}
	}break;
	case allClasses::spear:
	{
		if (_cost_spear <= list.count_warrior[0]) {
			list.count_warrior[0] -= _cost_spear;
			string message = "���� ������������ " + to_string(_cost_spear) + " �������� �� �������� ����������";
			list.count_warrior[2] ++;
			adapter->request("���� ��������� ����������� ����������");
			list.count_unit[1]++;
			adapter->request("���� ��������� ���������� ������");
			count_units++;
			adapter->request("���� ��������� ����� ���������� ������");
			adapter->request("���� ���������� � �������� ���������");
			createSpear(field, neutral, adapter);
		}
		else
		{
			adapter->request("���� �������� �������� ���������, ������������ ��������");
			cout << endl << "������������ �������� ��� ���������� �����!";
			cout << endl << endl << "������� �� ����� ������, ����� ���������� ����";
			_getch();
			adapter->request("������������ ����� �� ����� �������");
		}
	}break;
	case allClasses::healer:
	{
		if (_cost_healer <= list.count_warlock[0]) {
			list.count_warlock[0] -= _cost_healer;
			string message = "���� ������������ " + to_string(_cost_healer) + " �������� �� �������� ��������";
			list.count_warlock[1] ++;
			adapter->request("���� ��������� ����������� ���������");
			list.count_unit[2]++;
			adapter->request("���� ��������� ���������� �����������");
			count_units++;
			adapter->request("���� ��������� ����� ���������� ������");
			adapter->request("���� ���������� � �������� ��������");
			createHealer(field, neutral, adapter);
		}
		else
		{
			adapter->request("���� �������� �������� ��������, ������������ ��������");
			cout << endl << "������������ �������� ��� ���������� �����!";
			cout << endl << endl << "������� �� ����� ������, ����� ���������� ����";
			_getch();
			adapter->request("������������ ����� �� ����� �������");
		}
	}break;
	case allClasses::magician:
	{
		if (_cost_magician <= list.count_warlock[0]) {
			list.count_warlock[0] -= _cost_magician;
			string message = "���� ������������ " + to_string(_cost_magician) + " �������� �� �������� ����";
			list.count_warlock[2] ++;
			adapter->request("���� ��������� ����������� �����");
			list.count_unit[2]++;
			adapter->request("���� ��������� ���������� �����������");
			count_units++;
			adapter->request("���� ��������� ����� ���������� ������");
			adapter->request("���� ���������� � �������� ����");
			Units* unit = createMagician(field, neutral, adapter);
		}
		else
		{
			adapter->request("���� �������� �������� ����, ������������ ��������");
			cout << endl << "������������ �������� ��� ���������� �����!";
			cout << endl << endl << "������� �� ����� ������, ����� ���������� ����";
			_getch();
			adapter->request("������������ ����� �� ����� �������");
		}
	}break;
	
	}
}

int Bases::getEster(Adapter *adapter)
{
	string message = "���� ������������ ��������� � ���������� ������� �������";
	adapter->request(message);
	return ester;
}
int Bases::getHealth(Adapter *adapter)
{
	string message = "���� ������������ ��������� � �������� ����";
	adapter->request(message);
	return health;
}

bool Bases::getShild(Adapter *adapter)
{
	string message = "���� ������������ ��������� � ����";
	adapter->request(message);
	return shild;
}

int Bases::getEster()
{
	return ester;
}
int Bases::getHealth()
{
	return health;
}

bool Bases::getShild()
{
	return shild;
}

void Bases::activateShild(Adapter *adapter)
{
	ester-=30;
	shild = true;
	cout << endl << "��� �������!";
	cout << endl << endl << "������� �� ����� ������, ����� ���������� ����";
	string message = "���� ������������ �������� �����";
	adapter->request(message);
	_getch();
}


void Bases::skills(Adapter *adapter)
{
	cout << endl << "1 - ������������ ������������ ���" << endl << "2 - ��������� �����";
}

void Bases::functional(Map* field, Creating *neutral, Adapter *adapter)
{
	char choice = ' ';
	while (int(choice - '0') < 1 || int(choice - '0') > 4) {
		try {
			string event[4] = { "��������� ����","��������� ������","�������� �����","������ ������" };
			for (int i = 0; i < 4; i++)
			{
				cout << (i + 1) << " - " << event[i] << endl;
			}
			cout << "����� ��������: ";
			cin >> choice;
			if (isdigit(choice)){ 
				if (int(choice - '0') > 0 && int(choice - '0') < 5) {
					string message = "������������ ������ " + event[int(choice - '0') - 1];
					adapter->request(message);
				}
				switch (int(choice - '0'))
				{
				case 1: { showState(adapter);  } break;
				case 2: {
					showResour(adapter);
					cout << endl << endl << "������� �� ����� ������, ����� ���������� ����";
					_getch();
					adapter->request("������������ ����� �� ����� �������");
				} break;
				case 3:
				{
					int product = selectUnit(field, adapter);
					string message = "���� ������ �������� �����";
					adapter->request(message);
					production(product, field, neutral, adapter);
				} break;
				case 4: { activateShild(adapter); } break;
				default:
					throw error2(choice);
					break;
				}
			}
			else throw error1(choice);
		}
		catch (error1& e)
		{
			cout << e.what();
			e.printErr();
			continue;
		}
		catch (error2& e)
		{
			cout << e.what();
			e.printErr();
			continue;
		}
	}
}

void Bases::showState(Adapter *adapter)
{
	using namespace std;
	cout << endl << "��������� ����: " << getHealth(adapter) << " HP" << endl
		<< "������ ������: " << getEster(adapter) << " ������" << endl
		<< "������ �� ������: " << this->list.count_warrior[0] + this->list.count_warlock[0] + this->list.count_archer[0];
	cout << endl << endl << "������� �� ����� ������, ����� ���������� ����";
	string message = "���� ������������ ���������� � ��������� ����, ������� ������� � �������� �� ������";
	adapter->request(message);
	_getch();
}

int Bases::selectUnit(Map* field, Adapter *adapter)
{
	showResour(adapter);
	char choice = ' ';
	while (int(choice - '0') < 1 || int(choice - '0') > 6) {
		try {
			string select[6] = { "{M} - ���", "{H} - ��������", "{L} - ������", "{A} - �����������", "{F} - ������", "{G} - ��������" };
			for (int i = 0; i < 6; i++)
				cout << (i + 1) << " - " << select[i] << endl;
			cout << "����� ���� �����: ";
			cin >> choice;
			if (choice == 'M' || choice == 'H' || choice == 'L' || choice == 'A' || choice == 'F' || choice == 'G') {
				switch (choice)
				{
				case 'M':
					choice = '1';
					break;
				case 'H':
					choice = '2';
					break;
				case 'L':
					choice = '3';
					break;
				case 'A':
					choice = '4';
					break;
				case 'F':
					choice = '5';
					break;
				case 'G':
					choice = '6';
					break;
				}
			}
			if (isdigit(choice)) {
				if (int(choice - '0') > 0 && int(choice - '0') < 7) {
					string message = "������������ ������ " + select[int(choice - '0') - 1];
					adapter->request(message);
					break;
				}
				else throw error2(choice);
			}
			else throw error1(choice);
		}
		catch (error1& e)
		{
			cout << e.what();
			e.printErr();
			continue;
		}
		catch (error2& e)
		{
			cout << e.what();
			e.printErr();
			continue;
		}
	}
	return int(choice-'0');
}

void Bases::showResour(Adapter *adapter)
{
	using namespace std;
	cout<<  endl
		<<  "����� �������: " << this->list.count_warrior[0] + this->list.count_warlock[0] + this->list.count_archer[0] << '\t' << '\t'
		<<  "����������� ������: " << count_units << " ������" << endl
		<<  "�� ���: " << '\t' << '\t' << '\t'
		<<  "�� ���: " << endl
		<<  "������� �� ��������: " << this->list.count_archer[0] << '\t' << '\t'
		<<  "�������: " << this->list.count_unit[0] << " :: " << "���: " << this->list.count_archer[2] << " -_- " << "�������: " << this->list.count_archer[1] << endl
		<<  "������� �� �����������: " << this->list.count_warlock[0] << '\t'
		<<  "����������: " << this->list.count_unit[1] << " :: " << "��������: " << this->list.count_warlock[1] << " -_- " << "���: " << this->list.count_warlock[2] << endl
		<<  "������� �� ������: " << this->list.count_warrior[0] << '\t' << '\t'
		<<  "�����: " << this->list.count_unit[1] << " :: " << "�������: " << this->list.count_warrior[1] << " -_- " << "������: " << this->list.count_warrior[2] << endl;
	
	string message = "���� ������������ ���������� �� ����� ����������� ������, ��������, ������� ����� ���� ��������� �� �� �������� � ���������� ������ ������� ���� �����";
	adapter->request(message);
}

Units** Bases::getAllUnits(Adapter *adapter)
{
	string message = "���� ���������� ������� ���� ������ ��� � �����������";
	adapter->request(message);
	return iterat->getAllUnits();
}

Units** Bases::getAllUnits()
{
	return iterat->getAllUnits();
}

void Bases::refresh()
{
	_move_count = _move_count_max;
}


bool Bases::showAllUnits (Adapter *adapter)
{
	string message = "���� ���������� ������ ���� ������ ��� � �����������";
	adapter->request(message);
	if (iterat->getLinkUnit(1) == NULL)
	{
		cout << "������ �� ����������!";
		return false;
	}
	else
	{
		for (int i = 1; iterat->getLinkUnit(i) != NULL; i++)
		{
			cout << (iterat->getLinkUnit(i))->message;
		}
		return true;
	}
}

