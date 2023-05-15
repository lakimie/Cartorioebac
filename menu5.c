#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar dos string
int registro () //Fun��o responsalvel por cadastrar os usu�rios no sistema
{
    //inicio cria��o de vari�veis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da vari�veis/string

    printf("Digite o CPF  a ser cadastrado: "); //coletando informa��o do usu�rio
    scanf("%s", cpf); //%s refere-se a string

    strcpy(arquivo, cpf);//reponsavel por copiar os valores das string

    FILE *file; // cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo e o "w"� de write/escrever
    fprintf(file, cpf); //salva o valor da var�avel
    fclose(file); // fecha o arquivo

    file = fopen(arquivo,"a"); //atualiza o arquivo
    fprintf(file, ",");//coloca a virgula
    fclose(file);

    printf("Digite o nome a ser cadastrado: "); //coletando informa��es do usu�rio
    scanf("%s", nome);// refere-se a string

    file = fopen(arquivo, "a"); //atualiza o arquivo
    fprintf(file, nome);//salva o valor na variavel
    fclose(file);//fecha

    file = fopen(arquivo,"a");//atualiza o arquivo
    fprintf(file, ",");//coloca a virgula
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");//coletando informa��es
    scanf("%s", sobrenome);//refere-se a string

    file = fopen(arquivo, "a");//atualizando o arquivo
    fprintf(file, sobrenome);//salva o valor da variavel
    fclose(file);

    file = fopen (arquivo, "a");//atualizada o arquivo
    fprintf(file, ",");//coloca a virgula
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");//coletando informa��es
    scanf("%s", cargo);//refere-se a string

    file = fopen(arquivo, "a");//atualiza o arquvio
    fprintf(file, cargo);//salva o valor da variavel
    fclose(file);//fecha

    system("pause");//o sistema para por uns segundos para o usu�rio poder ler/escolher

}

int consulta ()
{
    setlocale(LC_ALL, "Portuguese");//a linguagem escolhida

    //inicio da v�riavel/string
    char cpf[40];
    char conteudo[200];
    //fim da varival/string

    printf("Digite um CPF a ser consultado: ");//coletando informa��es
    scanf("%s", cpf);//refere-se a string

    FILE *file;//cria o arquivo
    file = fopen(cpf,"r");//cria o arquivo e o "r" � para ler

    if(file == NULL)
    {
        printf("N�o foi poss�vel abrir o arquivo, n�o localizado!. \n");
    }

    while(fgets(conteudo, 200, file) != NULL)
    {
        printf("Essas s�o as informa��es do usu�rio: ");
        printf("%s", conteudo);
        printf("\n\n");
    }

    system("pause");
}

int deletar ()
{
   char cpf[40];

   printf("Digite o CPF do usu�rio a ser deletado: ");
   scanf("%s", cpf);


   remove("cpf");


   FILE *file;
   file = fopen(cpf,"r");

   if(file == NULL)
   {
       prinft("Usu�rio n�o se encontra no sistema!. \n");
       system (pause);

   }

   else
   {
       remove("cpf");
       printf("Usu�rio deletado com sucesso!. \n");
       system (pause);
   }


}


int main()
{
    int opcao=0; //Definindo vari�veis
    int laco=1;

    for(laco=1;laco=1;)
    {
        system("cls"); //respons�vel por limpar a tela


        setlocale(LC_ALL, "Portuguese"); //Defiindo a linguagem

        printf("###Cart�rio da EBAC###\n\n");
        printf("Escolha a op�ao desejada do menu: \n\n");
        printf("\t1 - Registrar nome\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Excluir nomes\n\n");
        printf("Op��o:");

        scanf ("%d",&opcao); //Armazenando informa��oes

        system ("cls");

        switch(opcao)
        {
            case 1:
            registro(); //chamada de fun��es
            break;

            case 2:
            consulta(); //chamada de fun��es
            break;

            case 3:
            deletar(); //chamada de fun��es
            break;

            default:
            printf("Essa op��o n�o est� dispon�vel\n");
            system("pause");
            break;

            //fim da sele��o

        }

    }
}
