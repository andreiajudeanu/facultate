#include <iostream>
#include <cstring>

using namespace std;

const char* numeProfil[] = {"Mate-Info", "Stiinte ale naturii", "Stiinte Sociale"};

struct Student {
	char *nume; //numele il aloc dinamic pt fiecare litera in parte avem un octet
	enum Profil {
		MATE_INFO,
		STIINTE_ALE_NATURII,
		STIINTE_SOCIALE,
	};//as fi putut declara aici profil
	int varsta;
	int nrNote;
	int* note;// alocam dinamic notele deoarece avem mai multe
	Profil profil; 
};
//i) functie care citeste un student
void citire(Student& s) {
	char buffer[21]; // ne folosim de buffer pentru a aloca exact cat trebuie pentru un nume
	cin.ignore();// deoarece dupa ce introducem cin>>n ia si spatiul si nu pot introduce numele ma da direct la varsta
	cout << "Nume: ";
	cin.getline(buffer, 21);
	s.nume = new char [strlen(buffer) + 1];//dupa ce am introdus numele, ii numar literele si aloc dinamic cu +1 pt \0
	strcpy_s(s.nume, strlen(buffer) + 1, buffer);//copiem bufferul in nume
	cout << "Varsta: ";
	cin >> s.varsta;
	
	cout << "Numar note:";
	cin >> s.nrNote;
	s.note = new int [s.nrNote];// aloc dinamic notele
	for (int i = 0; i < s.nrNote; i++) {
		cout << "Nota " << i + 1<<": ";
		cin >> s.note[i];
	}

	int p;
	cout << "Profil (0 - Matematica-Informatica, 1 - Stiinte ale naturii, 2 - Stiinte sociale): ";
	cin >> p;
	s.profil = (Student::Profil)p;	// s.profil = 1 (nu ar fi mers deoarece s.profil este de tip enum, iar 1 este int)
}
//ii) functie care afiseaza un student
void afisare(Student s) {
	cout << "Nume: " << s.nume << endl;
	cout << "Varsta: " << s.varsta << endl;
	cout << "Note: ";
	for (int i = 0; i < s.nrNote; i++) {
		cout << s.note[i]<<" ";
	}
	cout << endl;
	cout << "Profil: " << numeProfil[s.profil] << endl;
}
void dezalocare(Student s) {
	delete[] s.nume;
	delete[] s.note;
	s.nume = nullptr;
	s.note = nullptr;
}
int main() {
	int n;
	cin >> n;
	Student* studenti = new Student[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Studentul: " << i + 1 << ":\n";
		citire(studenti[i]);
	}
	cout << "Lista de studenti: " << endl;
	for (int i = 0; i < n; i++) {
		afisare(studenti[i]);
		cout << endl;
	}
	delete[] studenti;
	studenti = nullptr;
	return 0;
}