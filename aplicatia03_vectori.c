#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#include <string.h>

struct Laptop {
	int id;
	int anFabricatie;
	char* marca;
	char* procesor;
	float greutate;
	float pret;
	char serie;
};

struct Laptop initializare(int id, int anFabricatie, const char* marca, const char* procesor, float greutate, float pret, char serie) {
	struct Laptop l;
	l.id = id;
	l.anFabricatie = anFabricatie;

	l.marca = (char*)malloc(sizeof(char) * (strlen(marca) + 1));
	if (l.marca != NULL) {
		strcpy_s(l.marca, strlen(marca) + 1, marca);
	}
	else {
		l.marca = NULL;
	}

	l.procesor = (char*)malloc(sizeof(char) * (strlen(procesor) + 1));
	if (l.procesor != NULL) {
		strcpy_s(l.procesor, strlen(procesor) + 1, procesor);
	}
	else {
		l.procesor = NULL;
	}
	l.greutate = greutate;
	l.pret = pret;
	l.serie = serie;

	return l;
}

void afisareLaptop(struct Laptop l) {
	if (l.marca != NULL && l.procesor != NULL) {
		printf("Id: %d\n", l.id);
		printf("An fabricatie: %d\n", l.anFabricatie);
		printf("Marca: %s\n", l.marca);
		printf("Procesor: %s\n", l.procesor);
		printf("Greutate: %5.2f\n", l.greutate);
		printf("Pret: %5.2f\n", l.pret);
		printf("Seria: %c\n", l.serie);

		printf("\n");

	}
	else {
		printf("Id: %d\n", l.id);
		printf("An fabricatie: %d\n", l.anFabricatie);
		printf("Marca: \n");
		printf("Procesor: \n");
		printf("Greutate: %5.2f\n", l.greutate);
		printf("Pret: %5.2f\n", l.pret);
		printf("Seria: %c\n", l.serie);
		printf("\n");
	}

}

void dezalocare(struct Laptop* l) {
	if (l->marca != NULL) {
		free(l->marca);
		l->marca = NULL;
	}

	if (l->procesor != NULL) {
		free(l->procesor);
		l->procesor = NULL;
	}
}

void afisareVector(struct Laptop* vector, int nrElemente) {

	//parcurgem vectorul si apelam functia de afisare pentru fiecare element 

	for (int i = 0; i < nrElemente; i++) {
		afisareLaptop(vector[i]);
	}

}

// dezalocare pentru campurile alocate dinamic

void dezalocareVector(struct Laptop** vector, int* nrElemente) {
	if(vector != NULL && *vector != NULL) {
		for (int i = 0; i < (*nrElemente); i++) {
			dezalocare(&(*vector)[i]);
		}
		free(*vector);
		*vector = NULL;
		*nrElemente = 0;
	}
}

void crestereaPretului(struct Laptop* vector, int nrElemente, float procent) {
	//parcurcem vectorul pentru a creste pretul fiecarui laptop cu 10%
	if (vector != NULL) {
		for (int i = 0; i < nrElemente; i++) {
			vector[i].pret = vector[i].pret + (vector[i].pret * procent / 100);
		}
	}
}

void getPrimulLaptopByMarca(struct Laptop* vector, int nrElemente, const char* marca) {
	struct Laptop l;
	l.marca = NULL;

	// parcurgem vectorul
	for (int i = 0; i < nrElemente; i++) {
		if (strcmp(vector[i].marca, marca) == 0) {
			l = vector[i];
			//deep copy pentru campurile alocate dinamic	
			l.marca = (char*)malloc(strlen(vector[i].marca) + 1);
			strcpy_s(l.marca, strlen(vector[i].marca) + 1, vector[i].marca);
		}

	}

}


int main() {

	struct Laptop* laptopuri = NULL;
	int nrLaptopuri = 3;
	//alocam spatiu
	laptopuri = (struct Laptop*) malloc(sizeof(struct Laptop) * nrLaptopuri);
	//initializam fiecare pozitie din vector
	laptopuri[0]= initializare(1, 2020, "Lenovo", "i5", 150, 1999.99, 'C');
	laptopuri[1] = initializare(2, 2020, "Lenovo", "i5", 150, 2575, 'B');
	laptopuri[2] = initializare(3, 2020, "Apple", "M4", 150, 3000, 'X');

	afisareVector(laptopuri, nrLaptopuri);

	printf("\n=========================================================\n");

	crestereaPretului(laptopuri, nrLaptopuri, 10);
	afisareVector(laptopuri, nrLaptopuri);

	printf("\n=========================================================\n");

	getPrimulLaptopByMarca(laptopuri, nrLaptopuri, "Apple");
	afisareLaptop(laptopuri[2]);
	

}


