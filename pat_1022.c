/*
1022. D���Ƶ�A+B (20)

���������Ǹ�10��������A��B(<=230-1)�����A+B��D (1 < D <= 10)�������� 
�����ʽ�� 
������һ�������θ���3������A��B��D�� 
�����ʽ�� 
���A+B��D�������� 
����������
123 456 8
���������
1103*/
#include<stdio.h>
int main(){
	int A=0,B=0,D=0;
	int num=0,a[32],i=0;
	scanf("%d %d %d",&A,&B,&D);
	num=A+B;
	
	while(num){
		a[i++]=num%D;
		num=(num-(num%D))/D;
	}
	i--;
	if(num==0&&i<0){
		printf("%d",0);
	}
	while(i>=0){
		printf("%d",a[i]);
		i--;
	}
	return 0;
}
