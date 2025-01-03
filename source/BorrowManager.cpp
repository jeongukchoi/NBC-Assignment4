#include "BorrowManager.h"

// stock 맵에 <제목, 수량(기본값 kStockMax)> 으로 저장
void BorrowManager::initializeStock(Book book, int quantity) {
    stock.insert(make_pair(book.title, quantity));
}

void BorrowManager::borrowBook(const string& title) {
    // 도서 재고가 있는 경우 대여
    if (stock[title] > 0) {
        stock[title]--;
        cout << title << " 도서를 대여합니다. 잔여 수량: " << stock[title] << "권\n";
    }

    // 도서 재고가 없는 경우 안내
    else {
        cout << "현재 " << title << " 도서의 재고가 없습니다.\n";
    }
}

void BorrowManager::returnBook(const string& title) {
    // 도서가 대여 상태인 경우 반납 (i.e. 현재 재고가 원래 재고보다 적음)
    if (stock[title] < kStockMax) {
        stock[title]++;
        cout << "'" << title << "' 도서를 반납하였습니다. 잔여 수량: " << stock[title] << "권\n";
    }

    // 도서가 대여되지 않은 상태인 경우 안내 (i.e. 현재 재고 = 원래 재고)
    else {
        cout << "'" << title << "' 도서는 대여 중이 아니므로 반납할 수 없습니다. 도서명을 다시 확인하세요.\n";
    }
}

void BorrowManager::displayStock() {
    if (stock.size() == 0) return;

    cout << "현재 도서 재고:\n";
    // stock 에 저장된 도서명과 수량 출력
    for (auto item : stock) {
        cout << "- " << item.first << " / 잔여 : " << item.second << "권\n";
    }
}