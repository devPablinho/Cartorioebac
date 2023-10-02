#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das Strings

int registro()//Fun��o para registrar os nomes dos usu�rios
	{
		//In�cio cria��o de vari�veis/string
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		char telefone[40];
		//Final da cria��o de vari�veis/string
		
		printf("Digite o CPF a ser cadastrado: ");//Coletando inform��es do usu�rio
		scanf("%s",cpf);//%s refere-se a string
		
		strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
		
		FILE *file; //cria o arquivo no banco de dados
		file = fopen(arquivo, "w"); //cria o arquivo e o "W" significa escrever
		fprintf(file, cpf); // salvo o valor da vari�vel 
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
		
		printf("Digite o nome a ser cadrastrado: ");
		scanf("%s", nome);
		
		file = fopen(arquivo, "a");
		fprintf(file, nome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
		
		printf("Digite o sobrenome a ser cadastrado: ");
		scanf("%s", sobrenome);
		
		file = fopen(arquivo, "a");
		fprintf(file, sobrenome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);	
		
		printf("Digite o cargo a ser cadastrado: ");
		scanf("%s", cargo);
		
		file = fopen(arquivo, "a");
		fprintf(file, cargo);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
		
		printf("Digite o telefone a ser cadastrado: ");
		scanf("%s", telefone);
		
		file = fopen(arquivo, "a");
		fprintf(file, telefone);
		fclose(file);
		
		system("pause");
		
	}

int consultar()//Fun��o para consulta os nomes
	{
		setlocale(LC_ALL, "Portuguse");//Definindo a linguagem
		
		//in�cio da cria��o das vari�veis/string
		char cpf[40];
		char conteudo[200];
		//fim da cria��o das vari�veis/string
		
		printf("Digite o CPF a ser consultado: ");//coletando a informa��o do usu�rio
		scanf("%s", cpf);//armazanendo a informa��o do usu�rio
		
		FILE *file; //Consulta na biblioteca FILE a fun��o file
		file = fopen(cpf, "r");// Abre o arquivo file e pede para ler o mesmo
		
		if(file == NULL)
		{
			printf("N�o foi poss�vel localizar o arquivo consultado!\n");
			
		}
		
		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\nEssas s�o as informa��es do usu�rio: \n");
			printf("%s", conteudo);
			printf("\n\n");
		}
		
		system("pause");
	
	}

int deletar()//Fun��o para deletar os nomes
	{	
		char cpf[40];
		
		printf("Digite o CPF do usu�rio a ser deletado: ");
		scanf("%s", cpf);
		
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
		{
			printf("O usu�rio n�o foi encontrado no sistema!\n");
			system("pause");
		}
			
		
		}

int main()//Fun��o main/principal e cria��o do menu
	{
	int opcao=0;// Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{	 
		
		system("cls");

		setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
	
		//In�cio do menu
		printf("\t### Cart�rio da EBAC ###\n\n"); 
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o:");//Fim do menu
	
		scanf("%d", &opcao);//Armazena a escolha do usu�rio
	
		system("cls");//Limpa a tela para o usu�rio
		
		switch(opcao)//Inicio da sele��o do menu
		{
			case 1:
			registro(); //chamada da fun��o registro
			break;
			
			case 2:
			consultar();//chamada da fun��o consultar
			break;
			
			case 3:
			deletar();//chamada da fun��o deletar
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Est� op��o n�o est� dispon�vel\n");
			system("pause");
			break;// Final da sele��o
		}
}
}

