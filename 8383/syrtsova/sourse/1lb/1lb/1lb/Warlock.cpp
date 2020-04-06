#include "pch.h"
#include "Warlock.h"
#include "Classes.h"
#include "Bases.h"
#include "Units.h"
#include "Map.h"
#include <windows.h>

Magician::Magician(int &x, int &y) : Classe_warlock('M', 50, 6, 4, 100)
{
	XY.x = x;
	XY.y = y;
	ether = 20;
}


void Magician::selectSkill(int ch, Map* field)
{
	switch (ch)
	{
	case 1: 
	{
		selectLine();
		if ((*field).isUnit(this->_xy.x, _xy.y))
		{
			/*Units *un;
			for (int i = 1; i <= base->count_units; ++i)
			{
				un = field->iterator->mas[i]->getUnit;
				if (un->XY.x == this->_xy.x && un->XY.y == this->_xy.y)
				{*/
					meteorite(this->getLink(field));
					return;
				//}
			//}
		}
		else
		{
		cout << endl << "�� ��������� ������ ��� ������!" << endl << "��� �������� ����������, �� ����� ���� ���������!";
		mana -= 1;
		}
	}
		break;
	case 2: 
	{
		selectLine();
		if ((*field).isUnit(this->_xy.x, _xy.y))
		{
			storm(this->getLink(field));
			return;
		}
		else 
		{
			cout << endl << "�� ��������� ������ ��� ������!" << endl << "��� �������� ����������, �� ����� ���� ���������!";
			mana -= 1;
		}
	}
		break;
	case 3: 
	{
		selectLine();
		if ((*field).isUnit(this->_xy.x, _xy.y))
		{
			skill_fireball(this->getLink(field));
		}
		else
		{
			cout << endl << "�� ��������� ������ ��� ������!" << endl << "��� �������� ����������, �� ����� ���� ���������!";
			mana -= 1;
		}
	}
		break;
	case 4: ARMAGEDON(field);
		break;
	}
	if (mana <= 0)
	{
		cout << endl << "���� �������!";
		mana = 0;
	}
}

void Magician::showSkills()
{
	cout << endl << "���������� ����: " << mana     << "\t\t"              << "���������� �����: " << this->ether;
	cout << endl << "1: <��������> "    << "\t\t\t" << "������� ����: "    << manacost[2] 
		 << endl << "2: <�����>"        << "\t\t\t" << "������� ����: "    << manacost[1]
		 << endl << "3: <�������� ���>" << "\t\t"   << "������� ����: "    << manacost[0]
		 << endl << "4: <���������>"    << "\t\t\t" << "����� �����: "	   << manacost[3];
}

