#pragma once

#define ISBN_LENGTH 18
#define TITLE_LENGTH 40
#define SURNAME_LENGTH 25
#define DATE_LENGTH 3

#define ERROR 0
#define ERROR_MEMORY -1
#define SUCCESS 1

typedef struct t_reader {
    int date[DATE_LENGTH];
    char surname[SURNAME_LENGTH];
} t_reader;

typedef struct t_book {
    char ISBN[ISBN_LENGTH];
    char tile[TITLE_LENGTH];
    int year_publishing;
    int count;
    int count_readers;
    t_reader* readers;
    struct t_book* next;
} t_book;

typedef struct t_library {
    t_book* book_head;
} t_library;

int count_readers(t_library* library);
t_book* books_on_hands(t_library* library);

t_library* create_library();
void push_book(t_library* library, t_book* book);
int scan_books(t_library* library);

int validate_book(t_book* book);
int validate_reader(t_reader* reader);

void pop_book(t_library* library);
void free_library(t_library* library);