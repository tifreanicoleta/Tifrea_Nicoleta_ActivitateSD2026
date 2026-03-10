#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include<stdio.h>
#include<string.h>

struct ContBancar {
	int idClient;
	char* numeClient;
	float sold;
	char* moneda;
};

struct ContBancar initializare(int idClient, const char* numeClient, float sold, const char* moneda) {
	struct ContBancar c;

	c.idClient = idClient;

	c.numeClient = (char*)malloc(sizeof(char) * (strlen(numeClient) + 1));
	if (c.numeClient != NULL) {
		strcpy_s(c.numeClient, strlen(numeClient) + 1, numeClient);
	}
	else {
		c.numeClient = NULL; 
	}

	c.sold = sold;

	c.moneda = (char*)malloc(sizeof(char) * (strlen(moneda) + 1));

	if (c.moneda != NULL) {
		strcpy_s(c.moneda, strlen(moneda) + 1, moneda);
	}
	else {
		c.moneda = NULL;
	}

	return c;
}

void afisareContBancar(struct ContBancar c) {
	if (c.numeClient != NULL && c.moneda != NULL) {
		printf("Id client : %d \n", c.idClient);
		printf("Nume Client: %s\n", c.numeClient);
		printf("Sold: %5.2f \n", c.sold);
		printf("Moneda: %s\n", c.moneda);
	}
	else {
		printf("Id Client:  %d.\n ", c.idClient);
		printf("Nume Client: \n ");
		printf("Sold: %5.2f \n", c.sold);
		printf("Moneda: \n");

	}
}

int main() {

	// initializarea structurii ContBancar si afisarea acesteia in main
	struct ContBancar c;
	c = initializare(1, "Rizea Marius", 3258.75, "EUR");
	afisareContBancar(c);

	struct ContBancar c1;


}