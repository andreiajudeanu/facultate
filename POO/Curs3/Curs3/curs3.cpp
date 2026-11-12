#include <iostream>
#include <cstring>
using namespace std;

// TO DO 
// de implementat mecanisme pt ca utilizatorul sa scrie textul ROSU iar la afisare 
// sa se afiseze testul rosu, nu codificarea numerica din spate

enum culoare {
	ROSU, VERDE, ALBASTRU, GALBEN
};

struct Masina{
	char* model;
	int anFabricatie;
};




int main() {
	Masina m1;
	m1.model = new char[strlen("Opel") + 1];
	strcpy_s(m1.model, strlen("Opel") + 1, "Opel");
	m1.anFabricatie = 2010;

}