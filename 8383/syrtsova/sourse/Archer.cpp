#include "pch.h"
#include "Archer.h"
#include "Classes.h"
#include "Map.h"


Archer::Archer(int &x, int &y) : Classe_archer('L', 60, 6, 2, 10)
{
	XY.x = x;
	XY.y = y;
	_luck = 30;
	for (int i = 0; i < 4; i++)
	{
		nameSkills[i] = nameSkill[i];
	}
}

void Archer::selectSkill(int ch, Map* field, Units **link, Adapter *adapter, bool sLine)
{
	switch (ch)
	{
	case 1: hail_of_arrows(field, link, adapter);
	break;
	case 2:
	{
		selectLine(adapter);
		if ((*field).isUnit(this->_xy.x, _xy.y))
		{
			poison_arrow(this->getLink(link), field, adapter);
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
		selectLine(adapter);
		if ((*field).isUnit(this->_xy.x, _xy.y))
		{
			skill_headshot(this->getLink(link), field, adapter);
		}
		else
		{
			cout << endl << "�� ��������� ������ ��� ������!" << endl << "������� ��� �������� ������!";
			arrows -= 1;
		}
	}
	break;
	case 4: {
		selectLine(adapter);
		if ((*field).isUnit(this->_xy.x, _xy.y))
		{
			double_shot(this->getLink(link), field, adapter);
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


void Archer::showSkills(Adapter *adapter) {
	cout << endl << "���������� �����: " << arrows <<"\t\t"   << "�����: " << _luck << endl
				 << "1: <�������>"			 <<"\t\t\t"<<"������� �����: " << arrowscost[0] << endl
				 << "2: <����������� ������>"<<"\t\t"  <<"������� �����: " << arrowscost[1] << endl
				 << "3: <������� � ������>"  <<"\t\t"    <<"������� �����: " << arrowscost[2] << endl
				 << "4: <������� �������>"   <<"\t\t"  <<"��������� �������: " << arrowscost[3] << endl;
}

void Archer::double_shot(Units* unit, Map* field, Adapter *adapter)
{
	if (_luck >= arrowscost[3])
	{
		cout << endl << "������� ���������, ��� ��������� �������� � ��� ���� ������ �����.";
		unit->health.change(-4);
		unit->reaction(field, adapter);
		arrows -= 1;
		_luck -= arrowscost[3];
	}
	else
		cout << endl << "������������ �����!";
}
void Archer::hail_of_arrows(Map* field, Units **link, Adapter *adapter)
{
	if (arrows >= arrowscost[0])
	{
		cout << endl << "������ ������� ������, ����� � ������� 1 ������ �������� ����!";
		string message = "������ ������� ������, ����� � ������� 1 ������ �������� ����!";
		adapter->request(message);
		// ������ ������ 6
		if ((*field).isUnit(this->XY.x + 1, XY.y))
		{
			_xy.x = this->XY.x + 1;
			_xy.y = this->XY.y;
			Units *un = this->getLink(link);
			un->health.change(-(3 + this->attack.returnAttack()));
			un->reaction(field, adapter);
		}
		// ������ ������� ������ 3
		if ((*field).isUnit(this->XY.x + 1, XY.y - 1))
		{
			_xy.x = this->XY.x + 1;
			_xy.y = this->XY.y - 1;
			Units *un = this->getLink(link);
			un->health.change(-(3 + this->attack.returnAttack()));
			un->reaction(field, adapter);
		}
		// ����� ������ 4 
		if ((*field).isUnit(this->XY.x - 1, XY.y))
		{
			_xy.x = this->XY.x - 1;
			_xy.y = this->XY.y;
			Units *un = this->getLink(link);
			un->health.change(-(3 + this->attack.returnAttack()));
			un->reaction(field, adapter);
		}
		// ������ ������ ������ 9
		if ((*field).isUnit(this->XY.x + 1, XY.y + 1))
		{
			_xy.x = this->XY.x + 1;
			_xy.y = this->XY.y + 1;
			Units *un = this->getLink(link);
			un->health.change(-(3 + this->attack.returnAttack()));
			un->reaction(field, adapter);
		}
		// ������ ������ 8
		if ((*field).isUnit(this->XY.x, XY.y + 1))
		{
			_xy.x = this->XY.x;
			_xy.y = this->XY.y + 1;
			Units *un = this->getLink(link);
			un->health.change(-(3 + this->attack.returnAttack()));
			un->reaction(field, adapter);
		}
		// ������� ����� ������ 1
		if ((*field).isUnit(this->XY.x - 1, XY.y - 1))
		{
			_xy.x = this->XY.x - 1;
			_xy.y = this->XY.y - 1;
			Units *un = this->getLink(link);
			un->health.change(-(3 + this->attack.returnAttack()));
			un->reaction(field, adapter);
		}
		// ������ ����� ������ 7
		if ((*field).isUnit(this->XY.x - 1, XY.y + 1))
		{
			_xy.x = this->XY.x - 1;
			_xy.y = this->XY.y + 1;
			Units *un = this->getLink(link);
			un->health.change(-(3 + this->attack.returnAttack()));
			un->reaction(field, adapter);
		}
		//������� ������ 2
		if ((*field).isUnit(this->XY.x, XY.y - 1))
		{
			_xy.x = this->XY.x;
			_xy.y = this->XY.y - 1;
			Units *un = this->getLink(link);
			un->health.change(-(3 + this->attack.returnAttack()));
			un->reaction(field, adapter);
		}
		arrows -= arrowscost[0];
		_luck += 1;
	}
}
void Archer::poison_arrow(Units* unit, Map* field, Adapter *adapter)
{
	if (arrows >= arrowscost[1])
	{

		cout << endl << "����������� ������.";
		string message = "������ ���������� ����������� <����������� ������>";
		adapter->request(message);
		unit->health.change(-3);
		unit->reaction(field, adapter);
		arrows -= arrowscost[1];
		_luck += 1;
	}
	else
	{
		cout << endl << "������������ �����!";
		string message = "������ �� ����� ������������ ����������";
		adapter->request(message);
	}

}
Archer::~Archer()
{
	cout << endl << "������ ��� ���������!";
}

Arbalester::Arbalester(int &x, int &y) : Classe_archer('A', 70, 7, 3, 6)
{
	XY.x = x;
	XY.y = y;
	for (int i = 0; i < 4; i++)
	{
		nameSkills[i] = nameSkill[i];
	}
}

void Arbalester::selectSkill(int ch, Map* field, Units **link, Adapter *adapter, bool sLine)
{
	switch (ch)
	{
	case 4: 
	{
		selectLine(adapter);
		if ((*field).isUnit(this->_xy.x, _xy.y))
		{
			crossbow_shot(this->getLink(link), field, adapter);
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
		selectLine(adapter);
		if ((*field).isUnit(this->_xy.x, _xy.y))
		{
			fire_shot(this->getLink(link), field, adapter);
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
		selectLine(adapter);
		if ((*field).isUnit(this->_xy.x, _xy.y))
		{
			skill_headshot(this->getLink(link), field, adapter);
		}
		else
		{
			cout << endl << "�� ��������� ������ ��� ������!" << endl << "���������� ��� �������� ������!";
			arrows -= 1;
		}
	}
	break;
	case 1: { reliable_shot(adapter); } break;
	}
	if (arrows <= 0)
	{
		cout << endl << "������ �������!";
		arrows = 0;
	}
}

void Arbalester::showSkills(Adapter *adapter) {
	cout << endl << "���������� �����: " << "\t\t"<< arrows << "��������: " << _intuition
		<< "1: <�������� ����>\t\t��������� ��������: " << arrowscost[0] << endl
		<< "2: <�������� ������>\t\t������� �����: " << arrowscost[1] << endl
		<< "3: <������� � ������>\t\t������� �����: " << arrowscost[2] << endl
		<< "4: <�������>\t\t������� �����: " << arrowscost[3] << endl;
	adapter->request("���������� ����������� � ��������� ������������");
}

void Arbalester::crossbow_shot(Units* unit, Map* field, Adapter *adapter)
{
	if (arrows >= arrowscost[0])
	{

		cout <<"����������� ������ ������� �� ��������"<< endl << " ";
		unit->health.change(-(2 + this->attack.returnAttack()));
		adapter->request("���������� ������ ������� �� ��������");
		unit->reaction(field, adapter);
		arrows -= arrowscost[0] * 4;
		_intuition -= arrowscost[0];
		
	}
	else
	{
		cout << endl << "������������ �����!";
		adapter->request("���������� �������� ��������, ������������ �����");
	}
}

void Arbalester::fire_shot(Units* unit, Map* field, Adapter *adapter)
{
	if (arrows >= arrowscost[1])
	{
		cout << endl << "�������� ������.";
		adapter->request("���������� ��������� �������� ������");
		unit->health.change(-(3 + this->attack.returnAttack()));
		unit->reaction(field, adapter);
		arrows -= arrowscost[1];
		_intuition += 1;
		
	}
	else
	{
		cout << endl << "������������ �����!";
		adapter->request("���������� �������� ��������, ������������ �����");
	}
	
}

void Arbalester::reliable_shot(Adapter *adapter)
{
	if (_intuition >= arrowscost[3])
	{
		cout << endl << "���������� ������ ���� ������ � ����� �������� � ����. ���������� ����� ���������.";
		adapter->request("���������� ������ ���� ������ � ����� �������� � ����");
		this->attack.change(2);
		arrows += 5;
		_intuition -= arrowscost[3];
		
	}
	else
	{
		cout << endl << "������������ �����!";
		adapter->request("���������� �������� ��������, ������������ ��������");
	}
}

Arbalester::~Arbalester()
{
	cout << endl << "��������� ��� ���������!";
}

