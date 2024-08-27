#include <stdio.h>
#include <string.h>
#include "library.h"

void add_book(book arr_of_books[], unsigned int *countbook)
{
    if (NULL == countbook || NULL == arr_of_books)
    {
        printf("Error: Null pointer in countbook or arr_of_books\n");
        return;
    }
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF); 

    printf("==============================================\n");
    printf("Please enter the book title:\n");
    fgets(arr_of_books[*countbook].title, sizeof(arr_of_books[*countbook].title), stdin);
    arr_of_books[*countbook].title[strcspn(arr_of_books[*countbook].title, "\n")] = '\0';
  
    printf("==============================================\n");
    printf("Please enter the book author:\n");
    fgets(arr_of_books[*countbook].author, sizeof(arr_of_books[*countbook].author), stdin);
    arr_of_books[*countbook].author[strcspn(arr_of_books[*countbook].author, "\n")] = '\0';  

    arr_of_books[*countbook].available = 1;
    arr_of_books[*countbook].Id = (*countbook) + 1;
    printf("The book titled \"%s\" has been added successfully.\n", arr_of_books[*countbook].title);
    printf("==============================================\n");

    (*countbook)++;
}

void view_books(book arr_of_books[], unsigned int *countbook)
{
    if (NULL == countbook || NULL == arr_of_books)
    {
        printf("Error: Null pointer in countbook or arr_of_books\n");
        return;
    }

    printf("Books in the library:\n");
    if ((*countbook) == 0)
    {
        printf("The library is empty. Please add some books.\n");
    }
    else
    {
        printf("==============================================\n");
        for (unsigned int i = 0; i < *countbook; i++)
        {
            printf("ID -> %u  |  Title -> %s  |  Author -> %s  |  Status -> %s\n",
                   arr_of_books[i].Id, arr_of_books[i].title,
                   arr_of_books[i].author, arr_of_books[i].available ? "Available" : "Borrowed");
        }
        printf("==============================================\n");
    }
}
void search_book_bytitle(book arr_of_books[], unsigned int *countbook)
{
    char titlesearch[numoftitle];
    int found = 0;

    if (NULL == countbook || NULL == arr_of_books)
    {
        printf("Error: Null pointer in countbook or arr_of_books\n");
        return;
    }

    if ((*countbook) == 0)
    {
        printf("The library is empty. Please add some books.\n");
        return;
    }
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);  

    printf("==============================================\n");
    printf("Please enter the book title to search for:\n");
    fgets(titlesearch, sizeof(titlesearch), stdin);
    titlesearch[strcspn(titlesearch, "\n")] = '\0';

    for (unsigned int i = 0; i < *countbook; i++)
    {
        if (strcmp(titlesearch, arr_of_books[i].title) == 0)
        {
            printf("ID -> %u  |  Title -> %s  |  Author -> %s  |  Status -> %s\n",
                   arr_of_books[i].Id, arr_of_books[i].title,
                   arr_of_books[i].author, arr_of_books[i].available ? "Available" : "Borrowed");
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("The book titled \"%s\" was not found.\n", titlesearch);
    }
    printf("==============================================\n");
}
void borrow_book(book arr_of_books[], unsigned int *countbook)
{
    unsigned int bookid = 0;

    if (NULL == countbook || NULL == arr_of_books)
    {
        printf("Error: Null pointer in countbook or arr_of_books\n");
        return;
    }

    printf("==============================================\n");
    printf("Enter the ID of the book to borrow:\n");
    scanf("%u", &bookid);

    for (unsigned int i = 0; i < *countbook; i++)
    {
        if (arr_of_books[i].Id == bookid)
        {
            if (arr_of_books[i].available)
            {
                arr_of_books[i].available = 0;
                printf("The book titled \"%s\" has been borrowed successfully.\n", arr_of_books[i].title);
            }
            else
            {
                printf("The book is already borrowed.\n");
            }
            printf("==============================================\n");
            return;
        }
    }

    printf("The book with ID %u was not found.\n", bookid);
    printf("==============================================\n");
}

void return_book_from_borrow(book arr_of_books[], unsigned int *countbook)
{
    unsigned int bookid = 0;

    if (NULL == countbook || NULL == arr_of_books)
    {
        printf("Error: Null pointer in countbook or arr_of_books\n");
        return;
    }

    printf("==============================================\n");
    printf("Enter the ID of the book to return:\n");
    scanf("%u", &bookid);

    for (unsigned int i = 0; i < *countbook; i++)
    {
        if (arr_of_books[i].Id == bookid)
        {
            if (!(arr_of_books[i].available))
            {
                arr_of_books[i].available = 1;
                printf("The book titled \"%s\" is now available.\n", arr_of_books[i].title);
            }
            else
            {
                printf("The book titled \"%s\" is already available.\n", arr_of_books[i].title);
            }
            printf("==============================================\n");
            return;
        }
    }

    printf("The book with ID %u was not found.\n", bookid);
    printf("==============================================\n");
}

void remove_book(book arr_of_books[], unsigned int *countbook)
{
    unsigned int bookid = 0;

    if (NULL == countbook || NULL == arr_of_books)
    {
        printf("Error: Null pointer in countbook or arr_of_books\n");
        return;
    }

    printf("==============================================\n");
    printf("Enter the ID of the book to remove:\n");
    scanf("%u", &bookid);

    for (unsigned int i = 0; i < *countbook; i++)
    {
        if (arr_of_books[i].Id == bookid)
        {
            for (unsigned int j = i; j < (*countbook) - 1; j++)
            {
                arr_of_books[j] = arr_of_books[j + 1];
                arr_of_books[j].Id--;
            }

            (*countbook)--;

            printf("The book has been removed successfully.\n");
            printf("==============================================\n");
            return;
        }
    }

    printf("The book with ID %u was not found.\n", bookid);
    printf("==============================================\n");
}

