#pragma once
#include "iostream"

/// ����� ������

/**
* ��������� ������ ������������ ������ ���������� ���������� �����. ������ �� �� ����������� ��������� ���������
*/
class Memento {
public:
	virtual std::string& state() const = 0;
};