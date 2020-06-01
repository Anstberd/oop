//#include <SFML/Graphics.hpp>


#include "Handler.h" //for lab 3


#include "Base.h"
#include "ArmyFactory.h "   //for lab 2
#include "Object.h" 
#include "landscapeMapExample.h"



//���������� ������ ���������
void example1() {

	PlayingField field1(10, 10); //�� ��������� �������� ���������
	field1.setLandscape(mapExample_10x10); // ������������ �������

	Base* base = new Base(10, &field1, 1,2,true); // ��������� ���� ������� ����� �������� ����������� 10 ������
	if (!base->isAlive()) {
		delete base;
		return;
	}

	std::cout << "Field 1:\n"; field1.showConsoleField();	std::cout << "\n";
	std::cout << "Landscape 1:\n"; field1.showConsoleLandscape();	std::cout << "\n";
	
	//������� ����� �������� �����
	std::cout << "Create unit with existing flyweight\n";
	base->createUnit_("W_t", "red",1, 1); //�� � ������������ ���� ��� ��� ������ �������� � ���������� �������� �����, �� �� �� ��������� ��������
	std::cout << "Field 1:\n"; field1.showConsoleField();	std::cout << "\n";
	std::cout << "Create unit with new flyweight\n";
	base->createUnit_("B_d", "pink", 2, 2);//� ������ ������ ��������� ����� ��������
	std::cout << "Field 1:\n"; field1.showConsoleField();	std::cout << "\n";
	std::cout << "Create unit with previous flyweight\n";
	base->createUnit_("S_d", "pink",2, 5);//� ������ ������ ����� ����������� ���������� ��������
	std::cout << "Field 1:\n"; field1.showConsoleField();	std::cout << "\n";

	std::cout << " END\n";
}


//������ ������ ���������� ������ �������� ��������� � ��� ���� ������������ ���������� ������
void example2() {
	PlayingField field(10, 10); //�� ��������� �������� ���������
	field.setLandscape(mapExample_10x10); // ������������ �������

	Base* base = new Base(3, &field, 1, 2); // ��������� ���� ������� ����� ������� �������� 3 �����
	if (!base->isAlive()) {
		delete base;
		return;
	}
	std::cout << "Creating 4 unit, but base has a limit of 4\n";

	Unit* wt0 = base->createUnit_("W_t", "red",  1, 1);
	Unit* wt1 = base->createUnit_("W_t", "red", 1, 2);
	Unit* wd0 = base->createUnit_("W_d", "red", 1, 3);
	std::cout << "Cant create last unit\n";
	Unit* wd1 = base->createUnit_("W_d", "yellow", 1, 4); //4 ����� ���� ������� �� �����

	HealBooster* hb = new HealBooster(); //������� ������� � �������� �� ����

	field.addObject(hb, 3, 3);

	std::cout << "Field 1:\n"; field.showConsoleField();	std::cout << "\n";


	//������������ ������ �������� ���������

	std::cout << "Use heal boost on tank\n";
	*wt0 += hb; //������ ��������� ���� ������� ���������� 50 �� 
	//std::cout << "Field 1:\n"; field.showConsoleField();	std::cout << "\n";
	std::cout << "\n";
	std::cout << "Use heal boost on damager\n";
	*wd0 += hb;//������ ��������� ���� ������� ���������� 30 �� 
}

//������ ������ ���������� ������ �������� ������ � ��� ���� ��������� �� ������ �����
void example3() {
	PlayingField field(10, 10); //�� ��������� �������� ���������
	field.setLandscape(mapExample_10x10); // ������������ �������
	//PlayingField field1(10, 12);
	//field = field1;
	Base* base1 = new Base(3, &field, 1, 100); // ��������� ���� �� ������������ �����������
	if (!base1->isAlive()) {
		delete base1;
	}

	Base* base = new Base(3, &field, 0, 5);
	if (!base->isAlive()) {
		delete base;
		return;
	}
	std::cout << "\nInteraction of the unit with the landscape:\n";

	Unit* wt = base->createUnit_("W_t", "red",3, 6);

	std::cout << "Field 1:\n"; field.showConsoleField();	std::cout << "\n";

	std::cout << "Landscape 1:\n"; field.showConsoleLandscape();	std::cout << "\n";
	

}



