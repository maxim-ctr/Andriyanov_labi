// Andriyanov_lab.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
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

