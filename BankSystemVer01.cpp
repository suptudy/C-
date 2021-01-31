#include <iostream>
#include <cstring>
using namespace std;
void ShowMenu(); //�޴����
void MakeAccount(); //���°����� ���� �Լ�
void DepositMoney(); //�Ա�
void WithdrawMoney(); //���
void ShowAllAccInfo(); //�ܾ���ȸ 

typedef struct {
	int accID; //����ID
	int balance; //�ܾ�
	char cusName[20]; //�� �̸� 
} Account;

Account accArr[100]; //Account ������ ���� �迭
int accNum = 0; //����� Account �� 

int main() {
	int choice;
	
	while(1) {
		ShowMenu();
		cout<<"����: ";
		cin>>choice;
		cout<<endl; 
	
		switch(choice) {
			case 1: MakeAccount();
			case 2: DepositMoney();
			case 3: WithdrawMoney();
			case 4: ShowAllAccInfo();
			case 5: return 0;
			default: cout<<"�߸��� �����Դϴ�."<<endl; 
		}
	}
	return 0;
}

void ShowMenu() {
	cout<<"-----Menu-----"<<endl;
	cout<<"1. ���°���"<<endl;
	cout<<"2. �Ա�"<<endl;
	cout<<"3. ���"<<endl;
	cout<<"4. �������� ��ü ���"<<endl;
	cout<<"5. ���α׷� ����"<<endl; 
} 

void MakeAccount() {
	int id, balance;
	char name[20];
	
	cout<<"[���°���]"<<endl;
	cout<<"����ID: "; cin>>id; 
	cout<<"�̸�: "; cin>>name;
	cout<<"�Աݾ�: "; cin>>balance;
	cout<<endl;
	
	accArr[accNum].accID = id;
	accArr[accNum].balance = balance;
	strcpy(accArr[accNum].cusName, name);
	accNum++; 
}

void DepositMoney() {
	int money, id;
	
	cout<<"[�Ա�]"<<endl;
	cout<<"����ID: "; cin>>id;
	cout<<"�Աݾ�: "; cin>>money;
	
	for(int i=0;i<accNum;i++) {
		if(accArr[i].accID == id) {
			accArr[i].balance += money;
			cout<<"�ԱݿϷ�"<<endl; 
			return;
		}
	}
	cout<<"��ȿ���� ���� ID �Դϴ�"<<endl<<endl;
}

void WithdrawMoney() {
	int money, id;
	cout<<"[���]"<<endl;
	cout<<"����ID: "; cin>>id;
	cout<<"��ݾ�: "; cin>>money;
	
	for(int i=0; i<accNum; i++) {
		if(accArr[i].accID == id) {
			if(accArr[i].balance < money) {
				cout<<"�ܾ׺���"<<endl<<endl; 
				return;
			}
			accArr[i].balance -=money;
			cout<<"��ݿϷ�"<<endl<<endl;
			return; 
		}
	} 
	cout<<"��ȿ���� ���� ID �Դϴ�"<<endl<<endl;
}

void ShowAllAccInfo() {
	for(int i=0; i<accNum; i++) {
		cout<<"����ID: "<<accArr[i].accID<<endl;
		cout<<"�̸�: "<<accArr[i].cusName<<endl;
		cout<<"�ܾ�: "<<accArr[i].balance<<endl; 
	}
}
