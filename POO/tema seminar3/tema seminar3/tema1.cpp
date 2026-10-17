//TEMA din siruri
	// avem o lista de prieteni, cate un prieten pe fiecare
	// linie a unei matrice
	// sa se citeasca prietenii si sa se verifice daca un anume prieten
	// este in lista 
#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;

void citire(char **& prieteni, int n){
	char buffer[21];
	prieteni = new char* [n];
	for (int i = 0; i < n; i++) {
		cin.getline(buffer, 21);
		prieteni[i] = new char[strlen(buffer) + 1];
		strcpy_s(prieteni[i], strlen(buffer) + 1, buffer);
	}
}

void dezalocare(int n, char**& prieteni) {
	for (int i = 0; i < n; i++) {
		delete[] prieteni[i];
	}
	delete[] prieteni;
	prieteni = nullptr;
}

int cautare(int n, char** prieteni, char prieten[21]) {
	int gasit = 0;
	for (int i = 0; i < n; i++) {
		if (strcmp(prieteni[i], prieten) == 0) {
			gasit = 1;
			break;
		}
	}
	return gasit;
}

int main() {
	char** prieteni = nullptr;
	int n;
	cin >> n; cin.ignore();
	citire(prieteni, n);

	cout << "Introduceti prietenul :";
	char prieten[21];
	cin.getline(prieten, 21);

	if (cautare(n, prieteni, prieten) == 1) cout << "Prietenul se afla in lista.";
	else cout << "Prietenul NU se afla in lista.";
	dezalocare(n, prieteni);
}

/*int main() {
	char buffer[21];
	int n;
	cin >> n; //nr prieteni
	cin.ignore(); //pentru a nu citi \n din cin>>n;
	char** prieteni;
	prieteni = new char* [n];
	for (int i = 0; i < n; i++) {
		cin.getline(buffer, 21);
		prieteni[i] = new char[strlen(buffer) + 1];
		strcpy_s(prieteni[i],strlen(buffer)+1, buffer);
	}
	cout << "Introduceti prietenul :";
	char prieten[20];
	cin.getline(prieten, 20);

	int gasit = 0;
	for (int i = 0; i < n; i++) {
		if (strcmp(prieteni[i], prieten) ==  0){
			gasit = 1;
			break;
		}
	}
	if (gasit) cout << "Prietenul se afla in lista.";
	else cout << "Prietenul NU se afla in lista.";

	for (int i = 0; i < n; i++) {
		delete [] prieteni[i];
	}
	delete[] prieteni;
	prieteni = nullptr;

	return 0;
}
*/

//TEMA 2
/*
struct student{
	char nume[25]
	//adaugati o enumeratie
	int varsta
	//alte campuri
	// vector de note + cate note
}
i) functie care citeste un student
ii) functie care afiseaza un student

*/