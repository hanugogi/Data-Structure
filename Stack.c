#include<stdio.h>
#define SIZE 10

int pop();
int popall();//���� pop��Ű�� �Լ� 
int push(int item);//push �Լ� 
int stackprint();//��ü ����Լ� 

int stack[SIZE], top = -1;//���ð� top���� 

int main(void){
	printf("���� �Է� : push\n   9999\t : pop\n   8888\t : ����\n   7777\t : ���� pop\n\n");
	while(1){
		int item; //Input��, top 
		
		printf("Input : ");
		scanf("%d",&item);
		if(item == 8888) {
			return 0;
		}//�Է� ���� 8888�ϰ�� ���� 
		else if(item == 9999){
			pop();
		}//�Է� ���� 9999�� ��� pop 
		else if(item == 7777){
			popall();
		}
		else if(item != 8888 && item != 9999 && item != 7777){
			push(item);
		} //�� �� �ƴҰ�� push 
		else{
			printf("����\n\n");
		}//Ȥ�� �� ������ ����Ͽ�
		stackprint();
		printf("\n");
	}
}
int pop(){
	if(top <= -1){
		printf("underflow\n\n");
	}
	else{
		printf("%d\n",stack[top]);
		top--;
	}
} //pop �Լ� 
int popall(){
	while(top != -1){
		pop();	
	}
 } 
int push(int item){
	if(top >= 9){
		printf("overflow\n\n");
	}
	else{
		stack[top+1] = item;
		top ++;
	}
}//push�Լ� 
int stackprint(){
	int i;
	
	printf("STACK [");
	i = 0; 
	
	while(i <= top){
		printf("%d ",stack[i]);
		i++;
	}
		printf("]\n"); 
}//���� ���� �����ִ� �Լ� 
