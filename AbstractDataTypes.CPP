//Este programa contiene muchas funciones.
/*Nota de aplicaci¢n (¨?)
   PCLSLDAR.CPP
     -> P = Pila
     -> C = Cola
     -> LS = Lista Simple
     -> LD = Lista Doble
     -> AR = µrbol		*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
//#include <plcproto.h>
#include "D:\BORLANDC\PCLPROTO.H"
#define MAX 8
#define MENU clrscr();                         		\
	     printf("0.-Salir");               	        \
	     printf("\n1.-Pilas Compactas");		\
	     printf("\n2.-Pilas Dispersas");		\
	     printf("\n3.-Colas Compactas");		\
	     printf("\n4.-Colas Dispersas");		\
	     printf("\n5.-Cola Circular Compacta");	\
	     printf("\n6.-Cola Circular Dispersa");	\
	     printf("\n7.-Listas Simples");		\
	     printf("\n8.-Listas Dobles");		\
	     printf("\n9.-µrboles");			\
	     printf("\n10.-Listar");			\
	     printf("\nSu elecci¢n: ");

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
// FUNCIàN PRINCIPAL (MAIN)                                                 //
/*--------------------------------------------------------------------------*/

void main(void)
{
//PENDIENTE
  //Declaraciones para Pilas Compactas.
  struct data pila[MAX];
  int INDP=0;
  struct data var1;
  int vacia;

  //Declaraciones para Pilas Dispersas.
  struct nodo *inicp=NULL;
  struct nodo *PP=NULL; //Puntero de Pila.

  //Declaraciones para Colas Compactas.
  struct data cola[MAX];
  int ENT=0;
  int SAL=0;

  //Declaraciones para Colas Dispersas.
  struct nodo *inicc=NULL;
  struct nodo *L=NULL;

  //Declaraciones para Colas Circulares Compactas.
  int VAC=1;
  int LLE=0;

  //Declaraciones para Listas Simples.
  struct nodo *inicio=NULL;

  //Declaraciones para Listas Dobles.
  struct nodod **inicld=NULL;


  short int opcion;
  do
  { MENU;
    //fflush(stdin);
    scanf("%hi", &opcion);
    switch(opcion)
    { case 0: //Salir.
	break;

      case 1: //Pilas Compactas.
	case_picomp(pila,INDP,var1,vacia);
	break;

      case 2: //Pilas Dispersas.
	case_pidisp(inicp,PP,var1,vacia);
	break;

      case 3: //Colas Compactas.
	case_cocomp(cola,var1,ENT,SAL,vacia);
	break;

      case 4: //Colas Dispersas.
	case_codisp(inicc,L,var1,vacia);
	break;

      case 5: //Cola Circular Compacta.
	case_cocircomp(cola,var1,ENT,SAL,LLE,VAC,vacia);
	break;

      case 6:
	printf("¨Acaso es esto posible?");
	getch();
	break;

      case 7: //Listas Simples.
	case_lisim(inicio);
	break;

      case 8: //Listas Dobles.
	case_lidob(inicld);

/*--------------------------------------------------------------------------*/
// BAJO PRUEBA								    //
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/

    }
  } while(opcion);
}


/*--------------------------------------------------------------------------*/
// FUNCIONES DE PILAS, COLAS, LISTAS Y µRBOLES                              //
/*--------------------------------------------------------------------------*/

void escribep(struct data Dato, int *Ind, struct data *Pila)
{ if(*Ind>=MAX)
  { printf("PILA LLENA");
    getch();
    return;
  }
  ingdata(&Dato);
  Pila[*Ind]=Dato;
  (*Ind)++;
}

int leep(struct data *Pila, int *Ind, struct data *Dato)
{ if(!(*Ind)) //Error en el cuaderno.
  { printf("Pila vac¡a");
    return 0;
  }
  (*Ind)--;
  *Dato=Pila[*Ind];
  return 1;
}

void escribepd(struct nodo **inicio, struct nodo *PP)
{ ins_ppio(inicio);
  PP=*inicio;
  PP=PP; //Est  solamente para que no aparezca un Warning.
}

int leepd(struct nodo **inicio, struct nodo *PP, struct data *var)
{ if(!*inicio)
  { printf("Pila vac¡a");
    return 0;
  }
  *var=(*inicio)->datos;
  PP=*inicio;
  *inicio=(*inicio)->sig;
  free(PP);
  PP=*inicio;
  return 1;
}

void escribec(struct data Dato, struct data *Cola, int *Ent)
{ if(*Ent>=MAX)
  { printf("Cola Llena");
    getch();
    return;
  }
  ingdata(&Dato);
  Cola[*Ent]=Dato;
  (*Ent)++;
}

int leec(struct data *Cola, int *Sal, struct data *Dato, int Ent)
{ if(*Sal==Ent)
  { printf("Cola vac¡a");
    return 0;
  }
  *Dato=Cola[*Sal];
  (*Sal)++;
  return 1;
}

void escribecd(struct nodo **inicc, struct nodo **L)
{ ins_final(inicc);
  *L=*inicc;
  L=L; //Est  solamente para que no salte un Warning.
}

