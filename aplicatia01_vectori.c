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
	
	struct Telefon* copiazaPrimeleNElemente(struct Telefon * vector, int nrElemente, int nrElementeCopiate) {
		struct Telefon* vectorNou = NULL;	

		//alocam spatiu pentru vectorul nou
		vectorNou = (struct Telefon*)malloc(sizeof(struct Telefon) * nrElementeCopiate);
		//parcurgem vectorul de n elemente copiate

		for (int i = 0; i < nrElementeCopiate; i++) {
			vectorNou[i] = vector[i];
			// facem deep copy pentru campurile alocate dinamic
			// alocam spatiu pt producator
			vectorNou[i].producator = (char*)malloc(strlen(vector[i].producator) + 1);
			//facem copierea 
			strcpy_s(vectorNou[i].producator, strlen(vector[i].producator) + 1, vector[i].producator);
		} 

		return vectorNou;
		
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

		//testarea functiei de copiere a primelor n elemente din vector

		printf("\n===========================================================\n");

		struct Telefon* primeleTelefoane = NULL;
		int nrPrimeleTelefoane = 1;
		primeleTelefoane = copiazaPrimeleNElemente(telefoane, nrTelefoane, nrPrimeleTelefoane);
		printf("\n\n Primele Telefoane: \n");
		afisareVector(primeleTelefoane, nrPrimeleTelefoane);


		return 0;

	}