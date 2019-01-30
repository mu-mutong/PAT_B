/*

1078. 字符串压缩与解压 (20)
时间限制 
400 ms
内存限制 
65536 kB
代码长度限制 
8000 B
判题程序 
Standard 
作者 
CHEN, Yue
文本压缩有很多种方法，这里我们只考虑最简单的一种：
把由相同字符组成的一个连续的片段用这个字符和片段中含有这个字符的
个数来表示。例如 ccccc 就用 5c 来表示。如果字符没有重复，
就原样输出。例如 aba 压缩后仍然是 aba。 
解压方法就是反过来，把形如 5c 这样的表示恢复为 ccccc。 
本题需要你根据压缩或解压的要求，对给定字符串进行处理。
这里我们简单地假设原始字符串是完全由英文字母和空格组成的非空字符串

 
输入格式： 
输入第一行给出一个字符，如果是 C 就表示下面的字符串需要被压缩；
如果是 D 就表示下面的字符串需要被解压。第二行给出需要被压缩或
解压的不超过1000个字符的字符串，以回车结尾。
题目保证字符重复个数在整型范围内，且输出文件不超过1MB。 
输出格式： 
根据要求压缩或解压字符串，并在一行中输出结果。 
输入样例 1：
C
TTTTThhiiiis isssss a   tesssst CAaaa as
输出样例 1：
5T2h4is i5s a3 te4st CA3a as
输入样例 2：
D
5T2h4is i5s a3 te4st CA3a as10Z
输出样例 2：
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
