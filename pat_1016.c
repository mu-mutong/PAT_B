/*1016. 部分A+B (15)

正整数A的“DA（为1位整数）部分”定义为由A中所有DA组成的新整数PA。
例如：给定A = 3862767，DA = 6，则A的“6部分”PA是66，因为A中有2个6。
现给定A、DA、B、DB，请编写程序计算PA + PB。
输入格式： 
输入在一行中依次给出A、DA、B、DB，中间以空格分隔，其中0 < A, B < 1010。
输出格式： 
在一行中输出PA + PB的值。 
输入样例1：
3862767 6 13530293 3
输出样例1：
399
输入样例2：
3862767 1 13530293 8
输出样例2：
0*/ 
#include<stdio.h>
#include<stdlib.h>
int main(){
	char a[11],b[11];
	int i=0,da=0,db=0,pa=0,pb=0;
	scanf("%s",a);
	scanf("%d",&da);
	scanf("%s",b);
	scanf("%d",&db);
	while(a[i]){
		if(a[i]-'0'==da){
			pa=pa*10+da;
		}
		i++;
	} 
	i=0;
	while(b[i]){
		if(b[i]-'0'==db){
			pb=pb*10+db;
		}	
		i++;
	}
	printf("%d",pa+pb);
	return 0;
}
