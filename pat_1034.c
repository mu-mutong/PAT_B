/*
1034. ��������������(20)

����Ҫ���д���򣬼���2���������ĺ͡�������̡�
�����ʽ�� 
������һ���а��ա�a1/b1 a2/b2��
�ĸ�ʽ��������������ʽ����������
���з��Ӻͷ�ĸȫ�����ͷ�Χ�ڵ�������
����ֻ���ܳ����ڷ���ǰ����ĸ��Ϊ0�� 
�����ʽ�� 
�ֱ���4���а��ա�������1 ����� ������2 = �����
�ĸ�ʽ˳�����2���������ĺ͡�������̡�
ע�������ÿ�������������Ǹ��������������ʽ��k a/b����
����k���������֣�a/b�����������֣���Ϊ��������������ţ�
��������ĸΪ0���������Inf����
��Ŀ��֤��ȷ�������û�г������ͷ�Χ�������� 
��������1��
2/3 -4/2
�������1��
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
��������2��
5/3 0/6
�������2��
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


