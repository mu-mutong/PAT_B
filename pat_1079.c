/*

1079. 延迟的回文数 (20)

给定一个 k+1 位的正整数 N，写成
...a1a0 的形式，
其中对所有 i 有 0 <= ai < 10 且 ak > 0。N 被称为一个回文数，
当且仅当对所有 i 有 ai = ak-i。零也被定义为一个回文数。 
非回文数也可以通过一系列操作变出回文数。首先将该数字逆转，
再将逆转数与该数相加，如果和还不是一个回文数，
就重复这个逆转再相加的操作，直到一个回文数出现。
如果一个非回文数可以变出回文数，就称这个数为延迟的回文数。
（定义翻译自 https://en.wikipedia.org/wiki/Palindromic_number） 
给定任意一个正整数，本题要求你找到其变出的那个回文数。 
输入格式： 
输入在一行中给出一个不超过1000位的正整数。 
输出格式： 
对给定的整数，一行一行输出其变出回文数的过程。每行格式如下 
A + B = C
其中A是原始的数字，B是A的逆转数，C是它们的和。
A从输入的整数开始。重复操作直到C在10步以内变成回文数，
这时在一行中输出“C is a palindromic number.”；
或者如果10步都没能得到回文数，
最后就在一行中输出“Not found in 10 iterations.”。 
输入样例 1：
97152
输出样例 1：
97152 + 25179 = 122331
122331 + 133221 = 255552
255552 is a palindromic number.
输入样例 2：
196
输出样例 2：
196 + 691 = 887
887 + 788 = 1675
1675 + 5761 = 7436
7436 + 6347 = 13783
13783 + 38731 = 52514
52514 + 41525 = 94039
94039 + 93049 = 187088
187088 + 880781 = 1067869
1067869 + 9687601 = 10755470
10755470 + 07455701 = 18211171
Not found in 10 iterations.

*/
#include<stdio.h>
#include<string.h>
int leng(int a[]);
void sum(int a[],int a_length,int b[],int c[]);
int judge(int a[],int length); 
void zhuan(int a[],int b[],int c[],int length);
int main(){
	char s1[]={" is a palindromic number.\0"};
	char s2[]={"Not found in 10 iterations.\0"};
	int a[1010],b[1010],c[1010];
	char num[1010];
	int i=0,n=0,m=0,count=0,j=0;
	int a_length=0,c_length=0;
	for(i=0;i<1010;i++){
		a[i]=0;
		b[i]=0;
		c[i]=0;
	}
	i=0;
	scanf("%s",&num);

	while(num[n]!='\0'){
		n++;
	}
	n=n-1;
	while(n>=0){
		a[i++]=num[n]-'0';
		n--;
	}
	a_length=i;

	if(judge(a,i)==1){
		for(j=0;j<i;j++){
			printf("%d",a[j]);
		}
		printf("%s",s1);
	}else{
		for(i=0;i<a_length;i++){
			b[a_length-i-1]=a[i];
		}
		while(count<10){
			sum(a,a_length,b,c);
			for(i=0;i<a_length;i++){
				printf("%d",b[i]);
			}
			printf(" + ");
			for(i=0;i<a_length;i++){
				printf("%d",a[i]);
			}
			printf(" = ");
			c_length=leng(c);
			for(i=c_length-1;i>=0;i--){
				printf("%d",c[i]);
			}
			printf("\n");
			if(judge(c,c_length)==1){
				for(i=0;i<c_length;i++){
					printf("%d",c[i]);
				}
				printf("%s",s1);
				break;
			}else{
			
				count++;
				zhuan(a,b,c,c_length);
				a_length=leng(a);
			}
		}
		if(count==10){
			printf("%s",s2);
		}
	}
	return 0;
}
int leng(int a[]){
	int length=0,i=1009;
	for(i;i>=0;i--){
		if(a[i]!=0){
			return i+1;
		}
	}
	return 0;
}
int judge(int a[],int length){
	int mid=length/2;
	int i=0;
	for(i=0;i<mid;i++){
		if(a[i]!=a[length-i-1]){
			return 0;
		}
	}
	return 1;
}
void sum(int a[],int a_length,int b[],int c[]){
	int i=0,j=0;

	int n=0;
	for(i=0;i<a_length;i++){
		c[i]=a[i]+b[i];
	}
	for(i=0;i<a_length;i++){
		n=c[i];
		int a1=n%10;
		int a2=n/10;
		c[i]=a1;
		c[i+1]+=a2;
	}
}
void zhuan(int a[],int b[],int c[],int length){
	int i=0;
	for(i=0;i<length;i++){
		a[i]=b[length-i-1]=0;
		a[i]=b[length-i-1]=c[i];
		c[i]=0;
	}
}
