#include <iostream>
#include <string>

using namespace std;

class Student {
	string nume = "-";
	const int nrMatricol = 0;
	int nrDiscipline = 0;
	int* note = nullptr;
	bool areBursa = false;
public:
	Student(string _nume, int _nrMatricol, int _nrDiscipline, int* _note, bool _areBursa) :nrMatricol(_nrMatricol) {
		this->nume = _nume;
		this->areBursa = _areBursa;
		if (_nrDiscipline > 0 && _note != nullptr) {
			this->nrDiscipline = _nrDiscipline;
			this->note = new int[this->nrDiscipline];
			for (int i = 0; i < this->nrDiscipline; i++) {
				if (1 <= _note[i] && _note[i] <= 10) {
					this->note[i] = _note[i];
				}
				else if (_note[i] < 1) {
					this->note[i] = 1;
				}
				else if (_note[i] > 10) {
					this->note[i] = 10;
				}
			}
		}
	}
	void afisare() {
		int x = 0;
		int y = 0;
		int z = 0;

		for (int i = 0; i < this->nrDiscipline; i++) {
			if (this->note[i] < 5) x++;
			else if (this->note[i] >= 5 && this->note[i] <= 7) {
				y++;
			}
			else if (this->note[i] >= 8 && this->note[i] <= 10) {
				z++;
			}
		}
		cout << "Nume: " << this->nume
			<< " | Nr matricol: " << this->nrMatricol
			<< " | Nr discipline: " << this->nrDiscipline
			<< " | Bursa: " << (this->areBursa==1 ? "Da" : "Nu");
		cout << " | Restante: " << x << " | 5-7: " << y << " | 8-10: " << z;
	}
	double mediePromovare() {
		int suma = 0;
		double medie = 0;
		int nr = 0;
		for (int i = 0; i < this->nrDiscipline;i++) {
			nr++;
			suma += this->note[i];
		}
		return suma / nr;
	}

	int getRestante() {
		int nr = 0;
		for (int i = 0; i < this->nrDiscipline; i++) {
			if (this->note[i] < 5) nr++;
		}
		return nr;
	}
};

int studentiIntegralisti(Student* studenti, int n, int prag) {
	int nr = 0;
	for (int i = 0; i < n; i++) {
		if (studenti[i].mediePromovare() > prag && studenti[i].getRestante() == 0) {
			nr++;
		}
	}
	return nr;
}

int main() {
	int noteAna[] = { 9, 12, 8 };
	int noteMihai[] = { 0, 10, 9 };
	int noteIoana[] = { 7, 8, 9 };

	Student studenti[] = {
		{ "Ana", 101, 3, noteAna, true },
		{ "Mihai", 102, 3, noteMihai, false },
		{ "Ioana", 103, 3, noteIoana, false }
	};

	for (int i = 0; i < 3; i++) {
		studenti[i].afisare();
		cout << " Media notelor de promovare: "
			<< studenti[i].mediePromovare() << '\n';
	}

	cout << "\nIntegralisti cu media peste 8: "
		<< studentiIntegralisti(studenti, 3, 8.0) << '\n';
}