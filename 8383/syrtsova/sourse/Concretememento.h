#pragma once
#include "Memento.h"

/// ����� ����������� ������

/**
* ���������� ������ �������� �������������� ��� �������� ��������� ���������
*/
class ConcreteMemento : public Memento
{
private:
	std::string& fout;

public:
	ConcreteMemento(std::string& fout);
	std::string& state() const override {
		return fout;
	}
};