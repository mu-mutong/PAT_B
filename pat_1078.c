/*

1078. �ַ���ѹ�����ѹ (20)
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
�ı�ѹ���кܶ��ַ�������������ֻ������򵥵�һ�֣�
������ͬ�ַ���ɵ�һ��������Ƭ��������ַ���Ƭ���к�������ַ���
��������ʾ������ ccccc ���� 5c ����ʾ������ַ�û���ظ���
��ԭ����������� aba ѹ������Ȼ�� aba�� 
��ѹ�������Ƿ������������� 5c �����ı�ʾ�ָ�Ϊ ccccc�� 
������Ҫ�����ѹ�����ѹ��Ҫ�󣬶Ը����ַ������д���
�������Ǽ򵥵ؼ���ԭʼ�ַ�������ȫ��Ӣ����ĸ�Ϳո���ɵķǿ��ַ���

 
�����ʽ�� 
�����һ�и���һ���ַ�������� C �ͱ�ʾ������ַ�����Ҫ��ѹ����
����� D �ͱ�ʾ������ַ�����Ҫ����ѹ���ڶ��и�����Ҫ��ѹ����
��ѹ�Ĳ�����1000���ַ����ַ������Իس���β��
��Ŀ��֤�ַ��ظ����������ͷ�Χ�ڣ�������ļ�������1MB�� 
�����ʽ�� 
����Ҫ��ѹ�����ѹ�ַ���������һ������������ 
�������� 1��
C
TTTTThhiiiis isssss a   tesssst CAaaa as
������� 1��
5T2h4is i5s a3 te4st CA3a as
�������� 2��
D
5T2h4is i5s a3 te4st CA3a as10Z
������� 2��
TTTTThhiiiis isssss a   tesssst CAaaa asZZZZZZZZZZ

*/


#include<stdio.h>
#include<string.h>
int main(){
	char a;
	char s[1002];
	
	scanf("%c",&a);
	getchar();
	gets(s);
	int length=strlen(s),i=0;
	if(a=='C'){
		int num=1,j=0;
		for(i=0;i<length;i++){
			for(j=i+1;j<length;j++){
				if(s[j]==s[i]){
					num++;
				}else{
					break;
				}
			}
			if(num>1){
				printf("%d",num);
			}
			printf("%c",s[i]);
			num=1;
			i=j-1;
		}
	
	}else{
		int n=0,j=0;
		for(i=0;i<length;i++){
			if(s[i]>='0'&&s[i]<='9'){
				n=n*10+(s[i]-'0');
			}else{
				if(n){
					for(j=0;j<n;j++){
						printf("%c",s[i]);
					}
					n=0;
				}else{
					printf("%c",s[i]);
				}
			}
		}
	}
	return 0;
}
