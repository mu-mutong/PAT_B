/*

1069. ΢��ת���齱(20)

С��PAT�������֣�����֮���������΢��ת���齱�����ת���������а�˳��ÿ��N���˾ͷ���һ������������д���������ȷ���н������� 
�����ʽ�� 
�����һ�и�������������M��<= 1000����N��S���ֱ���ת����������С���������н�������Լ���һλ�н��ߵ���ţ���Ŵ�1��ʼ�������M�У�˳�����ת��΢�������ѵ��ǳƣ�������20���ַ����������ո�س��ķǿ��ַ������� 
ע�⣺��������ת����Σ��������н���Ρ�����������ڵ�ǰ�н�λ�õ������Ѿ��й�������������˳��ȡ��һλ�� 
�����ʽ�� 
���������˳������н�������ÿ���ǳ�ռһ�С����û�����н����������Keep going...���� 
��������1��
9 3 2
Imgonnawin!
PickMe
PickMeMeMeee
LookHere
Imgonnawin!
TryAgainAgain
TryAgainAgain
Imgonnawin!
TryAgainAgain
�������1��
PickMe
Imgonnawin!
TryAgainAgain
��������2��
2 3 5
Imgonnawin!
PickMe
�������2��
Keep going...

*/

#include<stdio.h>
#include<string.h>
int main(){
	int M,N,S;
	int i=0,j=0;
	char s[1002][23];
	int flag=0;
	scanf("%d %d %d",&M,&N,&S);
	int a[M];
	for(i=1;i<=M;i++){
		scanf("%s",&s[i]);
		a[i]=i; 
	}
	for(i=1;i<=M;i++){
		for(j=i+1;j<=M;j++){
			if(strcmp(s[i],s[j])==0){
				if(a[j]==j){
					a[j]=i;
				}
			}
		}
	}
	for(i=S;i<=M;i+=N){
		if(a[i]>0){
			printf("%s\n",s[i]);
			flag++;
			int t=a[i];
			for(j=i;j<=M;j++){
				if(a[j]==t){
					a[j]=-1;
				}
			}
		}
		else if(a[i]==-1){
			while(i<=M){
				if(a[i]>=0){
					printf("%s\n",s[i]);
					int t=a[i];
					for(j=i;j<=M;j++){
						if(a[j]==t){
						a[j]=-1;
						}
					}
					break;
				}
				i++;
			}
		}
	}
	if(!flag){
		printf("Keep going...");
	}
	return 0;
}
