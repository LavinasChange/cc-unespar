#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>


typedef struct noarv {
        struct noarv *esq;
        int info;       // Declara��o da estrutura do n� da �rvore
        struct noarv *dir;
        } tnoarv;
        
typedef tnoarv *tArv;



//representa a raiz da �rvore(primeiro elemento)
tArv t = NULL;

//====================================================================================
// fun��o para posicionamento dos caracteres na tela
void gotoxy(int x, int y){
     COORD coord;
     HANDLE handle;
     handle = GetStdHandle(STD_OUTPUT_HANDLE);
     coord.X = x;
     coord.Y = y;
     SetConsoleCursorPosition(handle, coord);
}
//====================================================================================
void exibir_arvore(tArv T, int col, int lin, int desloc){

  if (T == NULL) {
    return;
  }  
  gotoxy(col, lin);
  printf("(%d)\n", T->info);
  if (T->esq != NULL)
     exibir_arvore(T->esq, col - desloc, lin + 2, desloc / 2 + 1);
  if (T->dir != NULL)
     exibir_arvore(T->dir, col + desloc, lin + 2, desloc / 2 + 1);
}

//====================================================================================
// Verifica se o n� � nulo
int arvore_vazia(tArv t){
    return (t == NULL);
}
//====================================================================================
void inserir(tArv *t, int dado){
  if (*t == NULL) {  // se t aponta para null, a inser��o � na raiz...
    *t = (tnoarv *) malloc(sizeof(tnoarv));
    if (*t == NULL) 
       return;
    (*t)->esq = NULL;
    (*t)->dir = NULL;
    (*t)->info = dado;
  }
  if (dado < (*t)->info) { // Se o dado a ser inserido for menor que o n� atual, recursividade � esquerda
     inserir(&((*t)->esq), dado);
  } else {
    if (dado > (*t)->info) { // Se o dado a ser inserido for menor que o n� atual, recursividade � direita
       inserir(&((*t)->dir), dado);
    }
  }
}
//===============================================================================================
tArv minimo(tArv T){// procura o n� com valor m�nimo
    if(arvore_vazia(T)){
       return NULL;
    }else{
          if( arvore_vazia(T->esq) ){
              return T;
          }else{
              return minimo(T->esq);
          }
    }
}
//===============================================================================================
tArv maximo(tArv T){// procura o n� com valor m�ximo
     if(!arvore_vazia(T)){
       while( !arvore_vazia(T->dir) ){
          T = T->dir;
       }
     }
     return T;
}

//===============================================================================================
void remover(tArv *raiz, int valor){
    tArv aux;
    if(!arvore_vazia(*raiz)){
       // se o valor que ser� removido for menor que o n� atual,                                    
       if(valor < (*raiz)->info){ 
           // faz recursividade � esquerda     
           remover(&((*raiz)->esq), valor); 
       }else{
            // se o valor que ser� removido for maior que o n� atual, 
            if(valor > (*raiz)->info){ 
                 // faz recursividade � direita.    
                 remover(&((*raiz)->dir), valor); 
            }else{                
                // entra aqui caso tenha encontrado o elemento
                // verificamos se os n�s filhos da esquerda e direita n�o s�o null.                
                if( !arvore_vazia((*raiz)->esq) && !arvore_vazia((*raiz)->dir) ){ // quando o n� a ser removido for encontrado,                
                     // se n�o forem null, buscamos o menor n� a partir do n� da direita.
                     aux = minimo((*raiz)->dir); 
                     (*raiz)->info = (aux->info);
                     remover(&(*raiz)->dir, (*raiz)->info);
                }else{ 
                     // caso os n� da direita e da esqueda, ou somente o da direita, precisamos apenas remover  
                     // o n� atual e ajustar os ponteiros 
                     aux = *raiz;                      
                     // se o n� da esquerda for vazio
                     if(arvore_vazia((*raiz)->esq)) {
                         // o n� pai do atual, apontar� para o filho da direita do n� atual.
                         *raiz = (*raiz)->dir; 
                     // se o n� da esquerda n�o for vazio. 
                     } else{ 
                         // o n� pai do atual, apontar� para o filho da esquerda do n� atual.
                         *raiz = (*raiz)->esq; 
                     }    
                     free(aux);
                }
            }     
        } 
    }  
}

//====================================================================================
// A fun��o pesquisa nos n�s da �rvore o valor passado como par�metro, caso o valor esteja
// na �rvore, ela retorna este n� que est� o valor.
tArv busca_elemento(tArv t, int dado){
     tArv achou;
     if (arvore_vazia(t)) 
        return NULL;
     if (t->info == dado) 
        return t;
     achou = busca_elemento(t->esq, dado);
     if (arvore_vazia(achou))
         achou = busca_elemento(t->dir, dado);
     return achou;
}



void exibe_emordem(tArv t){
  if (t == NULL) {
     return ;
  }   
  if (t->esq != NULL){
      exibe_emordem(t->esq);
  }
  printf("(%d)", t->info);
  if (t->dir != NULL){
      exibe_emordem(t->dir);
  }    
}

void preordem (tArv t) { 
     if (t == NULL){
         return ;
     }    
     printf("(%d)", t->info);
     if (t->esq != NULL){
        preordem(t->esq);
     }  
     if (t->dir != NULL){
        preordem(t->dir);
     }         
} 

void posordem(tArv t) {
     if (t == NULL){ 
        return ;    
     }    
     if (t->esq != NULL){
        posordem(t->esq);
     }  
     if (t->dir != NULL){
        posordem(t->dir);
     }  
     printf("(%d)", t->info);       
}

void mostraArvore(){
     if(t == NULL){
          gotoxy(32,10); printf("ARVORE VAZIA");
     }else{
          exibir_arvore(t,37,10,15);gotoxy(1,1);
     } 
}     

int main(){
  int elemento, op;
  do{
    system("cls");
    printf("1 - Inserir\n");
    printf("2 - Excluir\n");
    printf("3 - Listar - Em-Ordem\n");
    printf("4 - Listar - Pre-Ordem\n");
    printf("5 - Listar - Pos-Ordem\n"); 
    printf("6 - Buscar Elemento\n");                  
    printf("0 - Sair\n");
    printf("Digite a opcao:");
    scanf("%d",&op);           
    // system("cls");           
    if(op == 1){
         printf("Digite o elemento:");
         scanf("%d",&elemento);
         inserir(&t,elemento);
         mostraArvore();
    } else if(op == 2){           
         printf("Digite o elemento:");
         scanf("%d",&elemento);
         remover(&t,elemento);
         mostraArvore();         
    } else if(op == 3){
         exibe_emordem(t);
         mostraArvore();
    } else if(op == 4){
         preordem(t);
         mostraArvore();         
    } else if(op == 5){
         posordem(t); 
         mostraArvore();         
    } else if(op == 6){
         int numero;  
         printf("Informe o elemento para a busca: ");
         scanf("%d", &numero);
         tArv r = busca_elemento(t, numero);
         if(r != NULL){
              printf("\nO elemento esta inserido na arvore!");
         }else{
              printf("\nElemento nao encontrado!\n");  
         }                   
    }        
    getch();
  }while(op!=0);
}


