#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>

struct Telefon {
		int id;
		int RAM;
		char* producator;
		float pret;
		char serie;
};

struct Telefon initializare(int id, int ram, const char* producator, float pret, char serie) { //asemanator constructor cu parametrii din poo
		struct Telefon t;
		t.id = id;
		t.RAM = ram;
	
		// alocam spatiu pentr char* producator cu malloc
	
		t.producator = (char*)malloc(sizeof(char) * (strlen(producator) + 1));
		//copierea in zona de memorie
	
		strcpy_s(t.producator, strlen(producator)+ 1, producator);
		t.pret = pret;
		t.serie = serie;
		return t;
	}
	
	
	// functia de afisare a structurii telefon
	
	void afisare(struct Telefon t) {
		if (t.producator != NULL) {
			printf("%d. Telefonul %s seria %c are %d Gb RAM si costa %5.2f RON \n", t.id, t.producator, t.serie, t.RAM, t.pret);
		}
		else {
			printf("%d. Telefonul din seria %c are %d Gb RAM si costa %5.2f RON \n", t.id, t.serie, t.RAM, t.pret);
		}
	}

	void afisareVector(struct Telefon* vector, int nrElemente) {
		// PARCURGEM VECTORUL SI APELAM FUNCTIA DE AFISARE PENTRU FIECARE ELEMENT
		for (int i = 0; i < nrElemente; i++) {
			afisare(vector[i]);
		}

	}


	int main() {
		struct Telefon* telefoane = NULL;
		int nrTelefoane = 3;
		telefoane = (struct Telefon*)malloc(sizeof(struct Telefon) * nrTelefoane);

		// initializam fiecare pozitie din vector
		telefoane[0] = initializare(1, 256, "Motorola", 1999.99, 'A');
		telefoane[1] = initializare(2, 128, "Samsung", 2999.99, 'B');
		telefoane[2] = initializare(3, 64, "Apple", 3999.99, 'X');

		afisareVector(telefoane, nrTelefoane);

	}