/*1017. A����B (20)
ʱ������ 
100 ms
�ڴ����� 
65536 kB
���볤������ 
8000 B
������� 
Standard 
���� 
CHEN, Yue
����Ҫ�����A/B������A�ǲ�����1000λ����������B��1λ������������Ҫ�������Q������R��ʹ��A = B * Q + R������
�����ʽ�� 
������1�������θ���A��B���м���1�ո�ָ��� 
�����ʽ�� 
��1�����������Q��R���м���1�ո�ָ��� 
����������
123456789050987654321 7
���������
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
