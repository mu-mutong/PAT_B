/*
1067. ������(20)
ʱ������ 
400 ms
�ڴ����� 
65536 kB
���볤������ 
8000 B
������� 
Standard 
���� 
CHEN, Yue
������ͼ��¼ĳ��ϵͳȴ��������ʱ��ϵͳһ��ֻ�������㳢�����޶�Σ��������������ʱ���˺žͻᱻ���������������ʵ�����С���ܡ� 
�����ʽ�� 
�����ڵ�һ�и���һ�����루���Ȳ�����20�ġ��������ո�Tab���س��ķǿ��ַ�������һ��������N��<= 10�����ֱ�����ȷ�������ϵͳ�����ԵĴ��������ÿ�и���һ���Իس������ķǿ��ַ��������û�������������롣���뱣֤������һ�γ��ԡ�������һ��ֻ�е���#�ַ�ʱ�����������������һ�в����û������롣 
�����ʽ�� 
���û���ÿ�����룬�������ȷ�������ҳ��Դ���������N������һ���������Welcome in������������������Ǵ���ģ�����һ���а���ʽ�����Wrong password: �û�����Ĵ������롱���������ԴﵽN��ʱ�������һ�С�Account locked�������������� 
��������1��
Correct%pw 3
#ashahg
#
�������1��
Wrong password: correct%pw
Wrong password: Correct@PW
Wrong password: whatisthepassword!
Account locked
��������2��
cool@gplt 1
correct%pw
#
�������2��
Wrong password: coolman@gplt
Wrong password: coollady@gplt
Welcome in
*/
#include<string.h>
#include<stdio.h>
int main(){
	int m,b[10],i=0,flag=0;
	char s1[22],s2[100000],ch='\0',a[12][100000];
	scanf("%s",&s1);
	scanf("%d",&m);
	ch=getchar();
	while(strcmp(gets(s2),"#")!=0){
		if(i<m){
			strcpy(a[i++],s2);
		}
		flag++;
	}
	
	for(i=0;i<m&&i<flag;i++){
		if(strcmp(s1,a[i])==0){
			printf("Welcome in");
			break;
		}
		else{
			printf("Wrong password: %s\n",a[i]);
		}
	}
	if(i==m&&flag>= m){           //ע���˳�ʱ�ķ�Χ 
		printf("Account locked");
	}
	return 0;
}
