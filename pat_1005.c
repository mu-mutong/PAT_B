#include<stdio.h>
int main(){
	int n,i=0,j=0,sum=0;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		sum=a[i];
		while(sum){
			if(sum==1){
				break;
			}
			else if(sum%2==0){
				sum=sum/2;
			}
			else if(sum%2==1){
				sum=(3*sum+1)/2;
			}
		// ÿ����һ�β���������һ�����飬�ҳ������
		// �����ȵ�������0�������ظ����� 
			for(j=0;j<n;j++){
				if(a[j]==sum&&a[j]!=1){
					a[j]=0;
				}
			}
		}
	}
	// �����ս���������� 
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a[i]<a[j]){
				int t=0;
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	for(i=0;i<n;i++){
		if(a[i]){
			printf("%d",a[i]);
			if(a[i+1]&&i+1<n){
					printf(" ");
			} 
		}
		if(a[i]==0){
	 		break;
		}
	}
return 0;
}
