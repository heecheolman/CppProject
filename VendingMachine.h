//
//  VendingMachine.h
//  CppProject
//
//  Created by 김희철 on 2018. 6. 3..
//  Copyright © 2018년 Heekim. All rights reserved.
//

#pragma once

#define ITEMLIST_MAX 5
#define ITEM_MAX 10
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
