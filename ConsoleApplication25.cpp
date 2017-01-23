// ConsoleApplication25.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


class printer
{
private:
	bool color;
	bool laser;
	unsigned int price;
	char model[30] = {};
public:
	void input(void)
	{
		cout << "color printer? (1 - yes, 0 - no)\n";
			cin >> color;
			cout << "laser printer? (1 - yes, 0 - no)\n";
			cin >> laser;
			cout << "model\n";
			cin >> model;
			cout << "price\n";
			cin >> price;
	}
	void output(void)
	{
		cout << "color printer (1 - yes, 0 - no) : " << color << "\n";
		cout << "laser printer (1 - yes, 0 - no) : " << laser << "\n";
		cout << "model : " << model << "\n";
		cout << "price : " << price << "\n";
	}
	printer()
	{
		color = 0;
		laser = 0;
		price = 0;
		model[0] = '/0';
	}
};

class lists {
private:
	char* information = new char(30);
	unsigned short number;
public:
	void output(void)
	{
		cout << "\ninformation : " << information;
		cout << "\nnumber : " << number;
	}
	void input(char* information2, const unsigned short number2)
	{
		information = information2;
		number = number2;
	}
	void input(const unsigned short number2)
	{
		number = number2;
	}
	~lists ()
	{ 
		delete(information); 
	}
	lists()
	{
		information = "no";
		number = 0;
	}
};

class computer
{
protected:
	char cpu_model[30];
	char gpu_model[30];
	unsigned short ram_volume;
	unsigned short hdd_volume;
	unsigned int price_computer;
	bool graphics_support(void)
	{
		if (gpu_model[0] != '/0')
		{
			return 1;
		}
		else { return 0; }
	}
	computer()
	{
		gpu_model[0] = '/0';
		cpu_model[0] = '/0';
		ram_volume = 0;
		hdd_volume = 0;
		price_computer = 0;
	}
};

class basic_configuration_computer : protected computer
{
protected:
	char monitor_model[30];
	int monitor_price;
	char keyboard_model[30];
	int keyboard_price;
	char mouse_model[30];
	int mouse_price;
	int price_basic_configuration()
	{
		return price_computer + keyboard_price + mouse_price + monitor_price;
	}
basic_configuration_computer(): computer()
{
	monitor_model[0] = '/0';
	monitor_price = 0;
	keyboard_model[0] = '/0';
	keyboard_price = 0;
	mouse_model[0] = '/0';
	mouse_price = 0;
}
};

class extended_configuration_computer : protected basic_configuration_computer
{
private:
	char printer_model[30];
	int printer_price;
	char speakers_model[30];
	int speakers_price;
	int price_extended_configuration()
	{
		return price_basic_configuration() + printer_price + speakers_price;
	}
public:
	extended_configuration_computer() : basic_configuration_computer()
	{
		printer_model[0] = '/0';
		printer_price = 0;
		speakers_model[0] = '/0';
		speakers_price = 0;
	}
};

int main(void)
{
	printer printer1;
	printer1.input();
	printer1.output();
	system("Pause");
    return 0;
}

