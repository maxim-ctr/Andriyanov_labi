﻿// Andriyanov_lab.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void printMenu() {
	cout << "\nMenu:\n";
	cout << "1. Add pipe\n";
	cout << "2. Add station\n";
	cout << "3. Output\n";
	cout << "4. Edit pipe\n";
	cout << "5. Edit station\n";
	cout << "6. Save\n";
	cout << "7. Load\n";
	cout << "0. Exit\n\n";
}


struct Pipe
{
	int id;
	int d;
};

void PrintPipe(Pipe& p)
{
  cout << "Truba " << p.id << " - diametr = " << p.d;
}

Pipe AddPipe()
{
	Pipe p;
	p.id = 0;
	cout << "Vvedite diametr\n";
	cin >> p.d;
	return p;
}

int main()
{
	Pipe p = AddPipe();
	PrintPipe(p);
}
