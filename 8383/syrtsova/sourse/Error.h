#pragma once
#include <exception>

using namespace std;
/// ����� ����������� ������ ���� "������������ ������"
class error1 : public exception {//������������ ������
public:     explicit error1(char a) { this->a = a; }
			virtual const char* what() const throw()
			{
				return "������������ ����.\n";
			}
			void printErr()
			{
				cout << "������ \"" << a << "\" �� �����.\n";
			}
private:     char a;
};

/// ����� ����������� ������ ���� "������������ �����"
class error2 : public exception {//������������ ������
public:     explicit error2(char a) { this->a = a; }
			virtual const char* what() const throw()
			{
				return "������������ ����.\n";
			}
			void printErr()
			{
				cout << "����� \"" << a << "\" ��� � ���� ������.\n";
			}
private:     char a;
};