int leecd(struct nodo **inicc, struct nodo *L, struct data *var)
{ if(!*inicc)
  { printf("Cola vac¡a");
    return 0;
  }
  *var=(*inicc)->datos;
  L=*inicc;
  *inicc=(*inicc)->sig;
  free(L);
  L=*inicc;
  return 1;
}

void escribecc(struct data *cola, int *ENT, struct data Dato, int *LLE, int *VAC, int SA)
{ if(*LLE)
  { printf("Cola llena");
    getch();
    return;
  }
  ingdata(&Dato);
  cola[*ENT]=Dato;
  (*ENT)++;
  *VAC=0;
  if(*ENT==MAX)
    *ENT=0;
  if(*ENT==SA)
    *LLE=1;
}

int leecc(struct data *cola, int *SAL, int ENT, int *LLE, int *VAC, struct data *Dato)
{ if(*VAC)
  { printf("Cola vac¡a");
    return 0;
  }
  *Dato=cola[*SAL];
  (*SAL)++;
  *LLE=0;
  if(*SAL==MAX)
    *SAL=0;
  if(*SAL==ENT)
    *VAC=1;
  return 1;
}

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
    getch();
    return 1;
  }

  //printf("Ingrese nombre");
  //fflush(stdin);
  //gets(p->nombre);
  //printf("Ingrese dato");
  //scanf("%i", p->data.dato);

  ingdata(&(p->datos));
  p->sig=*ppio;
  *ppio=p;
  return 0;
}

int ins_final(struct nodo **ppio)
{ struct nodo *p, *q;
  if(!(p=(struct nodo *)malloc(sizeof(struct nodo))))
  { printf("\n\n­Memoria Insuficiente!");
    getch();
    return 1;
  }

  //printf("Ingrese nombre:");
  //fflush(stdin);
  //gets(p->nombre);

  ingdata(&(p->datos));
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
{ clrscr(); //system("cls");
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
  printf("\nLa lista contiene %i nodos.\nOcupa %i bytes en memoria.", i,i*(sizeof(nodo)));
  getch(); //system("PAUSE");
}

void borrar(struct nodo **Inic)
{ struct nodo *act=*Inic, *ant=*Inic;
  int opcion;
  struct data Dato;
  char eleccion;

  gestborra(); //Gesti¢n de borrado.
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
    getch();
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
      getch();
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
    getch();
  }
  else
  { printf("\nOperaci¢n cancelada.\n");
    getch();
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

  gestborra(); //Gesti¢n de borrado.
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
  if(getch()=='N')
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
{ clrscr();
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
    getch();
    return;
  }
  ingdata(&(p->datos));
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
    getch();
    return;
  }
  ingdata(&(p->datos));
  if(!*inicio)
  { p->sig=NULL;
    *inicio=p;
    (*inicio)->ant=NULL;
    return;
  }
  //ingdata(&(p->datos));
  aux=p;
  aux->sig=*inicio; //Ac  antes dec¡a (*inicio)->sig
  *inicio=p;
  p->sig->ant=p;
  (*inicio)->ant=NULL;
}
/*----------------------- o ---------------------------*/



/*--------------------------------------------------------------------------*/
// Funciones adicionales                                                    //
/*--------------------------------------------------------------------------*/
void ingdata(struct data *var)
{ printf("\nIngrese un valor: ");
  fflush(stdin);
  scanf("%i", &(var->valor)); //&((*var).valor))
  printf("\nIngrese un string: ");
  fflush(stdin);
  gets(var->str);  //(*var).str
}

//void case_picomp (void)
void case_picomp(struct data *pila, int INDP, struct data var1, int pilavacia)
{ int opcion;
  do
  { clrscr();
    printf("PILAS COMPACTAS");
    printf("\n\n¨Leer o escribir?");
    printf("\n 1.-Leer.");
    printf("\n 2.-Escribir.");
    printf("\n 3.-Volver al men£ principal.");
    printf("\n Su elecci¢n: ");
    scanf("%hi", &opcion);
    switch(opcion)
    { case 1:
	pilavacia=leep(pila,&INDP,&var1);
	//printf("%i", INDP);
	if(pilavacia)
	  printf("\nDatos le¡dos:\n  Valor: %i\n  String: %s", var1.valor,var1.str);
	getch();
	break;

      case 2:
	//ingdata(&var2);
	escribep(var1,&INDP,pila);
	//getch();
    }
  } while(opcion!=3);
}

void case_cocomp(struct data *cola,struct data var1, int ENT, int SAL, int vacia)
{ int opcion;
  do
  { clrscr();
    printf("COLAS COMPACTAS");
    printf("\n\n¨Leer o escribir?");
    printf("\n 1.-Leer.");
    printf("\n 2.-Escribir.");
    printf("\n 3.-Volver al men£ principal.");
    printf("\n Su elecci¢n: ");
    scanf("%hi", &opcion);
    switch(opcion)
    { case 1:
	vacia=leec(cola,&SAL,&var1,ENT);
	//printf("%i", INDP);
	if(vacia)
	  printf("\nDatos le¡dos:\n  Valor: %i\n  String: %s", var1.valor,var1.str);
	getch();
	break;

      case 2:
	//ingdata(&var2);
	escribec(var1,cola,&ENT);
	//getch();
    }
  } while(opcion!=3);
}

