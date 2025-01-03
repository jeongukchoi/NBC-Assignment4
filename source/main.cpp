#include "Book.h"
#include "BookManager.h"
#include "BorrowManager.h"

int main() {
    BookManager manager;
    BorrowManager borrow;

    // 도서관 관리 프로그램의 기본 메뉴를 반복적으로 출력하여 사용자 입력을 처리합니다.
    // 프로그램 종료를 선택하기 전까지 계속 동작합니다.
    while (true) {
        cout << "\n도서관 관리 프로그램" << endl;
        cout << "1. 책 추가" << endl; // 책 정보를 입력받아 책 목록에 추가
        cout << "2. 모든 책 출력" << endl; // 현재 책 목록에 있는 모든 책 출력
        cout << "3. 도서명 검색 및 대여" << endl; // 도서명으로 저장된 책 목록 검색 및 대여
        cout << "4. 작가명 검색 및 대여" << endl; // 작가명으로 저장된 책 목록 검색 및 대여
        cout << "5. 도서 반납" << endl; // 도서 반납
        cout << "0. 종료" << endl; // 프로그램 종료
        cout << "선택: ";

        int choice; // 사용자의 메뉴 선택을 저장
        cin >> choice;
        cout << "\n";
        
        // 1번 선택: 책 추가
        if (choice == 1) {
            string title, author;
            cout << "책 제목: ";
            cin.ignore();
            getline(cin, title); // 사용자 입력 --> 도서명
            cout << "책 저자: ";
            getline(cin, author); // 사용자 입력 --> 작가명

            manager.addBook(title, author); // BookManager : 책 목록에 입력받은 책 추가
            borrow.initializeStock(Book(title, author)); // BorrowManager : 재고 목록에 입력받은 책 추가
        }

        // 2번 선택: 모든 책 출력
        else if (choice == 2) {
            manager.displayAllBooks(); // 책 정보 출력
            borrow.displayStock(); // 책 재고 출력
        }

        // 3번 선택: 도서명 검색 및 대여
        else if (choice == 3) {
            string title;
            cout << "검색할 도서명: ";
            cin.ignore();
            getline(cin, title);

            // BookManager : 검색어와 도서명이 일치하는 (없으면 검색어가 도서명에 포함된) 도서 1건 반환
            // *해당하는 도서가 없거나 여러 건인 경우 안내 문구 출력 및 nullptr 반환*
            Book* searchResult = manager.getBookByTitle(title);

            // BorrowManager : 검색된 도서 대여 (재고에서 차감) / 재고가 없는 경우 대여 불가 안내
            if (searchResult != nullptr) {
                cout << searchResult->title << " 도서를 대여하려면 숫자 1을 입력하세요.\n";
                int choice2;
                cin >> choice2;
                if (choice2 == 1) {
                    borrow.borrowBook(searchResult->title);
                }
            }
        }

        // 4번 선택: 작가명 검색 및 대여
        else if (choice == 4) {
            string author;
            cout << "검색할 작가명: ";
            cin.ignore();
            getline(cin, author);

            // BookManager : 검색어와 작가명이 일치하는 (없으면 검색어가 작가명에 포함된) 도서 1건 반환
            // *해당하는 도서가 없거나 여러 건인 경우 안내 문구 출력 및 nullptr 반환*
            Book* searchResult = manager.getBookByAuthor(author);

            // BorrowManager : 검색된 도서의 '도서명'으로 대여 (재고 감소) / 재고가 없는 경우 대여 불가 안내
            if (searchResult != nullptr) {
                cout << searchResult->title << " 도서를 대여하려면 숫자 1을 입력하세요.\n";
                int choice2;
                cin >> choice2;
                if (choice2 == 1) {
                    borrow.borrowBook(searchResult->title);
                }
            }
        }

        // 5번 선택: 도서 반납
        else if (choice == 5) {
            string title;
            cout << "반납할 도서명 (공백 포함): ";
            cin.ignore();
            getline(cin, title);

            // BookManager: 도서명으로 반납할 도서 검색
            Book* searchResult = manager.getBookByTitle(title);

            // BorrowManager: 검색 결과가 한 건일 경우 도서 반납 (재고 증가) / 재고가 최대인 경우 대여 상태가 아니므로 반납 불가 안내
            if (searchResult != nullptr) {
                borrow.returnBook(searchResult->title);
            }
        }

        // 0번 선택: 종료
        else if (choice == 0) {
            // 프로그램을 종료하고 사용자에게 메시지를 출력합니다.
            cout << "프로그램을 종료합니다." << endl;
            break; // while 루프 종료
        }
        else {
            // 잘못된 입력 처리
            // 메뉴에 없는 번호를 입력했을 경우 경고 메시지를 출력합니다.
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
        }
    }

    return 0; // 프로그램 정상 종료
}