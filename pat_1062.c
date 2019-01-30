/*

1062. 最简分数(20)

一个分数一般写成两个整数相除的形式：N/M，其中M不为0。最简分数是指分子和分母没有公约数的分数表示形式。 
现给定两个不相等的正分数 N1/M1 和 N2/M2，要求你按从小到大的顺序列出它们之间分母为K的最简分数。 
输入格式： 
输入在一行中按N/M的格式给出两个正分数，随后是一个正整数分母K，其间以空格分隔。题目保证给出的所有整数都不超过1000。 
输出格式： 
在一行中按N/M的格式列出两个给定分数之间分母为K的所有最简分数，按从小到大的顺序，其间以1个空格分隔。行首尾不得有多余空格。题目保证至少有1个输出。 
输入样例：
7/18 13/20 12
输出样例：
5/12 7/12
*/
int Gcd(int a,int b){
	int k;
	while(b){
		k=a%b;
		a=b;
		b=k;
	}
	return a;
}
#include<stdio.h>
int main(){
	int a1=0,a2=0,b1=0,b2=0,i=1,min=1,max=1,flag=1;
	int k=0;
	char ch;
	scanf("%d%c%d",&a1,&ch,&a2);
	scanf("%d%c%d",&b1,&ch,&b2);
	scanf("%d",&k);
	while(1){
		if(min*a2>a1*k){
			break;
		}
		min++;
	}
	while(1){
		if(max*b2>=b1*k){
			max--;
			break;
		}
		max++;
	}
	if(min>max){
		int t=min;
		min=max;
		max=t;
	}
	for(i=min;i<=max;i++){
		if(Gcd(i,k)==1){
			if(flag!=1){
				printf(" %d%c%d",i,ch,k);
			}
			else{
				printf("%d%c%d",i,ch,k);
				flag++;
			}
		}
	}
	return 0;
}
