#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"

NameCard* MakeNameCard(char*name, char*phone)
{
	NameCard* card;
	card=(NameCard*)malloc(sizeof(NameCard));
	// NameCard*card=(NameCard*)malloc(sizeof(NameCard));

	// card->name[NAME_LEN]=name; //(X) 끝에 것만 복사됨.
	// card->name=name (X)
	// strcpy(card->name,name)
	// name은 주솟값 상수 !
	strcpy(card->name,name);
	// card->phone[PHONE_LEN]=(*phone);
	strcpy(card->phone,phone);

	return card;
}

void ShowNameCardInfo(NameCard*pcard)
{

	printf("%s\n", pcard->name);
	printf("%s\n", pcard->phone); 

}

int NameCompare(NameCard*pcard, char*name)
{
	// if(pcard->name[NAME_LEN]==fputs(name,stdout))
	if(!strcmp(pcard->name,name))
	return 0;

	else
	return -1;
}

void ChangePhoneNum(NameCard*pcard, char*phone)
{
	// pcard->phone[PHONE_LEN]=fputs(phone,stdout);
	strcpy(pcard->phone,phone);
}

