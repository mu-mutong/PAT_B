/*
1048. ���ּ���(20)

����Ҫ��ʵ��һ�����ּ��ܷ�����
���ȹ̶�һ��������������A������һ������B��
����ÿ1λ������A�Ķ�Ӧλ���ϵ����ֽ����������㣺
������λ����Ӧλ��������Ӻ��13ȡ�ࡪ��
������J����10��Q����11��K����12����ż��λ��
��B�����ּ�ȥA�����֣������Ϊ���������ټ�10��
�������λΪ��1λ��
�����ʽ�� 
������һ�������θ���A��B����Ϊ������100λ����������
����Կո�ָ��� 
�����ʽ�� 
��һ����������ܺ�Ľ���� 
����������
1234567 368782971
���������
3695Q8118
*/

#include<stdio.h>
#include<string.h>
int main(){
	char s1[103],s2[103],s3[103]={'\0'};
	int len1=0,len2=0,len3=0,i=0;
	scanf("%s",s1);
	scanf("%s",s2);
	len1=strlen(s1);
	len2=strlen(s2);
	if(len1<len2){
			for(i=0;i<len2-len1;i++){
			printf("%c",s2[i]);
		}
	}
	
	for(i=len1-1;i>=0;i--){
		s3[len3++]=s1[i];
	}
	strcpy(s1,s3);
	len3=0;
	
	
	for(i=len2-1;i>=0;i--){
		s3[len3++]=s2[i];
	}
	
	if(len1>len2){
		for(i=len2;i<len1;i++){
			s3[len3++]='0';
		}
	}
	strcpy(s2,s3);
	len3=0;
	len3=len1-1;

	for(i=0;i<len1;i++){
		if(i%2!=0){
			int t=s2[i]-s1[i];
			if(t<0){
				t+=10;
				
			}
	
			s3[len3--]=t+'0';
		
		}
		else{
			int t=s2[i]+s1[i]-2*'0';
			t=t%13;
			switch(t){
				case 10:
					s3[len3--]='J';
					break;
				case 11:
					s3[len3--]='Q';
					break;
				case 12:
					s3[len3--]='K';
					break;
				default:
					s3[len3--]=t+'0';
					break;
			}
			
		}
	}
	
	 
	s3[len1]='\0';
	printf("%s",s3);
	return 0;
}


