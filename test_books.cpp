#include <gtest/gtest.h>

extern "C" {
    #include "books.h"
    #include <malloc.h>
    #include "string.h"
}

TEST(test_book, assert_0){
    t_library* library = create_library();
    if (library == NULL) {
        return;
    }
    t_book* book = (t_book*) calloc(1, sizeof(t_book));
    strcpy(book->ISBN, "111-1-111111-11-1");
    book->count_readers = 0;
    book->readers = NULL;
    book->next = NULL;
    push_book(library, book);
    int count = count_readers(library);
    EXPECT_EQ(count, 0);
}

TEST(test_book, assert_3){
    t_library* library = create_library();
    if (library == NULL) {
        return;
    }
    t_book* book1 = (t_book*) calloc(1, sizeof(t_book));
    strcpy(book1->ISBN, "111-1-111111-11-1");
    book1->count_readers = 1;
    push_book(library, book1);
    t_book* book2 = (t_book*) calloc(1, sizeof(t_book));
    strcpy(book2->ISBN, "333-3-333333-33-3");
    book2->count_readers = 2;
    push_book(library, book2);
    int count = count_readers(library);
    t_book* books = books_on_hands(library);
    EXPECT_EQ(count, 3);
    EXPECT_EQ(books[0].ISBN[0], '1');
    EXPECT_EQ(books[1].ISBN[0], '3');
    EXPECT_EQ(books[2].ISBN[0], '3');
}

TEST(test_book, validate_book){
    t_book* book = (t_book*) calloc(1, sizeof(t_book));
    strcpy(book->ISBN, "111-1-111111-11-1");
    book->count = 100;
    book->count_readers = 0;
    book->readers = NULL;
    book->next = NULL;

    int res = validate_book(book);
    EXPECT_EQ(res, SUCCESS);
}

TEST(test_book, validate_reader){
    t_reader* reader = (t_reader*) calloc(1, sizeof(t_reader));
    reader->date[0] = 25;
    reader->date[1] = 12;
    reader->date[2] = 2021;

    int res = validate_reader(reader);
    EXPECT_EQ(res, SUCCESS);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}