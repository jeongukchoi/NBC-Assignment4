#include "BookManager.h"

// books 벡터에 저장되어 있지 않은 새로운 책인가?
bool BookManager::isNewBook(const string& title) {
    for (size_t i = 0; i < books.size(); i++) {
        if (books[i].title == title) return false; // 제목이 일치하는 책이 이미 books에 존재하는 경우 새로운 책이 아님 (false)
    }
    return true; // 제목이 일치하는 책이 books에 없는 경우 새로운 책임 (true)
}

// books 벡터에 title, author 정보로 Book 객체 만들어 추가
void BookManager::addBook(const string& title, const string& author) {
    if (this->isNewBook(title)) {
        books.push_back(Book(title, author));
        cout << "책이 추가되었습니다: " << title << " by " << author << endl;
    }
    else {
        cout << "동일한 이름의 책이 이미 존재하여 책을 추가할 수 없습니다.\n" << endl;
    }
}

// books 벡터에 저장된 Book 출력
void BookManager::displayAllBooks() {
    // 책이 없는 경우 안내
    if (books.empty()) {
        cout << "현재 등록된 책이 없습니다." << endl;
        return;
    }

    // 도서 목록 출력
    cout << "현재 도서 목록:" << endl;
    for (size_t i = 0; i < books.size(); i++) {
        cout << "- " << books[i].title << " by " << books[i].author << endl;
    }
}

// books 벡터에 저장된 Book.title 사용자 입력과 비교하여 검색 결과 반환 (동일한 경우 없음)
Book* BookManager::getBookByTitle(const string& title) {
    int contain = 0; // 검색어 '포함'인 경우 카운트
    size_t containIndex = 0; // 검색어 '포함'인 경우 인덱스
    for (size_t i = 0; i < books.size(); i++) {
        // 도서명이 검색어와 완벽히 일치하는 경우 해당 도서 반환
        if (books[i].title == title) {
            cout << "도서명이 검색어와 완벽히 일치하는 도서를 찾았습니다. - " << books[i].title << " by " << books[i].author << endl;
            cout << "\n검색 결과\n" << "번호: " << i + 1 << endl << "도서명 : " << books[i].title << endl << "작가명 : " << books[i].author << endl;
            return &books[i];
        }

        // 도서명에 검색어가 포함된 경우 카운트 증가 및 인덱스 기록
        if (books[i].title.find(title) != string::npos) {
            cout << "도서명에 검색어가 포함된 도서를 찾았습니다. - " << books[i].title << " by " << books[i].author << endl;
            contain++;
            containIndex = i;
        }
    }

    // 도서명에 검색어가 포함된 책이 단 한 권인 경우 해당 도서 반환
    if (contain == 1) {
        cout << "\n검색 결과\n" << "번호: " << containIndex + 1 << endl << "도서명 : " << books[containIndex].title << endl << "작가명 : " << books[containIndex].author << endl;
        return &books[containIndex];
    }

    // 도서명에 검색어가 포함된 책이 없거나 여러 개인 경우 안내 및 nullptr 반환
    if (contain == 0) {
        cout << "도서명에 " << title << "이(가) 포함된 도서가 없습니다.\n";
    }
    else {
        cout << "도서명에 " << title << "이(가) 포함된 도서가 여러 개 검색되었습니다. 검색 결과를 확인해 정확한 도서명으로 검색하세요.\n";
    }
    return nullptr;
}

// books 벡터에 저장된 Book.author 사용자 입력과 비교하여 검색 결과 반환 (작가명이 같은 경우 - Book.title 이 다름)
Book* BookManager::getBookByAuthor(const string& author) {
    int contain = 0, match = 0; // 작가명 '포함'인 경우와 '일치'인 경우 카운트
    size_t containIndex = 0, matchIndex = 0; // 작가명 '포함'인 경우와 '일치'인 경우 인덱스
    for (size_t i = 0; i < books.size(); i++) {
        // 작가명이 검색어와 완벽히 일치하는 경우 카운트 증가 및 인덱스 기록
        if (books[i].author == author) {
            cout << "작가명이 검색어와 완벽히 일치하는 도서를 찾았습니다. - " << books[i].title << " by " << books[i].author << endl;
            match++;
            matchIndex = i;
        }

        // 작가명에 검색어가 포함된 경우 카운트 증가 및 인덱스 기록
        else if (books[i].author.find(author) != string::npos) {
            cout << "작가명에 검색어가 포함된 도서를 찾았습니다. - " << books[i].title << " by " << books[i].author << endl;
            contain++;
            containIndex = i;
        }
    }

    // 작가명이 검색어와 완벽히 일치하는 책이 단 한 권인 경우 해당 도서 반환
    if (match == 1) {
        cout << "\n검색 결과\n" << "번호: " << matchIndex + 1 << endl << "도서명 : " << books[matchIndex].title << endl << "작가명 : " << books[matchIndex].author << endl;
        return &books[matchIndex];
    }

    // 작가명이 검색어와 완벽히 일치하는 책이 여러 권인 경우 안내 및 nullptr 반환
    else if (match > 1) {
        cout << "작가명이 " << author << "와(과) 일치하는 도서가 여러 개 검색되었습니다. 검색 결과를 확인한 후 정확한 도서명으로 검색해보세요.\n";
        return nullptr;
    }

    // 작가명에 검색어가 포함된 책이 단 한 권인 경우 해당 도서 반환
    if (contain == 1) {
        cout << "\n검색 결과\n" << "번호: " << containIndex + 1 << endl << "도서명 : " << books[containIndex].title << endl << "작가명 : " << books[containIndex].author << endl;
        return &books[containIndex];
    }

    // 작가명에 검색어가 포함된 책이 없거나 여러 개인 경우 안내 및 nullptr 반환
    if (contain == 0) {
        cout << "작가명에 " << author << "이(가) 포함된 도서가 없습니다.\n";
    }
    else {
        cout << "작가명에 " << author << "이(가) 포함된 도서가 여러 개 검색되었습니다. 검색 결과를 확인해 정확한 도서명으로 검색해보세요.\n";
    }
    return nullptr;
}