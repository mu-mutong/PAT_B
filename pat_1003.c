#include<stdio.h>
#include<string.h>
int main(){
	int n=0;
	char a[100],b[100];
	int Long=0,num_right=0,num_left=0,num_middle=0,t=0;
	int i=0,k=0;
	scanf("%d",&n);
	// ��¼ÿ�������Ƿ����Ҫ�� 
	int c[n];
	for(i=0;i<n;i++){
		c[i]=1;
	}
	i=0;
	while(n){
		scanf("%s",a);
		Long=strlen(a);
		num_right=0,num_left=0,num_middle=0;
		// ����P����ж��ٸ�A 
		for(i=0;i<Long;i++){
			if(a[i]=='A'){
				num_right++;
			}
			else if(a[i]=='P'){
				i++;
				break;
			}
			else{
				c[k]=0;
				break;
			}
		}
		if(c[k]){
			// �ж�P��T֮���ж��ٸ�A 
			for(i;i<Long;i++){
				if(a[i]=='A'){
					num_middle++;
				}
				else if(a[i]=='T'){
					i++;
					t++;
					break;
				}
				else{
					c[k]=0;
					break;
				}
			}
		}
		// �������һ��T�������������⣬c[k]Ϊ0 
		if(t!=1){
			c[k]=0;
		}
		if(c[k]){
			// �ж�T�ұ��ж��ٸ�A 
			for(i;i<Long;i++){
				if(a[i]=='A'){
					num_left++;
				}
				else{
					c[k]=0;
					break;
				}
			}
		}
		// ����м��A�ĸ���Ϊ0����ʹ�����ж�������Ҳ���������⣬��c[k]Ϊ0 
		if(num_middle==0){
			c[k]=0;
		}
		if(num_right*num_middle!=num_left){
			c[k]=0;
		}
		k++;
		n--;
		t=0;
	}
	for(i=0;i<k;i++){
		if(c[i]){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}
