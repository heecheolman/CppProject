//  main.cpp
//  CppProject
//
//  Created by 김희철 on 2018. 5. 30..
//  Copyright © 2018년 Heekim. All rights reserved.

#define ITEMLIST_MAX 5
#define ITEM_MAX 10


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
// ─ │ ┌ ┐ ┘ └ ├ ┬ ┤ ┴ ┼
using namespace std;

typedef struct Item {
    bool isSoldOut;
    int itemPrice;
    int itemCount;
    string itemName;
    Item * left;
    Item * right;
} Item;

typedef struct ItemList {
    Item * head;
    Item * tail;
    Item * cur;
    int numOfData;
} ItemList;

typedef struct Admin {
    string ID;
    string PW;
    int money;
} Admin;

typedef struct VendingMachine {
    Admin * admin;
    ItemList * list;
} VendingMachine;

/* Message */
void ClearScreen() {
    cout << string( 100, '\n' );
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
    // ─ │ ┌ ┐ ┘ └ ├ ┬ ┤ ┴ ┼
    cout << "┌────────────────────────┐" << endl;
    cout << "│     VENDING MACHINE    │" << endl;
    cout << "├────────────────────────┘" << endl;
    cout << "|" << endl;
    cout << "├──[ 1 ]  관리자 정보변경" << endl;
    cout << "|" << endl;
    cout << "├──[ 2 ]  상품 추가" << endl;
    cout << "|" << endl;
    cout << "├──[ 3 ]. 상품 삭제" << endl;
    cout << "|" << endl;
    cout << "├──[ 4 ]. 상품 수정" << endl;
    cout << "|" << endl;
    cout << "├──[ 5 ]. 상품 전체보기" << endl;
    cout << "|" << endl;
    cout << "├──[ 6 ]. 상품 검색" << endl;
    cout << "|" << endl;
    cout << "├──[ 7 ]. 매출현황 보기" << endl;
    cout << "|" << endl;
    cout << "├──[ 8 ]. 판매 개시" << endl;
    cout << "|" << endl;
    cout << "├──[ 9 ]. 종료" << endl;
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
    cout << "└────────────────────────┘" << endl;
    cin >> select;
    return select;
}

