/*
1075. ����Ԫ�ط���(25)

����һ�����������д��������Ԫ�ؽ��з������У�
ʹ�����и�ֵԪ�ض����ڷǸ�ֵԪ�ص�ǰ�棬
��[0, K]�����ڵ�Ԫ�ض����ڴ���K��Ԫ��ǰ�档
��ÿһ���ڲ�Ԫ�ص�˳���ǲ��ܸı�ġ�
���磺��������Ϊ 18��7��-4��0��5��-6��10��11��-2��
KΪ10�������Ӧ��Ϊ -4��-6��-2��7��0��5��10��18��11��
�����ʽ�� 
ÿ���������1������������
ÿ������������1�и�������1�����ĵ�ַ��
����ܸ�������������N (<= 105)��
�Լ�������K (<=1000)��
���ĵ�ַ��5λ�Ǹ�������NULL��ַ��-1��ʾ��
��������N�У�ÿ�и�ʽΪ��
Address Data Next
����Address�ǽ���ַ��
Data�Ǹý�㱣������ݣ�Ϊ[-105, 105]�����ڵ�������
Next����һ���ĵ�ַ����Ŀ��֤����������Ϊ�ա�
�����ʽ�� 
��ÿ������������
�������ͷ��β��˳��������ź�Ľ������
����ÿ�����ռһ�У���ʽ��������ͬ��
����������
00100 9 10
23333 -10 27777
00000 -1 99999
00100 -18 12309
68237 -6 23333
33218 -4 00000
48652 -2 -1
99999 -5 68237
27777 -11 48652
12309 -7 33218
���������
33218 -4 68237
68237 -6 48652
48652 -2 12309
12309 7 00000
00000 0 99999
99999 5 23333
23333 10 00100
00100 18 27777
27777 11 -1

*/

#include<stdio.h>
int main(){
	int a1[100000],next_add[100000],a2[100000],a3[100000];
	int first=0,N=0,K=0,i=0,flag=0;
	//int add1=-1,add2=-1,add3=-1;
	int begin=0;
	for(i=0;i<100000;i++){
		a1[i]=0;
		next_add[i]=0;
		a2[i]=0;
		a3[i]=0;
	}
	scanf("%d %d %d",&begin,&N,&K);
	for(i=0;i<N;i++){
		int key=0;
		scanf("%d",&key);
		scanf("%d %d",&a1[key],&next_add[key]);
	}
	first=begin; 
	while(first!=-1){
		if(a1[first]<0){
			if(flag==0){
				printf("%05d %d ",first,a1[first]);
				flag++;
			} 
			else{
				printf("%05d\n%05d %d ",first,first,a1[first]);
			}
		}
		first=next_add[first];
	}
	first=begin;
	while(first!=-1){
		if(a1[first]>=0&&a1[first]<=K){
			if(flag==0){
				printf("%05d %d ",first,a1[first]);
				flag++;
			} 
			else{
				printf("%05d\n%05d %d ",first,first,a1[first]);
			}
			
		}
		first=next_add[first];
	}
	first=begin;
	while(first!=-1){
		if(a1[first]>K){
			if(flag==0){
				printf("%05d %d ",first,a1[first]);
				flag++;
			} 
			else{
				printf("%05d\n%05d %d ",first,first,a1[first]);
			}
			
		}
		first=next_add[first];
	}
/*	for(i=0;i<100000&&flag<N;i++){
		/*if(a2[i]){
			if(flag==0){
				printf("%05d %d ",i,a2[i]);
				flag++;
			} 
			else if(flag<N){
				printf("%05d\n%05d %d ",i,i,a2[i]);
				flag++;
			}
		
		}
		if(a1[first]<=K){
			
			a3[first]=a1[first];
			a1[first]=0;
	}
	for(i=0;i<100000&&flag<N;i++){
		if(a3[i]){
			if(flag==0){
				printf("%05d %d ",i,a3[i]);
				flag++;
			} 
			else if(flag<N){
				printf("%05d\n%05d %d ",i,i,a3[i]);
				flag++;
			}
		
		}
	}
	for(i=0;i<100000&&flag<N;i++){
		if(a1[i]){
			if(flag==0){
				printf("%05d %d ",i,a1[i]);
				flag++;
			} 
			else if(flag<N){
				printf("%05d\n%05d %d ",i,i,a1[i]);
				flag++;
			}
		
		}
	}*/
	printf("-1");
	return 0;
}
