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
    int revenue;
} Admin;

typedef struct VendingMachine {
    Admin * admin;
    ItemList * list;
} VendingMachine;

/* Message */
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
    cout << "├──[ 9 ]  종료" << endl;
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

bool CheckAdminInfo(string adminPW) {
    bool isSame = false;
    string tempPW;
    cout <<  endl;
    cout << "──── *    정보를 변경합니다   * ────" << endl;
    cout << "─┬── *  비밀번호를 입력해주세요 * ────" << endl;
    cout << " |" << endl;
    cout << " └───>>   ";
    cin >> tempPW;
    cout <<  endl;
    isSame = (adminPW == tempPW) ? true : false;
    if(!isSame) {
        cout << "****** ! 비밀번호가 일치하지 않습니다 ! *****" << endl;
        cout << "****** !       되돌아갑니다       ! *****" << endl;
        PressAnyKey(false);
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
        cout << " ├── *  돌아가시려면 (n / N)   * ────" << endl;
        cout << " |" << endl;
        cout << " ├───>>  ";
        cin >>  tempInfo;
        if(tempInfo == "n" || tempInfo == "N") {
            cout << "****** !    되돌아갑니다     ! *****" <<  endl;
            PressAnyKey(false);
            break;
            return;
        }
        cout << " |" << endl;
        cout << " ├─── 입력하신 정보가 " << tempInfo << "가 맞습니까 ? ( Y or N )" << endl;
        cout << " |" << endl;
        cout << " └───>>  ";
        cin >> YorN;
        cout << endl; cout << endl;
        if(YorN == "Y" || YorN == "y") {
            hasDone = true;
            *adminInfo = tempInfo;
            cout <<  endl;
            cout << "──── *    변경되었습니다   * ────" << endl;
            cout << "──── *    재로그인합니다   * ────" << endl;
            cout <<  endl;
            PressAnyKey(false);
        }else {
            cout <<  endl;
            cout << "****** !    변경되지 않았습니다     ! *****" << endl;
            cout << "****** !       되돌아갑니다       ! *****" << endl;
            cout <<  endl;
            PressAnyKey(false);
        }
    }
}

void ReturnMenu() {
    cout << "****** !    되돌아갑니다     ! *****" <<  endl;
    PressAnyKey(false);
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
    inputID = Input("ID");
    inputPW = Input("PASSWORD");
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
        PressAnyKey(false);
        return;
    }
    string tempName;
    int tempPrice;
    
    cout << "─┬── *    아이템 이름 설정   * ────" << endl;
    cout << " ├── *  돌아가시려면 (n / N)   * ────" << endl;
    cout << " │" << endl;
    cout << " ├───>>  ";
    cin >> tempName;
    
    if(tempName == "n" || tempName == "N") {
        cout << "****** !    되돌아갑니다     ! *****" <<  endl;
        PressAnyKey(false);
        return;
    }
    cout << " │" << endl;
    cout << " ├── *    아이템 가격 설정   * ────" << endl;
    cout << " │" << endl;
    cout << " └───>>  ";
    cin >> tempPrice;
    
    Item * newItem = new Item;
    newItem->right = list->tail;
    newItem->left = list->tail->left;
    list->tail->left->right = newItem;
    list->tail->left = newItem;
    
    newItem->itemName = tempName;
    newItem->itemPrice = tempPrice;
    newItem->itemCount = ITEM_MAX;
    newItem->isSoldOut = false;
    (list->numOfData)++;
    
    cout << endl; cout << endl;
    cout << endl;cout << endl;
    cout << "──── *  상품을 추가했습니다   * ────" << endl;
    cout << endl;
    cout << "┌─────────────────────────┐" << endl;
    cout << "│            " << list->numOfData << "            │" << endl;
    cout << "├───────────┬─────────────┤" << endl;
    cout << "│   NAME    │"; cout.width(10); cout.fill(' '); cout << right << newItem->itemName; cout.width(6); cout.fill(' '); cout << right << "│" << endl;
    cout << "├───────────┼─────────────┤" << endl;
    cout << "│   PRICE   │"; cout.width(8); cout.fill(' '); cout << right << newItem->itemPrice; cout.width(8); cout.fill(' '); cout << right << "│" << endl;
    cout << "├───────────┼─────────────┤" << endl;
    cout << "│   COUNT   │"; cout.width(8); cout.fill(' '); cout << right << newItem->itemCount; cout.width(8); cout.fill(' '); cout << right << "│" << endl;
    cout << "└───────────┴─────────────┘" << endl;
    PressAnyKey(false);
}

