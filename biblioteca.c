#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 200
#define M 10 //number of math books

// library book database
int openFile(char *nameOfMatter, int counter, int codeMatter);
int retiradaDeLivro(char *chosenBook, int withdrawalLine, int codeMatter);

typedef struct
{
    char writer[MAX];
    char content[MAX];
    char nome[MAX];

} dados;

typedef struct
{
    dados dados;

} materia;

materia descricao[MAX];

//codeMatter
// 0 = matematica
// 1 = geografia
// 2 = historia
// 3 = sociologia
// 4 = fisica
// 5 = quimica
// 6 = sociologia
// 7 = estudos gerais
// 8 = teologia

void clean(void);

int main(void)
{
    FILE *math;
    FILE *livros;
    int escolhaDoUsuario, tamanhoDoNome;
    char nomeDoUsuario[MAX];
    int quantidadeDeLivros, adicaoDeLivro, codeMatter, resetDeLivro;
    int counter = 0;
    int withdrawalLine;
    char *livroRetirado[MAX];

    printf("Voce deseja adicionar um novo livro na biblioteca? [1] Sim ou [2] Nao.\n");
    scanf("%d", &adicaoDeLivro);
    printf("Voce deseja resetar os livros? [1] Sim ou [2] Nao\n");
    scanf("%d", &resetDeLivro);
    if (resetDeLivro == 1)
    {
        printf("Digite o código da matéria que você quer resetar: ");
        scanf("%d", &codeMatter);
        if (codeMatter == 0)
        {
            math = fopen("math.csv", "w");
            math = fopen("math.csv", "a");
            fprintf(math, "%s, %s, %s\n", "nome", "writer", "content");
            fclose(math);
        }

        return 0;
    }

    if (adicaoDeLivro == 1)
    {
        //banco de livros
        printf("Digite a quantidade de livros que voce quer armazenas.\n");
        scanf("%d", &quantidadeDeLivros);
        printf("Digite o código da matéria que você quer armazenar: ");
        scanf("%d", &codeMatter);
        system("clear");

        getchar();
        for (int i = 0; i < quantidadeDeLivros; i++)
        {
            if (codeMatter == 0)
            {
                math = fopen("math.csv", "a");
            }

            printf("Digite o nome do livro.\n");
            fgets(descricao[codeMatter].dados.nome, MAX, stdin);
            tamanhoDoNome = strlen(descricao[codeMatter].dados.nome);
            if (descricao[codeMatter].dados.nome[tamanhoDoNome - 1] == '\n')
            {
                descricao[codeMatter].dados.nome[tamanhoDoNome - 1] = '\0';
            }

            printf("Digite o writer do livro.\n");
            fgets(descricao[codeMatter].dados.writer, MAX, stdin);
            tamanhoDoNome = strlen(descricao[codeMatter].dados.writer);
            if (descricao[codeMatter].dados.writer[tamanhoDoNome - 1] == '\n')
            {
                descricao[codeMatter].dados.writer[tamanhoDoNome - 1] = '\0';
            }

            printf("Digite o content do livro.\n");
            fgets(descricao[codeMatter].dados.content, MAX, stdin);
            tamanhoDoNome = strlen(descricao[codeMatter].dados.content);
            if (descricao[codeMatter].dados.content[tamanhoDoNome - 1] == '\n')
            {
                descricao[codeMatter].dados.content[tamanhoDoNome - 1] = '\0';
            }

            //armazenamento em matematica
            if (codeMatter == 0)
            {
                fprintf(math, "%s, %s, %s\n", descricao[codeMatter].dados.nome, descricao[codeMatter].dados.writer, descricao[codeMatter].dados.content);
                fclose(math);
            }

            system("clear");
        }

        return 0;
    }

    getchar();
    system("clear");

    printf(" __________________________________________\n"
           " |                                         |\n"
           " |                                         |\n"
           " |                                         |\n"
           " |                                         |\n"
           " |     Welcome to libraby Penbookers       |\n"
           " |                                         |\n"
           " |                                         |\n"
           " |                                         |\n"
           " |_________________________________________|\n");

    printf("Digite uma tecla para avancar.\n");
    getchar();

    system("clear");

    printf("Digite seu nome: ");

    fgets(nomeDoUsuario, MAX, stdin);
    //retirada do espaço que o fgets
    tamanhoDoNome = strlen(nomeDoUsuario);
    if (nomeDoUsuario[tamanhoDoNome - 1] == '\n')
    {
        nomeDoUsuario[tamanhoDoNome - 1] = '\0';
    }
    system("clear");

    printf("Bem vindo %s a biblioteca Penbookers\n", nomeDoUsuario);
    printf("\n");

    printf("Escolha uma das opcoes abaixo\n"
           "1 - Escolher um livro para estudar na biblioteca.\n"
           "2 - Escolher um livro para levar.\n"
           "3 - Saber quanto tempo falta para entrega do meu livro.\n"
           "4 - Saber alguma informacao sobre o livro, qual é o writer e afins.\n");
    printf("Digite o que voce deseja.\n");
    scanf("%d", &escolhaDoUsuario);
    system("clear");

    switch (escolhaDoUsuario)
    {
    case 1:

        printf("Veja os generos disponiveis:\n"
               "1 - Livros de estudo.\n"
               "2 - Livros de Romance.\n"
               "3 - Livros de crianças.\n"
               "4 - Livros de ficcao.\n");

        printf("Digite o que voce deseja: ");
        scanf("%d", &escolhaDoUsuario);

        system("clear");
        switch (escolhaDoUsuario)
        {
        case 1:
            printf("Escolha a disciplina:\n"
                   "1 - Matemática. \n"
                   "2 - Geografia.\n"
                   "3 - História.\n"
                   "4 - Sociologia.\n"
                   "5 - Fisica.\n"
                   "6 - Química.\n"
                   "7 - Filosofia.\n"
                   "8 - Estudos gerais.\n"
                   "9 - Teologia.\n");
            printf("Digite o que voce deseja:\n");
            scanf("%d", &escolhaDoUsuario);
            system("clear");

            switch (escolhaDoUsuario)
            {
            case 1:
                codeMatter = 0;

                //exposição dos livros de matematica
                for (int i = 0; i < M; i++)
                {
                    counter = openFile(descricao[i].dados.nome, counter, codeMatter);
                    printf("%s\n", descricao[i].dados.nome);
                }
                printf("Voce deseja retirar algum livro? [1] SIM ou [2] NAO\n");
                scanf("%d", &escolhaDoUsuario);
                if (escolhaDoUsuario == 1)
                {
                    printf("Digite o numero presente antes do livro para retirar:\n");
                    scanf("%d", &withdrawalLine);
                    retiradaDeLivro(livroRetirado, withdrawalLine, codeMatter);
                    printf("Seu livro retirado foi: %s\n", livroRetirado);
                }
                else
                {
                    break;
                }
                break;
            }
        case 2:
            //exposição dos livros de geografia

            break;
        }
        break;

    case 2:
        printf("Veja os generos disponiveis:\n"
               "1 - Livros de estudo.\n"
               "2 - Livros de Romance.\n"
               "3 - Livros de crianças.\n"
               "4 - Livros de ficcao.\n");
        break;
    }
}

