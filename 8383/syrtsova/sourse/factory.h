#include "Warrior.h"
#include "Warlock.h"
#include "Archer.h"
#include "Map.h"
#include "Neutral.h"
#include "Adapter.h"

/// ����������� ������� ��� ������������ 
/**
* ����������� ����� �������� ����������� ������� �������� ������.
*/
class Factory
{
public:
	/// ����������� ������� �������� �������
	virtual Swordsman* createSwordsman(Map* field, Creating *neutral, Adapter *adapter, int x = 0, int = 0) = 0;
	/// ����������� ������� �������� �������
	virtual Spear* createSpear(Map* field, Creating *neutral, Adapter *adapter�, int x = 0, int  = 0) = 0;
	/// ����������� ������� �������� �������
	virtual Magician* createMagician(Map* field, Creating *neutral, Adapter *adapter�, int x, int y) = 0;
	/// ����������� ������� �������� �������
	virtual Healer* createHealer(Map* field, Creating *neutral, Adapter *adapter, int x, int y) = 0;
	/// ����������� ������� �������� �������
	virtual Archer* createArcher(Map* field, Creating *neutral, Adapter *adapter, int x, int y) = 0;
	/// ����������� ������� �������� �������
	virtual Arbalester* createArbalester(Map* field, Creating *neutral, Adapter *adapter, int x, int y) = 0;
};
