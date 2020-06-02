#pragma once
#include "Classes.h"

/// ����� �������
class Archer : public Classe_archer
{
	int _luck;
public:
	string nameSkill[4] = { "�������", "���������� ������", "������� � ������", "������� �������" };
	int  arrowscost[4] = { 10, 2, 3, 5 };
	void hail_of_arrows(Map* field, Units **link, Adapter *adapter);
	void double_shot(Units* unit, Map* field, Adapter *adapter);
	void poison_arrow(Units* unit, Map* field, Adapter *adapter);
	void showSkills(Adapter *adapter)  override;
	void selectSkill(int ch, Map* field, Units **link, Adapter *adapter, bool sLine = false) override;
	Archer(int &x, int &y);
	~Archer();
};

/// ����� �����������
class Arbalester : public Classe_archer
{
	int _intuition;
public:
	string nameSkill[4] = { "�������� ����", "�������� ������", "������� � ������", "�������" };
	int arrowscost[4] = { 5, 2, 3, 4 };
	void reliable_shot(Adapter *adapter);
	void crossbow_shot(Units* unit, Map* field, Adapter *adapter);
	void fire_shot(Units* unit, Map* field, Adapter *adapter);
	void showSkills(Adapter *adapter) override;
	void selectSkill(int ch, Map* field, Units **link, Adapter *adapter, bool sLine = false) override;
	Arbalester(int &x, int &y);
	~Arbalester();
};





