/*
1054. ��ƽ��ֵ (20)
����Ļ���Ҫ��ǳ��򵥣�����N��ʵ�����������ǵ�ƽ��ֵ�������ӵ�����Щ�������ݿ����ǷǷ��ġ�һ�����Ϸ�����������[-1000��1000]�����ڵ�ʵ����������ྫȷ��С�����2λ���������ƽ��ֵ��ʱ�򣬲��ܰ���Щ�Ƿ������������ڡ�
�����ʽ�� 
�����һ�и���������N��<=100�������һ�и���N��ʵ�������ּ���һ���ո�ָ��� 
�����ʽ�� 
��ÿ���Ƿ����룬��һ���������ERROR: X is not a legal number��������X�����롣�����һ��������������The average of K numbers is Y��������K�ǺϷ�����ĸ�����Y�����ǵ�ƽ��ֵ����ȷ��С�����2λ�����ƽ��ֵ�޷����㣬���á�Undefined���滻Y�����KΪ1���������The average of 1 number is Y���� 
��������1��
7
5a -3.200 aaa 9999 .2.3.4 7.123 2.35
�������1��
ERROR: aaa is not a legal number
ERROR: 9999 is not a legal number
ERROR: 2.3.4 is not a legal number
ERROR: 7.123 is not a legal number
The average of 3 numbers is 1.38
��������2��
2
aaa -9999
�������2��
ERROR: aaa is not a legal number
ERROR: -9999 is not a legal number
The average of 0 numbers is Undefined
*/
int jude(char s1[],float *sum){
	int i=0;
	float a=0,b=0,n=1;
	int flag=0;
	int num_point=0;
	*sum=0;
	if(s1[0]=='.'){
		return 0;
	}
	if(s1[0]=='-'){
		i++;
	}
	while(s1[i]){
		if(s1[i]>='0'&&s1[i]<='9'){
			if(num_point==0){
				a=a*10+s1[i]-'0';
			}
			else if(num_point==1){
				flag++;
				if(flag>2){
					return 0;
				}
				n/=10;
				b+=((s1[i]-'0')*n);
			}
		}
		else if(s1[i]=='.'){
			num_point++;
			if(num_point>1){
				return 0;
			}
		}
		else{
			return 0;
		}
		i++;
	}
	*sum=a+b;
	if(s1[0]=='-'){
		*sum=(*sum)*-1;
	}
	return 1;
}
#include<stdio.h>
#include<math.h>
int main(){
	char s1[100000];
	int N=0,i=0,num=0,flag=0;
	float sum=0;
	float all=0;
	scanf("%d",&N);
	while(N--){
		scanf("%s",&s1);
 		if(jude(s1,&sum)==1){
			if(sum>=-1000&&sum<=1000){
				num++;
				all+=sum;
			}
			else{
				printf("ERROR: %s is not a legal number\n",s1);
			}
		}
		else{
			printf("ERROR: %s is not a legal number\n",s1);
		}
	}
	if(num==0){
		printf("The average of 0 numbers is Undefined\n");
	}
	else if(num==1){
		printf("The average of 1 number is %0.2f\n",all);
	}
	else {
		printf("The average of %d numbers is %0.2f\n",num,all/num);
	}
	return 0;
}
