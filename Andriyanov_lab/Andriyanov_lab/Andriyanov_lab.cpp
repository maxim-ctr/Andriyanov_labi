// Andriyanov_lab.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

int input_integer() {
	string str;
	cin.ignore();
	cin >> str;
	if (str.find_first_not_of("0123456789") != string::npos) {
		cout << "Wrong input\n";
		cout << "Try again: \n";
	}
	else {
		return stoi(str);
	}
	return -1;
}

double input_double() {
	string str;
	cin.ignore();
	cin >> str;
	if (str.find_first_not_of("0123456789.") != string::npos || str.length() == count(str.begin(), str.end(), '.')) {
		cout << "Wrong input\n";
		cout << "Try again: \n";
	}
	else {
		return stod(str);
	}
	return -1;
}



struct Pipe
{
	int id = 0;
	int diameter;
	double length;
	bool isWorking = true;
};

bool PiExists(const Pipe& p) {
	return p.id != -1;
}


Pipe AddPipe(int id)
{
	cout << "Adding Pipe\n";
	Pipe p;

	cout << "Input diameter:\n";
	p.diameter = 0;
	while (p.diameter <= 0) {
		p.diameter = input_integer();
	}

	cout << "Input length:\n";
	p.length = 0;
	while (p.length <= 0) {
		p.length = input_double();
	}
	return p;
}

void PipeEdit(Pipe& p) {
	// if (array_of_pipes != 0) {}
	if (PiExists(p)) {
		p.isWorking = !p.isWorking;
		cout << "Pipe edited\n";
		cout << "Is pipe working? " << p.isWorking << "\n";
	}
	else {
		cout << "\nNo pipes\n";
	}
}



int main()
{
	
}

