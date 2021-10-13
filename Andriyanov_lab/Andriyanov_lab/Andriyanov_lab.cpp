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

struct Station {
	int id = 0;
	string name;
	int number_of_workshops;
	int number_of_working_workshops;
	int Efficiency;
};

bool StExists(const Station& s)
{
	return s.id != -1;;
}

Station AddStation(int id) {
	cout << "Adding Station\n";
	Station s;

	cout << "Input name:\n";
	cin >> s.name;

	cout << "Input number of workshops:\n";
	s.number_of_workshops = 0;
	while (s.number_of_workshops <= 0) {
		s.number_of_workshops = input_integer();
	}

	cout << "Input number of working workshops:\n";
	s.number_of_working_workshops = -1;
	while (s.number_of_working_workshops < 0 || s.number_of_working_workshops > s.number_of_workshops) {
		s.number_of_working_workshops = input_integer();
		if (s.number_of_working_workshops > s.number_of_workshops) {
			cout << "Wrong input\n";
			cout << "Try again:\n";
		}
	}

	cout << "Input Efficiency (0 < e <= 100):\n";
	s.Efficiency = 0;
	while (s.Efficiency <= 0 || s.Efficiency > 100) {
		s.Efficiency = input_integer();
	}
	return s;
}

void StationEdit(Station& s) {
	// if (array_of_stations != 0){}
	if (StExists(s)) {
		cout << "Editing station\n";
		cout << "Input number of working workshops:\n";
		s.number_of_working_workshops = -1;
		while (s.number_of_working_workshops < 0 || s.number_of_working_workshops > s.number_of_workshops) {
			s.number_of_working_workshops = input_integer();
			if (s.number_of_working_workshops > s.number_of_workshops) {
				cout << "Wrong input\n";
				cout << "Try again:\n";
			}
		}
	}
	else {
		cout << "\nNo stations\n";
	}
}

void Output(const Pipe& p, const Station& s)
{
	cout << "\nOutput\n";
	// if (vector_of_Pipes.length != 0
	if (p.length > 0) {
		cout << "\nOutput Pipe(s)";
		cout << "\nId: " << p.id;
		cout << "\nDiameter: " << p.diameter;
		cout << "\nLength: " << p.length << "\n";
	}
	// if (vector_of_Station.length != 0){}
	if (s.name != "") {
		cout << "\nOutput station(s)";
		cout << "\nId: " << s.id;
		cout << "\nname: " << s.name;
		cout << "\nnumber of workshops: " << s.number_of_workshops;
		cout << "\nnumber of working workshops: " << s.number_of_working_workshops;
		cout << "\nEfficiency: " << s.Efficiency << "\n";
	}
}



int main()
{
	
}

