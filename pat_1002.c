#include<stdio.h>
#include<string.h>
int main(){
	char a[100];
	int num=0,b[10],i=0;
	scanf("%s",a);
	// 将a作为一个字符串读入，保证大整数的输入正确 
	while(a[i]){
	// 化为int型进行加法 
		num+=a[i]-'0';
		i++;
	}
	i=0;
	// 再把求和结果每位分解出来 
	while(num){
		b[i]=num%10;
		num=num/10;
		i++;
	}
	while(i){
		i--;
	// 根据题目要求，输出每一位拼音 
		switch(b[i]){
			case 1:
				printf("yi");
				break;
			case 2:
				printf("er");
				break;
			case 3:
				printf("san");
				break;
			case 4:
				printf("si");
				break;
			case 5:
				printf("wu");
				break;
			case 6:
				printf("liu");
				break;
			case 7:
				printf("qi");
				break;
			case 8:
				printf("ba");
				break;
			case 9:
				printf("jiu");
				break;
			case 0:
				printf("ling");
				break;
		}
		if(i>0){
			printf(" ");
		}
		else{
			printf("\n");
		}
	}
	return 0;
} 
