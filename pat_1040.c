/*
1040. �м���PAT��25��
ʱ������ 
120 ms
�ڴ����� 
65536 kB
���볤������ 
8000 B
������� 
Standard 
���� 
CAO, Peng
�ַ���APPAPT�а������������ʡ�PAT�������е�һ��PAT�ǵ�2λ(P),��4λ(A),��6λ(T)���ڶ���PAT�ǵ�3λ(P),��4λ(A),��6λ(T)��
�ָ����ַ�������һ�������γɶ��ٸ�PAT��
�����ʽ�� 
����ֻ��һ�У�����һ���ַ��������Ȳ�����105��ֻ����P��A��T������ĸ�� 
�����ʽ�� 
��һ������������ַ����а������ٸ�PAT�����ڽ�����ܱȽϴ�ֻ�����1000000007ȡ�����Ľ���� 
����������
APPATPAT
���������
2
*/
#include<stdio.h>
#include<string.h>
int main(){
	char s1[100001];
	int i=0,j=0;
	int num_a=0,num_pat=0,num_t=0;
	scanf("%s",&s1);
	for(i=strlen(s1)-1;i>=0;i--){
		if(s1[i]=='T'){
			num_t++;
		}
		else if(s1[i]=='A'){
			num_a=(num_a+num_t)%1000000007;
		}
		else{
			num_pat=(num_a+num_pat)%1000000007;
		}
	}
	printf("%d",num_pat);
	return 0;
}
