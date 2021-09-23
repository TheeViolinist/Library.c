#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 200
#define M 10 //number of math books

// library book database
int openFile(char *nameOfMatter, int counter, int codeMatter);
int bookWithdrawal(char *chosenBook, int withdrawalLine, int codeMatter);

typedef struct
{
    char writer[MAX];
    char content[MAX];
    char name[MAX];

} data;

typedef struct
{
    data data;

} material;

material description[MAX];

//codeMatter
// 0 = math
// 1 = geography
// 2 = history
// 3 = sociology
// 4 = physics
// 5 = chemistry
// 6 = general studies
// 7 = theology


void clean(void);

int main(void)
{
    FILE *math;
    FILE *livros;
    int userChoice, nameSize;
    char nameUser[MAX];
    int numberBooks, bookAdd, codeMatter, restartBooks;
    int counter = 0;
    int withdrawalLine;
    char *withdrawnBook[MAX];

    printf("Do you wanna adding a book to library? [1] Yes or [2] No.\n");
    scanf("%d", &bookAdd);
    printf("Do you wanna reset the books? [1] Yes or [2] No\n");
    scanf("%d", &restartBooks);
    if (restartBooks == 1)
    {
        printf("Enter the code of the materiall you want to reset: ");
        scanf("%d", &codeMatter);
        if (codeMatter == 0)
        {
            math = fopen("math.csv", "w");
            math = fopen("math.csv", "a");
            fprintf(math, "%s, %s, %s\n", "name", "writer", "content");
            fclose(math);
        }

        return 0;
    }

    if (bookAdd == 1)
    {
        //data of books
        printf("Enter the number of books you want to store.\n");
        scanf("%d", &numberBooks);
        printf("Enter the code of the materiall you want to add: ");
        scanf("%d", &codeMatter);
        system("clear");

        getchar();
        for (int i = 0; i < numberBooks; i++)
        {
            if (codeMatter == 0)
            {
                math = fopen("math.csv", "a");
            }

            printf("Enter the name of the book.\n");
            fgets(description[codeMatter].data.name, MAX, stdin);
            nameSize = strlen(description[codeMatter].data.name);
            if (description[codeMatter].data.name[nameSize - 1] == '\n')
            {
                description[codeMatter].data.name[nameSize - 1] = '\0';
            }

            printf("Enter the writer of the book.\n");
            fgets(description[codeMatter].data.writer, MAX, stdin);
            nameSize = strlen(description[codeMatter].data.writer);
            if (description[codeMatter].data.writer[nameSize - 1] == '\n')
            {
                description[codeMatter].data.writer[nameSize - 1] = '\0';
            }

            printf("Enter the content of the book.\n");
            fgets(description[codeMatter].data.content, MAX, stdin);
            nameSize = strlen(description[codeMatter].data.content);
            if (description[codeMatter].data.content[nameSize - 1] == '\n')
            {
                description[codeMatter].data.content[nameSize - 1] = '\0';
            }

            //data of math
            if (codeMatter == 0)
            {
                fprintf(math, "%s, %s, %s\n", description[codeMatter].data.name, description[codeMatter].data.writer, description[codeMatter].data.content);
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

    printf("Enter the key to advance.\n");
    getchar();

    system("clear");

    printf("Type your name: ");

    fgets(nameUser, MAX, stdin);
    //withdrawnl from \n
    nameSize = strlen(nameUser);
    if (nameUser[nameSize - 1] == '\n')
    {
        nameUser[nameSize - 1] = '\0';
    }
    system("clear");

    printf("Welcome %s to library Penbookers\n", nameUser);
    printf("\n");

    printf("Choose one of the options below \n"
           "1 - Choosing a book to study at the library.\n"
           "2 - Choose a book to take.\n"
           "3 - How long to return the book.\n"
           "4 - Know some information about the book.\n");

    printf("Type what do you want.\n");
    scanf("%d", &userChoice);
    system("clear");

    switch (userChoice)
    {
    case 1:

        printf("See the available genres:\n"
               "1 - Books of study.\n"
               "2 - Books of romance.\n"
               "3 - Books for childrens.\n"
               "4 - Books of fiction.\n");

        printf("Type what do you want: ");
        scanf("%d", &userChoice);

        system("clear");
        switch (userChoice)
        {
        case 1:
            printf("Choose the subject:\n"
                   "1 - Math. \n"
                   "2 - Geography.\n"
                   "3 - History.\n"
                   "4 - Sociology.\n"
                   "5 - Physics.\n"
                   "6 - Chemistry.\n"
                   "7 - Philosophy.\n"
                   "8 - General studies.\n"
                   "9 - Theology.\n");
            printf("Type what do you want:\n");
            scanf("%d", &userChoice);
            system("clear");

            switch (userChoice)
            {
            case 1:
                codeMatter = 0;

                //Showing math books
                for (int i = 0; i < M; i++)
                {
                    counter = openFile(description[i].data.name, counter, codeMatter);
                    printf("%s\n", description[i].data.name);
                }
                printf("Do you want to withdraw a book? [1] Yes or [2] No\n");
                scanf("%d", &userChoice);
                if (userChoice == 1)
                {
                    printf("Enter the number present before the book to withdraw:\n");
                    scanf("%d", &withdrawalLine);
                    bookWithdrawal(withdrawnBook, withdrawalLine, codeMatter);
                    printf("Your withdrawn book was: %s\n", withdrawnBook);
                }
                else
                {
                    break;
                }
                break;
            }
        case 2:
            //Showing geography books

            break;
        }
        break;

    case 2:
        printf("See the available genres:\n"
               "1 - Books of study.\n"
               "2 - Books of romance.\n"
               "3 - Books for childrens.\n"
               "4 - Books of fiction.\n");
        break;
    }
}

// File read
int openFile(char *nameOfMatter, int counter, int codeMatter)
{
    int code = codeMatter;
    counter++;
    FILE *math;
    if (code == 0)
    {
        math = fopen("math.csv", "r");
    }

    char buffer[MAX];
    int i = 0;
    do
    {
        if (code == 0)
        {
            //fgets reads everything until it finds one \n and buffers everything
            fgets(buffer, MAX, math);
            fscanf(math, "%[^,]", nameOfMatter);
            i++;
        }

    } while (i < counter);
    if (code == 0)
    {
        fclose(math);
    }

    return counter;
}

//book withdrawal function

int bookWithdrawal(char *chosenBook, int withdrawalLine, int codeMatter)
{
    FILE *math;
    if (codeMatter == 0)
    {
        math = fopen("math.csv", "r");
    }
    
    FILE *withdrawal = fopen("transferring.csv", "w");
    char buffer[MAX];
    int currentLine = 1;
    int counter = 0;
    

    if (codeMatter == 0)
    {
        while (fgets(buffer, MAX, math) != NULL)
        {
            if (currentLine != withdrawalLine)
            {
                fputs(buffer, withdrawal);
            }

            

            strcpy(chosenBook, buffer);
            memset(buffer, 0, sizeof(char) * MAX);
            currentLine += 1;
        }
        fclose(math);
    }
    
  
    //modifies the book, to remove only the name
    while (1)
    {
        if (chosenBook[counter] == ',')
        {
            chosenBook[counter] = '\0';
            break;
        }
        counter++;
    }

    fclose(withdrawal);
    remove("math.csv");
    rename("transferring.csv", "math.csv");
    return 0;
}
