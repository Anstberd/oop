#include "pch.h"
#include "Archer.h"
#include "Classes.h"
#include "Map.h"


Archer::Archer(int &x, int &y) : Classe_archer('L', 60, 6, 2, 10)
{
	XY.x = x;
	XY.y = y;
	luck = 30;
}

void Archer::selectSkill(int ch, Map* field)
{
	switch (ch)
	{
	case 1: hail_of_arrows(field);
	break;
	case 2:
	{
		selectLine();
		if ((*field).isUnit(this->_xy.x, _xy.y))
		{
			poison_arrow(this->getLink(field));
		}
		else
		{
			cout << endl << "�� ��������� ������ ��� ������!" << endl << "������� ��� �������� ������!";
			arrows -= 1;
		}
	}
	break;
	case 3:
	{
		selectLine();
		if ((*field).isUnit(this->_xy.x, _xy.y))
		{
			skill_headshot(this->getLink(field));
		}
		else
		{
			cout << endl << "�� ��������� ������ ��� ������!" << endl << "������� ��� �������� ������!";
			arrows -= 1;
		}
	}
	break;
	case 4: {
		selectLine();
		if ((*field).isUnit(this->_xy.x, _xy.y))
		{
			double_shot(this->getLink(field));
		}
		else
		{
			cout << endl << "�� ��������� ������ ��� ������!" << endl << "������� ��� �������� ������!";
			arrows -= 1;
		}
	}
		break;
	}
	if (arrows <= 0)
	{
		cout << endl << "������ �������!";
		arrows = 0;
	}
}


void Archer::showSkills() {
	cout << endl << "���������� �����: " << arrows << "�����: " << luck
		<< "1: <�������>\t\t\t������� �����: " << arrowscost[0] << endl
		<< "2: <����������� ������>\t\t������� �����: " << arrowscost[1] << endl
		<< "3: <������� � ������>\t������� �����: " << arrowscost[2] << endl
		<< "4: <������� �������>\t\t��������� �������: " << arrowscost[3] << endl;
}

void Archer::double_shot(Units* unit)
{
	if (luck >= arrowscost[3])
	{
		cout << endl << "������� ���������, ��� ��������� �������� � ��� ���� ������ �����.";
		unit->health.change(-4);
		arrows -= 1;
		luck -= arrowscost[3];
	}
	else
		cout << endl << "������������ �����!";
}
void Archer::hail_of_arrows(Map* field)
{
	if (arrows >= arrowscost[0])
	{
		cout << endl << "������ ������� ������, ����� � ������� 1 ������ �������� ����!";
		// ������ ������ 6
		if ((*field).isUnit(this->XY.x + 1, XY.y))
		{
			_xy.x = this->XY.x + 1;
			_xy.y = this->XY.y;
			Units *un = this->getLink(field);
			un->health.change(-(3 + this->attack.returnAttack()));
		}
		// ������ ������� ������ 3
		if ((*field).isUnit(this->XY.x + 1, XY.y - 1))
		{
			_xy.x = this->XY.x + 1;
			_xy.y = this->XY.y - 1;
			Units *un = this->getLink(field);
			un->health.change(-(3 + this->attack.returnAttack()));
		}
		// ����� ������ 4 
		if ((*field).isUnit(this->XY.x - 1, XY.y))
		{
			_xy.x = this->XY.x - 1;
			_xy.y = this->XY.y;
			Units *un = this->getLink(field);
			un->health.change(-(3 + this->attack.returnAttack()));
		}
		// ������ ������ ������ 9
		if ((*field).isUnit(this->XY.x + 1, XY.y + 1))
		{
			_xy.x = this->XY.x + 1;
			_xy.y = this->XY.y + 1;
			Units *un = this->getLink(field);
			un->health.change(-(3 + this->attack.returnAttack()));
		}
		// ������ ������ 8
		if ((*field).isUnit(this->XY.x, XY.y + 1))
		{
			_xy.x = this->XY.x;
			_xy.y = this->XY.y + 1;
			Units *un = this->getLink(field);
			un->health.change(-(3 + this->attack.returnAttack()));
		}
		// ������� ����� ������ 1
		if ((*field).isUnit(this->XY.x - 1, XY.y - 1))
		{
			_xy.x = this->XY.x - 1;
			_xy.y = this->XY.y - 1;
			Units *un = this->getLink(field);
			un->health.change(-(3 + this->attack.returnAttack()));
		}
		// ������ ����� ������ 7
		if ((*field).isUnit(this->XY.x - 1, XY.y + 1))
		{
			_xy.x = this->XY.x - 1;
			_xy.y = this->XY.y + 1;
			Units *un = this->getLink(field);
			un->health.change(-(3 + this->attack.returnAttack()));
		}
		//������� ������ 2
		if ((*field).isUnit(this->XY.x, XY.y - 1))
		{
			_xy.x = this->XY.x;
			_xy.y = this->XY.y - 1;
			Units *un = this->getLink(field);
			un->health.change(-(3 + this->attack.returnAttack()));
		}
		arrows -= arrowscost[0];
		luck += 1;
	}
}
void Archer::poison_arrow(Units* unit)
{
	if (arrows >= arrowscost[1])
	{
		cout << endl << "����������� ������.";
		unit->health.change(-3);
		arrows -= arrowscost[1];
		luck += 1;
	}
	else
		cout << endl << "������������ �����!";
}
Archer::~Archer()
{
	cout << endl << "������ ��� ���������!";
}

