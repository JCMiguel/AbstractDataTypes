/*
 ============================================================================
 Name        : AbstractDataTypes.c
 Author      : JCMiguel
 Version     :
 Copyright   : GPL License
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "AbstractDataTypes.h"

/*--------------------------------------------------------------------------*/
// FUNCIONES DE PILAS						                                //
/*--------------------------------------------------------------------------*/

Stack_t CreateStack (unsigned long sizeOfData, unsigned long elem) {
	Stack_t ptrStack;

	ptrStack = (Stack_t) malloc(sizeof(Stack_struct));
	if(!ptrStack) {
		return NULL;
	}
	ptrStack->data = calloc(elem, sizeOfData );
	if(!(ptrStack->data)) {
		return NULL;
	}

	ptrStack->index = 0;
	ptrStack->maxSize = elem;
	ptrStack->__sizeData = sizeOfData;

	return ptrStack;
}

int AddToStack(Stack_t stack, void *data) {
	if(stack->index >= stack->maxSize) {
		printf("PILA LLENA");
		return -1;
	}
	memcpy((stack->data + ((stack->index)*stack->__sizeData)), data, stack->__sizeData);
	stack->index++;
	return 0;

}

int ReadFromStack (Stack_t stack, void * data) {
	if(stack->index <= 0) {
		printf("Pila vacia");
		return -1;
	}
	stack->index--;
	memcpy(data, (stack->data + ((stack->index)*stack->__sizeData)), stack->__sizeData);
	return 0;
}

void FreeStack (Stack_t stack){
	if(stack->data != NULL) {
		free(stack->data);
		stack->data =NULL;
	}
	stack->index =0;
	stack->maxSize = 0;
	stack->__sizeData = 0;
	if(stack != NULL) {
		free(stack);
		stack = NULL;
	}
}


/*--------------------------------------------------------------------------*/
// FUNCIONES DE COLAS						                                //
/*--------------------------------------------------------------------------*/

typedef enum {
	EMPTY_QUEUE,
	FREE_QUEUE,
	FULL_QUEUE
} StatusQueue;

Queue_t CreateQueue (unsigned long sizeOfData, unsigned long elem) {
	Queue_t ptrQueue;

	ptrQueue = (Queue_t) malloc(sizeof(Queue_struct));
	if(!ptrQueue) {
		return NULL;
	}
	ptrQueue->data = calloc(elem, sizeOfData );
	if(!(ptrQueue->data)) {
		return NULL;
	}

	ptrQueue->readPtr = 0;
	ptrQueue->writePtr = 0;
	ptrQueue->maxSize = elem;
	ptrQueue->__sizeData = sizeOfData;
	ptrQueue->__statusQueue = EMPTY_QUEUE;

	return ptrQueue;
}

int AddToQueue(Queue_t queue, void *data) {
	if(queue->__statusQueue == FULL_QUEUE) {
		printf("COLA LLENA");
		return -1;
	}
	memcpy((queue->data + ((queue->readPtr)*queue->__sizeData)), data, queue->__sizeData);
	queue->readPtr++;
	if(queue->readPtr >= queue->maxSize)
		queue->readPtr = 0;
	if(queue->readPtr == queue->writePtr)
		queue->__statusQueue = FULL_QUEUE;
	else
		queue->__statusQueue = FREE_QUEUE;
	return 0;

}

int ReadFromQueue (Queue_t queue, void * data) {
	if(queue->__statusQueue == EMPTY_QUEUE) {
		printf("Cola vacia");
		return -1;
	}
	memcpy(data, (queue->data + ((queue->writePtr)*queue->__sizeData)), queue->__sizeData);
	queue->writePtr++;
	if(queue->writePtr >= queue->maxSize)
		queue->writePtr = 0;
	if(queue->readPtr == queue->writePtr)
		queue->__statusQueue = EMPTY_QUEUE;
	else
		queue->__statusQueue = FREE_QUEUE;
	return 0;
}

void FreeQueue (Queue_t queue){
	if(queue->data != NULL) {
		free(queue->data);
		queue->data =NULL;
	}
	queue->readPtr =0;
	queue->writePtr =0;
	queue->maxSize = 0;
	queue->__sizeData = 0;
	queue->__statusQueue = EMPTY_QUEUE;
	if(queue != NULL) {
		free(queue);
		queue = NULL;
	}
}

