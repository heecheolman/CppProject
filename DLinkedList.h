//
//  DLinkedList.h
//  CppProject
//
//  Created by 김희철 on 2018. 6. 4..
//  Copyright © 2018년 Heekim. All rights reserved.
//

#pragma once
#include "VendingMachine.h"
#include "SystemFunction.h"

using namespace std;

void ILInit(ItemList * list);
void ILInsert(ItemList * list);
bool ILFirst(ItemList * list, Item * tempItem);
bool ILNext(ItemList * list, Item * tempItem);
bool ILRemove(ItemList * list, Item * target);
Item *ILFind(ItemList * list, string targetName);
