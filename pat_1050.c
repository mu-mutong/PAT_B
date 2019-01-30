/*
1050. 螺旋矩阵(25)
时间限制 
150 ms
内存限制 
65536 kB
代码长度限制 
8000 B
判题程序 
Standard 
作者 
CHEN, Yue
本题要求将给定的N个正整数按非递增的顺序，填入“螺旋矩阵”。所谓“螺旋矩阵”，是指从左上角第1个格子开始，按顺时针螺旋方向填充。要求矩阵的规模为m行n列，满足条件：m*n等于N；m>=n；且m-n取所有可能值中的最小值。 
输入格式： 
输入在第1行中给出一个正整数N，第2行给出N个待填充的正整数。所有数字不超过104，相邻数字以空格分隔。 
输出格式： 
输出螺旋矩阵。每行n个数字，共m行。相邻数字以1个空格分隔，行末不得有多余空格。 
输入样例：
12
37 76 20 98 76 42 53 95 60 81 58 93
输出样例：
98 95 93
42 37 81
53 20 76
58 60 76


*/#include<stdio.h>
#include<math.h>
int cmp(const void *a,const void *b){
	return *(int *)a-*(int *)b; 
}
int main(){
	int N;
	int min1=0,max1=0,min2=0,max2=0;
	int i=0,j=0,flag1=0,flag2=1;
	scanf("%d",&N);
	int a[N];
	for(i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	qsort(a,N,sizeof(a[0]),cmp); 
	for(i=sqrt(N);i>=1;i--){
		if(N%i==0){
			min1=i;
			max1=N/i;
			break;
		}
	}
	int b[max1][min1];
	i=0;
	j=0;
	min2=min1;
	max2=max1;
	N=N-1;
	while(N>=0){
		for(j=flag1;j<min1&&N>=0;j++){
		//	printf("***%d***\n",N);
			b[i][j]=a[N];
		//	printf("***%d***\n",a[N]);
			N--;
		//	printf("***%d***\n",b[i][j]);
		}
		
		min1--;
		j=min1;
		for(i=flag2;i<max1&&N>=0;i++){
			b[i][j]=a[N--];
		}
	
		max1--;
		i=max1;
		for(j=min1-1;j>=flag1&&N>=0;j--){
			b[i][j]=a[N--];
		}
		//min1--;
		j=flag1;
		flag1++;
		
		for(i=max1-1;i>=flag2&&N>=0;i--){
			b[i][j]=a[N--];
		}
		//max1--;
		i=flag2;
		flag2++;
	}
	for(i=0;i<max2;i++){
		for(j=0;j<min2;j++){
			if(j!=0)
				printf(" ");
			printf("%d",b[i][j]);
			
		}
		printf("\n");
	}
	
	return 0;
}
