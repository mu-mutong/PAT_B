#include<stdio.h>
int main(){
	int n,num=0;
	scanf("%d",&n);
	while(1){
		if(n==1)    // ������n=1Ϊ������������ü������ֱ�����0�� 
			break;
		//ż�����	
		if(n%2==0){
			n=n/2;
			num++;
		}
		//�������	
		else if(n%2==1){
			n=(3*n+1)/2;
			num++;
		}
	} 
	printf("%d",num);
	return 0;
}
