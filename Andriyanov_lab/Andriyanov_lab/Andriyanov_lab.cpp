﻿
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

bool PiExists(const Pipe& p) { //проверка существования трубы
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

	if (p.length >0) {  //!
		cout << "\nOutput Pipe(s)";
		cout << "\nId: " << p.id;
		cout << "\nDiameter: " << p.diameter;
		cout << "\nLength: " << p.length << "\n";
	}
	
	if (s.name != "") {
		cout << "\nOutput station(s)";
		cout << "\nId: " << s.id;
		cout << "\nname: " << s.name;
		cout << "\nnumber of workshops: " << s.number_of_workshops;
		cout << "\nnumber of working workshops: " << s.number_of_working_workshops;
		cout << "\nEfficiency: " << s.Efficiency << "\n";
	}
}

void Save(const Pipe& p, const Station& s) {
	ofstream file;
	file.open("database.txt");
	
	if (file.good()) {
		if (p.length > 0) {
			file << "Pipe:\n";
			file << p.id << "\n";
			file << p.diameter << "\n";
			file << p.length << "\n";
			file << p.isWorking << "\n";
		}
		if (s.name != "") {
			file << "Station:\n";
			file << s.id << "\n";
			file << s.name << "\n";
			file << s.number_of_workshops << "\n";
			file << s.number_of_working_workshops << "\n";
			file << s.Efficiency;
		}
		file.close();
		cout << "Saved\n";
	}
}

void Load(Pipe& p, Station& s) {
	ifstream file;
	file.open("database.txt");
	if (file.good()) {
		while (!file.eof()) {
			string type;
			file >> type;
			if (type == "Pipe:") {
				file >> p.id;
				file >> p.diameter;
				file >> p.length;
				file >> p.isWorking;
			}
			if (type == "Station:") {
				file >> s.id;
				file >> s.name;
				file >> s.number_of_workshops;
				file >> s.number_of_working_workshops;
				file >> s.Efficiency;
			}
		}
	}
	cout << "Loaded\n";
}




int main()
{
	Pipe p1;
	p1.length = -1;  
	Station s1;
	s1.name = "";  

	while (1) {
		printMenu();
		switch (input_integer()) {
		case 0:
			cout << "\nExit\n";
			return 0;
		case 1:
			p1 = AddPipe(0);
			break;
		case 2:
			s1 = AddStation(0);
			break;
		case 3:
			Output(p1, s1);
			break;
		case 4:
			PipeEdit(p1);
			break;
		case 5:
			StationEdit(s1);
			break;
		case 6:
			Save(p1, s1);
			break;
		case 7:
			Load(p1, s1);
			break;
		default:
			break;
		}
	}
	return 0;
}

