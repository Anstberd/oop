#pragma once
#include "Target.h"
#include "Proxy.h"

/// �������

/**
* ������ ������������ ����� ����������� � ������� �����������
*/

class Adapter : public Target
{
public:
	/// ��������� � �������� �� "Recorder" ����� "Proxy"
	Proxy* _write;
	/// ����������� ��������
	Adapter(Proxy* write);
	/// ���������������� ������� ��� ������ �������
	bool request(std::string str) override;
};