/*
1048. 数字加密(20)

本题要求实现一种数字加密方法。
首先固定一个加密用正整数A，对任一正整数B，
将其每1位数字与A的对应位置上的数字进行以下运算：
对奇数位，对应位的数字相加后对13取余——
这里用J代表10、Q代表11、K代表12；对偶数位，
用B的数字减去A的数字，若结果为负数，则再加10。
这里令个位为第1位。
输入格式： 
输入在一行中依次给出A和B，均为不超过100位的正整数，
其间以空格分隔。 
输出格式： 
在一行中输出加密后的结果。 
输入样例：
1234567 368782971
输出样例：
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


