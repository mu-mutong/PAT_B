/*
1043. 输出PATest(20)

给定一个长度不超过10000的、仅由英文字母构成的字符串。
请将字符重新调整顺序，按“PATestPATest....”这样的顺序输出，
并忽略其它字符。当然，六种字符的个数不一定是一样多的，
若某种字符已经输出完，则余下的字符仍按PATest的顺序打印，
直到所有字符都被输出。
输入格式： 
输入在一行中给出一个长度不超过10000的、
仅由英文字母构成的非空字符串。 
输出格式： 
在一行中按题目要求输出排序后的字符串。题目保证输出非空。
输入样例：
redlesPayBestPATTopTeePHPereatitAPPT
输出样例：
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