void Magician::ARMAGEDON(Map* field)
{
	if (ether <= manacost[3]) {
		cout << endl << "���� ����������� ����� �������! �� �� � ��������� � ��������������."
			<< endl << "�� ��� ����� ���������� ����, � � ����� ������ ���������."
			<< endl << "���� � ������� ���� ������, ��� ����� � ������ �������� ��������� � ����."
			<< endl << "������ ���������.";
		Object* o = new Object('@');
		o->color = colorLand::red;

		// ������ ������ 6
		(*field).add_on_map(this->XY.x + 1, this->XY.y, o);
		system("cls");
		(*field).print_map();
		if ((*field).isUnit(this->XY.x + 1, XY.y))
		{
			_xy.x = this->XY.x + 1;
			_xy.y = this->XY.y;
			Units *un = this->getLink(field);
			delete un;
		}
		Sleep(10);
	
		// ������ ������� ������ 3
		(*field).add_on_map(this->XY.x + 1, this->XY.y - 1, o);
		system("cls");
		(*field).print_map();
		if ((*field).isUnit(this->XY.x + 1, XY.y - 1))
		{
			_xy.x = this->XY.x + 1;
			_xy.y = this->XY.y - 1;
			Units *un = this->getLink(field);
			delete un;
		}
		Sleep(10);

		// ����� ������ 4 
		(*field).add_on_map(this->XY.x - 1, this->XY.y, o);
		system("cls");
		(*field).print_map();
		if ((*field).isUnit(this->XY.x - 1, XY.y))
		{
			_xy.x = this->XY.x - 1;
			_xy.y = this->XY.y;
			Units *un = this->getLink(field);
			delete un;
		}
		Sleep(10);

		// ������ ������ ������ 9
		(*field).add_on_map(this->XY.x + 1, this->XY.y + 1, o);
		system("cls");
		(*field).print_map();
		if ((*field).isUnit(this->XY.x + 1, XY.y + 1))
		{
			_xy.x = this->XY.x + 1;
			_xy.y = this->XY.y + 1;
			Units *un = this->getLink(field);
			delete un;
		}
		Sleep(10);

		// ������ ������ 8
		(*field).add_on_map(this->XY.x    , this->XY.y + 1, o);
		system("cls");
		(*field).print_map();
		if ((*field).isUnit(this->XY.x, XY.y + 1))
		{
			_xy.x = this->XY.x;
			_xy.y = this->XY.y + 1;
			Units *un = this->getLink(field);
			delete un;
		}
		Sleep(10);

		// ������� ����� ������ 1
		(*field).add_on_map(this->XY.x - 1, this->XY.y - 1, o);
		system("cls");
		(*field).print_map();
		if ((*field).isUnit(this->XY.x - 1, XY.y - 1))
		{
			_xy.x = this->XY.x - 1;
			_xy.y = this->XY.y - 1;
			Units *un = this->getLink(field);
			delete un;
		}
		Sleep(10);

		// ������ ����� ������ 7
		(*field).add_on_map(this->XY.x - 1, this->XY.y + 1, o);
		system("cls");
		(*field).print_map();
		if ((*field).isUnit(this->XY.x - 1, XY.y + 1))
		{
			_xy.x = this->XY.x - 1;
			_xy.y = this->XY.y + 1;
			Units *un = this->getLink(field);
			delete un;
		}
		Sleep(10);
		
		//������� ������ 2
		(*field).add_on_map(this->XY.x, this->XY.y - 1, o);
		system("cls");
		(*field).print_map();
		if ((*field).isUnit(this->XY.x, XY.y - 1))
		{
			_xy.x = this->XY.x;
			_xy.y = this->XY.y - 1;
			Units *un = this->getLink(field);
			delete un;
		}
		Sleep(10);
		// ����������� ������ 5
		(*field).add_on_map(this->XY.x, this->XY.y, o);
		system("cls");
		(*field).print_map();
		delete this;
		Sleep(10);
	}
	else
		cout << endl << "������������ ������ �������!";
}

void Magician::meteorite(Units* unit)
{
	if (mana >= manacost[1])
	{
		cout << endl << "� ���� ����� �������� ��������!";
		unit->health.change(-5);
		mana -= manacost[1];
		ether += 5;
	}
	else
		cout << endl << "������������ ����!";
}

void Magician::storm(Units* unit)
{
	if (mana >= manacost[2])
	{
		cout << endl << "���� ���������. ������ � ������ ������� �������� ����, �� ���� ������";
		unit->health.change(-10);
		this->health.change(-4);
		mana -= manacost[2];
		ether += 10;
	}
	else
		cout << endl << "������������ ����!";
}

Magician::~Magician()
{
	cout << endl << "��� ��� ���������!";
}


void Healer::selectSkill(int ch, Map* field)
{
	switch (ch)
	{
	case 1:
	{
		cover();
	} break;
	case 2:
	{
		selectLine();
		if ((*field).isUnit(this->_xy.x, _xy.y))
		{
			heal(this->getLink(field));
		}
		else
		{
			cout << endl << "�� ��������� ������ ��� ������!" << endl << "�������� ������ �������� ��������.";
			cover();
		}
	} break;
	case 3:
	{
		selectLine();
		if ((*field).isUnit(this->_xy.x, _xy.y))
		{
			skill_fireball(this->getLink(field));
		}
		else
		{
			cout << endl << "�� ��������� ������ ��� ������!" << endl << "�������� �������� ����������, �� ����� ���� ���������!";
			mana -= 1;
		}
	} break;
	case 4: mass_heal(field);
		break;
	}
	if (mana <= 0)
	{
		cout << endl << "���� �������!";
		mana = 0;
	}
}

