#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

//programa principal
void menu(){
     system("cls");
     printf("Escolha uma das opcoes do menu: \n");
     printf("------------------------------\n");
     printf("1. Insere na lista\n");     //Lista *lista_insere(Lista *l, int dado)  
     printf("2. Retira da lista\n");	 //Lista *lista_retira(Lista *l, int dado) 
     printf("3. Mostra a lista\n");      //void *lista_mostra(Lista *l) 
     printf("4. Busca na lista\n");		 //Lista *lista_busca(Lista *l, int dado) 
     printf("9. Fim\n");
     printf("==> ");
}
//--------------------------------------------------     
//programa principal       
//---------------------------------------------------
main(){
  int opmenu, item;
  Lista *li=lista_cria();//inicializa a lista com NULL
  Lista *aux;//ponteiro auxiliar - necessário para a busca
  do{
     menu();   
     scanf("%d",&opmenu);
     switch(opmenu){
        case 1: //insere
               printf("Informe o item que deseja adicionar: ");
               scanf("%d",&item);
               li=lista_insere(li,item);
               break;
        case 2:  //retira
             printf("Informe o item que deseja retirar: ");
             scanf("%d",&item);
             li=lista_retira(li,item); 
             break;
        case 3://mostra
		    if(lista_vazia(li))
			   printf("Lista vazia\n");
			else {
		  		  printf("\nLista:\n");
		          lista_mostra(li);
		      }
            break;
        case 4://busca
        	   printf("Informe o item que deseja buscar: ");
               scanf("%d",&item);
               aux=lista_busca(li,item);
               if (aux==NULL)
                   printf("%d NAO encontrado!\n",item);
                else
                	printf("%d Encontrado!\n",aux->info);
               break;
        }//fim switch
   printf("\n");
   system("pause");
   }while(opmenu!=9);
   lista_libera(li);
}
