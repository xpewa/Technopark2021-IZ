#include <stdio.h>
#include <malloc.h>
#include "books.h"

int main(void) {
  t_library* library = create_library();
  int res = scan_books(library);
  if (res == ERROR_MEMORY) {
    printf("Memory error.");
    free_library(library);
    return 0;
  }
  if (res == ERROR) {
    printf("Error.");
    free_library(library);
    return 0;
  }
  int c_readers = count_readers(library);
  printf("Count of readers: %d\n", c_readers);
  t_book* reader_books = books_on_hands(library);
  if (reader_books != NULL) {
    printf("Codes of the books taken:\n");
    for (int i = 0; i < c_readers; ++i) {
      printf("%17s\n", reader_books[i].ISBN);
    }
    free(reader_books);
  }

  free_library(library);
  return 0;
}