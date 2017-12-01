#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct data{
     int dia;
     int mes;
     int ano;
}; 
     

struct aluno{
      char nome[50];
      char sobreNome[50];
      struct data dataNascimento;
      char rg[15];
      float mediaPrimeiroBimestre;
      float mediaSegundoBimestre;
};

struct aluno listaDeAlunos[3];

main(){
       setlocale(LC_ALL, "");   
       int  i;
       for (i = 0 ; i < 3; i++){
         printf("Digite o nome do %d� aluno: ",  i + 1); 
         setbuf(stdin, NULL);         
         gets(listaDeAlunos[i].nome);                  
         printf("Digite o sobrenome do %d� aluno: ", i + 1);    
         setbuf(stdin, NULL);         
         gets(listaDeAlunos[i].sobreNome);  
         printf("Digite o dia do nascimento do %d� aluno: ", i + 1);  
         scanf("%d", &listaDeAlunos[i].dataNascimento.dia); 
         printf("Digite o mes do nascimento do %d� aluno: ", i + 1);  
         scanf("%d", &listaDeAlunos[i].dataNascimento.mes); 
         printf("Digite o ano do nascimento do %d� aluno: ", i + 1);  
         scanf("%d", &listaDeAlunos[i].dataNascimento.ano);   
         printf("Digite o RG do %d� aluno: ", i + 1);    
         setbuf(stdin, NULL);         
         gets(listaDeAlunos[i].rg); 
         printf("Digite a m�dia do primeiro bimestre do %d� aluno: ", i + 1);  
         scanf("%f", &listaDeAlunos[i].mediaPrimeiroBimestre); 
         printf("Digite a m�dia do segundo bimestre do %d� aluno: ", i + 1);  
         scanf("%f", &listaDeAlunos[i].mediaSegundoBimestre);
         printf("\n");                 
      }    
      
      for (i = 0; i < 3; i++){
          printf("\n\nNome: %s", listaDeAlunos[i].nome);
          printf("\nSobrenome : %s", listaDeAlunos[i].sobreNome);
          printf("\nDia: %d", listaDeAlunos[i].dataNascimento.dia);
          printf("\nMes : %d", listaDeAlunos[i].dataNascimento.mes);
          printf("\nAno: %d", listaDeAlunos[i].dataNascimento.ano);
          printf("\nRG : %s", listaDeAlunos[i].rg);
          printf("\nM�dia Primeiro Bimestre: %.2f", listaDeAlunos[i].mediaPrimeiroBimestre);
          printf("\nM�dia Segundo Bimestre : %.2f", listaDeAlunos[i].mediaSegundoBimestre);
      }
      printf("\n");
      printf("\n");  
      system("PAUSE");
}