Healer::Healer(int &x, int &y) : Classe_warlock('H', 40, 8, 2, 80)
{
	XY.x = x;
	XY.y = y;
	prayer = 10;
}

void Healer::showSkills()
{
	cout << endl << "���������� ����: " << mana << "\t\t"   << "���� �������: "		    << prayer;
	cout << endl << "1: <�������> "             << "\t\t\t" << "������� ����: "         << manacost[2]
		 << endl << "2: <���������>"            << "\t\t\t" << "������� ����: "         << manacost[1]
		 << endl << "3: <�������� ���>"         << "\t\t"   << "������� ����: "         << manacost[0]
		 << endl << "4: <�������� ���������>"   << "\t\t"   << "����� ��������� ����: " << manacost[3];
}


void Healer::heal(Units* unit)
{
	if (mana >= manacost[1])
	{
		cout << endl << "�������� ������ ���������� � ����� � ������� � ���������� � ���������";
		unit->health.change(2);
		mana -= manacost[1];
	}
	else
		cout << endl << "������������ ����!";
}
void Healer::mass_heal( Map* field)
{
	if (prayer >= manacost[3])
	{
		cout << endl << "�������� ������� � �������, ����� � ������� 1 ������ ��������";
		// ������ ������ 6
		if ((*field).isUnit(this->XY.x + 1, XY.y))
		{
			_xy.x = this->XY.x + 1;
			_xy.y = this->XY.y;
			Units *un = this->getLink(field);
			un->health.change(3);
		}
		// ������ ������� ������ 3
		if ((*field).isUnit(this->XY.x + 1, XY.y - 1))
		{
			_xy.x = this->XY.x + 1;
			_xy.y = this->XY.y - 1;
			Units *un = this->getLink(field);
			un->health.change(3);
		}
		// ����� ������ 4 
		if ((*field).isUnit(this->XY.x - 1, XY.y))
		{
			_xy.x = this->XY.x - 1;
			_xy.y = this->XY.y;
			Units *un = this->getLink(field);
			un->health.change(3);
		}
		// ������ ������ ������ 9
		if ((*field).isUnit(this->XY.x + 1, XY.y + 1))
		{
			_xy.x = this->XY.x + 1;
			_xy.y = this->XY.y + 1;
			Units *un = this->getLink(field);
			un->health.change(3);
		}
		// ������ ������ 8
		if ((*field).isUnit(this->XY.x, XY.y + 1))
		{
			_xy.x = this->XY.x;
			_xy.y = this->XY.y + 1;
			Units *un = this->getLink(field);
			un->health.change(3);
		}
		// ������� ����� ������ 1
		if ((*field).isUnit(this->XY.x - 1, XY.y - 1))
		{
			_xy.x = this->XY.x - 1;
			_xy.y = this->XY.y - 1;
			Units *un = this->getLink(field);
			un->health.change(3);
		}
		// ������ ����� ������ 7
		if ((*field).isUnit(this->XY.x - 1, XY.y + 1))
		{
			_xy.x = this->XY.x - 1;
			_xy.y = this->XY.y + 1;
			Units *un = this->getLink(field);
			un->health.change(3);
		}
		//������� ������ 2
		if ((*field).isUnit(this->XY.x, XY.y - 1))
		{
			_xy.x = this->XY.x;
			_xy.y = this->XY.y - 1;
			Units *un = this->getLink(field);
			un->health.change(3);
		}
		// ����������� ������ 5
		this->health.change(3);
	}	
	else
		cout << endl << "��������� ������� �� �������!";
}


void Healer::cover()
{
	if (mana >= manacost[2])
	{
		cout << endl << "�������� ������ �������, ���������� ��������� ���� �������������";
		prayer += 1;
	}
	else
		cout << endl << "������������ ����!";
}


Healer::~Healer()
{
	cout << endl << "�������� ��� ���������!";
}


