/*1017. A除以B (20)

本题要求计算A/B，其中A是不超过1000位的正整数，B是1位正整数。
你需要输出商数Q和余数R，使得A = B * Q + R成立。
输入格式： 
输入在1行中依次给出A和B，中间以1空格分隔。 
输出格式： 
在1行中依次输出Q和R，中间以1空格分隔。 
输入样例：
123456789050987654321 7
输出样例：
17636684150141093474 3*/
#include<stdio.h>
int main(){
	double a,b,c;

	scanf("%lf",&a);
	scanf("%lf",&b);
	printf("%lf ",a/b);
/*	c=a;
	while(a){
		if(c-b*a<b&&c-b*a>=0){
			printf("%0.lf ",a);
			printf("%0.lf",c-a*b);
			break;
		}
		else if(c-b*a<b&&c-b*a<0){
			printf("0 ");
			printf("%0.lf",c);
			break;
		}
		a--;
	}
	*/
	return 0;
}
