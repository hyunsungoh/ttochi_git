#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#pragma warning (disable : 4996)

#define NAME_LEN 20
#define CUSTOM_SIZE 100

typedef struct Customer
{
	int no;
	int accnum;
	char name[NAME_LEN];
	int balance;
}Customer;

enum custom_menu
{
	TERMINATE, ADD, DELETE, TRANSFER, SHOW_BALANCE, PRINT_TOTAL, SUSPEND, ACTIVATE
};

void add_account(Customer* p, int* pIdx);
void delete_account(Customer* p, int* pIdx);
void transfer(Customer* p, int* pIdx);
void showbalance(Customer* p, int* pIdx);
void printtotal(Customer* p, int* pIdx);
void suspendaccount(Customer* p, int* pIdx);
void activateaccount(Customer* p, int* pIdx);


int main()
{
	Customer cus[CUSTOM_SIZE];
	int choice;
	int index = 0; //저장할 위치의 인덱스
	while (1)
	{
		system("cls");
		printf("1. 계좌 생성\n");
		printf("2. 계좌 삭제\n");
		printf("3. 다른 계좌로 이체\n");
		printf("4. 계좌 잔고 출력\n");
		printf("5. 전체 계좌 총액 출력\n");
		printf("6. 계좌 정지\n");
		printf("7. 계좌 활성화\n");
		printf("0. 프로그램 종료\n");
		printf("\n메뉴선택 : [ ]\b\b");
		scanf("%d", &choice);
		while (getchar() != '\n');

		switch (choice)
		{
		case ADD:
			add_account(cus, &index);
			break;
		case DELETE:
			delete_account(cus, &index);
			break;
		case TRANSFER:
			transfer(cus, &index);
			break;
		case SHOW_BALANCE:
			showbalance(cus, &index);
			break;
		case PRINT_TOTAL:
			printtotal(cus, &index);
			break;
		case SUSPEND:
			suspendaccount(cus, &index);
			break;
		case ACTIVATE:
			activateaccount(cus, &index);
			break;
		case TERMINATE:
			exit(0);
		}

		printf("\n\n\t\t");
		system("pause");
	}

	return 0;
}

void add_account(Customer* p, int* pIdx)
{
	if (*pIdx >= CUSTOM_SIZE)
	{
		printf("\n\n\t\t최대 %d건의 데이터만 저장할 수 있습니다.\n", CUSTOM_SIZE);
		printf("\t\t삭제 후 다시 이용하세요\n");
		return;
	}

	system("cls");
	p[*pIdx].no = *pIdx + 1;

	printf("계좌번호 : ");
	scanf("%d", &p[*pIdx].accnum);
	while (getchar() != '\n');

	printf("사용자 이름 : \n");
	gets_s(p[*pIdx].name, NAME_LEN - 1);

	printf("계좌잔고 : ");
	scanf("%d", &p[*pIdx].balance);
	while (getchar() != '\n');

	(*pIdx)++;
}

void delete_account(Customer* p, int* pIdx)
{
	int del_num;
	int i, j;
	int flag = 0;

	system("cls");

	printf("삭제할 계좌번호를 입력하세요 : %d\n");
	scanf("%d", &del_num);
	while (getchar() != '\n');

	for (i = 0; i < *pIdx; i++)
	{
		if (del_num == p[*pIdx].accnum)
		{
			for (j = i + 1; j < *pIdx; j++, i++)	// 삭제될 다음 위치부터 마지막까지 반복
			{
				p[i] = p[j];					// 뒤에 있는 데이터를 앞으로 이동
			}

			flag = 1;	// 삭제되었다면 1로 변환
			(*pIdx)--;	// index 1 감소
			break;		// 삭제 후 반복문 탈출
		}
	}

	if (flag == 0)
		printf("\n\n\t\t등록된 데이터가 없습니다. \n");
}

void transfer(Customer* p, int* pIdx)
{
	int i, j;
	int remit;
	system("cls");

	printf("이체할 계좌를 입력하시오 : \n");
	scanf("%d", &i);


	printf("송금할 금액을 입력하시오 : \n");
	scanf("%d", &remit);

	if (remit >= p[i].balance)
		printf("이체가능합니다\n");
	if (remit < p[i].balance)
	{
		printf("이체불가합니다. 다른 금액을 입력하세요.\n");
		scanf("%d", &remit);
	}

	printf("이체받을 계좌를 입력하시오 : \n");
	scanf("%d", &j);

	p[i].balance -= remit;
	p[j].balance += remit;
}

void showbalance(Customer* p, int* pIdx)
{
	int i;

	system("cls");

	printf("검색할 계좌번호를 입력하시오 : ");
	scanf("%d", &i);
	printf("현재 계좌 잔고를 출력하시오: %d", p[i].balance);
}

void printtotal(Customer* p, int* pIdx)
{
	int i;
	int total = 0;

	system("cls");

	printf("전체 계좌 총액을 출력하시오 : ");
	for (i = 0; i < (*pIdx) + 1; i++)
	{
		total += p[i].balance;
	}
}

void suspendaccount(Customer* p, int* pIdx)
{
	int i;

	printf("검색할 계좌번호를 입력하시오 : ");
	scanf("%d", &i);
	printf("%s의 계좌 %d는 정지되었습니다", p[i].name, p[i].accnum);
}
void activateaccount(Customer* p, int* pIdx)
{
	int i;

	printf("검색할 계좌번호를 입력하시오 : ");
	scanf("%d", &i);
	printf("%s의 계좌 %d는 활성화되었습니다", p[i].name, p[i].accnum);
}
