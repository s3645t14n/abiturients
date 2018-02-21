#include <conio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <windows.h>

using namespace std;

//======= class Abiturient =================
class Abiturient {
	string name, address; //private
	int math, phys, rus, sum;
public:
	Abiturient();
	void show();
	void read(fstream &file);
};

Abiturient::Abiturient()
{
	name = "0";
	address = "0";
	math = 0;
	phys = 0;
	rus = 0;
	sum = math + phys + rus;
}

void Abiturient::show()
{
	cout << "Name :" << name << endl;
	cout << "Address :" << address << endl;
	cout << "Math :" << math << endl;
	cout << "Phys :" << phys << endl;
	cout << "Rus :" << rus << endl;
	cout << "Sum :" << sum << endl;
}

void Abiturient::read(fstream &file)
{
	getline(file, name);
	getline(file, address);
	file >> math;
	file >> phys;
	file >> rus;
	sum = math + rus + phys;
}

//========= main ===============
void main()
{
	setlocale(LC_ALL, "russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	fstream ifs;
	ifs.open("file.txt", ios::in);
	Abiturient *spis;
	int n;
	ifs >> n;
	spis = new Abiturient[n];
	
	for (int i = 0; i<n; i++) {
		spis[i].read(ifs);
	}

	for (int i = 0; i<n; i++) {
		cout << "==============================" << endl;
		spis[i].show();
	}
	
	delete[] spis;
	cout << "Нажмите любую клавишу!";
	while (!_kbhit());
}