bool ILFirst(ItemList * list, Item * tempItem) {
    if(list->numOfData == 0) {
        cout << "****** !    저장된 데이터가 없습니다     ! *****" << endl;
        PressAnyKey(false);
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
        PressAnyKey(false);
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
    cout << endl;
    willRemove = YesOrNo("제거");
    if(willRemove){
        target->left->right = target->right;
        target->right->left = target->left;
        cout << endl; cout << endl;
        cout << "****** !    다음 상품을 제거했습니다     ! *****" << endl;
        cout << endl;
        cout << "┌─────────────────────────┐" << endl;
        cout << "│            " << list->numOfData << "            │" << endl;
        cout << "├───────────┬─────────────┤" << endl;
        cout << "│   NAME    │"; cout.width(10); cout.fill(' '); cout << right << target->itemName; cout.width(6); cout.fill(' '); cout << right << "│" << endl;
        cout << "├───────────┼─────────────┤" << endl;
        cout << "│   PRICE   │"; cout.width(8); cout.fill(' '); cout << right << target->itemPrice; cout.width(8); cout.fill(' '); cout << right << "│" << endl;
        cout << "├───────────┼─────────────┤" << endl;
        cout << "│   COUNT   │"; cout.width(8); cout.fill(' '); cout << right << target->itemCount; cout.width(8); cout.fill(' '); cout << right << "│" << endl;
        cout << "└───────────┴─────────────┘" << endl;
        cout << endl;
        free(target);
        (list->numOfData)--;
    }else {
        cout << endl;
        cout << "****** !    취소했습니다.     ! *****" << endl;
        cout << endl;
        PressAnyKey(false);
    }
    PressAnyKey(false);
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

bool ShowItemInfo(Item * target) {
    cout << endl; cout << endl;
    cout << "┌─────────────────────────┐" << endl;
    cout << "│        ITEM  INFO       │" << endl;
    cout << "├───────────┬─────────────┤" << endl;
    cout << "│   NAME    │"; cout.width(10); cout.fill(' '); cout << right << target->itemName; cout.width(6); cout.fill(' '); cout << right << "│" << endl;
    cout << "├───────────┼─────────────┤" << endl;
    cout << "│   PRICE   │"; cout.width(8); cout.fill(' '); cout << right << target->itemPrice; cout.width(8); cout.fill(' '); cout << right << "│" << endl;
    cout << "├───────────┼─────────────┤" << endl;
    cout << "│   COUNT   │"; cout.width(8); cout.fill(' '); cout << right << target->itemCount; cout.width(8); cout.fill(' '); cout << right << "│" << endl;
    cout << "└───────────┴─────────────┘" << endl;
    PressAnyKey(false);
    return true;
}

bool EditItemInfo(Item * target) {
    bool hasEdit = false;
    string inputName;
    int inputPrice;
    int menu = 0;
    ShowItemInfo(target);
    cout << endl;
    cout << "┌────────────────────────┐" << endl;
    cout << "│       EDIT   ITEM      │" << endl;
    cout << "├────────────────────────┘" << endl;
    cout << "|" << endl;
    cout << "├──[ 1 ]  아이템 이름" << endl;
    cout << "|" << endl;
    cout << "├──[ 2 ]  아이템 가격" << endl;
    cout << "|" << endl;
    cout << "├──[ 3 ]  나가기" << endl;
    cout << "|" << endl;
    cout << "└┬───────────────────────┘" << endl;
    cout << " |" << endl;
    cout << " └───>>  ";
    cin >> menu;
    cout << endl; cout << endl;
    switch(menu) {
        case 1:
            cout << "┌────────────────────────┐" << endl;
            cout << "│   변경될 아이템 이름 입력    │" << endl;
            cout << "└┬───────────────────────┘" << endl;
            cout << " |" << endl;
            cout << " └───>>  ";
            cin >> inputName;
            cout << endl;
            hasEdit = YesOrNo("변경");
            if(hasEdit) {
                target->itemName = inputName;
            }
            break;
        case 2:
            cout << "┌────────────────────────┐" << endl;
            cout << "│   변경될 아이템 가격 입력    │" << endl;
            cout << "└┬───────────────────────┘" << endl;
            cout << " |" << endl;
            cout << " └───>>  ";
            cin >> inputPrice;
            hasEdit = YesOrNo("변경");
            if(hasEdit) {
                target->itemPrice = inputPrice;
            }
            break;
        case 3:
            cout << "****** !    종료합니다     ! *****" << endl;
            hasEdit = false;
            break;
    }
    if(hasEdit) {
        cout << "──── * 다음과 같이 변경되었습니다   * ────" << endl;
        cout << endl;
        ShowItemInfo(target);
    }else {
        cout << "****** !    변경되지 않았습니다     ! *****" << endl;
    }
    PressAnyKey(false);
    return true;
}


void ShowAllItem(ItemList * list) {
    Item * target;
    target = list->head->right;
    int itemNumber = 0;
    
    if(target == list->tail) {
        cout << "****** !    저장된 데이터가 없습니다     ! *****" <<  endl;
        PressAnyKey(false);
        return;
    }
    while(target != list->tail) {
        itemNumber++;
        cout << "┌─────────────────────────┐" << endl;
        cout << "│             " << itemNumber << "           │" << endl;
        cout << "├───────────┬─────────────┤" << endl;
        cout << "│   NAME    │"; cout.width(10); cout.fill(' '); cout << right << target->itemName; cout.width(6); cout.fill(' '); cout << right << "│" << endl;
        cout << "├───────────┼─────────────┤" << endl;
        cout << "│   PRICE   │"; cout.width(8); cout.fill(' '); cout << right << target->itemPrice; cout.width(8); cout.fill(' '); cout << right << "│" << endl;
        cout << "├───────────┼─────────────┤" << endl;
        cout << "│   COUNT   │"; cout.width(8); cout.fill(' '); cout << right << target->itemCount; cout.width(8); cout.fill(' '); cout << right << "│" << endl;
        cout << "└───────────┴─────────────┘" << endl;
        target = target->right;
    }
    PressAnyKey(false);
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

void Selling(ItemList * list) {
    srand((unsigned int)time(NULL));
    
    Item * target;
    target = list->head->right;
    while(target != list->tail) {
        if(target->itemCount != 0){
            target->itemCount = (rand() % (target->itemCount));
        }
        target = target->right;
    }
    cout << "──── *    판매하였습니다   * ────" << endl;
    PressAnyKey(false);
}

void ShowSalesGraph(ItemList * list) {
    Item * target;
    string square;
    int sellingCount = 0;
    int revenue = 0;
    
    target = list->head->right;
    cout << "┌─────────────────────────┐" << endl;
    cout << "│         매출 그래프        │" << endl;
    cout << "├─────────────────────────┘" << endl;
    cout << "│" << endl;
    while(target != list->tail) {
        square = "";
        sellingCount = ITEM_MAX - target->itemCount;
        revenue += sellingCount * target->itemPrice;
        for(int i = 0; i < sellingCount; i++) {
            square += "■";
        }
        cout << "├──  "; cout.width(15); cout.fill(' '); cout << left << target->itemName; cout << " ["; cout.width(2); cout.fill(' '); cout << left << sellingCount; cout << "] | " << square << endl;
        cout << "│" << endl;
        target = target->right;
    }
    cout << "├─────────────────────────┐" << endl;
    cout << "│         총 매출금액        │" << endl;
    cout << "├─────────────────────────┤" << endl;
    cout << "│           "; cout.width(9); cout.fill(' '); cout << left << revenue; cout << "     │" << endl;
    cout << "└─────────────────────────┘" << endl;
    PressAnyKey(false);
}

bool IsSoldOut(ItemList * list) {
    bool isSoldOut = false;
    Item * target;
    target = list->head->right;
    while(target != list->tail) {
        if(target->itemCount == 0) {
            isSoldOut = true;
            break;
        }
        target = target->right;
    }
    if(isSoldOut) {
        cout << "****** !    품절인 항목이 있습니다     ! *****" << endl;
    }
    return isSoldOut;
}

bool ConfirmAdminInfo(string id, string pw) {
    bool isConfirm = false;
    string confirm;
    cout << endl; cout << endl;
    cout << "──── *    ID 와 PW 가 맞습니까? ( Y / N )   * ────" << endl;
    cout << endl;
    cout << "┌───────────┬─────────────┐" << endl;
    cout << "│    ID     │"; cout.width(10); cout.fill(' '); cout << right << id; cout.width(6); cout.fill(' '); cout << right << "│" << endl;
    cout << "├───────────┼─────────────┤" << endl;
    cout << "│    PW     │"; cout.width(8); cout.fill(' '); cout << right << pw; cout.width(8); cout.fill(' '); cout << right << "│" << endl;
    cout << "└───────────┴─────────────┘" << endl;
    cout << endl; cout << endl;
    cin >> confirm;
    isConfirm = (confirm == "y" || confirm == "Y") ? true : false;
    return isConfirm;
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
    // 아이디 비밀번호 체크
    bool isConfirm = false;
    // 메뉴선택
    int selectedMenu = 0;
    // 아이템이름
    string searchItemName;
    string tempID, tempPW;
    
    // Set ID and Password
    PrintSetAdminMessage();
    
    while(!isConfirm) {
        tempID = Input("ID");
        tempPW = Input("PASSWORD");
        isConfirm = ConfirmAdminInfo(tempID, tempPW);
    }

    vm->admin->ID = tempID;
    vm->admin->PW = tempPW;
    SetAccountMessage();
    PressAnyKey(false);
    
    ClearScreen();
    while(selectedMenu != 9) {
        ClearScreen();
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
                            case 3:
                                ReturnMenu();
                                break;
                        }
                    }
                    break;
                case 2: // 상품추가
                    ILInsert(vm->list);
                    break;
                case 3: // 상품제거
                    ShowAllItem(vm->list);
                    if(vm->list->numOfData != 0) searchItemName = inputServieceMessage();
                    if(searchItemName == "n" || searchItemName == "N") break;
                    pData = ILFind(vm->list, searchItemName);
                    pData ? ILRemove(vm->list, pData) : PressAnyKey(true);
                    break;
                case 4: // 상품수정
                    ShowAllItem(vm->list);
                    if(vm->list->numOfData != 0) searchItemName = inputServieceMessage();
                    pData = ILFind(vm->list, searchItemName);
                    pData ? EditItemInfo(pData) : PressAnyKey(true);
                    break;
                case 5: // 상품전체보기
                    ShowAllItem(vm->list);
                    break;
                case 6: // 상품검색
                    if(vm->list->numOfData != 0) searchItemName = inputServieceMessage();
                    pData = ILFind(vm->list, searchItemName);
                    pData ? ShowItemInfo(pData) : PressAnyKey(true);
                    break;
                case 7: // 매출현황
                    if(vm->list->numOfData != 0) ShowSalesGraph(vm->list);
                    else {
                        cout << "****** !    등록된 상품이 없습니다     ! *****" << endl;
                        PressAnyKey(false);
                    }
                    break;
                case 8: // 판매개시
                    if(vm->list->numOfData != 0 && !IsSoldOut(vm->list)) {
                        Selling(vm->list);
                    }
                    else if(vm->list->numOfData == 0) {
                        cout << "****** !    등록된 상품이 없습니다     ! *****" << endl;
                        PressAnyKey(false);
                    }
                    break;
            }
        }
    }
}
