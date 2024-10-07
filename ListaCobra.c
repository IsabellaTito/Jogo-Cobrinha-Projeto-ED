#include "ListaCobra.h"
#include <stdlib.h>
#include <stdio.h>


void criar(LISTA *lst, int tam_MAX){

  lst-> MAX = tam_MAX; 
  lst -> pos = 0;
  lst -> arr = (NO*) malloc(sizeof(NO)*lst->MAX);

  if(lst->arr == NULL){
    printf("ERRO FATAL! Memoria não pode ser alocada. \n");
    exit(1); //Finaliza o programa com saída de erro
  }   
}

void criar_no(NO *ponto, int x, int y ){
  ponto->x = x;
  ponto->y = y;
}

void inserir(LISTA *lst, NO elemento){
  if (lst->pos >= lst->MAX)
    redimensionar(lst, lst->MAX*2);
  lst->arr[lst->pos] = elemento;
  lst->pos++; 
}

int tamanho(LISTA *lst){
  return lst->pos;
}


void redimensionar(LISTA *lst1, int MAX){
  if(MAX < lst1->pos){
    printf("Não é possível reduzir, pois haverá perda de elementos!\n");
    exit(1);
  }
  lst1->MAX = MAX;
  NO *p = (NO*) malloc(sizeof(NO)*lst1->MAX);
  if(p == NULL){
    printf("Não foi possível redimensionar por falta de   espaço na memória!\n");
    exit(1);
  }
  for (int i=0; i<lst1->pos;i++)
    p[i] = lst1->arr[i];
  free(lst1->arr);
  lst1->arr = p;
}



void gameover(){
  printf("                                    ____\n");
  printf("           ________________________/ O  \\___/\n");
  printf("          <_O_O_O_O_O_O_O_O_O_O_O_O_____/   \\\n");
  printf("   ____                         ___                 _ \n");
  printf("  / ___| __ _ _ __ ___   ___   / _ \\__   _____ _ __| |\n");
  printf(" | |  _ / _` | '_ ` _ \\ / _ \\ | | | \\ \\ / / _ | '__| |\n");
  printf(" | |_| | (_| | | | | | |  __/ | |_| |\\ V |  __| |  |_|\n");
  printf("  \\____|\\__,_|_| |_| |_|\\___|  \\___/  \\_/ \\___|_|  (_)\n");
  printf("\n");

}

void finalizado(){
  printf("                                            ____\n");
  printf("                   ________________________/ O  \\___/\n");
  printf("                  <_O_O_O_O_O_O_O_O_O_O_O_O_____/   \\\n");
  printf("      _                     _____ _             _ _              _       _ \n");
  printf("     | | ___   __ _  ___   |  ___(_)_ __   __ _| (_)______ _  __| | ___ | |\n");
  printf("  _  | |/ _ \\ / _` |/ _ \\  | |_  | | '_ \\ / _` | | |_  / _` |/ _` |/ _ \\| |\n");
  printf(" | |_| | (_) | (_| | (_) | |  _| | | | | | (_| | | |/ | (_| | (_| | (_) |_|\n");
  printf("  \\___/ \\___/ \\__, |\\___/  |_|   |_|_| |_|\\__,_|_|_/___\\__,_|\\__,_|\\___/(_)\n");
  printf("              |___/                                                        \n");
  printf("\n");

}

void titulo(){
  printf("  _____ _            ____              _           ____                      \n");
  printf(" |_   _| |__   ___  / ___| _ __   __ _| | _____   / ___| __ _ _ __ ___   ___ \n");
  printf("   | | | '_ \\ / _ \\ \\___ \\| '_ \\ / _` | |/ / _ \\ | |  _ / _` | '_ ` _ \\ / _ \\\n");
  printf("   | | | | | |  __/  ___) | | | | (_| |   |  __/ | |_| | (_| | | | | | |  __/\n");
  printf("   |_| |_| |_|\\___| |____/|_| |_|\\__,_|_|\\_\\___|  \\____|\\__,_|_| |_| |_|\\___|\n");
  printf("\n\n");
}