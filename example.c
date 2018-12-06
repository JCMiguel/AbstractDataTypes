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
	Queue_t queue;
	int i, offset;
	struct tura pkg;

	// ------------------------------- STACK ---------------------------------
	puts("Example with a stack of structs");

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


	// ------------------------------- QUEUE ---------------------------------
	puts("Example with a queue of structs");

	queue = CreateQueue(sizeof(pkg), 2);
	if(queue == NULL) {
		puts("Error...");
		return EXIT_FAILURE;
	}

	for(offset = 0; offset < 15 ; offset+=10) {
		for(i = 0; i< 3 ; i++) {
			pkg.a = i +14 + offset;
			pkg.b = '0' + i + offset;
			pkg.c = 3.2 + i + offset;
			if(AddToQueue(queue, &pkg) < 0 ) {
				puts("Error al agregar elemento");
				continue;
			}
			printf("Elementos agregados: %d %c %f\n", pkg.a, pkg.b, pkg.c);
		}

		pkg.a = 0;
		pkg.b = 0;
		pkg.c = 0;
		for(i =0; i< 3 ; i++) {
			if(ReadFromQueue(queue, &pkg) < 0 ) {
				puts("Error al obtener elemento");
				continue;
			}
			printf("Elementos extraidos: %d %c %f\n", pkg.a, pkg.b, pkg.c);
		}

	}
	FreeQueue(queue);

	return EXIT_SUCCESS;
}
