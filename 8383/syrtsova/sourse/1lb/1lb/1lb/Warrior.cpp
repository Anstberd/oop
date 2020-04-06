#include "pch.h"
#include "Warrior.h"
#include "Classes.h"


void Swordsman::selectSkill(int ch, Map* field)
{
	switch (ch)
	{
	case 1:
	{
		selectLine();
		if ((*field).isUnit(this->_xy.x, _xy.y))
		{
			shield_strike(this->getLink(field));
		}
		else
		{
			cout << endl << "�� ��������� ������ ��� ������!" << endl << "������ ��� �������� ����!";
			force -= 1;
		}
	} break;
	case 2:
	{
		selectLine();
		if ((*field).isUnit(this->_xy.x, _xy.y))
		{
			swepping_blow(this->getLink(field));
		}
		else
		{
			cout << endl << "�� ��������� ������ ��� ������!" << endl << "������ ��� �������� ����!";
			force -= 1;
		}
	} break;
	case 3: skill_berserk();
		break;
	case 4: 
	{
		selectLine();
		if ((*field).isUnit(this->_xy.x, _xy.y))
		{
			furious_strike(this->getLink(field));
		}
		else
		{
			cout << endl << "�� ��������� ������ ��� ������!" << endl << "������ ��� �������� ����!";
			force -= 1;
		}
	} break;
	}
	if (force <= 0)
	{
		cout << endl << "���� �������";
		force = 0;
	}	
}

void Swordsman::showSkills() {
	cout << endl << "���������� ����: "       << force    << "��������: "           << zeal
		 << endl << "1: <���� �����>"         << "\t\t"   << "������� ����: "       << forcecost[0]
		 << endl << "2: <������������� ����>" << "\t\t"   << "������� ����: "       << forcecost[1]
		 << endl << "3: <�������>"            << "\t\t\t" << "������� ����: "       << forcecost[3]
		 << endl << "4: <�������� ����>"      << "\t\t"   << "��������� ��������: " << forcecost[2];
}

Swordsman::Swordsman(int &x, int &y) : Classe_warrior('F', 50, 8, 10)
{
	XY.x = x;
	XY.y = y;
	zeal = 10;
}
void Swordsman::furious_strike(Units* unit)
{
	if (zeal >= forcecost[2])
	{
		cout << endl << "������ ��������� �������� ����! ��������� ������ ����� �����.";
		unit->health.change(-8);
		force -= 3;
		zeal -= forcecost[2];
	}
	else
		cout << endl << "������������ ���������!";
}
void Swordsman::shield_strike(Units* unit)
{
	if (force >= forcecost[0])
	{
		cout << endl << "������ ��������� ���� �����!";
		unit->health.change(-3);
		force -= forcecost[0];
		zeal += 1;
	}
	else
		cout << endl << "������������ ����!";
}

void Swordsman::swepping_blow(Units* unit)
{
	if (force >= forcecost[1])
	{
		cout << endl << "������ ������� ������������� ����! ��������� �� �������� ���������� � �������� ����.";
		unit->health.change(-5);
		force -= forcecost[1];
		zeal += 2;
	}
	else
		cout << endl << "������������ ����!";
}

Swordsman::~Swordsman()
{
	cout << endl << "������ ��� ���������!";
}


Spear::Spear(int &x, int &y) : Classe_warrior('G', 40, 10, 8)
{
	XY.x = x;
	XY.y = y;
	rage = 10;
}



void Spear::selectSkill(int ch, Map* field)
{
	switch (ch)
	{
	case 1:
	{
		selectLine();
		if ((*field).isUnit(this->_xy.x, _xy.y))
		{
			exact_blow(this->getLink(field));
		}
		else
		{
			cout << endl << "�� ��������� ������ ��� ������!" << endl << "������ ��� �������� ����!";
			force -= 1;
		}
	} break;
	case 2:
	{
		selectLine();
		if ((*field).isUnit(this->_xy.x, _xy.y))
		{
			roll_forward(this->getLink(field));
		}
		else
		{
			cout << endl << "�� ��������� ������ ��� ������!" << endl << "������ ��� �������� ����!";
			force -= 1;
		}
	} break;
	case 3: skill_berserk();
		break;
	case 4:
	{
		selectLine();
		if ((*field).isUnit(this->_xy.x, _xy.y))
		{
			spear_strike(this->getLink(field));
		}
		else
		{
			cout << endl << "�� ��������� ������ ��� ������!" << endl << "������ ��� �������� ����!";
			force -= 1;
		}
	} break;
	}
	if (force <= 0)
	{
		cout << endl << "���� �������";
		force = 0;
	}
}
void Spear::showSkills() {
	cout << endl << "���������� ����: "   << force    << "������: "            << rage
		 << endl << "1: <���� ������>"    << "\t\t"   << "������� ����: "      << forcecost[0]//1
		 << endl << "2: <�����>"          << "\t\t\t" << "������� ����: "      << forcecost[1]//4
		 << endl << "3: <�������>"        << "\t\t\t" << "������� ����: "      << forcecost[2]//10
		 << endl << "4: <������ ����>"    << "\t\t"   << "���������� ������: " << forcecost[3];//5
}

void Spear::exact_blow(Units* unit)
{
	if (force >= forcecost[0])
	{
		cout << endl << "������ ������� ���� ������.";
		unit->health.change(-3);
		force -= forcecost[0];
		rage += 1;
	}
	else
		cout << endl << "������������ ����!";
}
void Spear::roll_forward(Units* unit)
{
	if (force >= forcecost[1])
	{
		cout << endl << "������ ������ ����� ������.";
		unit->health.change(-2);
		force -= forcecost[1];
		rage += 2;
	}
	else
		cout << endl << "������������ ����!";
}
void Spear::spear_strike(Units* unit)
{
	if (rage >= forcecost[3])
	{
		cout << endl << "������ ������� ������ ����! ��������� �� �������� ���������� � �������� ����.";
		unit->health.change(-5);
		rage -= forcecost[3];
		force -= 3;
	}
	else
		cout << endl << "������������ ������!";
}
Spear::~Spear()
{
	cout << endl << "������ ��� ���������!";
}


