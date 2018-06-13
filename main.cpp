//  main.cpp
//  CppProject
//
//  Created by 김희철 on 2018. 5. 30..
//  Copyright © 2018년 Heekim. All rights reserved.
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "VendingMachine.h"
#include "Message.h"
#include "SystemFunction.h"
#include "DLinkedList.h"

using namespace std;

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
    while(selectedMenu != 10) {
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
                case 9:
                    if(vm->list->numOfData != 0) RevenueSettled(vm->list);
                    else cout << "****** !    등록된 상품이 없습니다     ! *****" << endl;
                    PressAnyKey(false);
                    break;
            }
        }
    }
}
