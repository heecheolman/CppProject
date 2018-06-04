//
//  DLinkedList.cpp
//  CppProject
//
//  Created by 김희철 on 2018. 6. 4..
//  Copyright © 2018년 Heekim. All rights reserved.
//

#include <iostream>
#include "DLinkedList.h"

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


