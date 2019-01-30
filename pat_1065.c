/*

1065. 单身狗(25)

“单身狗”是中文对于单身人士的一种爱称。本题请你从上万人的大型派对中找出落单的客人，以便给予特殊关爱。 
输入格式： 
输入第一行给出一个正整数N（<=50000），
是已知夫妻/伴侣的对数；随后N行，
每行给出一对夫妻/伴侣——为方便起见，
每人对应一个ID号，为5位数字（从00000到99999），
ID间以空格分隔；之后给出一个正整数M（<=10000），
为参加派对的总人数；随后一行给出这M位客人的ID，
以空格分隔。题目保证无人重婚或脚踩两条船。 
输出格式： 
首先第一行输出落单客人的总人数；
随后第二行按ID递增顺序列出落单的客人。
ID间用1个空格分隔，行的首尾不得有多余空格。 
输入样例：
3
11111 22222
33333 44444
00000 99999
6
00000 4444 9999 22222 11111 33333
输出样例：
5
10000 23333 44444 55555 88888

*/ 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
return(*(long long int *)a-*(long long int *)b); //实现的是升序排序
}
int main(){
	int n,hus,wif;
	int a[100000],c[100000],i=0;
	int k=0,m=1,j=0;
	scanf("%d",&n);
	for(i=0;i<100000;i++){
		a[i]=-1;
		c[i]=0;
	}
	for(i=0;i<n;i++){
		scanf("%d %d",&hus,&wif);
		a[hus]=wif;
		a[wif]=hus;
	}
	scanf("%d",&k);
    long long int b[k];
    
	for(i=0;i<k;i++){
		scanf("%lld",&b[i]);
		if(b[i]<=99999&&b[i]>=0){
		c[b[i]]++;
		} 
	}
	for(i=0;i<k;i++){
		if(b[i]>=0&&b[i]<=99999){
			if(a[b[i]]>=0&&c[a[b[i]]]){
				c[b[i]]++;
				b[i]=-1;
				continue;
			}
			else{
				j++;
			}	
		}
		else{
			j++;
		}
	}
	printf("%d\n",j);
	if(j){
		qsort(b,k,sizeof(b[0]),cmp);
		for(i=0;i<k;i++){
			if(b[i]>=0&&m<j){
				printf("%05lld ",b[i]);
				m++;
			}
			else if(b[i]>=0&&m==j){
				printf("%05lld",b[i]);
			}
		}
	}
	
	return 0;
} 
