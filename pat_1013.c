/*1013. ������ (20)

��Pi��ʾ��i�����������θ�����������M <= N <= 104��
�����PM��PN������������
�����ʽ�� 
������һ���и���M��N������Կո�ָ���
�����ʽ�� 
�����PM��PN������������ÿ10������ռ1�У�
����Կո�ָ�������ĩ�����ж���ո�
����������
5 27
���������
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103*/
#include<stdio.h>
int prime(int n){
	int i=1,j=2;
	if(n==2){
		return n;
	}
	for(i;i*i<=n;i++);
	for(j=2;j<=i;j++){
		if(n%j==0){
			break;
		}
	}
	if(j-1==i){
		return n;
	}
	else {
		return 0;
	}
}
int main(){
	int m,n,i=2,num=0,flag=1;
	scanf("%d %d",&m,&n);
	while(i){
		if(prime(i)){
			
			num++;
		}
		if(num>=m&&num<=n&&prime(i)){
			printf("%d",prime(i));
			if(flag<10&&num!=n){
				printf(" ");
				flag++;
			}
			else{
				printf("\n");
				flag=1;
			}
		}
		if(num>n){
			break;
		}
		i++;
	}
	return 0;
}
