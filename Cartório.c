#include <stdio.h> // biblioteca de comunicação do usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string
int registro() //Função responsavel por cadastrar usuario no sistema
{
	//Inicio de criação de variáveis/string	
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];	
    //Final da criação de variáveis/string	
    
    printf("Digite o CPF a ser cadastrado:"); //Coletando informação	 do usuário
    scanf("%s", cpf);//%s refere-se a string
    
    strcpy(arquivo, cpf);	// responsavel por copiar os valores das string	
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo,"w"); //cria o arquivo e o "w" significa escrever
    fprintf(file,cpf); //salva o valor da variavel 
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
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
    scanf("%S", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);
    
    system("pause");
    
    
    		
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese"); //definindo a linguagem
    char cpf[40];
    char conteudo[200];
    	
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");		
    
    if(file == NULL)
    {
       printf(	"Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	
	{
	printf("\nEssas são as informações do usuário: ");
	printf("%s", conteudo);
	printf("\n\n");					
	}
	system("pause");
}

int deletar()
{		
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);	
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
}
 


int main()
									
    {
    int opcao=0;
    int laco=1;
    
    for(laco==1; laco==1;)
    {
	    system("cls");//responsavél por limpar a tela
	
	    setlocale(LC_ALL,"Portuguese"); //definindo a linguagem
    	printf("### Cartório da EBAC ### \n\n"); //inicio do menu
    	printf("escolha sua opção desejada no menu\n\n");
    	printf("\t1 registrar nomes\n"); 
    	printf("\t2 consultar nomes\n");
    	printf("\t3 deletar nomes\n\n");
    	printf("Opção:"); //final do menu
	
	    scanf("%d", &opcao); //armazenando a escolha do usuário
	    
	    system("cls");
	    
	     switch(opcao) //Inicio da seleção do menu	
	    {
		 	
	       case 1:			
	       registro();//chamada de funções
		   break;
		
		   case 2:
	       consulta();		
		   break;
	    
	       case 3:	
	       deletar();	
	       break;
	    
	    
	       default:
	       printf("Essa opção não está disponivel!\n");	
	       system("pause");
	       break;
	    }
	}
}
	    