string input(string message) {
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

bool CheckAdminInfo(string adminPW) {
    bool isSame = false;
    string tempPW;
    cout <<  endl;
    cout << "──── *    정보를 변경합니다   * ────" << endl;
    cout << "──── *  비밀번호를 입력해주세요 * ─────>>   ";
    cin >> tempPW;
    cout <<  endl;
    isSame = (adminPW == tempPW) ? true : false;
    if(!isSame) {
        cout << "****** ! 비밀번호가 일치하지 않습니다 ! *****" << endl;
        cout << "****** !       되돌아갑니다       ! *****" << endl;
    }
    return isSame;
}

void ChangeInfo(string message, string * adminInfo) {
    string tempInfo;
    string YorN;
    bool hasDone = false;
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
    
    while(!hasDone) {
        cout << " ├─── 변경하실 " << message << "를 입력해주세요" << endl;
        cout << " └───>>  ";
        cin >>  tempInfo;
        cout << " ├─── 입력하신 정보가 " << tempInfo << "가 맞습니까 ? ( Y or N )" << endl;
//        cout << " └───>>  입력하신 정보가 " << tempInfo << "가 맞습니까 ? ( Y or N )" << endl;
//        cout << "입력하신 정보가 " << tempInfo << "가 맞습니까? ( Y / N ) >> " << endl;
        cout << " └───>>  ";
        cin >> YorN;
        if(YorN == "Y" || YorN == "y") {
            hasDone = true;
            *adminInfo = tempInfo;
            cout <<  endl;
            cout << "──── *    변경되었습니다   * ────" << endl;
            cout << "──── *    재로그인합니다   * ────" << endl;
            cout <<  endl;
        }else {
            cout <<  endl;
            cout << "****** !    변경되지 않았습니다     ! *****" << endl;
            cout << "****** !       되돌아갑니다       ! *****" << endl;
            cout <<  endl;
        }
    }
}

void NoMenu() {
    cout << "없는 메뉴입니다" << endl;
}

bool YesOrNo(string message) {
    string YorN;
    bool yes = true;
    cout << message << " 하시겠습니까? ( Y or N )";
    cin >> YorN;
    yes = (YorN == "y" || YorN == "Y") ? true : false;
    return yes;
}

/***********/

/* System Function */
bool Loginning(string &adminID, string &adminPW) {
    string inputID;
    string inputPW;
    cout << "┌────────────────────────┐" << endl;
    
    cout.width(13);
    cout.fill(' ');
    cout << left << "│";
    
    cout.width(14);
    cout.fill(' ');
    cout << left << "LOGIN";
    
    cout.width(1);
    cout.fill(' ');
    cout << right << "│" << endl;
    
    cout << "└────────────────────────┘" << endl;
    inputID = input("ID");
    inputPW = input("PASSWORD");
    ClearScreen();
    return (inputID == adminID && inputPW == adminPW) ? true : false;
}

void ILInit(ItemList * list) {
    list->head = new Item;
    list->tail = new Item;
    
    list->cur = list->head;
    list->head->right = list->tail;
    list->tail->left = list->head;
    list->numOfData = 0;
}

void ILInsert(ItemList * list) {
    if(list->numOfData == ITEMLIST_MAX) {
        cout << "****** !    더 이상 추가할 수 없습니다     ! *****" << endl;
        return;
    }
    Item * newItem = new Item;
    newItem->right = list->tail;
    newItem->left = list->tail->left;
    list->tail->left->right = newItem;
    list->tail->left = newItem;
    cout << "─┬── *    아이템 이름 설정   * ────" << endl;
    cout << " │" << endl;
    cout << " ├───>>  ";
    cin >> newItem->itemName;
//    cout << "아이템 이름 설정 >> ";
    
    cout << " │" << endl;
    cout << " ├── *    아이템 가격 설정   * ────" << endl;
    cout << " │" << endl;
    cout << " └───>>  ";
    cin >> newItem->itemPrice;
//    cout << "아이템 가격 설정 >> ";
    newItem->itemCount = ITEM_MAX;
    newItem->isSoldOut = false;
    (list->numOfData)++;
}

bool ILFirst(ItemList * list, Item * tempItem) {
    if(list->numOfData == 0) {
        cout << "****** !    저장된 데이터가 없습니다     ! *****" << endl;
        return false;
    }
    list->cur = list->head->right;
    tempItem->itemName = list->cur->itemName;
    tempItem->itemPrice = list->cur->itemPrice;
    tempItem->itemCount = list->cur->itemCount;
    tempItem->isSoldOut = list->cur->isSoldOut;
    return true;
}

bool ILNext(ItemList * list, Item * tempItem) {
    if(list->numOfData == 0) {
        cout << "****** !    저장된 데이터가 없습니다     ! *****" << endl;
        return false;
    }
    list->cur = list->cur->right;
    if(list->cur == list->tail) {
        return false;
    }
    tempItem->itemName = list->cur->itemName;
    tempItem->itemPrice = list->cur->itemPrice;
    tempItem->itemCount = list->cur->itemCount;
    tempItem->isSoldOut = list->cur->isSoldOut;
    return true;
}

bool ILRemove(ItemList * list, Item * target) {
    bool willRemove = false;
    willRemove = YesOrNo("제거");
    if(willRemove){
        target->left->right = target->right;
        target->right->left = target->left;
        free(target);
        (list->numOfData)--;
        cout << "제거된 항목 : " << target->itemName << endl;
        cout << "제거된 항목 : " << target->itemPrice << endl;
        cout << "제거된 항목 : " << target->itemCount << endl;
        cout << "제거된 항목 : " << target->isSoldOut << endl;
        cout << list->numOfData << endl;
    }else {
        cout << "****** !    취소했습니다.     ! *****" << endl;
    }
    return willRemove;
}

Item *ILFind(ItemList * list, string targetName) {
    Item * seek;
    seek = list->head->right;
    string findItemName;
    while(seek != list->tail) {
        if(seek->itemName == targetName) {
            return seek;
        }
        seek = seek->right;
    }
    return NULL;
}

void EditItemInfo(Item * target) {
    bool hasEdit = false;
    string inputName;
    int inputPrice;
    int menu = 0;
    cout << "수정할 데이터" << endl;
    cout << "1. 아이템 이름" << endl;
    cout << "2. 아이템 가격" << endl;
    cout << "3. 나가기" << endl;
    cin >> menu;
    switch(menu) {
        case 1:
            cout << "변경될 아이템 이름 입력 >> ";
            cin >> inputName;
            hasEdit = YesOrNo("변경");
            if(hasEdit) {
                target->itemName = inputName;
            }
            break;
        case 2:
            cout << "변경될 아이템 가격 입력 >> ";
            cin >> inputPrice;
            hasEdit = YesOrNo("변경");
            if(hasEdit) {
                target->itemPrice = inputPrice;
            }
            break;
        case 3:
            cout << "종료" << endl;
            hasEdit = false;
            break;
    }
    hasEdit ? printf("변경되었습니다\n") : printf("****** !    변경되지 않았습니다     ! *****\n");
}

bool ShowItemInfo(Item * target) {
    cout << "아이템 이름 : " << target->itemName << endl;
    cout << "아이템 가격 : " << target->itemPrice << endl;
    cout << "아이템 개수 : " << target->itemCount << endl;
    return true;
}

void ShowAllItem(ItemList * list) {
    Item * target;
    target = list->head->right;
    if(target == list->tail) {
        cout << "****** !    저장된 데이터가 없습니다     ! *****" <<  endl;
        return;
    }
    while(target != list->tail) {
        ShowItemInfo(target);
        target = target->right;
    }
}

string inputServieceMessage() {
    string itemName;
    cout << "아이템 이름을 입력해주세요 >> ";
    cin >> itemName;
    return itemName;
}

void Selling(ItemList * list) {
    srand((unsigned int)time(NULL));
    
    Item * target;
    target = list->head->right;
    while(target != list->tail) {
        target->itemCount = (rand() % (target->itemCount));
        target = target->right;
    }
}

void ShowSalesGraph(ItemList * list) {
    Item * target;
    string dash;
    int sellingCount = 0;
    int revenue = 0;
    
    target = list->head->right;
    if(target == list->tail) {
        cout << "****** !    자판기에 품목이 없습니다     ! *****" << endl;
        return;
    }
    while(target != list->tail) {
        dash = "";
        sellingCount = ITEM_MAX - target->itemCount;
        revenue += sellingCount * target->itemPrice;
        for(int i = 0; i < sellingCount; i++) {
            dash += "-";
        }
        cout << target->itemName << "(" << sellingCount << ") | " << dash << endl;
        target = target->right;
    }
    cout << "매출액 : " << revenue << endl;
    // dash 의 개수가 sellingCount 만큼 나와야함
    // 어떻게 할래?
}



/*************/

int main() {
    VendingMachine *vm = new VendingMachine;
    vm->admin = new Admin;
    vm->list = new ItemList;
    // 자판기 내 리스트 초기화
    ILInit(vm->list);
    
    // 출력값 확인을 위한 임시 data;
    Item * pData;
    Item data;
    // 로그인 여부
    bool hasLogin = false;
    // 메뉴선택
    int selectedMenu = 0;
    // 아이템이름
    string itemName;
    
    // Set ID and Password
    PrintSetAdminMessage();
    vm->admin->ID = input("ID");
    vm->admin->PW = input("PASSWORD");
    ClearScreen();
    while(selectedMenu != 9) {
        
        if(!hasLogin) hasLogin = Loginning(vm->admin->ID, vm->admin->PW);
        if(hasLogin) {
            selectedMenu = SelectMainMenu();
            switch(selectedMenu) {
                case 1: // 정보변경
                    if(CheckAdminInfo(vm->admin->PW)){
                        selectedMenu = SelectAdminMenu();
                        switch(selectedMenu) {
                            case 1: // 아이디변경
                                ChangeInfo("ID", &vm->admin->ID);
                                hasLogin = !hasLogin;
                                break;
                            case 2: // 비밀번호변경
                                ChangeInfo("PASSWORD", &vm->admin->PW);
                                hasLogin = !hasLogin;
                                break;
                            default:
                                NoMenu();
                        }
                    }
                    break;
                case 2: // 상품추가
                    ILInsert(vm->list);
                    break;
                case 3: // 상품제거
                    itemName = inputServieceMessage();
                    pData = ILFind(vm->list, itemName);
                    pData ? ILRemove(vm->list, pData) : printf("****** !    제거할 대상을 찾지 못했습니다     ! *****\n");
                    break;
                case 4: // 상품수정
                    itemName = inputServieceMessage();
                    pData = ILFind(vm->list, itemName);
                    EditItemInfo(pData);
                    break;
                case 5: // 상품전체보기
                    ShowAllItem(vm->list);
                    break;
                case 6: // 상품검색
                    itemName = inputServieceMessage();
                    pData = ILFind(vm->list, itemName);
                    pData ? ShowItemInfo(pData) : printf("****** !    해당 품목을 찾지 못했습니다     ! *****\n");
                    break;
                case 7: // 매출현황
                    ShowSalesGraph(vm->list);
                    break;
                case 8: // 판매개시
                    Selling(vm->list);
                    break;
            }
        }
    }
}



/*

 1. 내일 해야 할 일. 업무 분담                                    ok
 2. 링크드리스트 이해해서 오기 ( 아이템 연결 )                        ok
 3. 자판기 내에는 아이템을 담는 구조체 배열이 필드값으로 정해져있음          ok
 4. 메뉴 선택, 관리자모드 아이디와 비밀번호 입력                           ok
 5. 상품 등록을 했다치자 판매 개시를 하면 랜덤으로 팔린다 ?
 6. 소득액을 파악하고 잘 팔리는것 위주로
 
 
 1. 메뉴 UI 만들기
 2. 링크드리스트 이해하기
 3. 매출현황을 어떻게 표현할것인지
 
 
 판매 그래프

 
 ItemMax = 10;
 ItemCount = 10; --> 4 : 6개 팔림
 
 for(int i = 0; i <6; i++) {
    string += "ㅡ";
 }
 
 핫식스 (4) | ㅡㅡㅡㅡ
 레드불 (5) | ㅡㅡㅡㅡㅡ
 이프로 (10)| ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
 이상찬 (1) | ㅡ
 김기림 (0) | -
 
 ─ │ ┌ ┐ ┘ └ ├ ┬ ┤ ┴ ┼
 
 ┌───────────────────┐
 │
 └┬──────────────────┘
  └───>>
 ┌─────────┐
 │  input  ├───>
 └─────────┘
 
 
 
 ├── 입력해주세요 ──┤
*/

