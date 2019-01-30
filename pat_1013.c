/*1013. 数素数 (20)

令Pi表示第i个素数。现任给两个正整数M <= N <= 104，
请输出PM到PN的所有素数。
输入格式： 
输入在一行中给出M和N，其间以空格分隔。
输出格式： 
输出从PM到PN的所有素数，每10个数字占1行，
其间以空格分隔，但行末不得有多余空格。
输入样例：
5 27
输出样例：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103*/
#include<stdio.h>
int prime(int n){
	int i=1,j=2;
	if(n==2){
		return n;
	}
	for(i;i*i<=n;i++);
	for(j=2;j<=i;j++){
		if(n%j==0){
			break;
		}
	}
	if(j-1==i){
		return n;
	}
	else {
		return 0;
	}
}
int main(){
	int m,n,i=2,num=0,flag=1;
	scanf("%d %d",&m,&n);
	while(i){
		if(prime(i)){
			
			num++;
		}
		if(num>=m&&num<=n&&prime(i)){
			printf("%d",prime(i));
			if(flag<10&&num!=n){
				printf(" ");
				flag++;
			}
			else{
				printf("\n");
				flag=1;
			}
		}
		if(num>n){
			break;
		}
		i++;
	}
	return 0;
}
