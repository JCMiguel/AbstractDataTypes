/*
 * AbstractDataTypes.h
 *
 *  Created on: 26 nov. 2018
 *      Author: juanc
 */

#ifndef ABSTRACTDATATYPES_H_
#define ABSTRACTDATATYPES_H_

#include <stdio.h>
//#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
//#include <plcproto.h>

#define MAX 8
#define MAX_SIZE	256

/*-------------------------JUGANDO CON LAS MACROS---------------------------*/
#define PEPE 50   	//¨Hace falta detallarlo...?
#if defined(PEPE)	//Un if com£n y silvestre...
#define A 50        	//Again... Se ejecuta si es verdadera la expr del if.
#else                  	//Un else com£n y silvestre...
#error WHAT IS THAT 	//Esto es nuevo.
/*El compilador lanza un error si se llega a este punto.*/
#endif			//Fin del if.
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
// ESTRUCTURAS (struct)                                                     //
/*--------------------------------------------------------------------------*/

struct data
{ int valor;
  char str[50];
};

struct nodo
{ struct data datos;
  struct nodo *sig;
};

struct nodod
{ struct data datos;
  struct nodod *ant, *sig;
};

/*--------------------------------------------------------------------------*/
// PILAS (Stack) (Memoria LIFO)                                             //
/*--------------------------------------------------------------------------*/

typedef struct {
	unsigned long maxSize;
	unsigned long index;
	unsigned long __sizeData;
	unsigned char * data;
} Stack_struct;

typedef Stack_struct* Stack_t;

Stack_t CreateStack (unsigned long sizeOfData, unsigned long elem);
int AddToStack(Stack_t stack, void *data);
int ReadFromStack (Stack_t stack, void * data);
void FreeStack (Stack_t stack);


/*--------------------------------------------------------------------------*/
// COLAS (Queue) (Memoria FIFO)                                            //
/*--------------------------------------------------------------------------*/

typedef struct {
	unsigned long maxSize;
	unsigned long readPtr;
	unsigned long writePtr;
	unsigned long __sizeData;
	unsigned char __statusQueue;
	unsigned char * data;
} Queue_struct;

typedef Queue_struct* Queue_t;

Queue_t CreateQueue (unsigned long sizeOfData, unsigned long elem);
int AddToQueue(Queue_t queue, void *data);
int ReadFromQueue (Queue_t queue, void * data);
void FreeQueue (Queue_t queue);


/*--------------------------------------------------------------------------*/
// LISTAS                                                                   //
/*--------------------------------------------------------------------------*/

//LISTAS SIMPLES [FUNCIONA]
void agregar (struct nodo **, struct data);  //Inserta al final.
int ins_ppio (struct nodo **);
int ins_final (struct nodo **);
int listar (struct nodo *);
void tam_lista (struct nodo *);  //No implementada a£n. [AHORA SI]
void borrar (struct nodo **);
void mostrar (struct nodo *);

//LISTAS DOBLES  [FUNCIONA A MEDIAS]
void ins_ppiod (struct nodod **);
void ins_finald (struct nodod **);
void agregard (struct nodod **);//, struct nodod *);   [!]
void borrard (struct nodod **);//, struct data);       [!]
void listard (struct nodod *);


/*--------------------------------------------------------------------------*/
// µRBOLES (¨Lo lograr‚ alg£n d¡a?)                                         //
/*--------------------------------------------------------------------------*/

//µRBOLES
// --- PRàXIMAMENTE ---

#endif /* ABSTRACTDATATYPES_H_ */
