/*

1065. ������(25)

���������������Ķ��ڵ�����ʿ��һ�ְ��ơ���������������˵Ĵ����ɶ����ҳ��䵥�Ŀ��ˣ��Ա��������ذ��� 
�����ʽ�� 
�����һ�и���һ��������N��<=50000����
����֪����/���µĶ��������N�У�
ÿ�и���һ�Է���/���¡���Ϊ���������
ÿ�˶�Ӧһ��ID�ţ�Ϊ5λ���֣���00000��99999����
ID���Կո�ָ���֮�����һ��������M��<=10000����
Ϊ�μ��ɶԵ������������һ�и�����Mλ���˵�ID��
�Կո�ָ�����Ŀ��֤�����ػ��Ų��������� 
�����ʽ�� 
���ȵ�һ������䵥���˵���������
���ڶ��а�ID����˳���г��䵥�Ŀ��ˡ�
ID����1���ո�ָ����е���β�����ж���ո� 
����������
3
11111 22222
33333 44444
00000 99999
6
00000 4444 9999 22222 11111 33333
���������
5
10000 23333 44444 55555 88888

*/ 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
return(*(long long int *)a-*(long long int *)b); //ʵ�ֵ�����������
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