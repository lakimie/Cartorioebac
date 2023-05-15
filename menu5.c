#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar dos string
int registro () //Função responsalvel por cadastrar os usuários no sistema
{
    //inicio criação de variáveis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da variáveis/string

    printf("Digite o CPF  a ser cadastrado: "); //coletando informação do usuário
    scanf("%s", cpf); //%s refere-se a string

    strcpy(arquivo, cpf);//reponsavel por copiar os valores das string

    FILE *file; // cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo e o "w"é de write/escrever
    fprintf(file, cpf); //salva o valor da varíavel
    fclose(file); // fecha o arquivo

    file = fopen(arquivo,"a"); //atualiza o arquivo
    fprintf(file, ",");//coloca a virgula
    fclose(file);

    printf("Digite o nome a ser cadastrado: "); //coletando informaçòes do usuário
    scanf("%s", nome);// refere-se a string

    file = fopen(arquivo, "a"); //atualiza o arquivo
    fprintf(file, nome);//salva o valor na variavel
    fclose(file);//fecha

    file = fopen(arquivo,"a");//atualiza o arquivo
    fprintf(file, ",");//coloca a virgula
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");//coletando informaçòes
    scanf("%s", sobrenome);//refere-se a string

    file = fopen(arquivo, "a");//atualizando o arquivo
    fprintf(file, sobrenome);//salva o valor da variavel
    fclose(file);

    file = fopen (arquivo, "a");//atualizada o arquivo
    fprintf(file, ",");//coloca a virgula
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");//coletando informações
    scanf("%s", cargo);//refere-se a string

    file = fopen(arquivo, "a");//atualiza o arquvio
    fprintf(file, cargo);//salva o valor da variavel
    fclose(file);//fecha

    system("pause");//o sistema para por uns segundos para o usuário poder ler/escolher

}

int consulta ()
{
    setlocale(LC_ALL, "Portuguese");//a linguagem escolhida

    //inicio da váriavel/string
    char cpf[40];
    char conteudo[200];
    //fim da varival/string

    printf("Digite um CPF a ser consultado: ");//coletando informações
    scanf("%s", cpf);//refere-se a string

    FILE *file;//cria o arquivo
    file = fopen(cpf,"r");//cria o arquivo e o "r" é para ler

    if(file == NULL)
    {
        printf("Não foi possível abrir o arquivo, não localizado!. \n");
    }

    while(fgets(conteudo, 200, file) != NULL)
    {
        printf("Essas são as informações do usuário: ");
        printf("%s", conteudo);
        printf("\n\n");
    }

    system("pause");
}

int deletar ()
{
   char cpf[40];

   printf("Digite o CPF do usuário a ser deletado: ");
   scanf("%s", cpf);


   remove("cpf");


   FILE *file;
   file = fopen(cpf,"r");

   if(file == NULL)
   {
       prinft("Usuário não se encontra no sistema!. \n");
       system (pause);

   }

   else
   {
       remove("cpf");
       printf("Usuário deletado com sucesso!. \n");
       system (pause);
   }


}


int main()
{
    int opcao=0; //Definindo variáveis
    int laco=1;

    for(laco=1;laco=1;)
    {
        system("cls"); //responsável por limpar a tela


        setlocale(LC_ALL, "Portuguese"); //Defiindo a linguagem

        printf("###Cartório da EBAC###\n\n");
        printf("Escolha a opçao desejada do menu: \n\n");
        printf("\t1 - Registrar nome\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Excluir nomes\n\n");
        printf("Opção:");

        scanf ("%d",&opcao); //Armazenando informaçãoes

        system ("cls");

        switch(opcao)
        {
            case 1:
            registro(); //chamada de funções
            break;

            case 2:
            consulta(); //chamada de funções
            break;

            case 3:
            deletar(); //chamada de funções
            break;

            default:
            printf("Essa opção não está disponível\n");
            system("pause");
            break;

            //fim da seleção

        }

    }
}
