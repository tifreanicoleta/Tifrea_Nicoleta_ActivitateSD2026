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




int main() {
	struct Telefon t;
	t = initializare(1, 256, "Samsung", 2000.5, 'A');
	return 0;

}