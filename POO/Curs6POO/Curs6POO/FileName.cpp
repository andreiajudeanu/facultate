#include <iostream>
#include <string>

using namespace std;

//const si static
// functii globale


class Proiect {
	const int id;
	string denumire ="-";
	int nrEtape = 0;
	float* bugetEtape = nullptr;
	static string numeCompanie;

public:
	//constructor default 
	Proiect() :id(0), denumire("") {

	}

	Proiect(int _id, string _denumire, int _nrEtape, float* _bugetEtape):id(_id) {
		this->denumire = _denumire;
		if (_nrEtape > 0 && _bugetEtape != nullptr) {
			this->nrEtape = _nrEtape;
			this->bugetEtape = new float[this->nrEtape];

			for (int i = 0; i < this->nrEtape; i++) {
				this->bugetEtape[i] = _bugetEtape[i];
			}
		}
	}
	void afisare() {
		cout << "\nId: " << this->id;
		cout << "\nDenumire: " << this->denumire;
		cout << "\nNr etape: " << this->nrEtape;
		cout << "\nBuget Etape: ";
		for (int i = 0; i < this->nrEtape; i++) {
			cout << this->bugetEtape[i] << " ";
		}
	}
	//const in metoda protejeaza pe this
	static string getNumeCompanie() {
		return Proiect::numeCompanie;
	}
	//metoda statica nu are this pt ca nu este a obiectului
	static void setNumeCompanie(string _numeCompanie) {
		Proiect::numeCompanie = _numeCompanie;
	}

	float getTotalBuget() const {
		float total = 0;
		for (int i = 0; i < this->nrEtape; i++) {
			total += this->bugetEtape[i];
		}
		return total;
	}
	string getDenumire() const{
		return this->denumire;
	}
};

//p -> afiasre(); = (&p).afisare();

string getDenumireProiectBugetMaxim(Proiect v[], int n) {
	float bugetMax = 0;
	string denumireMax;
	for (int i = 0; i < n; i++) {
		if (v[i].getTotalBuget() > bugetMax) {
			bugetMax = v[i].getTotalBuget();
			denumireMax = v[i].getDenumire();
		}
	}
	return "";
}

//declarare variabila globala de tip static in clasa
string Proiect::numeCompanie = "ABC";



int main() {
	float* bugete = new float[5];
	for (int i = 0; i < 5; i++) {
		bugete[i] = 1000 + i * 100;
	}
	Proiect p1(1, "Proiect", 5, bugete);
	p1.afisare();
	delete[] bugete;
	p1.afisare();

	cout << endl;
	cout << Proiect::getNumeCompanie(); // al clasei nu ma duc in p1.getnumecompanie ca sa gasesc numele
	//pt ca este tot static 
	cout << endl << getDenumireProiectBugetMaxim(nullptr, 0);
	return 0;
}