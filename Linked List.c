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
		printf("\t1.�Է�\n");
		printf("\t2.��ȸ\n");
		printf("\t3.����\n");
		scanf("%d",&what);
		printf("\n");
		
		switch(what)
		{
			case 1 :
			printf("�̸� �Է� : ");
			scanf("%s",value[i].name); 
			printf("��ȭ��ȣ �Է�(-����) : ");
			scanf("%s",value[i].PNB);
			printf("���� �Է� : ");
			scanf("%d",&value[i].age);
			(PREV+i-1)->next = &value[i];
			i++; break;
			
			case 2 : 
			j = 1;
			while(value[j-1].next != '\0')
			{
				printf("�̸� 	 : %s\n",value[j].name);
				printf("��ȭ��ȣ : %s\n",value[j].PNB);
				printf("����	 : %d\n",value[j].age);
				printf("\n");
				j++;
			}
			break;
			
			case 3 :
			printf("������ ����Ʈ�� index ��ȣ�� �Է��ϼ��� : ");
			scanf("%d",&index);
			if(value[index].next != '\0')
			value[index-1].next = &value[index+1];
			else if(value[index].next == '\0')
			value[index-1].next = '\0';
			break;
			default : printf("�ٽ� �Է��ϼ���\n"); break; 
		}
		system("pause");
		system("cls");	
	}
	
}
