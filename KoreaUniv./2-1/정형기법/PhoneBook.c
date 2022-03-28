#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

int i;
char phone[100];

int main()
{
    FindOp();
}

void FindOp()
{
    scanf("%d", i);
    if (phone[i] > 10000 && phone[i] < 99999)
        printf("this number is known\n");
    if (phone[i] == -1)
        printf("this number is unknown\n");
}








typedef struct TEL
{
    char name[NAME_LEN];
    char phone[PHONE_LEN];
}TEL;

void FindOp()
{
    for(i=0;i=<100;i++)
    {
        if (name[i]>=10000 && name[i]<=99999)
        {
            
        }

        if (name[i] = -1)
        {
            
        }
    }
}