Hi everyone, welcome to my first code or should i say : Whelcome to my library:

<div align = "center" >
```c
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
```
</div>

This is database code of a library and it's interface where you can do whatever you want, add a book of math? Yes, you can, add a book 
of geography? Yes, you can. but how? Look this >

```c
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
```

Now you can do whatever you want, add a name, writer and contente to a book.

Best of all, this was all done in C.
For now it's just a database center, but after that it will be the best library programming ever.

Thank you


