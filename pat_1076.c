/*

8
A-T B-F C-F D-F
C-T B-F A-F D-F
A-F D-F C-F B-T
B-T A-F C-F D-F
B-F D-T A-F C-F
A-T C-F B-F D-F
D-T B-F C-F A-F
C-T A-F B-F D-F

*/

#include<stdio.h>

int main(){
	int i=0,k=0;
	scanf("%d",&i);
	int wifi[i];
	int j=4*i;
	while(j>0){
		char a[4];
		scanf("%s",&a);
		if(a[2]=='T'){
			wifi[k++]=a[0]-'A'+1;	
		}
		j--;
	}
	for(k=0;k<i;k++){
		printf("%d",wifi[k]);
	}
	return 0;
} 
