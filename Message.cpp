//
//  Message.cpp
//  CppProject
//
//  Created by 김희철 on 2018. 6. 3..
//  Copyright © 2018년 Heekim. All rights reserved.
//
#include "Message.h"

void ClearScreen() {
    cout << string( 100, '\n' );
}

void SetAccountMessage() {
    cout << endl;
    cout << "──── *    계정이 설정되었습니다   * ────" << endl;
    cout << endl;
}

bool PressAnyKey(bool isFindMessage) {
    isFindMessage ? printf("──── * 찾지 못했습니다 계속 진행하려면 아무키나 누르세요  * ────") : printf("──── * 계속 진행하려면 아무키나 누르세요   * ────\n");
    getchar(); getchar();
    return true;
}

void PrintSetAdminMessage() {
    cout << "┌────────────────────────┐" << endl;
    
    cout.width(7);
    cout.fill(' ');
    cout << left << "│";
    
    cout.width(18);
    cout.fill(' ');
    cout << left << "SET ADMIN ACCOUNT";
    
    cout.width(5);
    cout.fill(' ');
    cout << right << "│" << endl;
    
    cout << "└────────────────────────┘" << endl;
}
int SelectMainMenu() {
    int select;
    cout << "┌────────────────────────┐" << endl;
    cout << "│     VENDING MACHINE    │" << endl;
    cout << "├────────────────────────┘" << endl;
    cout << "|" << endl;
    cout << "├──[ 1 ]  관리자 정보변경" << endl;
    cout << "|" << endl;
    cout << "├──[ 2 ]  상품 추가" << endl;
    cout << "|" << endl;
    cout << "├──[ 3 ]  상품 삭제" << endl;
    cout << "|" << endl;
    cout << "├──[ 4 ]  상품 수정" << endl;
    cout << "|" << endl;
    cout << "├──[ 5 ]  상품 전체보기" << endl;
    cout << "|" << endl;
    cout << "├──[ 6 ]  상품 검색" << endl;
    cout << "|" << endl;
    cout << "├──[ 7 ]  매출현황 보기" << endl;
    cout << "|" << endl;
    cout << "├──[ 8 ]  판매 개시" << endl;
    cout << "|" << endl;
    cout << "├──[ 9 ]  매출 정산" << endl;
    cout << "|" << endl;
    cout << "├──[ 10 ]  종료" << endl;
    cout << "|" << endl;
    cout << "└────────────────────────┘" << endl;
    cin >> select;
    return select;
}

int SelectAdminMenu() {
    int select;
    cout << "┌────────────────────────┐" << endl;
    cout << "│     VENDING MACHINE    │" << endl;
    cout << "├────────────────────────┘" << endl;
    cout << "|" << endl;
    cout << "├──[ 1 ]  관리자 아이디 변경" << endl;
    cout << "|" << endl;
    cout << "├──[ 2 ]  관리자 비밀번호 변경" << endl;
    cout << "|" << endl;
    cout << "├──[ 3 ]  되돌아가기" << endl;
    cout << "|" << endl;
    cout << "└────────────────────────┘" << endl;
    cin >> select;
    return select;
}

string Input(string message) {
    string data;
    cout << "┌────────────────────────┐" << endl;
    
    cout.width(1);
    cout << left << "|";
    
    cout.width(8);
    cout.fill(' ');
    cout << right << "input";
    
    cout.width(12);
    cout.fill(' ');
    cout << right << message;
    
    cout.width(7);
    cout.fill(' ');
    cout << right << "│" << endl;
    
    cout << "└┬───────────────────────┘" << endl;
    cout << " └───>>   ";
    cin >> data;
    return data;
}

bool YesOrNo(string message) {
    string YorN;
    bool yes = true;
    cout << " |" << endl;
    cout << " ├─── *    " << message << " 하시겠습니까 ? ( Y or N )" << endl;
    cout << " |" << endl;
    cout << " └───>>  ";
    cin >> YorN;
    cout << endl;cout << endl;
    yes = (YorN == "y" || YorN == "Y") ? true : false;
    return yes;
}

string inputServieceMessage() {
    string itemName;
    cout << "─┬── *    아이템 이름을 입력해주세요  * ────" << endl;
    cout << " ├── *     돌아가시려면 (n / N)   * ────" << endl;
    cout << " │" << endl;
    cout << " ├───>>  ";
    cin >> itemName;
    cout << endl;
    if(itemName == "n" || itemName == "N") {
        cout << "****** !    되돌아갑니다     ! *****" <<  endl;
    }
    return itemName;
}