// leitura do arquivo
int openFile(char *nameOfMatter, int counter, int codeMatter)
{
    int codigo = codeMatter;
    counter++;
    FILE *math;
    if (codigo == 0)
    {
        math = fopen("math.csv", "r");
    }

    char buffer[MAX];
    int i = 0;
    do
    {
        if (codigo == 0)
        {
            //o fgets ler tudo ate achar um \n e armazena tudo em buffer
            fgets(buffer, MAX, math);
            fscanf(math, "%[^,]", nameOfMatter);
            i++;
        }

    } while (i < counter);
    if (codigo == 0)
    {
        fclose(math);
    }

    return counter;
}

//funcao para retirada de livro

int retiradaDeLivro(char *chosenBook, int withdrawalLine, int codeMatter)
{
    FILE *math;
    if (codeMatter == 0)
    {
        math = fopen("math.csv", "r");
    }
    
    FILE *retirada = fopen("transferindo.csv", "w");
    char buffer[MAX];
    int linhaAtual = 1;
    int counter = 0;
    

    if (codeMatter == 0)
    {
        while (fgets(buffer, MAX, math) != NULL)
        {
            if (linhaAtual != withdrawalLine)
            {
                fputs(buffer, retirada);
            }
            //ajeitar a retirada de livro

            strcpy(chosenBook, buffer);
            memset(buffer, 0, sizeof(char) * MAX);
            linhaAtual += 1;
        }
        fclose(math);
    }
    
  
    //ele modifica o livro, para retirar somente o nome
    while (1)
    {
        if (chosenBook[counter] == ',')
        {
            chosenBook[counter] = '\0';
            break;
        }
        counter++;
    }

    fclose(retirada);
    remove("math.csv");
    rename("transferindo.csv", "math.csv");
    return 0;
}
