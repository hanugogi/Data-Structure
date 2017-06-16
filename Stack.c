#include<stdio.h>
#define SIZE 10

int pop();
int popall();//전부 pop시키는 함수 
int push(int item);//push 함수 
int stackprint();//전체 출력함수 

int stack[SIZE], top = -1;//스택과 top선언 

int main(void){
	printf("숫자 입력 : push\n   9999\t : pop\n   8888\t : 종료\n   7777\t : 전부 pop\n\n");
	while(1){
		int item; //Input값, top 
		
		printf("Input : ");
		scanf("%d",&item);
		if(item == 8888) {
			return 0;
		}//입력 값이 8888일경우 종료 
		else if(item == 9999){
			pop();
		}//입력 값이 9999일 경우 pop 
		else if(item == 7777){
			popall();
		}
		else if(item != 8888 && item != 9999 && item != 7777){
			push(item);
		} //셋 다 아닐경우 push 
		else{
			printf("오류\n\n");
		}//혹시 모를 오류에 대비하여
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
} //pop 함수 
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
}//push함수 
int stackprint(){
	int i;
	
	printf("STACK [");
	i = 0; 
	
	while(i <= top){
		printf("%d ",stack[i]);
		i++;
	}
		printf("]\n"); 
}//현재 스택 보여주는 함수 
