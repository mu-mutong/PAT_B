/*
1029. �ɼ���(20)

�ɼ����ϻ��˼���������������һ�����ֵ�ʱ��
��Ӧ���ַ��Ͳ�����֡����ڸ���Ӧ�������һ�����֡�
�Լ�ʵ�ʱ���������֣������г��϶���������Щ���� 
�����ʽ�� 
������2���зֱ����Ӧ����������֡�
�Լ�ʵ�ʱ���������֡�ÿ�������ǲ�����80���ַ��Ĵ���
����ĸA-Z��������Сд��������0-9���Լ��»��ߡ�_��
������ո���ɡ���Ŀ��֤2���ַ������ǿա� 
�����ʽ�� 
���շ���˳����һ������������ļ���
����Ӣ����ĸֻ�����д��ÿ������ֻ���һ�Ρ�
��Ŀ��֤������1��������
����������
7_This_is_a_test
_hs_s_a_es
���������
7TI*/
#include<stdio.h>
#include<string.h>
int main(){
	char a[82]={'\0'},b[82]={'\0'},ch='\0';
	int i=0,j=0,lena=0,lenb=0;

	while(1){
		scanf("%c",&ch);
		if(ch=='\n'){
			break;
		}
	
		if(ch>='a'&&ch<='z'){
			ch=ch-32;
		} 
		for(i=0;i<lena;i++){
			if(ch==a[i]){
				break;
			}
		} 
		if(i==lena){
			a[lena++]=ch;
		}
		
	}
	ch='\0';
	a[lena]=ch;
	
	while(1){
		scanf("%c",&ch);
		if(ch=='\n'){
			break;
		}
		
		if(ch>='a'&&ch<='z'){
			ch=ch-32;
		} 
		for(i=0;i<lenb;i++){
			if(ch==b[i]){
				break;
			}
		} 
		if(i==lenb){
			b[lenb++]=ch;
		}
	}
	ch='\0';
	b[lenb]=ch;

	for(i=0;i<lena;i++){
		for(j=0;j<lenb;j++){
			if(a[i]==b[j]){
				break;
			}
		}
		if(j<lenb){
			continue;
		}
		else{
			if(a[i]>='a'&&a[i]<='z'){
				printf("%c",a[i]-32);
			}
			else{
				printf("%c",a[i]);
			}
		}
	}
	return 0;
}
