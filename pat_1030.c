/*
1030. ��������(25)

����һ�����������У���������p������������е����ֵ��M����Сֵ��m�����M <= m * p���������������������С� 
���ڸ�������p��һЩ���������������ѡ�񾡿��ܶ��������һ���������С�
�����ʽ�� 
�����һ�и�������������N��p������N��<= 105����������������ĸ�����p��<= 109���Ǹ����Ĳ������ڶ��и���N����������ÿ����������109�� 
�����ʽ�� 
��һ�������������ѡ����ٸ����������������һ���������С� 
����������
10 8
2 3 20 4 5 1 6 7 8 9
���������
8
#include <string.h>
#include <stdlib.h>
int s[10000],n,i;
int cmp(const void *a,const void *b)
{
return(*(int *)b-*(int *)a); ?//ʵ�ֵ��ǽ�������
}
int main()
{
// ������Ҫ��������ĸ���
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
return(*(int *)a-*(int *)b); //ʵ�ֵ�����������
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
