/*
1042. 字符统计(20)

请编写程序，找出一段给定文字中出现最频繁的那个英文字母。
输入格式： 
输入在一行中给出一个长度不超过1000的字符串。
字符串由ASCII码表中任意可见字符及空格组成，
至少包含1个英文字母，以回车结束（回车不算在内）。 
输出格式： 
在一行中输出出现频率最高的那个英文字母及其出现次数，
其间以空格分隔。如果有并列，则输出按字母序最小的那个字母。
统计时不区分大小写，输出小写字母。
输入样例：
This is a simple TEST.  
There ARE numbers and other symbols 1&2&3...........
输出样例：
e 7

*/
#include<stdio.h>
int main(){
	char ch='\0';
	int a[26]={0},i=0,j=0;
	while(1){
		scanf("%c",&ch);
		if(ch=='\n'){
			break;
		}
		else if(ch>='a'&&ch<='z'){
			a[ch-'a']++;
		}
		else if(ch>='A'&&ch<='Z'){
			a[ch-'A']++;
		}
		else{
			continue;
		}
	}
	for(i=0;i<26;i++){
		if(a[i]>a[j]){
			j=i;
		}
	}
	printf("%c %d",j+'a',a[j]);
	return 0;
}
