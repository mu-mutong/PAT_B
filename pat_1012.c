/*1012. 数字分类 (20)
给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：
A1 = 能被5整除的数字中所有偶数的和； 
A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...； 
A3 = 被5除后余2的数字的个数； 
A4 = 被5除后余3的数字的平均数，精确到小数点后1位； 
A5 = 被5除后余4的数字中最大数字。 
输入格式： 
每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，
随后给出N个不超过1000的待分类的正整数。数字间以空格分隔。
输出格式： 
对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。
数字间以空格分隔，但行末不得有多余空格。
若其中某一类数字不存在，则在相应位置输出“N”。
输入样例1：
13 1 2 3 4 5 6 7 8 9 10 20 16 18
输出样例1：
30 11 2 9.7 9
输入样例2：
8 1 2 4 5 6 7 9 16
输出样例2：
N 11 2 N 9*/
#include<stdio.h>
int main(){
	int n=0,i=0,flag=1,a1=0,flag1=0,flag2=0,a2=0,a3=0,a4=0,num=0,a5=0;
	char ch;
	scanf("%d",&n);
	int a[n],b[n];
	while(ch!='\n'){
		scanf("%d",&a[i]);
		scanf("%c",&ch); 
		i++;
	}
	for(i=0;i<n;i++){
		int t=a[i]%5;
		switch (t){
			case 0:
				if(a[i]%2==0){
					a1+=a[i];
					flag1++;
				}
			
				break;
			case 1:
				if(flag%2==1){
					a2=a2+a[i];
				}
				else{
					a2=a2-a[i];
				}
				flag++;
				break;
			case 2:
				a3++;
				break;
			case 3:
				a4+=a[i];
				num++;
				break;
			case 4:
				if(a[i]>a5){
					a5=a[i];
				}
				break;
		}
	}
	if(flag1){
		printf("%d",a1);
	}
	else{
		printf("N");
	}
	if(flag>1){
		printf(" %d",a2);
	}
	else{
		printf(" N");
	}
	if(a3){
		printf(" %d",a3);
	}
	else{
		printf(" N");
	}
	if(a4){
		float x=a4*1.0/num;
		printf(" %.1f",x);
	}
	else{
		printf(" N");
	}
	if(a5){
		printf(" %d",a5);
	}
	else{
		printf(" N");
	}
	return 0;
}
