#pragma once
#include "Originator.h"
/// ����� ������

/**
* ������ �� ������� �� ������ ����������� ������. ����� �������, �� �� ����� ������� � ��������� ���������, ����������� ������ ������. 
* �� �������� �� ����� �������� ����� ������� ��������� ������
*/

class Caretaker {
private:
	///��������� ������
	Memento* memento = nullptr;
	///����������� ������ � ������ ������
	Originator *_originator;

public:
	///����������� �������
	Caretaker(Originator *originator);
	///������� ������ �������� ��������� 
	void backup(Game<Rules>* game, bool& isUnitSelected, bool& logToFile, bool& logToTerminal, bool& withoutLog, Units* selectedUnit, int& currNumBase);
	///������� �������������� ������� ������
	void undo(Game<Rules>* game, bool& isUnitSelected, bool& logToFile, bool& logToTerminal, bool& withoutLog, int& currNumBase);
};
