/*
1050. ��������(25)
ʱ������ 
150 ms
�ڴ����� 
65536 kB
���볤������ 
8000 B
������� 
Standard 
���� 
CHEN, Yue
����Ҫ�󽫸�����N�����������ǵ�����˳�����롰�������󡱡���ν���������󡱣���ָ�����Ͻǵ�1�����ӿ�ʼ����˳ʱ������������䡣Ҫ�����Ĺ�ģΪm��n�У�����������m*n����N��m>=n����m-nȡ���п���ֵ�е���Сֵ�� 
�����ʽ�� 
�����ڵ�1���и���һ��������N����2�и���N�����������������������ֲ�����104�����������Կո�ָ��� 
�����ʽ�� 
�����������ÿ��n�����֣���m�С�����������1���ո�ָ�����ĩ�����ж���ո� 
����������
12
37 76 20 98 76 42 53 95 60 81 58 93
���������
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
