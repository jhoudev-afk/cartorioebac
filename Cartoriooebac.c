#include <stdio.h>  //biblioteca de comunica��o com o usuario 
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria 
#include <locale.h> //biblioteca de aloca��es de texto por regi�o 
#include <string.h> //biblioteca respons�vel por cuidar das string 

int registro() //fun��o responsavel por cadastrar os usuarios no sistema 
{
	//inicio da cria��o de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variaveis/strings
	
	
	printf("Digite o CPF a ser cadastrado: "); //coletando forma��o do usuario 
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);//responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w");//cria arquivo e o 'w' significa escrever 
	fprintf(file,cpf);//salva o valor da variavel 
	fclose(file);//fecha o arquivo 
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system ("pause");
	
	
		
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem 
	
  	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o loocalizado!.\n");	
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
   }
   
   	system("pause");   
   
}


int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file >= 1)
	{
		printf("CPF DELETADO!\n");
		system("pause");
	}
	
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se conta no sistema!.\n");
		system("pause");
		
	}
		
}



int main()
{
	int opcao=0; //Definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //responsavel por limpar a tela 
	
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem 
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Ecolha a op��o desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n");
	printf("\t4 - Sair do sistema\n\n");
	printf("Op��o: "); //fim do menu 
	
	scanf("%d", &opcao); //armazenando a escolha do usu�rio 
	
	system("cls");
	
	switch(opcao)
	{
		case 1:
		registro(); //chamada de fun��o 
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		case 4:
		printf("Obrigado por utilizar o sistema!\n");
		return 0;
		break;
			
	
		
		default:
		printf("Essa op��o n�o esta disponivel!\n");
		system("pause");
		break;	
		// fim da sele�o 
		}
        }
	
}
