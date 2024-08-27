#ifndef  _library_h
#define  _library_h
#define  numofauthor 30
#define  numoftitle 30
  typedef struct 
  {
     char author[numofauthor];
     char title[numoftitle];
     unsigned int Id;
     unsigned char available;
  }book;
 void add_book(book arr_of_books[],unsigned int *countbook);
 void view_books(book arr_of_books[],unsigned int *countbook);
 void search_book_bytitle(book arr_of_books[],unsigned int *countbook);
 void borrow_book(book arr_of_books[],unsigned int *countbook);
 void return_book_from_borrow(book arr_of_books[],unsigned int *countbook);
 void remove_book(book arr_of_books[],unsigned int *countbook);
#endif