#ifndef BOOKMANAGER_H_
#define BOOKMANAGER_H_

#include <vector>
#include "Book.h"

class BookManager {
private:
    vector<Book> books; // Book 저장하는 벡터

    bool isNewBook(const string& title);

public:
    // 책 추가 메서드
    void addBook(const string& title, const string& author);

    // 모든 책 출력 메서드
    void displayAllBooks();

    // 도서명 검색 메서드
    Book* getBookByTitle(const string& title);

    // 작가명 검색 메서드 (!!작가명이 동일하고 도서명이 다른 경우가 있다고 가정!!)
    Book* getBookByAuthor(const string& author);
};

#endif