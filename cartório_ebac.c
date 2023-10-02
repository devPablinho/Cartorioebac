#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável por cuidar das Strings

int registro()//Função para registrar os nomes dos usuários
	{
		//Início criação de variáveis/string
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		char telefone[40];
		//Final da criação de variáveis/string
		
		printf("Digite o CPF a ser cadastrado: ");//Coletando informções do usuário
		scanf("%s",cpf);//%s refere-se a string
		
		strcpy(arquivo, cpf); //Responsável por copiar os valores das string
		
		FILE *file; //cria o arquivo no banco de dados
		file = fopen(arquivo, "w"); //cria o arquivo e o "W" significa escrever
		fprintf(file, cpf); // salvo o valor da variável 
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a");//abrindo o arquivo e o "a" é para adicionar
		fprintf(file, ",");//escrevendo a virgula
		fclose(file);//fecha o arquivo
		
		printf("Digite o nome a ser cadrastrado: ");//pede pro usuário digitar o nome
		scanf("%s", nome);// salvando a informação do usuário
		
		file = fopen(arquivo, "a");//abrindo o arquivo e o "a" é para adicionar
		fprintf(file, nome);//salva o valor da variável
		fclose(file);//fecha o arquivo
		
		file = fopen(arquivo, "a");//abrindo o arquivo e o "a" é para adicionar
		fprintf(file, ",");//escrevendo o arquivo
		fclose(file);//fecha o arquivo
		
		printf("Digite o sobrenome a ser cadastrado: ");//pede pro usuário digitar o sobrenome
		scanf("%s", sobrenome);//salva a informação do usuário
		
		file = fopen(arquivo, "a");//abrindo o arquivo e o "a" é para adicionar
		fprintf(file, sobrenome);//salva o valor da variavel
		fclose(file);//fecha o arquivo
		
		file = fopen(arquivo, "a");//abrindo o arquivo e o "a" é de para adicionar
		fprintf(file, ",");//escrevendo a virgula
		fclose(file);//fecha o arquivo
		
		printf("Digite o cargo a ser cadastrado: ");//pede pro usuário digitar o cargo
		scanf("%s", cargo);//salva a informação do usuário
		
		file = fopen(arquivo, "a");//abrindo o arquivo e o "a" é para adicionar
		fprintf(file, cargo);//salva o valor da variavel
		fclose(file);//fecha o arquivo
		
		file = fopen(arquivo, "a");//abrindo o arquivo e o "a" é para adicionar
		fprintf(file, ",");//escrevedno a virgula
		fclose(file);//fecha o arquivo
		
		printf("Digite o telefone a ser cadastrado: ");//Pede pro usuário digitar o telefone
		scanf("%s", telefone);//armazade a informação do usuário
		
		file = fopen(arquivo, "a");//abrindo o arquivo e o "a" é para adicionar
		fprintf(file, telefone);//salva o valor na variavel
		fclose(file);//fecha o arquivo
		
		system("pause");//pause o sistema para o usuário
		
	}

int consultar()//Função para consulta os nomes
	{
		setlocale(LC_ALL, "Portuguse");//Definindo a linguagem
		
		//início da criação das variáveis/string
		char cpf[40];
		char conteudo[200];
		//fim da criação das variáveis/string
		
		printf("Digite o CPF a ser consultado: ");//coletando a informação do usuário
		scanf("%s", cpf);//armazanendo a informação do usuário
		
		FILE *file; //Consulta na biblioteca FILE a função file
		file = fopen(cpf, "r");// Abre o arquivo file e pede para ler o mesmo
		
		if(file == NULL)//caso o arquivo for nulo/não encontrado
		{
			printf("Não foi possível localizar o arquivo consultado!\n");//mostra para o usuário que o arquivo não foi encontrado.
			
		}
		
		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\nEssas são as informações do usuário: \n");//pede para o usuário digitar a informação
			printf("%s", conteudo);//armazana a informação digitada
			printf("\n\n");
		}
		
		system("pause");//pausa o sistema
	
	}

int deletar()//Função para deletar os nomes
	{	
		char cpf[40];//criação da variável/string
		
		printf("Digite o CPF do usuário a ser deletado: ");//pede para o usuário digitar a informação/CPF
		scanf("%s", cpf);//armazena a irfomação digitada pelo o usuário
		
		remove(cpf);//remove o arquivo que o usuário digitou
		
		FILE *file;//consulta na biblioteca FILE a função file
		file = fopen(cpf,"r");//abre o arquivo e o "r" é para ler o arquivo
		
		if(file == NULL)//caso o arquivo não exista
		{
			printf("O usuário não foi encontrado no sistema!\n");//mostra para o usuário que o arquivo não foi encontrado/excluído
			system("pause");//pause o sistema
		}
			
		
		}

int main()//Função main/principal e criação do menu
	{
	int opcao=0;// Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{	 
		
		system("cls");

		setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
	
		//Início do menu
		printf("\t### Cartório da EBAC ###\n\n"); 
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção:");//Fim do menu
	
		scanf("%d", &opcao);//Armazena a escolha do usuário
	
		system("cls");//Limpa a tela para o usuário
		
		switch(opcao)//Inicio da seleção do menu
		{
			case 1:
			registro(); //chamada da função registro
			break;
			
			case 2:
			consultar();//chamada da função consultar
			break;
			
			case 3:
			deletar();//chamada da função deletar
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0; // quebra laço, quebra a função e sai do sistema
			break;
			
			default:
			printf("Está opção não está disponível\n");
			system("pause");
			break;// Final da seleção
		}
}
}

