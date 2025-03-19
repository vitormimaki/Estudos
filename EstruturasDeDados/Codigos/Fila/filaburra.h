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
        
void fila_insere(Fila *f, float v){
    int fim;
    if(f->n==N){ //fila cheia
      printf("Capacidade da fila esgotada.\n");
      return; //retorna ao programa 
      }
      //insere novo elemento
      f->vet[f->n]=v;
      f->n++; 
}     
         
int fila_vazia(Fila *f){
    return(f->n==f->ini);
}

void compacta(Fila *f){
	int i;
	for(i=0;i<f->n;i++){
		f->vet[i]=f->vet[i+1];//desloca os elementos 1 posição a frente
	}
	f->n--;//corrige o fim
}

float fila_retira(Fila *f){
     float v;
     //retira o elemento da fila
     v=f->vet[f->ini];
     //f->ini++;
     compacta(f);
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

