/*
 * main.c
 *
 *  Created on: 26 nov. 2018
 *      Author: juanc
 */


#include <stdio.h>
#include <stdlib.h>
#include "AbstractDataTypes.h"

/**
 *  Pilas ...
 *   -> funciona con INT
 *   -> funciona con structs
 */
struct tura {
	int a;
	char b;
	float c;
};

int main(void) {
	puts("¡Hola mundo!"); /* prints ¡Hola mundo! */

	Stack_t stack;
	int a, i;
	struct tura pkg;

	stack = CreateStack(sizeof(pkg), 5);
	if(stack == NULL) {
		puts("Error...");
		return EXIT_FAILURE;
	}

	for(i = 0; i< 6 ; i++) {
		pkg.a = i +14;
		pkg.b = '0' + i;
		pkg.c = 3.2 + i;
		if(AddToStack(stack, &pkg) < 0 ) {
			puts("Error al agregar elemento");
			continue;
		}
		printf("Elementos agregados: %d %c %f\n", pkg.a, pkg.b, pkg.c);
	}

	pkg.a = 0;
	pkg.b = 0;
	pkg.c = 0;
	for(i =0; i< 6 ; i++) {
		if(ReadFromStack(stack, &pkg) < 0 ) {
			puts("Error al obtener elemento");
			continue;
		}
		printf("Elementos extraidos: %d %c %f\n", pkg.a, pkg.b, pkg.c);
	}

	FreeStack(stack);

	return EXIT_SUCCESS;
}
