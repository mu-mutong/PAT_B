/*
1040. 有几个PAT（25）
时间限制 
120 ms
内存限制 
65536 kB
代码长度限制 
8000 B
判题程序 
Standard 
作者 
CAO, Peng
字符串APPAPT中包含了两个单词“PAT”，其中第一个PAT是第2位(P),第4位(A),第6位(T)；第二个PAT是第3位(P),第4位(A),第6位(T)。
现给定字符串，问一共可以形成多少个PAT？
输入格式： 
输入只有一行，包含一个字符串，长度不超过105，只包含P、A、T三种字母。 
输出格式： 
在一行中输出给定字符串中包含多少个PAT。由于结果可能比较大，只输出对1000000007取余数的结果。 
输入样例：
APPATPAT
输出样例：
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
