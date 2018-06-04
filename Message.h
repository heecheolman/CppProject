//
//  Message.h
//  CppProject
//
//  Created by 김희철 on 2018. 6. 3..
//  Copyright © 2018년 Heekim. All rights reserved.
//

#pragma once

#include <iostream>
using namespace std;

void ClearScreen();
void SetAccountMessage();
bool PressAnyKey(bool isFindMessage);
void PrintSetAdminMessage();
int SelectMainMenu();
int SelectAdminMenu();
string Input(string message);
bool YesOrNo(string message);
string inputServieceMessage();
