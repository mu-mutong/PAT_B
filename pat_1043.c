/*
1043. ���PATest(20)

����һ�����Ȳ�����10000�ġ�����Ӣ����ĸ���ɵ��ַ�����
�뽫�ַ����µ���˳�򣬰���PATestPATest....��������˳�������
�����������ַ�����Ȼ�������ַ��ĸ�����һ����һ����ģ�
��ĳ���ַ��Ѿ�����꣬�����µ��ַ��԰�PATest��˳���ӡ��
ֱ�������ַ����������
�����ʽ�� 
������һ���и���һ�����Ȳ�����10000�ġ�
����Ӣ����ĸ���ɵķǿ��ַ����� 
�����ʽ�� 
��һ���а���ĿҪ������������ַ�������Ŀ��֤����ǿա�
����������
redlesPayBestPATTopTeePHPereatitAPPT
���������
PATestPATestPTetPTePePee


*/
#include<stdio.h>
int main(){
	char ch;
	int a[13]={0},i=0;
	while(1){
		scanf("%c",&ch);
		if(ch=='\n'){
			break;
		}
		else {
			switch(ch){
				case 'P' :a[0]++;
						a[6]='P';
						break;
				case 'A' :a[1]++;
						a[7]='A';
						break;
				case 'T' :a[2]++;
						a[8]='T';
						break;
				case 'e' :a[3]++;
						a[9]='e'; 
						break;
				case 's' :a[4]++;
						a[10]='s';
						break;
				case 't' :a[5]++;
						a[11]='t';
						break;
				default :
					break;
			}
		}
	}
	for(i=0;i<6;i++){
		if(a[i]>a[12]){
			a[12]=a[i];
		}
	}
	while(1){
		if(a[12]==0){
			break;
		}
		for(i=0;i<6;i++){
			if(a[i]>0){
				printf("%c",a[i+6]);
				a[i]--;
			}
		}
		a[12]--;
		if(a[12]==0){
			break;
		}
	}
	return 0;
}
