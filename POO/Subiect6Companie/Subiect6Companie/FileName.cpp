#include <iostream>
#include <string>

using namespace std;

class Companie {
	string denumireCompanie = "-";
	int nrAngajati = 0;
	float* salariuLunar = nullptr;
	float salariuMinim = 0;
	float fondTotalSalarii = 0;
	double cifraAfaceri = 0;
public:
	Companie(string _denumireCompanie, int _nrAngajati, float* _salariuLunar, float _salariuMinim, float _fondTotalSalarii,
		double _cifraAfaceri) {
		this->denumireCompanie = _denumireCompanie;
		this->salariuMinim = _salariuMinim;
		this->fondTotalSalarii = _fondTotalSalarii;
		if (_nrAngajati > 0 && _salariuLunar != nullptr) {
			float suma = 0;
			this->salariuLunar = new float[_nrAngajati];
			for (int i = 0; i < _nrAngajati; i++) {
				if (_salariuLunar[i] < this->salariuMinim) {
					_salariuLunar[i] = this->salariuMinim;
				}
				if (suma + _salariuLunar[i] < this->fondTotalSalarii) {
					this->salariuLunar[this->nrAngajati] = _salariuLunar[i];
					suma += _salariuLunar[i];
					this->nrAngajati++;
				}
				else {
					break;
				}
			}
		}
	}
	void afisare() {
		cout << "Companie: " << this->denumireCompanie
			<< " | Nr. ang: " << this->nrAngajati
			<< " | Salariu Min.: " << this->salariuMinim
			<< " | Fond: " << this->fondTotalSalarii;
		cout << " | Salarii Lunare: ";
		for (int i = 0; i < this->nrAngajati; i++) {
			cout << this->salariuLunar[i] << " ";
		}
	}
	int nrMaximAngajati() {
		float suma = 0;
		for (int i = 0; i < this->nrAngajati; i++) {
			suma += this->salariuLunar[i];
		}
		float fondDisponibi = this->fondTotalSalarii - suma;
		return (int)fondDisponibi / this->salariuMinim;
	}
	int getSalariuMinim() {
		return this->salariuMinim;
	}


};
void stergereAngSalariuMinim(float* salarii, int& nrAngajati, float minim) {
	int j = 0;
	for (int i = 0; i < nrAngajati; i++) {
		if (salarii[i] > minim) {
			salarii[j] = salarii[i];
			j++;
		}
	}
	nrAngajati = j;
}

void stergere() {
	
}


int main() {
	float salarii[] = { 2500, 4500, 3000, 6000 };
	Companie c1("Firma", 4, salarii, 3000, 20000, 500000);
	c1.afisare();
	cout << "\n" << c1.nrMaximAngajati();

	int nrAngajati = 4;
	stergereAngSalariuMinim(salarii, nrAngajati, c1.getSalariuMinim());

	cout << "\nAngajati ramasi: " << nrAngajati << " | Salarii: ";
	for (int i = 0; i < nrAngajati; i++) {
		cout << salarii[i] << ' ';
	}
	cout << '\n';
}