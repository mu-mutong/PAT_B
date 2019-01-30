/*
1030. 完美数列(25)

给定一个正整数数列，和正整数p，设这个数列中的最大值是M，最小值是m，如果M <= m * p，则称这个数列是完美数列。 
现在给定参数p和一些正整数，请你从中选择尽可能多的数构成一个完美数列。
输入格式： 
输入第一行给出两个正整数N和p，其中N（<= 105）是输入的正整数的个数，p（<= 109）是给定的参数。第二行给出N个正整数，每个数不超过109。 
输出格式： 
在一行中输出最多可以选择多少个数可以用它们组成一个完美数列。 
输入样例：
10 8
2 3 20 4 5 1 6 7 8 9
输出样例：
8
#include <string.h>
#include <stdlib.h>
int s[10000],n,i;
int cmp(const void *a,const void *b)
{
return(*(int *)b-*(int *)a); ?//实现的是降序排序
}
int main()
{
// 输入想要输入的数的个数
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",&s[i]);
qsort(s,n,sizeof(s[0]),cmp);
for(i=0;i<n;i++)
printf("%d ",s[i]);
return(0);
}
*/ 
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
return(*(int *)a-*(int *)b); //实现的是升序排序
}
int main(){
	int N=0;
	long long p=0;
	scanf("%d %lld",&N,&p);
	
	int s[100005],i=0,j=0,num=0;
	for(i=0;i<N;i++){
		scanf("%d",&s[i]);
		
	}
	qsort(s,N,sizeof(s[0]),cmp);
	for(i=0;i<N;i++){
		
	
		for(j;j<N;j++){
			if(s[j]>s[i]*p){
				
				if((j-i)>num){
					num=j-i;
				}
				break;
			}
		}
		if(j==N){
			break;
		}
	}
	if(N-i>num){
		num=N-i;
	}
	printf("%d",num);
	return 0;	
}
