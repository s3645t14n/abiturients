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
	void show_loser(int);
	void show_sum_treshhold(int);
	void show_major(int);
	void show_half(int);
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

void Abiturient::show_loser(int pass_score)
{
	if (sum < pass_score) show();
}

void Abiturient::show_sum_treshhold(int score)
{
	if (sum >= score) show();
}

void Abiturient::show_major(int kolvo)
{

}

void Abiturient::show_half(int pass_score)
{
	if (sum == (pass_score / 2)) show();
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
	int n, pass_score, score, kolvo;
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
