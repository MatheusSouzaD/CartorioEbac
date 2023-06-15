#include <stdio.h> //biblioteca de comunicaçõa
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de texto da região
#include <string.h>//biblioteca de armazenamento de dados de string

int registro()//função de registrar o usuário
{
	//strings/conjunto de variáveis
	char arquivo[40];
	char cpf [40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final do conjunto
	
	
	printf("Digite o cpf que quer cadastrar: ");//comando pós o usuário apertar 1
	scanf("%s", cpf);//refere-se a string
	strcpy(arquivo,cpf); //responsável por copiar os valores da string
	
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e já escreve
	fprintf(file, cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file=fopen(arquivo, "a");//adiciona no arquivo a informação
	fprintf(file, ",");//adiciona vírgula no cadastro do usuário
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome que quer cadastrar: ");
	scanf("%s", nome);//refere-se a string/variáveis
	file=fopen(arquivo, "a");//adiciona no arquivo a informação
	fprintf(file,nome);//adiciona o nome como infirmação/dado
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
	
	system("pause");//pausa para o usuário
}

int consulta()
{
	    setlocale(LC_ALL, "Portuguese");//definindo idioma
	    
	    //string
	    char cpf[40];
	    char conteudo[200];
	    
	    printf ("Digite o CPF a ser consultado: ");//frase para que aparece para o usuário
	    scanf("%s", cpf);//refere-se a string
	    
	    FILE *file;
	    file = fopen(cpf,"r");
	    
	    if(file == NULL)//if de "caso" o usuário digite algo não cadastrado
	    {
	    	printf("Não foi possível abrir o arquivo\n");
		}
		
		while(fgets(conteudo, 200, file) != NULL)//enquanto o sistema puxa a informação aparecerá a mensagem seguinte
		{
			printf("\nEssas são as informações do usuário: ");
			printf("%s", conteudo);//puxa a info das strings
			printf("\n\n");//estética apenas
		}
		system("pause");
}

int deleta()
{
     	char cpf[40];//string
		 
	    printf("Digite o cpf do usuário que deseja deletar:\n");
		scanf("%s", cpf);//puxa dos dados salvos
		
		remove(cpf);//deleta o arquivo
		
		FILE *file;
		file = fopen(cpf,"r");//função de ler os arquivos cadastrados
		
		if(file == NULL)
		{
			printf("Esse usuário não se encontra no sistema!\n");
			system("pause");
		}
}

int main()
    {
	int opcao=0; //definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	    system("cls");
	
	
        setlocale(LC_ALL, "Portuguese");//definindo idioma
	
	    printf("\t CARTÓRIO \n\n");//pagina inicial
	    printf("Escolha a opção desejada do menu:\n\n\n");
     	printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n\n");//fim do menu
    	printf("\tOpção: \n");
	
    	scanf("%d", &opcao);//armazenando a escolha
	
	   system("cls");//limpa página pós seleção
	   
	          switch(opcao)
        { 
		case 1:
			registro();
		break;//pausa para a próxima etapa
		
		case 2:
			consulta();
	    break;
		
		case 3:
		    deleta();
	    break;
		
		default:
			printf("\tEssa opção não existe\n");
	        system("pause");
		break;    
       	}
    }
}
