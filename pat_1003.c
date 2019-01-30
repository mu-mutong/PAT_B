#include<stdio.h>
#include<string.h>
int main(){
	int n=0;
	char a[100],b[100];
	int Long=0,num_right=0,num_left=0,num_middle=0,t=0;
	int i=0,k=0;
	scanf("%d",&n);
	// 记录每组数据是否符合要求 
	int c[n];
	for(i=0;i<n;i++){
		c[i]=1;
	}
	i=0;
	while(n){
		scanf("%s",a);
		Long=strlen(a);
		num_right=0,num_left=0,num_middle=0;
		// 计数P左边有多少个A 
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
			// 判断P和T之间有多少个A 
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
		// 如果多余一个T，即不符合题意，c[k]为0 
		if(t!=1){
			c[k]=0;
		}
		if(c[k]){
			// 判断T右边有多少个A 
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
		// 如果中间的A的个数为0，即使满足判断条件，也不符合题意，故c[k]为0 
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
