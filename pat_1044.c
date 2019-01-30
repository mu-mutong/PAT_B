/*

1044. 火星数字(20)

火星人是以13进制计数的：
地球人的0被火星人称为tret。 
地球人数字1到12的火星文分别为：
jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec。 
火星人将进位以后的12个高位数字分别称为：tam, hel, maa, huh,
 tou, kes, hei, elo, syy, lok, mer, jou。 
例如地球人的数字“29”翻译成火星文就是“hel mar”；
而火星文“elo nov”对应地球数字“115”。
为了方便交流，请你编写程序实现地球和火星数字之间的互译。 
输入格式： 
输入第一行给出一个正整数N（<100），随后N行，
每行给出一个[0, 169)区间内的数字 —— 或者是地球文，
或者是火星文。 
输出格式： 
对应输入的每一行，在一行中输出翻译后的另一种语言的数字。
输入样例：
4
29
5
elo nov
tam
输出样例：
hel mar
may
115
13
strlen(s1)<=3
*/

#include<stdio.h>
#include<string.h>
int main(){
	char a[13][5]={"tret","jan","feb","mar","apr","may","jun"
	,"jly","aug","sep","oct","nov","dec"};
	char b[12][5]={"tam","hel","maa","huh","tou","kes"
	,"hei","elo","syy","lok","mer","jou"};
	char s1[10];
	int num=0,n=0,i=0,j=0,c[3]={0};
	scanf("%d",&n);
	getchar();
	for(j=0;j<n;j++){
		gets(s1);
		for(i=0;i<3;i++){
				c[i]=0;
			}
		num=0;
		i=0;
		if(s1[0]>='0'&&s1[0]<='9'){
			while(s1[i]){
				num=s1[i]-'0'+num*10;
				i++;
			}
			i=0;
			while(num){
				c[i++]=num%13;
				num/=13;
			}
			i-=1;
			if(i>0){
				printf("%s",b[c[i]-1]);
				i--;
				if(c[i]){
					printf(" %s",a[c[i]]);
				}
			}
			else{
				if(c[i])
					printf("%s",a[c[i]]);
				else
					printf("tret");
			}
			printf("\n");
			continue;
		}
		else{
			if(strlen(s1)==4){
				printf("0");
			}
			else if(strlen(s1)==3){
				for(i=1;i<13;i++){
					if(strcmp(s1,a[i])==0){
						printf("%d",i);
					}
				}
				for(i=0;i<12;i++){
					if(strcmp(s1,b[i])==0){
						printf("%d",(i+1)*13);
					}
				}
			}
			else{
				char s2[5];
				int k=4;
				while(s1[k]){
					s2[k-4]=s1[k];
					k++;
				}
				k=k-4;
				s1[3]='\0';
				s2[k]='\0';
				for(i=0;i<12;i++){
					if(strcmp(s1,b[i])==0){
						num=(i+1)*13;
					}
				}
				for(i=0;i<13;i++){
					if(strcmp(s2,a[i])==0){
						num+=i;
					}
				}
				printf("%d",num);
			}
			printf("\n");
		}
	}
	return 0;
}
