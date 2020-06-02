#include "pch.h"
#include "Classes.h"
#include "Units.h"



Classe_warrior::Classe_warrior(char N, const int &ar, const int &at, const int &f) : Units(N, 100, ar, at, 1)
{
	force = f;
	spr.setAtrib(force);
	radius.setAtrib(5);
}
void Classe_warrior::skill_berserk(Map* field, Adapter *adapter)
{
	if (force >= 10)
	{
		cout << endl << "���� �������� � ������. ��� �������������� ���������, �� ��� ���������� ������� �� ��� ������.";
		this->health.change(-3);
		this->reaction(field, adapter);
		force -= 10;
		this->armor.change(5);
		this->attack.change(4);
		this->force + 5;
		this->health.change(-5);
	}
}
Classe_warrior::~Classe_warrior()
{}

Classe_archer::Classe_archer(char N, const int &h, const int &at, const int &r, const int &ar) : Units(N, h, 20, at, r)
{
	arrows = ar;
	spr.setAtrib(arrows);
	radius.setAtrib(6);
}
void Classe_archer::skill_headshot(Units* unit, Map *field, Adapter *adapter)
{
	if (arrows >= 8)
	{
		cout << endl << "������ ��������� ������� � ������ ���������!";
		unit->health.change(-5);
		unit->reaction(field, adapter);
		arrows -= 8;
	}
}
Classe_archer::~Classe_archer()
{}

Classe_warlock::Classe_warlock(char N, const int &h, const int &ar, const int &r, const int &m) : Units(N, h, ar, 1, r)
{
	mana = m;
	spr.setAtrib(mana);
	radius.setAtrib(3);
}
void Classe_warlock::skill_fireball(Units* unit, Map *field, Adapter *adapter)
{
	if (mana >= 5)
	{
		cout << endl << "���������� ��� �������� ����, ��� �������� ���������� �����";
		unit->health.change(-3);
		unit->reaction(field, adapter);
		mana -= 5;
	}
}

Classe_warlock::~Classe_warlock()
{}

