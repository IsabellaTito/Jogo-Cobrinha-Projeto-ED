#include <stdio.h>
#include <stdlib.h>
#include "ListaCobra.h"
#include <time.h>

#define tam 21
char cenario[tam][tam*2], play;
int pontos[2];

FILE *file;
LISTA cobra;
NO apple;

void place();
void imprimircenario();
void insapple();
void reading();
void saving();
char instrucao();

int main() {

  NO head = {9,21}, body={10,21},plus;
  char direcao,sentido;
  
  //INICIO
  criar(&cobra,10);
  inserir(&cobra,head);
  inserir(&cobra,body);
  
  place();
  insapple();

  
  //------LOOP-----
  if(instrucao() == 'P'){
    reading();
    pontos[0] = 0;
    
    while(1){

      place();
      system("clear"); //terminal Linux
      //system("cls"); //terminal Windows
      titulo();
      imprimircenario();
      
      //PONTUAÇÃO

      printf(" ---------------         ----------------\n");
      printf("   Recorde: %d              Pontuacao: %d\n", pontos[1],pontos[0]);
      printf(" ---------------         ----------------\n");
      
      
      
      printf("\n");
      
      printf("Digite uma direcao (w, a, s, d) ou E (Exit) -> ");
      scanf(" %c", &direcao);
  
      // sentidos - u (up) / D(down) / e(esquerda) / d(direita)
  
      if(direcao == 'w' && sentido != 'D' ){
        for(int i=tamanho(&cobra)-1; i>0; i--){
          cobra.arr[i].x = cobra.arr[i-1].x ;
          cobra.arr[i].y = cobra.arr[i-1].y;
        }
        cobra.arr[0].x--;
        sentido = 'u';
      }
      else if(direcao == 's' && sentido != 'u'){
        for(int i=tamanho(&cobra)-1; i>0; i--){
          cobra.arr[i].x = cobra.arr[i-1].x ;
          cobra.arr[i].y = cobra.arr[i-1].y;
        }
        cobra.arr[0].x++;
        sentido = 'D';
      }
      else if(direcao == 'a' && sentido != 'd'){
        for(int i=tamanho(&cobra)-1; i>0; i--){
          cobra.arr[i].x = cobra.arr[i-1].x ;
          cobra.arr[i].y = cobra.arr[i-1].y;
        }
        cobra.arr[0].y--;
        sentido = 'e';
      }
      else if(direcao == 'd' && sentido != 'e'){
        for(int i=tamanho(&cobra)-1; i>0; i--){
          cobra.arr[i].x = cobra.arr[i-1].x ;
          cobra.arr[i].y = cobra.arr[i-1].y;
        }
        cobra.arr[0].y++;
        sentido = 'd';
      }
      else if(direcao == 'E'){
        
        finalizado();
        if(pontos[0]>pontos[1]){
          printf("              PARABENS, VOCE ESTABELECEU UM NOVO RECORDE!!!\n\n");
        }
        printf("                                PONTUACAO: %d\n", pontos[0]);
        saving();
        break;
      }
   
      if(cobra.arr[0].x == apple.x && cobra.arr[0].y == apple.y){
        
        insapple();
        
        if(sentido == 'u'){
          criar_no(&plus, (cobra.arr[tamanho(&cobra) - 1].x)+1, cobra.arr[tamanho(&cobra) - 1].y);
        }
        else if(sentido == 'D'){
          criar_no(&plus, (cobra.arr[tamanho(&cobra) - 1].x)-1, cobra.arr[tamanho(&cobra) - 1].y);
        }
        else if(sentido == 'e'){
          criar_no(&plus, cobra.arr[tamanho(&cobra) - 1].x, (cobra.arr[tamanho(&cobra) - 1].y)+1);
        }
        else{
          criar_no(&plus, cobra.arr[tamanho(&cobra) - 1].x, (cobra.arr[tamanho(&cobra) - 1].y)-1);
        }
        
        inserir(&cobra, plus);
        pontos[0]++;
        
      }
  
      else if(cenario[cobra.arr[0].x][cobra.arr[0].y] == '-' || cenario[cobra.arr[0].x][cobra.arr[0].y] == '|' || cenario[cobra.arr[0].x][cobra.arr[0].y] == 'o'){
        gameover();
        if(pontos[0]>pontos[1]){
          printf("     PARABENS, VOCE ESTABELECEU UM NOVO RECORDE!!!\n\n");
        }
        printf("                     PONTUACAO: %d\n", pontos[0]);
        saving();
        break;
      }
      
    } //while TRUE
  }
    
  return 0;
}


