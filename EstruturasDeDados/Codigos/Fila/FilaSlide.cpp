//fila com vetor
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

/*#include "filasmart.h"*/
/*#include "filaCircFloat.h"*/
void conta(Fila *q){
	Fila *a=fila_cria();//fila auxiliar
	int cont=0;
	float v;
	//esvazia a fila original para contar colocando os elementos na fila auxiliar
	while(!fila_vazia(q)){
		v=fila_retira(q);
		fila_insere(a,v);
		cont++;
	}
	//restaura a fila original
	while(!fila_vazia(a)){
		v=fila_retira(a);
		fila_insere(q,v);
	}
	fila_libera(a);
	printf("Numero de elementos: %d\n", cont);
}

void menu(){
     system("cls");
     printf("Escolha uma das opcoes do menu: \n");
     printf("1. Enfilera\n");       
     printf("2. Retira \n");
     printf("3. Mostra a fila\n");
     printf("4. Conta elementos\n");//void conta(Fila *q)
     printf("5. Somar elementos\n");//void soma(Fila *q)
     printf("6. Primeiro da fila\n");//float primeiro(Fila *q)
     printf("7. Ultimo da fila\n");//float ultimo(Fila *q)
     printf("9. Fim\n");
}     
                                          
main(){
 Fila *fi=fila_cria();
 int opmenu;
 float item;
 do{
    menu(); 
    scanf("%d", &opmenu);
    switch (opmenu){
    case 1 : //insere
          printf("Digite o valor a ser enfileirado: ");
          scanf("%f", &item);
          fila_insere(fi,item); break;
    case 2 : //retira
          if(fila_vazia(fi)) 
              printf("fila vazia.\n");
          else
              printf("Elemento retirado = %.0f\n",fila_retira(fi));
          break;    
    case 3 : //mostra
    		if(fila_vazia(fi)) 
              	printf("fila vazia.\n");
          	else
          		fila_mostra(fi); 
		  	break;   
	case 4:
			conta(fi);
			break;                
   }//switch
   printf("\n");
   system("pause"); 
 } while(opmenu!=9);
}
