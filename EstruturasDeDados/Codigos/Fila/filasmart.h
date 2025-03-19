#define N 50
typedef struct {
        int n;//posicao final
        int ini;
        float vet[N];
        }Fila;

Fila *fila_cria(void){
      Fila *f=(Fila*)malloc(sizeof(Fila));
      f->n=0;
      f->ini=0;
      return f;
}      
void compacta(Fila *f){
	int i;
	for(i=0;i<f->n;i++){
		f->vet[i]=f->vet[i+f->ini];//desloca os elementos 1 posição a frente
	}
	f->n=f->n - f->ini;//corrige o fim 
    f->ini=0;//volta o inicio para 0
}

void fila_insere(Fila *f, float v){
    int fim;
    if(f->n==N){ //pode estar cheia
     int tamfila= f->n - f->ini;
     	if (tamfila<N){ //então cabe
       		compacta(f);
       		
		}
		else
	   		printf("Fila realmente cheia!");
	}
	f->vet[f->n]=v;
	f->n++;
}       
       
int fila_vazia(Fila *f){
    return(f->n==f->ini);
}

float fila_retira(Fila *f){
     float v;
     //retira o elemento da fila
     v=f->vet[f->ini];
     f->ini++;
     return v;
}

void fila_libera(Fila *f){
     free(f);
}   
                        
void fila_mostra(Fila *f){
     printf("Conteudo da fila\n");
     int i;
     for(i=f->ini;i<f->n;i++)
              printf("%0.f\n",f->vet[i]);
     printf("\n");
}               