/*--------------------------------------------------------------------------*/
// FUNCIONES DE LISTAS SIMPLES						                                //
/*--------------------------------------------------------------------------*/


/*
void agregar(struct nodo **Inic, struct data Dato)
{ struct nodo *NVO, *ACT=*Inic;
  //Llegado a este punto, en mi cuaderno hice una anotaci¢n que dice:
  //"PARA FUNCION INSERTAR NO VA"
  //La anotaci¢n empieza donde escribo *nota* y termina donde *finnota*

  // *nota* //
  if(!(NVO=(nodo *)malloc(sizeof(struct nodo)))
  { printf("No hay mem");
    return;
  }
  NVO->Dato=Dat;
  NVO->Sig=NULL;
  // *finnota* //

  if(!*Inic)
  { *Inic=NVO;
    return;
  }
  while(ACT->sig)
    ACT=ACT->sig;
  ACT->sig=NVO;
}
*/

int ins_ppio(struct nodo **ppio)
{ struct nodo *p;
  if(!(p=(struct nodo *)malloc(sizeof(struct nodo))))
  { printf("\n\n­Memoria Insuficiente!");
    //getch();
    return 1;
  }

  //printf("Ingrese nombre");
  //fflush(stdin);
  //gets(p->nombre);
  //printf("Ingrese dato");
  //scanf("%i", p->data.dato);

  //ingdata(&(p->datos));
  p->sig=*ppio;
  *ppio=p;
  return 0;
}

int ins_final(struct nodo **ppio)
{ struct nodo *p, *q;
  if(!(p=(struct nodo *)malloc(sizeof(struct nodo))))
  { printf("\n\n­Memoria Insuficiente!");
    //getch();
    return 1;
  }

  //printf("Ingrese nombre:");
  //fflush(stdin);
  //gets(p->nombre);

  //ingdata(&(p->datos));
  p->sig=NULL;
  if(!*ppio)
  { *ppio=p;
    return 0;
  }
  q=*ppio;
  while(q->sig) //Falsa alarma >.<' ---> ERROR EN EL CUADERNO
    q=q->sig;
  q->sig=p;
  return 0;
}

int listar(struct nodo *p)
{ //clrscr(); //system("cls");
  if(!p)
  { printf("Lista vac¡a");
    return 0;
  }
  while(p) //Error en mi cuaderno.
  { printf("\n  Valor: %i\n  String: %s", p->datos.valor, p->datos.str);
    p=p->sig;
  }
  //getch(); //system("PAUSE");
  return 0;
}

void tam_lista(struct nodo *p)
{ int i=0;
  while(p) //Ac  dec¡a p->sig ... ­­­ERROR!!!
  { i++;
    p=p->sig;
  }
  printf("\nLa lista contiene %i nodos.\nOcupa %i bytes en memoria.", i,i*(sizeof(struct nodo)));
  //getch(); //system("PAUSE");
}

void borrar(struct nodo **Inic)
{ struct nodo *act=*Inic, *ant=*Inic;
  int opcion;
  struct data Dato;
  char eleccion;

  //gestborra(); //Gesti¢n de borrado.
  scanf("%i", &opcion);
  switch(opcion)
  { case 1:
      printf("Ingrese valor: ");
      scanf("%i", &Dato.valor);
      while((act->datos.valor)!=(Dato.valor) && act)
      { ant=act;
	act=act->sig;
      }
      break;

    case 2:
      printf("Ingrese string: ");
      fflush(stdin);
      gets(Dato.str);
      /*opcion=strcmp((act->datos.str),(Dato.str));
      while(opcion && act)*/
      while((strcmp((act->datos.str),(Dato.str))) && act)
      { ant=act;
	act=act->sig;
      }
      break;

    case 3:
      return;
  }
  if(!act)
  { printf("Dato NO encontrado");
    //getch();
    return;
  }
  printf("Desea borrar S/N ");
  fflush(stdin);
  scanf("%c", &eleccion);
  eleccion=toupper(eleccion);
  if(eleccion=='S')
  { if(act==*Inic)
    { *Inic=act->sig;
      free(act);
      printf("\nDato Borrado.");
      //getch();
      return;
    }
  // Lo que sigue, es remplazado m s adelante por algo m s breve.
  //if(!act->sig)
  //{ ant->sig=NULL;
  //  free(act);
  //  return;
  //}
  //ant->sig=act->sig;
  //free(act);
    ant->sig=act->sig;
    free(act);
    printf("\nDato Borrado.");
    //getch();
  }
  else
  { printf("\nOperaci¢n cancelada.\n");
    //getch();
    return;
  }
}

