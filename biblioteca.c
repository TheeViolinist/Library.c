#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 200
#define M 10 //number of math books
#define G 5

// library book database
int openFile(char *nameOfMatter, int counter, int codeMatter);
int bookWithdrawal(char *chosenBook, int withdrawalLine, int codeMatter);

//reset books
void ResetBooks(int restart, int code);

/*Data storage of books*/
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
    FILE *math;                                             /*pointing out of books*/                           
    FILE *livros;                                           /*pointing out of books*/ 
    FILE *geograph;                                         /*pointing out of books*/ 

    char nameUser[MAX];                                     /*nameUser = name of user*/
    char *withdrawnBook[MAX];                               /*withdrawnBook = name of the withdrawn books*/

    int userChoice, nameSize;                               /* variable of choice user */                                         
    int numberBooks, bookAdd, codeMatter, restartBooks;
    
    int counter = 0;                                        /*regulatory variables */
    int withdrawalLine;             
    

    /* If I wanna change the books, I click 1 */
    printf("Do you wanna adding a book to library? [1] Yes or [2] No.\n");
    scanf("%d", &bookAdd);
    /* If I wanna restart the books, I click 1 */
    printf("Do you wanna reset the books? [1] Yes or [2] No\n");
    scanf("%d", &restartBooks);

    /*this scope will scan the code of material and call the function ResetBooks */
    if (restartBooks == 1)
    {
        printf("Enter the code of the materiall you want to reset: ");
        scanf("%d", &codeMatter);
        ResetBooks(restartBooks, codeMatter);

    }
    
    /*This scope will adding books to the corresponding file to the code*/
    if (bookAdd == 1)
    {
        /*Here it will scan the number of books to add */
        printf("Enter the number of books you want to store.\n");
        scanf("%d", &numberBooks);
        /*and here the code of corresponding material */
        printf("Enter the code of the materiall you want to add: ");
        scanf("%d", &codeMatter);

        system("clear");
        /*This getchar scan the '\n' */
        getchar();

        /*This loop will open the file and add all of the book's features */
        for (int i = 0; i < numberBooks; i++)
        {
            if (codeMatter == 0)
            {
                math = fopen("math.csv", "a");
            }
            else if (codeMatter == 1)
            {
                geograph = fopen("geograph.csv", "a");
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

            /*Here, the code will open the file, and annex all datas */
            if (codeMatter == 0)
            {
                fprintf(math, "%s, %s, %s\n", description[codeMatter].data.name, description[codeMatter].data.writer, description[codeMatter].data.content);
                fclose(math);
            }
            else if (codeMatter == 1)
            {
                fprintf(geograph, "%s, %s, %s\n", description[codeMatter].data.name, description[codeMatter].data.writer, description[codeMatter].data.content);
                fclose(geograph);
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

                /* Here, this loop will call the function OpenFIle and */
                /* This function have 3 parameters, the pointer of books name*/
                /*A counter and the material code */
                for (int i = 0; i < M; i++)
                {
                    counter = openFile(description[i].data.name, counter, codeMatter);
                    printf("%s\n", description[i].data.name);
                }

                
                printf("Do you want to withdraw a book? [1] Yes or [2] No\n");
                scanf("%d", &userChoice);
                
                /*Thins condition will call the function Book Withdrawal*/
                if (userChoice == 1)
                {
                    printf("Enter the number present before the book to withdraw:\n");
                    scanf("%d", &withdrawalLine);
                    
                    bookWithdrawal(withdrawnBook, withdrawalLine, codeMatter);
                    printf("Your withdrawn book was: %s\n", withdrawnBook);
                    
                }

                break;

            case 2:
                codeMatter = 1;
                
                /*showing geography book */
                for (int i = 0; i < G; i++)
                {
                    counter = openFile(description[i].data.name, counter, codeMatter);
                    printf("%s\n", description[i].data.name);
                }
                printf("Do you want to withdraw a book? [1] Yes or [2] No\n");
                scanf("%d", &userChoice);
                
                /*Thins condition will call the function Book Withdrawal*/
                if (userChoice == 1)
                {
                    printf("Enter the number present before the book to withdraw:\n");
                    scanf("%d", &withdrawalLine);
                    
                    bookWithdrawal(withdrawnBook, withdrawalLine, codeMatter);
                    printf("Your withdrawn book was: %s\n", withdrawnBook);
                    
                }
                break;
    
            }
        break;
        case 2:
                


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

/***
 * OpenFile(): Change the contents of the book name pointer.
 *              First will add 1 to counter, because I want to
 *              Start in the second line, when arrives in 
 *              "fgets" I go to read everything until find a
 *              '\n' and stock on buffer and later, I gonna
 *              scan until find a ',' and stock on address book name.
 *              When the main loop close, return the counter, because
 *              it will start on the previous line plus one.
 * 
 * Parameters: 
 *          nameOfMatter = memory address book name
 *          counter = limit the read
 *          codeMatter = books code
 * 
 * return: The limit of the read
 ***/
int openFile(char *nameOfMatter, int counter, int codeMatter)
{
    int code = codeMatter;
    counter++;
    FILE *math;
    FILE *geograph;

    if (code == 0)
    {
        math = fopen("math.csv", "r");
    }
    else if (code == 1)
    {
        geograph = fopen("geograph.csv", "r");
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
        else if (code == 1)
        {
            fgets(buffer, MAX, geograph);
            fscanf(geograph, "%[^,]", nameOfMatter);
            i++;
        }

    } while (i < counter);

    if (code == 0)
    {
        fclose(math);
    }
    else if (code == 1)
    {
        fclose(geograph);
    }

    return counter;
}

/***
 * bookWithdrawal(): This function removes a book chosen by the user,
 *                  and create a new file.
 *                  When arrives in the main lopp, the fgets will read 
 *                  the file until the NULL, and stores everything 
 *                  that is not the chosen book in a new file.
 *                  And copy everything in string chosenBOok.
 *                  In the second loop, withdraw the name of the book.
 * 
 *                  
 * 
 * 
 * Parameters: 
 *          chosenBook = memory address book name
 *          whidrawanlLine = withdrawal line
 *          codeMatter = books code
 * 
 * return: nothing
 ***/

int bookWithdrawal(char *chosenBook, int withdrawalLine, int codeMatter)
{
    FILE *math;
    FILE *geograph;
    if (codeMatter == 0)
    {
        math = fopen("math.csv", "r");
    }
    else if (codeMatter == 1)
    {
        geograph = fopen("geograph.csv", "r");
    }
    
    FILE *withdrawal = fopen("transferring.csv", "w");
    
    char buffer[MAX];
    int currentLine = 1;
    int counter = 0;
    
    /*  Withdrawn math books    */
    if (codeMatter == 0)
    {
        while (fgets(buffer, MAX, math) != NULL)
        {
            if (currentLine != withdrawalLine)
            {
                fputs(buffer, withdrawal);
            }
            else
            {
                strcpy(chosenBook, buffer);
            }

            
            memset(buffer, 0, sizeof(char) * MAX);
            currentLine += 1;
        }
        fclose(math);
    }

    /*  Withdrawn geography books    */
    if (codeMatter == 1)
    {
        while (fgets(buffer, MAX, geograph) != NULL)
        {
            if (currentLine != withdrawalLine)
            {
                fputs(buffer, withdrawal);
            }

            else
            {
                strcpy(chosenBook, buffer);
            }
            
    
            memset(buffer, 0, sizeof(char) * MAX);
            currentLine += 1;
        }
        fclose(geograph);

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

    /*  organizing math data   */
    if(codeMatter == 0)
    {
        remove("math.csv");
        rename("transferring.csv", "math.csv");
    }
    /* organizing geography data    */
    if (codeMatter == 1)
    {
        remove("geograph.csv");
        rename("transferring.csv", "geograph.csv");
    }
    
    return 0;
}


/***
 * ResetBooks(): This function reset the files book.
 *              
 * 
 *       
 * Parameters: 
 *          Restart = If i wanna restart or no.
 *          codeMatter = books code
 * 
 * return: nothing
 ***/
void ResetBooks(int restart, int code)
{
    FILE *geograph;
    FILE *math;
    if (restart == 1)
    {
        
        if (code == 0)
        {
            math = fopen("math.csv", "w");
            math = fopen("math.csv", "a");
            fprintf(math, "%s, %s, %s\n", "name", "writer", "content");
            fclose(math);
        }
        if (code == 1)
        {
            geograph = fopen("geograph.csv", "w");
            geograph = fopen("geograph.csv", "a");
            fprintf(geograph, "%s, %s, %s\n", "name", "writer", "content");
            fclose(geograph);
        }

       
    }
}
