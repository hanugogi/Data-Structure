#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

typedef struct list{
	char name[16];
	char PNB[14];
	int age;
	struct list* next; //LIST* next;는 불가능 
}LIST; //구조체 선언

LIST head = {"\0","\0",0};
LIST* HEAD = &head; //최전방 리스트 포인터 
LIST* TAIL;			//최후방 리스트 포인터 

void insertion();  //리스트 삽입 
void Connect(LIST* p, int index);
void print();		  		  //리스트 출력 
void del_list();	 		  //리스트 삭제 

int main(void)
{
	int what;
	TAIL = HEAD;
	
	while(1)
	{		
		printf("//////////Linked List MENU//////////\n");
		printf("\t  1.Insert Data\n");
		printf("\t  2.Check Linked List\n");
		printf("\t  3.Delete Data\n");
		printf("\t  4.Exit\n");
		scanf("%d",&what);
		printf("\n");
		
		switch(what)	
		{
			case 1 : insertion(); break;
			
			case 2 : print(); break;

			case 3 : del_list(); break;
			
			case 4 : return 0;
			
			default : printf("Command Error\n"); break; 
		}
		Sleep(100);
	}
}

void insertion(){
	int index;
	printf("Enter the number to Insert(0 is TAIL's next) : ");
	scanf("%d",&index);
	
	LIST* p = (LIST*)malloc(sizeof(LIST));
	printf("Insert Age          : ");
	scanf("%d",&(p->age));
	printf("Insert Name         : ");
	scanf("%s",p->name);
	printf("Insert Phone number : ");
	scanf("%s",p->PNB);		//리스트 생성
	printf("\n");
	Connect(p,index);		//리스트 연결
}//리스트 생성함수

void Connect(LIST* p, int index){
	LIST* Connect = HEAD;
	if(index == 0)
	{
		TAIL->next = p;
		TAIL = p;
	}//TAIL에 이어주는 경우
	else if(index < 0)
	{
		printf("Command Errorn");
	}
	else
	{
		for(index;index-1>0;index--)
		{
			Connect = Connect->next;
		}
		p->next = Connect->next;
		Connect->next = p;
		if(p->next == '\0')
		{
			TAIL = p;
		}
	}//번호를 지정한 경우
	//리스트 마지막 부분과 연결
}//리스트 연결함수(생성 함수에 포함)

void print(){
	LIST* PRINT = HEAD;
	if(PRINT->next == '\0')
	{
		printf("None data\n");
		main();
	}//데이터가 하나도 없을 경우 메인으로 
	while(PRINT->next!='\0')
	{
		//printf("PRINT : %d PRINT->next : %d HEAD->next : %d\n ",PRINT,PRINT->next,HEAD->next);
		printf("Age          : %d\n",PRINT->next->age);
		printf("Name         : %s\n",PRINT->next->name);
		printf("Phone number : %s\n",PRINT->next->PNB);
		printf("\n");
		PRINT = PRINT->next;
	}//next가 0이 될 때까지 출력
			
}

void del_list( ){
	int index;
	printf("Enter the Index number to Delete : ");
	scanf("%d",&index);//삭제할 인덱스 번호 받기
	printf("\n");
	
	LIST* DEL = HEAD;
	for(index;index-1>0;index--)
	{
		DEL = DEL->next;	//삭제할 인덱스 바로 앞 리스트주소
	}
	if(DEL->next == '\0'){
		printf("Command Error\n");
		main();
	}//잘못 된 번호일경우 메인으로 
	LIST* DEL_ = DEL->next;//삭제할 인덱스 주소 저장
	if(DEL->next->next != '\0')
	{
		DEL->next = DEL->next->next;
	}//삭제할 인덱스가 가운데일 경우
	else
	{
		DEL->next = '\0';
	}//삭제할 인덱스가 마지막일 경우
		
	free(DEL_);//인덱스 삭제
}

