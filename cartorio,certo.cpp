#include <stdio.h> //biblioteca de comunica��a
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de texto da regi�o
#include <string.h>//biblioteca de armazenamento de dados de string

int registro()//fun��o de registrar o usu�rio
{
	//strings/conjunto de vari�veis
	char arquivo[40];
	char cpf [40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final do conjunto
	
	
	printf("Digite o cpf que quer cadastrar: ");//comando p�s o usu�rio apertar 1
	scanf("%s", cpf);//refere-se a string
	strcpy(arquivo,cpf); //respons�vel por copiar os valores da string
	
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e j� escreve
	fprintf(file, cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file=fopen(arquivo, "a");//adiciona no arquivo a informa��o
	fprintf(file, ",");//adiciona v�rgula no cadastro do usu�rio
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome que quer cadastrar: ");
	scanf("%s", nome);//refere-se a string/vari�veis
	file=fopen(arquivo, "a");//adiciona no arquivo a informa��o
	fprintf(file,nome);//adiciona o nome como infirma��o/dado
	fclose(file);//fecha o arquivo
	
	file=fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf ("Digite o sobrenome que quer cadastrar: ");
	scanf("%s", sobrenome);
	file=fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file=fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf ("Digite o cargo que quer cadastrar: ");
	scanf("%s", cargo);
	file=fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");//pausa para o usu�rio
}

int consulta()
{
	    setlocale(LC_ALL, "Portuguese");//definindo idioma
	    
	    //string
	    char cpf[40];
	    char conteudo[200];
	    
	    printf ("Digite o CPF a ser consultado: ");//frase para que aparece para o usu�rio
	    scanf("%s", cpf);//refere-se a string
	    
	    FILE *file;
	    file = fopen(cpf,"r");
	    
	    if(file == NULL)//if de "caso" o usu�rio digite algo n�o cadastrado
	    {
	    	printf("N�o foi poss�vel abrir o arquivo\n");
		}
		
		while(fgets(conteudo, 200, file) != NULL)//enquanto o sistema puxa a informa��o aparecer� a mensagem seguinte
		{
			printf("\nEssas s�o as informa��es do usu�rio: ");
			printf("%s", conteudo);//puxa a info das strings
			printf("\n\n");//est�tica apenas
		}
		system("pause");
}

int deleta()
{
     	char cpf[40];//string
		 
	    printf("Digite o cpf do usu�rio que deseja deletar:\n");
		scanf("%s", cpf);//puxa dos dados salvos
		
		remove(cpf);//deleta o arquivo
		
		FILE *file;
		file = fopen(cpf,"r");//fun��o de ler os arquivos cadastrados
		
		if(file == NULL)
		{
			printf("Esse usu�rio n�o se encontra no sistema!\n");
			system("pause");
		}
}

int main()
    {
	int opcao=0; //definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	    system("cls");
	
	
        setlocale(LC_ALL, "Portuguese");//definindo idioma
	
	    printf("\t CART�RIO \n\n");//pagina inicial
	    printf("Escolha a op��o desejada do menu:\n\n\n");
     	printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n\n");//fim do menu
    	printf("\tOp��o: \n");
	
    	scanf("%d", &opcao);//armazenando a escolha
	
	   system("cls");//limpa p�gina p�s sele��o
	   
	          switch(opcao)
        { 
		case 1:
			registro();
		break;//pausa para a pr�xima etapa
		
		case 2:
			consulta();
	    break;
		
		case 3:
		    deleta();
	    break;
		
		default:
			printf("\tEssa op��o n�o existe\n");
	        system("pause");
		break;    
       	}
    }
}
