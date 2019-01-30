/*
1022. D进制的A+B (20)

输入两个非负10进制整数A和B(<=230-1)，输出A+B的D (1 < D <= 10)进制数。 
输入格式： 
输入在一行中依次给出3个整数A、B和D。 
输出格式： 
输出A+B的D进制数。 
输入样例：
123 456 8
输出样例：
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
