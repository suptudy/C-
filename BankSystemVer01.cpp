#include <iostream>
#include <cstring>
using namespace std;
void ShowMenu(); //메뉴출력
void MakeAccount(); //계좌개설을 위한 함수
void DepositMoney(); //입금
void WithdrawMoney(); //출금
void ShowAllAccInfo(); //잔액조회 

typedef struct {
	int accID; //계좌ID
	int balance; //잔액
	char cusName[20]; //고객 이름 
} Account;

Account accArr[100]; //Account 저장을 위한 배열
int accNum = 0; //저장된 Account 수 

int main() {
	int choice;
	
	while(1) {
		ShowMenu();
		cout<<"선택: ";
		cin>>choice;
		cout<<endl; 
	
		switch(choice) {
			case 1: MakeAccount();
			case 2: DepositMoney();
			case 3: WithdrawMoney();
			case 4: ShowAllAccInfo();
			case 5: return 0;
			default: cout<<"잘못된 선택입니다."<<endl; 
		}
	}
	return 0;
}

void ShowMenu() {
	cout<<"-----Menu-----"<<endl;
	cout<<"1. 계좌개설"<<endl;
	cout<<"2. 입금"<<endl;
	cout<<"3. 출금"<<endl;
	cout<<"4. 계좌정보 전체 출력"<<endl;
	cout<<"5. 프로그램 종료"<<endl; 
} 

void MakeAccount() {
	int id, balance;
	char name[20];
	
	cout<<"[계좌개설]"<<endl;
	cout<<"계좌ID: "; cin>>id; 
	cout<<"이름: "; cin>>name;
	cout<<"입금액: "; cin>>balance;
	cout<<endl;
	
	accArr[accNum].accID = id;
	accArr[accNum].balance = balance;
	strcpy(accArr[accNum].cusName, name);
	accNum++; 
}

void DepositMoney() {
	int money, id;
	
	cout<<"[입금]"<<endl;
	cout<<"계좌ID: "; cin>>id;
	cout<<"입금액: "; cin>>money;
	
	for(int i=0;i<accNum;i++) {
		if(accArr[i].accID == id) {
			accArr[i].balance += money;
			cout<<"입금완료"<<endl; 
			return;
		}
	}
	cout<<"유효하지 않은 ID 입니다"<<endl<<endl;
}

void WithdrawMoney() {
	int money, id;
	cout<<"[출금]"<<endl;
	cout<<"계좌ID: "; cin>>id;
	cout<<"출금액: "; cin>>money;
	
	for(int i=0; i<accNum; i++) {
		if(accArr[i].accID == id) {
			if(accArr[i].balance < money) {
				cout<<"잔액부족"<<endl<<endl; 
				return;
			}
			accArr[i].balance -=money;
			cout<<"출금완료"<<endl<<endl;
			return; 
		}
	} 
	cout<<"유효하지 않은 ID 입니다"<<endl<<endl;
}

void ShowAllAccInfo() {
	for(int i=0; i<accNum; i++) {
		cout<<"계좌ID: "<<accArr[i].accID<<endl;
		cout<<"이름: "<<accArr[i].cusName<<endl;
		cout<<"잔액: "<<accArr[i].balance<<endl; 
	}
}
