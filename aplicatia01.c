#include <stdio.h>
#include <stdlib.h>

struct Telefon {
	int id;
	int RAM;
	char* producator;
	float pret;
	char serie;
};

//initializarea structurii

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

// functia de modificare a unui atribut

void modificaPret(struct Telefon* t, float pretNou) {
	// verificam inputul

	if (pretNou > 0) {
		t->pret = pretNou;
	}
}

//functia de dezalocare a campurilor alocate dinamic

void dezalocare(struct Telefon* t) {
	if (t->producator != NULL) {
		free(t->producator);
		t->producator = NULL;
	}
}
int main() {
	struct Telefon t;
	t = initializare(1, 256, "Samsung", 2000.5, 'A');
	
	struct Telefon t1;
	t1 = initializare(2, 64, "Apple", 3999.99, 'X');

	// testarea functiei de afisare in main

	afisare(t);
	afisare(t1);

	//testarea functiei de modificare a pretului
	
	modificaPret(&t, 1499.99);
	afisare(t);

	//testarea functiei de dezalocare a campurilor alocate dinamic
	dezalocare(&t);
	afisare(t); // verificam daca se afiseaza null dupa dezalocarea campului alocat dinamic 
	return 0;

}