#pragma once
#include "pch.h"
#include "Object.h"
//#include "Units.h"
#include <iostream>
#define MAX 4000

using namespace std;

class Map {
private:
	int  width;   //������� ����
	int  height;   //������� ����
	int  count_object;//���������� ��������
	int  mas_x[MAX];  //������ ��������� x ��������� �� ����
	int  mas_y[MAX];  //������ ��������� y ��������� �� ����
public:
	Object ***field;    //���� ����
	Map(int x, int y); //�����������
	Map() :Map(20, 20) {};
	bool isObject(int x, int y);
	Map(const Map & map); //����������� ����������� ����
	Map &operator=(const Map &map);//�������� ��� ������������ �����������
	// ����������� �����������,
	// ������� ������� ����� ������������� �� map.field � field
	Map(Map&& map);
	// �������� ������������ ������������,
	// ������� ������� ����� ������������� �� map.field � field
	Map& operator=(Map&& map);
	void print_map();//������� ����
	void add_on_map(int x, int y, Object* object);//��������� ������
	void remove_from_map(int x, int y);//������� � ���� ������
	int isLandscape(int x, int y);
	int isNeutral(int x, int y);
	bool isUnit(int x, int y);
	bool isBase(int x, int y);
	~Map();
};