void eventLoop() {
	unsigned clientCommand_;
	unsigned row;
	unsigned col;
	unsigned rowTo;
	unsigned colTo;
	unsigned maxUnits;
	std::string unitType;
	std::string color;
	std::string command;
	GameFacade* facade = new GameFacade();
	StartGame* chain = new StartGame(facade);
	chain->setNext(new AddUnit(facade))->setNext(new MoveUnit(facade))->
		setNext(new Attack(facade))->setNext(new GetInfo(facade))->setNext(new Heal(facade));

	ClientInput* input = new ClientInput();
	input->setStart(10, 10, 20);
	chain->handle(input);

	input->setAddUnit(7, 7, "W_t","blue");
	chain->handle(input);

	input->setAddUnit(7, 1, "W_t", "blue");
	chain->handle(input);
	bool curPlayer = true;

	while(facade->isPlayerAlive()){
		std::cout << "Enter command:\n";
		std::cin >> command;
		if (command == "move") {
			std::cout << "Enter first coords:\n";
			std::cin >> row >> col;
			std::cout << "Enter second coords:\n";
			std::cin >> rowTo >> colTo;
			input->setMove(row, col, rowTo, colTo);
		}
		else if (command == "attack") {
			std::cout << "Enter first coords:\n";
			std::cin >> row >> col;
			std::cout << "Enter second coords:\n";
			std::cin >> rowTo >> colTo;
			input->setAttack(row, col, rowTo, colTo);
		}
		else if (command == "add") {
			std::cout << "Enter coords:\n";
			std::cin >> row >> col;
			std::cout << "Enter unit type:\n";
			std::cin >> unitType;
			std::cout << "Enter unit color:\n";
			std::cin >> color;
			input->setAddUnit(row, col, unitType, color);
		}
		else if (command == "heal") {
			std::cout << "Enter coords:\n";
			std::cin >> row >> col;
			std::cout << "Enter second coords:\n";
			std::cin >> rowTo >> colTo;
			input->setHeal(row, col, rowTo, colTo);
		}
		else if (command == "info") {
			std::cout << "Enter coords:\n";
			std::cin >> row >> col;
			input->setGetInfo(row, col);
		}
		else if (command == "pass") {

			facade->switchPlayer();
			continue;
		}
		else if (command == "exit") {
			break;
		}
		else continue;
		chain->handle(input);
	}
}

void example_3_1() {

	GameFacade* facade = new GameFacade();

	StartGame* chain = new StartGame(facade);
	chain->setNext(new AddUnit(facade))->setNext(new MoveUnit(facade))->
		setNext(new Attack(facade))->setNext(new GetInfo(facade))->setNext(new Heal(facade));

	ClientInput* input = new ClientInput();
	input->setStart(10, 10, 20);
	chain->handle(input);

	input->setAddUnit(1, 1, "W_t", "white");
	chain->handle(input);

	input->setAddUnit(7, 7, "W_t", "red");
	chain->handle(input);

	input->setGetInfo(4, 4);
	chain->handle(input);

	input->setGetInfo(0, 0);
	chain->handle(input);

	input->setAttack(1, 1, 9, 9);
	chain->handle(input);

	input->setGetInfo(9, 9);
	chain->handle(input);
}

void example_3_2() {

	GameFacade* facade = new GameFacade();

	StartGame* chain = new StartGame(facade);
	chain->setNext(new AddUnit(facade))->setNext(new MoveUnit(facade))->
		setNext(new Attack(facade))->setNext(new GetInfo(facade))->setNext(new Heal(facade));

	ClientInput* input = new ClientInput();
	input->setStart(5, 7, 20);
	chain->handle(input);

	input->setAddUnit(1, 1, "W_t", "white");
	chain->handle(input);

	input->setAddUnit(7, 7, "W_t", "red");
	chain->handle(input);

	input->setGetInfo(4, 4);
	chain->handle(input);

	input->setGetInfo(0, 0);
	chain->handle(input);

	input->setAttack(1, 1, 9, 9);
	chain->handle(input);

	input->setGetInfo(9, 9);
	chain->handle(input);
}

int main() {

	//example1();
	//example2();
	//example3();

	//example_3_1();
	//example_3_2();
	eventLoop();
	return 0;
}

