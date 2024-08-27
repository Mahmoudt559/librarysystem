#include<stdio.h>
#include<stdlib.h>
#include "library.h"
#include "library.c"
#define MAX_ELEMENT_BOOKS 100
int main()
{
  int countbook=0;
  book arr_books [MAX_ELEMENT_BOOKS];
  unsigned int choice=0;
 while(1)
 {         
        printf("==============================================\n");
        printf("Library Management System\n");
        printf("==============================================\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Search Book by Title\n");
        printf("4. Borrow Book\n");
        printf("5. Return Book\n");
        printf("6. Remove Book\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add_book(arr_books,&countbook);
            break;
        case 2:
            view_books(arr_books,&countbook);
            break;
        case 3:
            search_book_bytitle(arr_books,&countbook);
            break;
        case 4:
            borrow_book(arr_books,&countbook);
            break;
        case 5:
            return_book_from_borrow(arr_books,&countbook);
            break;
        case 6:
            remove_book(arr_books,&countbook);
            break;
        case 7:
            exit(1);
        default:
            printf("please choose from 1 -> 7 only \n");
        }
 }
return 0;
}