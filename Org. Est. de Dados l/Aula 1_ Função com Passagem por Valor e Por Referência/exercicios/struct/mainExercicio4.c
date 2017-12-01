#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct estoque{
      int codigo;
      char nomeProduto[50];
      char corDoProduto[30];
      float quantidadeEstoque;
      float preco;
      char observacoes[150];
};

struct estoque listaDeEstoques[100];

main(){
       setlocale(LC_ALL, "");   
       int  i;
       for (i = 0; i < 100; i++){
         printf("Digite o c�digo do %d� produto: ", i + 1); 
         scanf("%d", &listaDeEstoques[i].codigo);
         if ((listaDeEstoques[i].codigo) == 0){                     
            break;                            
         }                                                        
         printf("Digite o nome do %d� produto: ", i + 1);    
         setbuf(stdin, NULL);         
         gets(listaDeEstoques[i].nomeProduto);          
         printf("Digite a cor do %d� produto: ", i + 1);    
         setbuf(stdin, NULL);         
         gets(listaDeEstoques[i].corDoProduto); 
         printf("Digite a quantidade em estoque do %d� produto: ", i + 1);  
         scanf("%f", &listaDeEstoques[i].quantidadeEstoque); 
         printf("Digite o pre�o do %d� produto: ", i + 1);  
         scanf("%f", &listaDeEstoques[i].preco);
         printf("Digite as observa��es do %d� produto: ", i + 1);    
         setbuf(stdin, NULL);         
         gets(listaDeEstoques[i].observacoes);
         printf("\n");                 
      }    
      
      for (i = 0; i < 100; i++){
          if (listaDeEstoques[i].codigo == 0){
             break;                           
          }   
          printf("\n--------------------------------------------");                           
          printf("\nC�digo: %d", listaDeEstoques[i].codigo);
          printf("\nNome do Produto: %s", listaDeEstoques[i].nomeProduto);
          printf("\nCOR: %s", listaDeEstoques[i].corDoProduto);
          printf("\nQuantidade em estoque: %.2f", listaDeEstoques[i].quantidadeEstoque);
          printf("\nPre�o: %.2f", listaDeEstoques[i].preco);
          printf("\nObserva��es: %s", listaDeEstoques[i].observacoes);
          printf("\n--------------------------------------------\n\n");
      }
      printf("\n");
      printf("\n");  
      system("PAUSE");
}
