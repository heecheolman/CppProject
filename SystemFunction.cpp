//
//  SystemFunction.cpp
//  CppProject
//
//  Created by 김희철 on 2018. 6. 3..
//  Copyright © 2018년 Heekim. All rights reserved.
//

#include "SystemFunction.h"

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
    int soldOutItemCount = 0;
    Item * target = list->head->right;
    
    while(target != list->tail) {
        if(target->itemCount == 0) {
            // 하나라도 개수가 존재한다면 false
            soldOutItemCount++;
        }
        target = target->right;
    }
    isSoldOut = soldOutItemCount == list->numOfData ? true : false;
    if(isSoldOut) cout << "****** !    전체 품절입니다.     ! *****" << endl;
    PressAnyKey(false);
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

void RevenueSettled(ItemList * list) {
    Item * iterator = list->head->right;
    Item * target = list->head->right;
    
    while(iterator != list->tail) {
        target = iterator;
        target->left->right = target->right;
        target->right->left = target->left;
        free(target);
        iterator = iterator->right;
    }
    list->numOfData = 0;
    cout << "──── *    정산되었습니다.   * ────" << endl;
}
