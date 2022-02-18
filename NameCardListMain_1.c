#include <stdio.h>
#include <stdlib.h>
#include "NameCard.h"
#include "ArrayList.h"


int main(void)
{
	List list;

	// NameCard*Card1;
	// NameCard*Card2;
	// NameCard*Card3;
	NameCard*pcard;

	// NameCard NC;
	// NameCard*LCard; // 반환할 포인터 변수 값

	char sname[NAME_LEN];
	char sphone[PHONE_LEN];

	ListInit(&list); // 리스트 초기화

	pcard=MakeNameCard("yonghee","01064043144");
	LInsert(&list,pcard);
	
	pcard=MakeNameCard("Jihwan", "01031312323");
	LInsert(&list,pcard);

	pcard=MakeNameCard("Haewon", "01020203131");
	LInsert(&list,pcard);

	
	// LInsert(&list,Card1); // 리스트 배열에 주소값 3개 저장
	// LInsert(&list,Card2);
	// LInsert(&list,Card3);


	printf("이름 검색 : ");
	scanf("%s", sname);

	if(LFirst(&list, &pcard))
	{
		if((NameCompare(pcard,sname))==0)
		{
			ShowNameCardInfo(pcard);
		}

		else //else를 붙여줘야 위의 if에서 조건 충족하면 건너뛰어짐
		{
		while(LNext(&list, &pcard))
		{
			if(NameCompare(pcard, sname)==0)
			{
				ShowNameCardInfo(pcard);
			}

			
		}
		}
		

	}

	printf("이름 검색 후 전화번호 변경 : ");
	scanf("%s", sname);
	printf("변경할 전화번호 : ");
	scanf("%s", sphone);

	if(LFirst(&list, &pcard))
	{
		if((NameCompare(pcard,sname))==0)
		{
			ChangePhoneNum(pcard,sphone);
		}

		else //else를 붙여줘야 위의 if에서 조건 충족하면 건너뛰어짐
		{
		while(LNext(&list, &pcard))
		{
			if(NameCompare(pcard, sname)==0)
			{
				ChangePhoneNum(pcard,sphone);
			}

			
		}
		}
		

	}

	printf("삭제할 이름 타이핑 : ");
	scanf("%s", sname);

	if(LFirst(&list, &pcard))
	{
		if((NameCompare(pcard,sname))==0)
		{
			pcard=LRemove(&list);
			free(pcard);
		}

		else //else를 붙여줘야 위의 if에서 조건 충족하면 건너뛰어짐
		{
		while(LNext(&list, &pcard))
		{
			if(NameCompare(pcard, sname)==0)
			{
				pcard=LRemove(&list);
				free(pcard);
			}

			
		}
		}
		
		if(LFirst(&list,&pcard))
		{
			ShowNameCardInfo(pcard);

			while(LNext(&list,&pcard))
			ShowNameCardInfo(pcard);
		
		}

	}

	

	 

	return 0;
}