void case_cocircomp(struct data *cola, struct data var1, int ENT, int SAL, int LLE, int VAC, int vacia)
{ int opcion;
  do
  { clrscr();
    printf("COLA CIRCULAR COMPACTA");
    printf("\n\n¨Leer o escribir?");
    printf("\n 1.-Leer.");
    printf("\n 2.-Escribir.");
    printf("\n 3.-Volver al men£ principal.");
    printf("\n Su elecci¢n: ");
    scanf("%hi", &opcion);
    switch(opcion)
    { case 1:
	vacia=leecc(cola,&SAL,ENT,&LLE,&VAC,&var1);
	//printf("%i", INDP);
	if(vacia)
	  printf("\nDatos le¡dos:\n  Valor: %i\n  String: %s", var1.valor,var1.str);
	getch();
	break;

      case 2:
	//ingdata(&var2);
	escribecc(cola,&ENT,var1,&LLE,&VAC,SAL);
	//getch();
    }
  } while(opcion!=3);
}

void gestborra(void)
{ clrscr();
  printf("¨Qu‚ desea buscar para borrar?");
  printf("\n 1.-Un valor.");
  printf("\n 2.-Un string.");
  printf("\n 3.-Nada, me equivoqu‚ de bot¢n.");
  printf("\n Su elecci¢n: ");
}

void case_lisim(struct nodo *inicio)
{ int opcion;
  do
  { clrscr();
    printf("LISTAS SIMPLES\n");
    printf("\n¨Qu‚ desea hacer?");
    printf("\n 1.-Insertar nodo al principio de la lista.");
    printf("\n 2.-Insertar nodo al final de la lista.");
    printf("\n 3.-Borrar un nodo de la lista.");
    printf("\n 4.-Mostrar lista completa.");
    printf("\n 5.-Estimar tama¤o de la lista.");
    printf("\n 6.-Volver al men£ principal.");
    printf("\n Su elecci¢n: ");
    scanf("%i", &opcion);
    switch(opcion)
    { case 1:
	ins_ppio(&inicio);
	break;

      case 2:
	ins_final(&inicio);
	break;

      case 3:
	borrar(&inicio);
	//getch();
	break;

      case 4:
	listar(inicio);
	getch();
	break;

      case 5:
	tam_lista(inicio);
    }
  } while(opcion!=6);
}

void case_pidisp(struct nodo *inicp, struct nodo *PP, struct data var1, int vacia)
{ int opcion;
  do
  { clrscr();
    printf("PILAS DISPERSAS");
    printf("\n\n¨Leer o escribir?");
    printf("\n 1.-Leer.");
    printf("\n 2.-Escribir.");
    printf("\n 3.-Volver al men£ principal.");
    printf("\n Su elecci¢n: ");
    scanf("%hi", &opcion);
    switch(opcion)
    { case 1:
	vacia=leepd(&inicp,PP,&var1);
	if(vacia)
	  printf("\nDatos le¡dos:\n  Valor: %i\n  String: %s", var1.valor,var1.str);
	getch();
	break;

      case 2:
	escribepd(&inicp,PP);
    }
  } while(opcion!=3);
}

void case_codisp(struct nodo *inicc, struct nodo *L,struct data var1, int vacia)
{ short int opcion;
  do
  { clrscr();
    printf("PILAS COMPACTAS");
    printf("\n\n¨Leer o escribir?");
    printf("\n 1.-Leer.");
    printf("\n 2.-Escribir.");
    printf("\n 3.-Volver al men£ principal.");
    printf("\n Su elecci¢n: ");
    scanf("%hi", &opcion);
    switch(opcion)
    { case 1:
	vacia=leecd(&inicc,L,&var1);
	if(vacia)
	  printf("\nDatos le¡dos:\n  Valor: %i\n  String: %s", var1.valor,var1.str);
	getch();
	break;

      case 2:
	escribecd(&inicc,&L);
    }
  } while(opcion!=3);
}

void case_lidob(struct nodod **inicld)
{ short int opcion;
  do
  { clrscr();
    printf("LISTAS DOBLES\n");
    printf("\n¨Qu‚ desea hacer?");
    printf("\n 1.-Insertar nodo al principio de la lista.");
    printf("\n 2.-Insertar nodo al final de la lista.");
    printf("\n 3.-Borrar un nodo de la lista.");
    printf("\n 4.-Mostrar lista completa.");
    printf("\n 5.-Agregar nodos ordenados por valor. \n\t(La lista debe empezar vac¡a)");
    printf("\n 6.-Volver al men£ principal.");
    printf("\n Su elecci¢n: ");
    scanf("%i", &opcion);
    switch(opcion)
    { case 1:
	ins_ppiod(inicld);
	break;

      case 2:
	ins_finald(inicld);
	break;

      case 3:
	borrard(inicld);
	break;

      case 4:
	listard(*inicld);
	getch();
	break;

      case 5:
	//agregard(inicld);
	break;
    }
  } while(opcion!=6);
}