#pragma once
/// ����� ��������
class Health
{
	int _health;
	int _max_health;
public:
	Health();
	void change(int shift);
	void setAtrib(int h);
	Health(int h);
	int returnHealth();
	~Health();
};

/// ����� �����
class Armor
{
	int _armor;
public:
	Armor();
	void setAtrib(int a);
	void change(int shift);
	Armor(int a);
	int returnArmor();
	~Armor();
};
/// ����� ������
class Attack
{
	int _attack;
public:
	Attack();
	void setAtrib(int a);
	void change(int shift);
	Attack(int a);
	int returnAttack();
	~Attack();
};

/// ����� ������� ������������
class Radius {
	int _radius;
	int _radius_max;
public:
	Radius();
	void setAtrib(int rh);
	void refresh();
	int getRadius();
	void change(int shift);
	Radius(int r);
	int returnRadius();
	~Radius();
};

/// ����� ������������ �������
class SpecialResources
{
	int _special_1 = 0;
	int _special_2 = 0;
public:
	void setAtrib(int &sp);
	void changeSp1(int sp);
	void changeSp2(int sp);
	int returnSp1();
	int returnSp2();
};

/// ����� ������������
class Name {
	char _name;
public:
	Name();
	void setAtrib(int n);
	void change(int shift);
	Name(char n);
	char returnName();
	~Name();
};