void mostrar(struct nodo *Inic)
{ while(Inic)
  { printf("%d", Inic->datos);
    Inic=Inic->sig;
  }
}


/*----------------------- o ---------------------------*/
/*
void agregard(struct nodod **Inic, struct nodod *Aux)
{ struct nodod *Act=*Inic;
  if(!*Inic)
  { *Inic=Aux;
    Aux->sig=NULL;
    Aux->ant=NULL;
    return;
  }
  while((Act->datos.valor<Aux->datos.valor) && Act)
  { ant=Act;
    Act=Act->sig;
  }
  if(Act==*Inic)
  { *Inic=Aux;
    Aux->sig=Act;
    Aux->ant=NULL;
    Act->ant=Aux;
    return;
  }
  Aux->ant=ant;
  Aux->sig=Act;
  ant->sig=Aux;
  if(Act)
    Act->ant=Aux;
}
*/
void borrard(struct nodod **Inic)
{ struct nodod *Act=*Inic;
  int opcion;
  struct data Dato;
  char eleccion;

  //gestborra(); //Gesti¢n de borrado.
  scanf("%i", &opcion);
  switch(opcion)
  { case 1:
      printf("Ingrese valor: ");
      scanf("%i", &Dato.valor);
      while((Act->datos.valor!=Dato.valor)&&(Act))
	Act=Act->sig;
      break;

    case 2:
      printf("Ingrese string: ");
      fflush(stdin);
      gets(Dato.str);
      //ME FALTà PONER EL WHILE!!!!!!
      //ASÖ ACABA BORRANDO SIEMPRE EL PRIMER NODO!!! XDDDDDDDDD
      break;

    case 3:
      return;
  }
  if(!Act)
  { printf("Dato no encontrado");
    return;
  }
  printf("ESTA SEGURO (S/N) ");
  if('N')//getch()=='N')
    return;
  if(Act==*Inic)
  { *Inic=Act->sig;
    Act->sig->ant=NULL;
    free(Act);
    return;
  }
  Act->ant->sig=Act->sig;
  if(Act->sig)
    Act->sig->ant=Act->ant;
  free(Act);
}

void listard(struct nodod *Inic)
{ //clrscr();
  if(!Inic)
    printf("Lista vac¡a");
  while(Inic)
  { //printf("%d", Inic->Dato);
    printf("\nDatos le¡dos:\n  Valor: %i\n  String: %s", Inic->datos.valor,Inic->datos.str);
    Inic=Inic->sig;
  }
}

void ins_finald(struct nodod **inicio)
{ //struct data var;
  struct nodod *p, *act=*inicio;
  if(!(p=(struct nodod *)malloc(sizeof(struct nodod))))
  { printf("\n­Memoria insuficiente!");
    //getch();
    return;
  }
  //ingdata(&(p->datos));
  if(!*inicio)
  { *inicio=p;
    p->sig=NULL;
    p->ant=NULL;
    return;
  }
  while(act->sig)
    act=act->sig;
  act->sig=p;
  p->sig=NULL;
  p->ant=act;
}

void ins_ppiod(struct nodod **inicio)
{ struct nodod *p, *aux;
  if(!(p=(struct nodod *)malloc(sizeof(struct nodod))))
  { printf("\n­Memoria insuficiente!");
    //getch();
    return;
  }
  //ingdata(&(p->datos));
  if(!*inicio)
  { p->sig=NULL;
    *inicio=p;
    (*inicio)->ant=NULL;
    return;
  }
  ////ingdata(&(p->datos));
  aux=p;
  aux->sig=*inicio; //Ac  antes dec¡a (*inicio)->sig
  *inicio=p;
  p->sig->ant=p;
  (*inicio)->ant=NULL;
}
/*----------------------- o ---------------------------*/
