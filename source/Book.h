#ifndef BOOK_H_
#define BOOK_H_

#include <string>
#include <iostream>

using namespace std;

class Book {
public:
    string title;
    string author;

    Book(const string& title, const string& author)
        : title(title), author(author) {
    }
};

#endif