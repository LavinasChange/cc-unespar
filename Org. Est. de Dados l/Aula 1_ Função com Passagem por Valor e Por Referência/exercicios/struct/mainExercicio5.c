#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct aluno{
      int codigo;
      char nome[50];
      char curso[50];
      char disciplina[50];
      float nota;      
};

struct aluno listaDeAlunos[50];

main(){
       setlocale(LC_ALL, "");   
       int i;
       int contador = 0;
       float soma = 0; 
       for (i = 0; i < 50; i++){
         printf("Digite o c�digo do %d� aluno: ", i + 1); 
         scanf("%d", &listaDeAlunos[i].codigo);
         if ((listaDeAlunos[i].codigo) == 0){                     
            break;                            
         }                                                        
         printf("Digite o nome do %d� aluno: ", i + 1);    
         setbuf(stdin, NULL);         
         gets(listaDeAlunos[i].nome);          
         printf("Digite o curso do %d� aluno: ", i + 1);    
         setbuf(stdin, NULL);         
         gets(listaDeAlunos[i].curso); 
         printf("Digite a disciplina do %d� aluno: ", i + 1);    
         setbuf(stdin, NULL);         
         gets(listaDeAlunos[i].disciplina);
         printf("Digite a nota do %d� aluno: ", i + 1);  
         scanf("%f", &listaDeAlunos[i].nota); 
         soma = soma + listaDeAlunos[i].nota;
         contador++;
         printf("\n");                 
      }    
            
      printf("\n--------------------------------------------");    
      if (contador > 0){                       
         printf("\nM�dia da notas dos %d alunos: %.2f", contador, soma / contador);          
      }else{
          printf("N�o h� notas para realizar a m�dia.");    
      }      
      printf("\n--------------------------------------------\n\n");      
      printf("\n");
      printf("\n");  
      system("PAUSE");
}
