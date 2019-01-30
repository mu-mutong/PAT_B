/*'

1035. 插入与归并(25)

根据维基百科的定义：
插入排序是迭代算法，逐一获得输入数据，逐步产生有序的输出序列。每步迭代中，算法从输入序列中取出一元素，将之插入有序序列中正确的位置。如此迭代直到全部元素有序。
归并排序进行如下迭代操作：首先将原始序列看成N个只包含1个元素的有序子序列，然后每次迭代归并两个相邻的有序子序列，直到最后只剩下1个有序的序列。
现给定原始序列和由某排序算法产生的中间序列，请你判断该算法究竟是哪种排序算法？
输入格式： 
输入在第一行给出正整数N (<=100)；随后一行给出原始序列的N个整数；最后一行给出由某排序算法产生的中间序列。这里假设排序的目标序列是升序。数字间以空格分隔。 
输出格式： 
首先在第1行中输出“Insertion Sort”表示插入排序、或“Merge Sort”表示归并排序；然后在第2行中输出用该排序算法再迭代一轮的结果序列。题目保证每组测试的结果是唯一的。数字间以空格分隔，且行末不得有多余空格。 

输入样例1：
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
输出样例1：
Insertion Sort
1 2 3 5 7 8 9 4 6 0
输入样例2：
10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
输出样例2：
Merge Sort
1 2 3 8 4 5 7 9 0 6
*/

#include<stdio.h>
int cmp(const void *a,const void *b)
{
return(*(int *)a-*(int *)b); //实现的是升序排序
}
void sort(int min,int max,int a[]){
	int i=min;
	int j=0;
	for(i=min;i<max;i++){
		for(j=i+1;j<max;j++){
			if(a[j]<a[i]){
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int i=0,j=0,a[n],b[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
		
	}
	for(i=0;b[i]<=b[i+1]&&i<n-1;i++);
	for(j=i+1;b[j]==a[j]&&j<n;j++);
	if(j==n){
		printf("Insertion Sort\n");
		qsort(a,i+2,sizeof(a[0]),cmp);
	}
	else{
		printf("Merge Sort\n");
		int k=1,flag=1;
		while(flag){
			flag=0;
			for(i=0;i<n;i++){
				if(a[i]!=b[i]){
					flag=1;
				}	
			}
			k*=2;
			for(i=0;i<n/k;i++){
				sort(i*k,(i+1)*k,a);
			}
			sort(n/k*k,n,a);
		}
	}
	for(i=0;i<n;i++){
		if(i!=0){
			printf(" ");
		}
		printf("%d",a[i]);
	}
	return 0;
}
