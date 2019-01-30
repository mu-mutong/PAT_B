/*

1079. �ӳٵĻ����� (20)

����һ�� k+1 λ�������� N��д��
...a1a0 ����ʽ��
���ж����� i �� 0 <= ai < 10 �� ak > 0��N ����Ϊһ����������
���ҽ��������� i �� ai = ak-i����Ҳ������Ϊһ���������� 
�ǻ�����Ҳ����ͨ��һϵ�в�����������������Ƚ���������ת��
�ٽ���ת���������ӣ�����ͻ�����һ����������
���ظ������ת����ӵĲ�����ֱ��һ�����������֡�
���һ���ǻ��������Ա�����������ͳ������Ϊ�ӳٵĻ�������
�����巭���� https://en.wikipedia.org/wiki/Palindromic_number�� 
��������һ��������������Ҫ�����ҵ��������Ǹ��������� 
�����ʽ�� 
������һ���и���һ��������1000λ���������� 
�����ʽ�� 
�Ը�����������һ��һ����������������Ĺ��̡�ÿ�и�ʽ���� 
A + B = C
����A��ԭʼ�����֣�B��A����ת����C�����ǵĺ͡�
A�������������ʼ���ظ�����ֱ��C��10�����ڱ�ɻ�������
��ʱ��һ���������C is a palindromic number.����
�������10����û�ܵõ���������
������һ���������Not found in 10 iterations.���� 
�������� 1��
97152
������� 1��
97152 + 25179 = 122331
122331 + 133221 = 255552
255552 is a palindromic number.
�������� 2��
196
������� 2��
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
