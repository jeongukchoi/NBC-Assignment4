#ifndef BORROWMANAGER_H_
#define BORROWMANAGER_H_

#include <unordered_map>
#include "Book.h"

const int kStockMax = 3;

class BorrowManager {
private:
    unordered_map<string, int> stock; // <책 제목, 재고 수량> 저장

public:
    // 도서 재고 초기화 메서드
    void initializeStock(Book book, int quantity = kStockMax);

    // 도서 대여 메서드
    void borrowBook(const string& title);

    // 도서 반납 메서드
    void returnBook(const string& title);

    // 도서 재고 출력 메서드
    void displayStock();
};

#endif