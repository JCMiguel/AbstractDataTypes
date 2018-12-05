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
#define PEPE 50   	//®Hace falta detallarlo...?
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

typedef struct {
	unsigned long maxSize;
	unsigned long index;
	unsigned long __sizeData;
	unsigned char * data;
} Stack_struct;

typedef Stack_struct* Stack_t;

/*--------------------------------------------------------------------------*/
// PILAS (Stack) (Memoria LIFO)                                             //
/*--------------------------------------------------------------------------*/

//PILAS COMPACTAS (MEMORIA ESTµTICA) [FUNCIONA]
void escribep (struct data, int *, struct data *);
int leep (struct data *,int *,struct data *);

//PILAS DISPERSAS
// --- PROXIMAMENTE --- [FUNCIONA]
void escribepd (struct nodo **, struct nodo *);
int leepd (struct nodo **, struct nodo *, struct data *);

Stack_t CreateStack (unsigned long sizeOfData, unsigned long elem);
int AddToStack(Stack_t stack, void *data);
int ReadFromStack (Stack_t stack, void * data);
void FreeStack (Stack_t stack);

/*--------------------------------------------------------------------------*/
// COLAS (Buffer) (Memoria FIFO)                                            //
/*--------------------------------------------------------------------------*/

//COLAS COMPACTAS (MEMORIA ESTµTICA) [FUNCIONA]
void escribec (struct data, struct data *, int *);
int leec (struct data *, int *, struct data *, int);

//COLAS DISPERSAS [FUNCIONA]
// --- PR‡XIMAMENTE ---
void escribecd (struct nodo **, struct nodo **);
int leecd (struct nodo **, struct nodo *, struct data *);

//COLA CIRCULAR COMPACTA (MEMORIA ESTµTICA) [FUNCIONA]
void escribecc (struct data *, int *, struct data, int *, int *, int);
int leecc (struct data *, int *, int, int *, int *, struct data *);

//COLA CIRCULAR DISPERSA
// --- PR‡XIMAMENTE ---

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
// µRBOLES (®Lo lograrÇ alg£n d°a?)                                         //
/*--------------------------------------------------------------------------*/

//µRBOLES
// --- PR‡XIMAMENTE ---

#endif /* ABSTRACTDATATYPES_H_ */
