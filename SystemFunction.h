//
//  SystemFunction.h
//  CppProject
//
//  Created by 김희철 on 2018. 6. 3..
//  Copyright © 2018년 Heekim. All rights reserved.
//

#pragma once
#include <iostream>
#include "VendingMachine.h"
#include "Message.h"
using namespace std;

bool ShowItemInfo(Item * target);
bool EditItemInfo(Item * target);
void ShowAllItem(ItemList * list);
void Selling(ItemList * list);
void ShowSalesGraph(ItemList * list);
bool IsSoldOut(ItemList * list);
bool ConfirmAdminInfo(string id, string pw);
void ChangeInfo(string message, string * adminInfo);
bool CheckAdminInfo(string adminPW);
void ReturnMenu();
bool Loginning(string &adminID, string &adminPW);
void RevenueSettled(ItemList * list);
