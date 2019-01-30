/*
1034. 有理数四则运算(20)

本题要求编写程序，计算2个有理数的和、差、积、商。
输入格式： 
输入在一行中按照“a1/b1 a2/b2”
的格式给出两个分数形式的有理数，
其中分子和分母全是整型范围内的整数，
负号只可能出现在分子前，分母不为0。 
输出格式： 
分别在4行中按照“有理数1 运算符 有理数2 = 结果”
的格式顺序输出2个有理数的和、差、积、商。
注意输出的每个有理数必须是该有理数的最简形式“k a/b”，
其中k是整数部分，a/b是最简分数部分；若为负数，则须加括号；
若除法分母为0，则输出“Inf”。
题目保证正确的输出中没有超过整型范围的整数。 
输入样例1：
2/3 -4/2
输出样例1：
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
输入样例2：
5/3 0/6
输出样例2：
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf

abs();
*/
#include<stdio.h>
#include<math.h>
long long int ojld(long long int a,long long int b);
void add(long long int a,long long int b,long long int c,long long int d);
void sub(long long int a,long long int b,long long int c,long long int d);
void mul(long long int a,long long int b,long long int c,long long int d);
void div(long long int a,long long int b,long long int c,long long int d);
void Print(long long int a,long long int b);

long long int main(){
	long long int a=0,b=0,c=0,d=0;
	char ch;
	scanf("%lld%c%lld",&a,&ch,&b);
	scanf("%lld%c%lld",&c,&ch,&d);
	//printf("%lld %lld %lld %lld \n",a,b,c,d);
	add(a,b,c,d);
	sub(a,b,c,d);
	mul(a,b,c,d);
	div(a,b,c,d);
	return 0;
}
long long int ojld(long long int a,long long int b){
	long long int j=a%b;
	while(j){
		a=b;
		b=j;
		j=a%b;
	}
	return b;
} 
void Print(long long int a,long long int b){
	long long int s=0;
	if(a==0){
		printf("0");
		return ;
	}
	if(a<0){
		s=ojld(a*(-1),b);
		a=a/s;
		b=b/s;
	}
	else{
		s=ojld(a,b);
		a=a/s;
		b=b/s;
	}
	if(a>0){
		if(b==1){
			printf("%lld",a);
		}
		else{
			if(a>b){
				printf("%lld %lld/%lld",a/b,a%b,b);
			}
			else{
				printf("%lld/%lld",a,b);
			}
		}
	}
	else{
		if(b==1){
			printf("(%lld)",a);
		}
		else if((-1)*a>b){
			a*=-1;
			printf("(-%lld %lld/%lld)",a/b,a%b,b);
		}
		else{
			printf("(%lld/%lld)",a,b);
		}
	}
}

void add(long long int a,long long int b,long long int c,long long int d){
	long long int h1=0,h2=0;
	h1=a*d+b*c;
	h2=b*d;
	Print(a,b);
	printf(" + ");
	Print(c,d);
	printf(" = ");
	Print(h1,h2);
	printf("\n");
}

void sub(long long int a,long long int b,long long int c,long long int d){
	long long int h1=0,h2=0;
	h1=a*d-b*c;
	h2=b*d;
	Print(a,b);
	printf(" - ");
	Print(c,d);
	printf(" = ");
	Print(h1,h2);
	printf("\n");
	
}

void mul(long long int a,long long int b,long long int c,long long int d){
	long long int h1=0,h2=0;
	h1=a*c;
	h2=b*d;
	Print(a,b);
	printf(" * ");
	Print(c,d);
	printf(" = ");
	Print(h1,h2);
	printf("\n");
	
}


void div(long long int a,long long int b,long long int c,long long int d){
	long long int h1=0,h2=0;
	
	h1=a*d;
	h2=b*c;
	if(h2<0){
		h1*=-1;
		h2*=-1;
	}
	Print(a,b);
	printf(" / ");
	Print(c,d);
	printf(" = ");
	if(h2==0){
		printf("Inf");
	}
	else{
		Print(h1,h2);
	}
	printf("\n");
}


