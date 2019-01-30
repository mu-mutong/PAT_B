/*
大侦探福尔摩斯接到一张奇怪的字条：“我们约会吧！ 
3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm”。
大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间“星期四 14:04”，
因为前面两字符串中第1对相同的大写英文字母（大小写有区分）是第4个字母'D'，
代表星期四；第2对相同的字符是'E'，那是第5个英文字母，
代表一天里的第14个钟头（于是一天的0点到23点由数字0到9、以及大写字母A到N表示）；
后面两字符串第1对相同的英文字母's'出现在第4个位置（从0开始计数）上，代表第4分钟。
现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。
输入格式： 
输入在4行中分别给出4个非空、不包含空格、且长度不超过60的字符串。 
输出格式： 
在一行中输出约会的时间，格式为“DAY HH:MM”，其中“DAY”是某星期的3字符缩写，
即MON表示星期一，TUE表示星期二，WED表示星期三，THU表示星期四，FRI表示星期五，
SAT表示星期六，SUN表示星期日。题目输入保证每个测试存在唯一解。
输入样例：
3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm
输出样例：
THU 14:04*/
#include<stdio.h>
#include<string.h>



int main(){
	char a1[60],a2[60],a3[60],a4[60];
	char *pday[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
	int pHH[15]={10,11,12,13,14,15,16,17,18,19,20,21,22,23,24}; 
	int Long1=0,Long2=0;
	int i=0,j=0,flag=0;
	gets(a1);
	gets(a2);
	gets(a3);
	gets(a4);
	Long1=strlen(a1);
	for(i=0;i<Long1;i++){
		if((a1[i]==a2[i])){
			if(a1[i]>='A'&&a1[i]<='G'){
				printf("%s ",pday[a1[i]-'A']);
				break;
			}
		}
	}
	i++;
	for(i;i<Long1;i++){
		if(a1[i]==a2[i]){
			if(a1[i]>='0'&&a1[i]<='9'){
				printf("0%d:",a1[i]-'0');
				break;
			}
			else if(a1[i]>='A'&&a1[i]<='N'){
				printf("%d:",pHH[a1[i]-'A']);
				break;
			}
			else{
				continue;
			}
		}
	}
			
	
	Long1=strlen(a3);
	
	for(i=0;i<Long1;i++){
		if(a3[i]==a4[i]){
			if((a3[i]>='A'&&a3[i]<='Z')||(a3[i]>='a')&&a3[i]<='z'){
				if(i<=9){
					printf("0%d",i);
				}
				else{
					printf("%d",i);
				}
				break;
			}
			else{
				continue;
			}
		}
	}
	return 0;
} 
