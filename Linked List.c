#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

typedef struct list{
	char name[16];
	char PNB[14];
	int age;
	struct list* next;
}List;

struct list value[100];
struct list* PREV = &value[0];

/*
void make();
void link();
void print();
void del_list();
*/
int main(void)
{
	int i = 1;
	PREV->next = '\0';
	int what;
	
	while(1)
	{
		int index;
		int j;
		
		printf("//////////MENU//////////\n");
		printf("\t1.입력\n");
		printf("\t2.조회\n");
		printf("\t3.삭제\n");
		scanf("%d",&what);
		printf("\n");
		
		switch(what)
		{
			case 1 :
			printf("이름 입력 : ");
			scanf("%s",value[i].name); 
			printf("전화번호 입력(-포함) : ");
			scanf("%s",value[i].PNB);
			printf("나이 입력 : ");
			scanf("%d",&value[i].age);
			(PREV+i-1)->next = &value[i];
			i++; break;
			
			case 2 : 
			j = 1;
			while(value[j-1].next != '\0')
			{
				printf("이름 	 : %s\n",value[j].name);
				printf("전화번호 : %s\n",value[j].PNB);
				printf("나이	 : %d\n",value[j].age);
				printf("\n");
				j++;
			}
			break;
			
			case 3 :
			printf("삭제할 리스트의 index 번호를 입력하세요 : ");
			scanf("%d",&index);
			if(value[index].next != '\0')
			value[index-1].next = &value[index+1];
			else if(value[index].next == '\0')
			value[index-1].next = '\0';
			break;
			default : printf("다시 입력하세요\n"); break; 
		}
		system("pause");
		system("cls");	
	}
	
}