Arbalester::Arbalester(int &x, int &y) : Classe_archer('A', 70, 7, 3, 6)
{
	XY.x = x;
	XY.y = y;
}

void Arbalester::selectSkill(int ch, Map* field)
{
	switch (ch)
	{
	case 4: 
	{
		selectLine();
		if ((*field).isUnit(this->_xy.x, _xy.y))
		{
			crossbow_shot(this->getLink(field));
		}
		else
		{
			cout << endl << "�� ��������� ������ ��� ������!" << endl << "���������� ��� �������� ������!";
			arrows -= 1;
		}
	}
		break;
	case 2:
	{
		selectLine();
		if ((*field).isUnit(this->_xy.x, _xy.y))
		{
			fire_shot(this->getLink(field));
		}
		else
		{
			cout << endl << "�� ��������� ������ ��� ������!" << endl << "���������� ��� �������� ������!";
			arrows -= 1;
		}
	}
	break;
	case 3:
	{
		selectLine();
		if ((*field).isUnit(this->_xy.x, _xy.y))
		{
			skill_headshot(this->getLink(field));
		}
		else
		{
			cout << endl << "�� ��������� ������ ��� ������!" << endl << "���������� ��� �������� ������!";
			arrows -= 1;
		}
	}
	break;
	case 1: { reliable_shot(); } break;
	}
	if (arrows <= 0)
	{
		cout << endl << "������ �������!";
		arrows = 0;
	}
}

void Arbalester::showSkills() {
	cout << endl << "���������� �����: " << arrows << "��������: " << intuition
		<< "1: <�������� ����>\t\t��������� ��������: " << arrowscost[0] << endl
		<< "2: <�������� ������>\t\t������� �����: " << arrowscost[1] << endl
		<< "3: <������� � ������>\t\t������� �����: " << arrowscost[2] << endl
		<< "4: <�������>\t\t������� �����: " << arrowscost[3] << endl;
}

void Arbalester::crossbow_shot(Units* unit)
{
	if (arrows >= arrowscost[0])
	{
		cout << endl << " ";
		unit->health.change(-(2 + this->attack.returnAttack()));
		arrows -= arrowscost[0] * 4;
		intuition -= arrowscost[0];
	}
	else
		cout << endl << "������������ �����!";
}

void Arbalester::fire_shot(Units* unit)
{
	if (arrows >= arrowscost[1])
	{
		cout << endl << "�������� ������.";
		unit->health.change(-(3 + this->attack.returnAttack()));
		arrows -= arrowscost[1];
		intuition += 1;
	}
	else
		cout << endl << "������������ �����!";
	
}

void Arbalester::reliable_shot()
{
	if (intuition >= arrowscost[3])
	{
		cout << endl << "���������� ������ ���� ������ � ����� �������� � ����. ���������� ����� ���������.";
		this->attack.change(2);
		arrows += 5;
		intuition -= arrowscost[3];
	}
	else
		cout << endl << "������������ ��������!";
}

Arbalester::~Arbalester()
{
	cout << endl << "��������� ��� ���������!";
}

