#ifndef LISTA_SNEAK_H
#define LISTA_SNEAK_H

typedef struct{
  int x,y;
} NO;

typedef struct {
  unsigned MAX;
  int pos;
  NO *arr;
}LISTA;



void criar(LISTA *lst, int tam_MAX);
void inserir(LISTA *lst, NO elemento);
void criar_no(NO *ponto, int x, int y );
void redimensionar(LISTA *lst1, int MAX);
int tamanho(LISTA *lst);
void gameover();
void finalizado();
void titulo();

#endif