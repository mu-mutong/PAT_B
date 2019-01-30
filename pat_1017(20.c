/*1017. A除以B (20)
时间限制 
100 ms
内存限制 
65536 kB
代码长度限制 
8000 B
判题程序 
Standard 
作者 
CHEN, Yue
本题要求计算A/B，其中A是不超过1000位的正整数，B是1位正整数。你需要输出商数Q和余数R，使得A = B * Q + R成立。
输入格式： 
输入在1行中依次给出A和B，中间以1空格分隔。 
输出格式： 
在1行中依次输出Q和R，中间以1空格分隔。 
输入样例：
123456789050987654321 7
输出样例：
17636684150141093474 3*/
#include<stdio.h>
#include<string.h>
int main(){
	char a[1001];
	int n,i=0,length=0;
	int sum,shan,yu;
	scanf("%s",a);
	scanf("%d",&n);
	length=strlen(a);
	if(length==1){
		sum=a[0]-'0';
		printf("%d ",sum/n);
		printf("%d",sum%n);
	}
	if(length==2){
		sum=a[0]-'0';
		sum=sum*10+a[1]-'0';
		printf("%d ",sum/n);
		printf("%d",sum%n);
	}
	if(length>=3){
		sum=a[0]-'0';
		for(i=1;i<length;i++){
			sum=sum*10+a[i]-'0';
			printf("%d",sum/n);
			sum=sum%n;
		}
		printf(" %d",sum);
	}
	
	return 0;
} 
