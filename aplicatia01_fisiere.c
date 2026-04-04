//lucrul cu fisiere

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <malloc.h>
#include<stdio.h>

struct StructuraMasina {
	int id;
	int nrUsi;
	float pret;
	char* model;
	char* numeSofer;
	unsigned char serie;

};
typedef struct StructuraMasina Masina; // alias

void afisareMasina(Masina masina) {
	printf("Id: %d\n", masina.id);
	printf("Nr usi: %d\n", masina.nrUsi);
	printf("Pret: %5.2f\n", masina.pret);
	printf("Model: %s\n", masina.model);
	printf("Nume sofer: %s\n", masina.numeSofer);
	printf("Serie: %c\n", masina.serie);
}

void afisareVectorMasini(Masina* masini, int nrMasini) {
	for (int i = 0; i < nrMasini; i++) {
		afisareMasina(masini[i]);
	}
}

void adaugaMasinaInVector(Masina** masini, int* nrMasini, Masina masinaNoua) {
	Masina* aux = (Masina*)malloc(sizeof(Masina) * ((*nrMasini) + 1));
	for (int i = 0; i < *nrMasini; i++) {
		aux[i] = (*masini)[i];
	}
	aux[(*nrMasini)] = masinaNoua;
	free(*masini);
	(*masini) = aux;
	(*nrMasini)++;

}

Masina citireMasinaFisier(FILE* file) {
	Masina m;
	char buffer[100];
	char sep[4] = ",;\n";
	fgets(buffer, 100, file);
	m.id = atoi(strtok(buffer, sep));
	m.nrUsi = atoi(strtok(NULL, sep));
	m.pret = atof(strtok(NULL, sep));
	char* aux;
	aux = strtok(NULL, sep);
	m.model = (char*)malloc(strlen(aux) + 1);
	strcpy(m.model, aux);
	char* aux;
	aux = strtok(NULL, sep);
	m.numeSofer = (char*)malloc(strlen(aux) + 1);
	strcpy(m.numeSofer, aux);
	m.serie = strtok(NULL, sep)[0];
	return m;


}

void main() {

}