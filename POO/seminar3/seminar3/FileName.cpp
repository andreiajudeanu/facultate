#include <iostream>
using namespace std;

int main() {
	//siruri de caractere
	//tipuri de copieri
	//matrice
	
	char s1[25];
	cout << s1;
	int x = 5;
	cout << x;
	strcpy_s(s1, strlen("Ana") + 1, "Ana");
	//strcpy_s(s1, strlen("Ana"+1), "Ana");
	
	// strlen("Ana" + 1) = strlen("na")
	//primesc eroare de executie

	char* ps;
	//cout << endl << ps; // OxCCCCC
	cout << endl << &ps;// o adresa pe stiva pt ca nu am alocat inca
	cout << endl << sizeof(ps);// 4 oct
	cout << endl << sizeof(&ps); //4 oct
	cout << endl << sizeof(ps[0]);// 1 octet
	cout << endl << s1;

	//ps = "Ana";
	ps = s1;//shallow copy // daca-l modific pe s1, ps va fi modificat, doua siruri care pointeaza catre aceeasi zona de memorie
	
	cout << endl << ps;
	cout << endl << s1;
	s1[1] = 'm';
	s1[2] = 'i';
	cout << endl << ps;
	cout << endl << s1;
	//delete[] ps; // nu se poate pt ca dezaloc o adresa de pe stiva
	ps = new char[strlen("Gigel") + 1]; //aloc o zona undde sa stochez un sir de caraactere
	strcpy_s(ps, strlen("Gigel") + 1, "Maria");
	cout << endl << ps;
	delete[] ps;

	//TEMA din siruri
	// avem o lista de prieteni, cate un prieten pe fiecare
	// linie a unei matrice
	// sa se citeasca prietenii si sa se verifice daca un anume prieten
	// este in lista 

	int m1[2][4]; //se aloca 2*4 * 4octeti pe stiva la o adresa, alocare statica
	int** m2; // (e un pointer) care ocupa 4 oct (32) sau 8 octeti pe stiva
	// se aloca zona de memorie pt m2
	m2 = new int* [2]; // cauta pe heap 8 octeti (4*[2]) aloca 2 locuri de int*
	for (int i = 0; i < 2; i++) {
		m2[i] = new int[4];
	}
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 4; j++)
			m2[i][j] = i + j + 10;

	// daca dezaloc de sus in jos nu o sa mai am acces la celelalte alocari
	for (int i = 0; i < 2; i++) {
		delete[] m2[i];
		//m2[i] = nullptr; este in plus deoarece dupa delete[] m2 oricum se sterge nullptr
	}
	delete[] m2;
	m2 = nullptr;


	return 0;
}