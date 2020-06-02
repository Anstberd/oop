#pragma once
#include "factory.h"
#include "Object.h"
#include <iostream>
#include <iomanip>
#include <string>
#include "Map.h"
#include "Units.h"
#include "Iterator.h"
#include "Neutral.h"
#include "Adapter.h"


/*!
\brief ����� ����

����� ������ ��� �������� ����, ������������� ��������, �������� � ��������������� ������.
����� � ��� �������� ���������� � ������� ��������� ���� � ������.
*/

class Bases : public Factory, public Object{
	
/*!
\brief ������������ ��������� ������

������������ �������� ���������� � ��������� ������ � �� ����������
���: 1, ��������: 2, ������: 3, ����������: 4, ������: 5, ������: 6
*/
	enum allClasses
	{
		magician = 1, healer, archer, arbalester, swordsman, spear
	};
/*!
\brief ��������� ��������� ����

�������� ���������� � �������� ��������� ���� � ������������ �� �����
*/
	struct Coordinates {
		int x, y;
	}XY;
/// ������������ ������
	string units[7] = { "test", "magician", "healer", "archer", "arbalester", "swordsman", "spear" };
/// ���������� ���������� ��������
	int _move_count; 
/// ������������ ���������� ��������
	int _move_count_max; 
/// ��������� ���������� ��������
	int _resources; 
/// ��������� �������� �����������
	int _cost_arbalester = 1; 
/// ��������� �������� �������
	int _cost_archer = 2; 
/// ��������� �������� ������
	int _cost_swordsman = 1; 
/// ��������� �������� ������
	int _cost_spear = 2; 
/// ��������� �������� ��������
	int _cost_healer = 2; 
/// ��������� �������� ����
	int _cost_magician = 3; 
protected:
/// ����������� ���� �� �����
	char name; 
/// ���������� ������� �������
	int ester;
/// ���������� HP ����
	int health; 
/// ��������� ��������� ����
	bool shild = false; 
/// ��������� ��������� �����
	bool fleet = false; 
public:
/// �������, ����������� ���������� ���������� �������� ����� ���������� ���� 
	void refresh(); 
/// �������� ������
	Iterator *iterat; 
/*!
\brief �������, ����������� ���� ������ � ������� ������
\param *adapter ������� ��� ����������� �������� ����
\return ������ ��������� ������
*/
	Units **getAllUnits(Adapter *adapter); 
/*!
\brief �������, ������������ ���� ������ � ������ �������� ����������
\return ������ ��������� ������
*/
	Units **getAllUnits(); 
/*!
\brief ������� ��������� �������� ��������� ����
\param x,y ���������� �� ��� X � ��� Y
*/
	void setLoc(int x, int y); 
/*!
\brief ������� ��������� ������������ ����
\param n ���������� ����������� �� �����
*/
	void setName(char n);
	/// ������� ��������� ����� ���� (������� �� ���������� �������)
	void setColor(int c); 
	/// ������� ��������� ���������� HP ����
	void setHealth(int h); 
	/// ������� ��������� ���������� ������� ������� 
	void setEster(int est); 
	/// ��������� ������ �� ����������� �����
	Units *getLink(int pos); 
	/// ���������� ������
	int count_units = 0; 
	/// ������ ������������ ����
	int X, Y; 
/*!
\brief ����������� ����
\param pos_x,pos_y ���������� ����
\param N,col,health,move_count ������������ ����, � ����, ���������� HP � ������������ ���������� �������� �� ���
\param *adapter ������� ��� ����������� �������� ����

� ������������ ���������� ������������� ������ ��������� ����. ���������� ������������� ��������

*/
	Bases(int pos_x, int pos_y, char N, int col, int health, int res, int move_count, Adapter *adapter);  
/// ������� ������������ ������
	void production(int select, Map *field, Creating *neutral, Adapter *adapter); 
/// ������� ������������� ��������� ��������
	void initialization(int resources, Adapter *adapter); 
/// ���������������� ������� �������� �������
	Swordsman* createSwordsman(Map *field, Creating *neutral, Adapter *adapter, int x = 0, int y = 0) override; 
/// ���������������� ������� �������� ������
	Spear* createSpear(Map *field, Creating *neutral, Adapter *adapter, int x = 0, int y = 0) override; 
/// ���������������� ������� �������� ����
	Magician* createMagician(Map *field, Creating *neutral, Adapter *adapter, int x = 0, int y = 0) override; 
/// ���������������� ������� �������� ��������
	Healer* createHealer(Map *field, Creating *neutral, Adapter *adapter, int x = 0, int y = 0) override; 
/// ���������������� ������� �������� �������
	Archer* createArcher(Map *field, Creating *neutral, Adapter *adapter, int x = 0, int y = 0) override;
/// ���������������� ������� �������� �����������
	Arbalester* createArbalester(Map *field, Creating *neutral, Adapter *adapter, int x = 0, int y = 0) override; 
/// ������� ����������� ���� ������ 
	bool showAllUnits(Adapter *adapter); 
/// ������� ����������� ���������� ����������� ����
	void functional(Map* field, Creating *neutral, Adapter *adapter); 
/// ������� ������ �����
	int selectUnit(Map* field, Adapter *adapter); 
/// �������, ������������ ���������� �������� ����
	void showResour(Adapter *adapter); 
/// �������, ������������ ��������� ���� � ������� ������ 
	void showState(Adapter *adapter); 
/// ������� ��������� ������� ������� � ������� ������ 
	int getEster(Adapter *adapter); 
/// ������� ��������� ���������� HP ���� � ������� ������ 
	int getHealth(Adapter *adapter); 
/// ������� ��������� ��������� ���� � ������� ������ 
	bool getShild(Adapter *adapter); 
/// ������� ��������� ������� ������� � ������ �������� ����������
	int getEster(); 
/// ������� ��������� HP � ������ �������� ����������
	int getHealth(); 
/// ������� ��������� ��������� ���� � ������ �������� ����������
	bool getShild(); 
/// ������� ��������� ����
	Bases* getBase();
/// ������� ��������� ����
	void activateShild(Adapter *adapter); 
/// ������� ������ ������
	void skills(Adapter *adapter); 
/// ��������� ��������� ������
	struct List { 
		int count_unit[3] = { 0 , 0 , 0 };
		int count_warlock[3] = { 0 , 0 , 0 };
		int count_archer[3] = { 0 , 0 , 0 };
		int count_warrior[3] = { 0 , 0 , 0 };
	}list; 
/// ���������� ����
	~Bases() {} 
};

