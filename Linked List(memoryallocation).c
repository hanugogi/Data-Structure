#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

typedef struct list{
	char name[16];
	char PNB[14];
	int age;
	struct list* next; //LIST* next;�� �Ұ��� 
}LIST; //����ü ����

LIST head = {"\0","\0",0};
LIST* HEAD = &head; //������ ����Ʈ ������ 
LIST* TAIL;			//���Ĺ� ����Ʈ ������ 

void insertion();  //����Ʈ ���� 
void Connect(LIST* p, int index);
void print();		  		  //����Ʈ ��� 
void del_list();	 		  //����Ʈ ���� 

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
	scanf("%s",p->PNB);		//����Ʈ ����
	printf("\n");
	Connect(p,index);		//����Ʈ ����
}//����Ʈ �����Լ�

void Connect(LIST* p, int index){
	LIST* Connect = HEAD;
	if(index == 0)
	{
		TAIL->next = p;
		TAIL = p;
	}//TAIL�� �̾��ִ� ���
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
	}//��ȣ�� ������ ���
	//����Ʈ ������ �κа� ����
}//����Ʈ �����Լ�(���� �Լ��� ����)

void print(){
	LIST* PRINT = HEAD;
	if(PRINT->next == '\0')
	{
		printf("None data\n");
		main();
	}//�����Ͱ� �ϳ��� ���� ��� �������� 
	while(PRINT->next!='\0')
	{
		//printf("PRINT : %d PRINT->next : %d HEAD->next : %d\n ",PRINT,PRINT->next,HEAD->next);
		printf("Age          : %d\n",PRINT->next->age);
		printf("Name         : %s\n",PRINT->next->name);
		printf("Phone number : %s\n",PRINT->next->PNB);
		printf("\n");
		PRINT = PRINT->next;
	}//next�� 0�� �� ������ ���
			
}

void del_list( ){
	int index;
	printf("Enter the Index number to Delete : ");
	scanf("%d",&index);//������ �ε��� ��ȣ �ޱ�
	printf("\n");
	
	LIST* DEL = HEAD;
	for(index;index-1>0;index--)
	{
		DEL = DEL->next;	//������ �ε��� �ٷ� �� ����Ʈ�ּ�
	}
	if(DEL->next == '\0'){
		printf("Command Error\n");
		main();
	}//�߸� �� ��ȣ�ϰ�� �������� 
	LIST* DEL_ = DEL->next;//������ �ε��� �ּ� ����
	if(DEL->next->next != '\0')
	{
		DEL->next = DEL->next->next;
	}//������ �ε����� ����� ���
	else
	{
		DEL->next = '\0';
	}//������ �ε����� �������� ���
		
	free(DEL_);//�ε��� ����
}