void place(){
  
  // CONTORNO
  
  for(int i=0; i<tam;i++){
    for(int j=0; j<tam*2; j++){
      if(i==0 || i==tam-1)
        cenario[i][j] = '-';
      else if (j==0 || j==tam*2-1)
        cenario[i][j] = '|';
      else
        cenario[i][j] = ' ';
    }
  }

  //COBRA
  
  cenario[cobra.arr[0].x][cobra.arr[0].y] = 'O';
  for(int i = 1; i<tamanho(&cobra); i++){
   cenario[cobra.arr[i].x][cobra.arr[i].y] = 'o';    
  }
  
  //MAÇA
  
  cenario[apple.x][apple.y] = '@';
}

void imprimircenario(){
  for(int i=0; i<tam;i++){
    for(int j=0; j<tam*2; j++)
      printf("%c",cenario[i][j]);
    printf("\n");
  }
}

void insapple(){
  int N = tam-1, N2 = (tam-1)*2;
  srand(time(NULL));
  do{
    apple.x = rand()%(N);
    apple.y = rand()%(N2);
  }while(cenario[apple.x][apple.y] != ' ');
}

void reading(){
  char c, g[15];
  if ((file=fopen ("ponto.txt","r")) != NULL) {
    int i=0;
    while( (c=fgetc(file)) != EOF) {
      g[i] = c;
      i++;
    }
    pontos[1] = atoi(g);
    }
  fclose(file);
}

void saving(){
    if(pontos[0]>pontos[1]){
      if((file=fopen("ponto.txt","w"))!=NULL){
        fprintf(file,"%d",pontos[0]);
      }
      fclose(file);
    }
}

//INSTRUÇÕES

char instrucao(){
  titulo();  
  printf("Seja bem vindo ao Jogo da cobrinha, ou melhor, THE SNAKE GAME!! tssssssssss...\n\n");

  printf("O objetivo do jogo eh conseguir levar a cobrinha a comer o maximo de macas \npossiveis. A cada maca que ela comer, seu corpo aumenta em uma bolinha.\nMAS MUITO CUIDADO!!! Durante toda a movimentacao da cobrinha ela nao pode\nbater em seu proprio corpo e nem nas cercas!\n\n");

  printf("Fique atento aos movimentos e nao se esqueca de apertar ENTER apos colocar\no movimento indicado!\n\n");
  printf("w -> ir para cima\n");
  printf("s -> ir para baixo\n");
  printf("a -> ir para esquerda\n");
  printf("d -> ir para direita\n\n");

  printf("Caso deseje sair do jogo antes dele acabar basta digitar a letra E (EXIT).\n\n");

printf("                                                    ____\n");
printf("                           ________________________/ O  \\___/\n");
printf("                          <_O_O_O_O_O_O_O_O_O_O_O_O_____/   \\\n");
printf("         ____                ____ ____ ____ ____             _       _ _ \n");
printf("        | __ )  ___   __ _  / ___/ ___/ ___/ ___|  ___  _ __| |_ ___| | |\n");
printf("        |  _ \\ / _ \\ / _` | \\___ \\___ \\___ \\___ \\ / _ \\| '__| __/ _ | | |\n");
printf("        | |_) | (_) | (_| |  ___) ___) ___) ___) | (_) | |  | ||  __|_|_|\n");
printf("        |____/ \\___/ \\__,_| |____|____|____|____/ \\___/|_|   \\__\\___(_(_)\n");
printf("\n\n");
printf("Desenvolvido por Isabella Tito\n\n");


  printf("Digite P quando estiver pronto para comecar -> ");
  scanf(" %s",&play);
  return play;
}
