/*
1029. 旧键盘(20)

旧键盘上坏了几个键，于是在敲一段文字的时候，
对应的字符就不会出现。现在给出应该输入的一段文字、
以及实际被输入的文字，请你列出肯定坏掉的那些键。 
输入格式： 
输入在2行中分别给出应该输入的文字、
以及实际被输入的文字。每段文字是不超过80个字符的串，
由字母A-Z（包括大、小写）、数字0-9、以及下划线“_”
（代表空格）组成。题目保证2个字符串均非空。 
输出格式： 
按照发现顺序，在一行中输出坏掉的键。
其中英文字母只输出大写，每个坏键只输出一次。
题目保证至少有1个坏键。
输入样例：
7_This_is_a_test
_hs_s_a_es
输出样例：
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
