/*--------------------------------------------------------------------------*/
// Funciones adicionales                                                    //
/*--------------------------------------------------------------------------*/
void ingdata (struct data *);
void gestborra (void); //Es un men£.
void case_picomp (struct data *, int, struct data, int);
void case_pidisp (struct nodo *, struct nodo *, struct data, int);
void case_cocomp (struct data *, struct data, int, int, int);
void case_codisp (struct nodo *, struct nodo *, struct data, int);
void case_cocircomp (struct data *, struct data, int, int, int, int, int);
void case_lisim (struct nodo *);
void case_lidob (struct nodod **);

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