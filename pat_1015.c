/*
1015. �²��� (25)

�δ�ʷѧ��˾����ڡ�����ͨ��������һ�������ġ��²��ۡ���
���ǹʲŵ�ȫ��ν֮ʥ�ˣ��ŵ¼���ν֮���ˣ���ʤ��ν֮���ӣ�
��ʤ��ν֮С�ˡ���ȡ��֮����������ʥ�ˣ����Ӷ���֮��
�����С�ˣ����������ˡ��� 
�ָ���һ�������ĵ²ŷ����������˾�������۸���¼ȡ������ 
�����ʽ�� 
�����1�и���3�����������ֱ�Ϊ��N��<=105����
������������L��>=60����Ϊ¼ȡ��ͷ����ߣ�
���·ֺͲŷ־�������L�Ŀ��������ʸ񱻿���¼ȡ��
H��<100����Ϊ����¼ȡ�ߡ����·ֺͲŷ־������ڴ��ߵı�����Ϊ���ŵ�ȫ������
���࿼�����²��ִܷӸߵ������򣻲ŷֲ������·ֵ��ߵ�һ�࿼�����ڡ���ʤ�š���
Ҳ���ܷ����򣬵����ڵ�һ�࿼��֮�󣻵²ŷ־�����H��
���ǵ·ֲ����ڲŷֵĿ������ڡ��ŵ¼����������С���ʤ�š��ߣ�
���ܷ����򣬵����ڵڶ��࿼��֮�������ﵽ�����L�Ŀ���Ҳ���ܷ�����
�����ڵ����࿼��֮�� 
���N�У�ÿ�и���һλ��������Ϣ��������׼��֤�š��·֡��ŷ֣�����׼��֤��Ϊ8λ�������²ŷ�Ϊ����[0, 100]�ڵ����������ּ��Կո�ָ���

�����ʽ�� 
�����1�����ȸ����ﵽ��ͷ����ߵĿ�������M��
���M�У�ÿ�а��������ʽ���һλ��������Ϣ��
������������˵���Ĺ���Ӹߵ������򡣵�ĳ�࿼�����ж����ܷ���ͬʱ��
����·ֽ������У����·�Ҳ���У���׼��֤�ŵ���������� 
����������
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60
���������
12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
10000002 90 60
10000014 66 60
10000008 75 79
10000001 64 90
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct student{
	int num;
	int de;
	int cai;
	int sum;
}student;

int cmp(const void *a,const void *b){
	const struct student *p = a;
	const struct student *q = b;

	if(p->sum!=q->sum){
		return (p->sum-q->sum)*-1;
	}
	else if(p->de!=q->de){
		return(p->de-q->de)*-1;
	}
	else {
		return(p->num-q->num); 
	}

	
}
void sort_stu(student stu[],int n){
	int i=0,j=0;
	qsort(stu,n,sizeof(stu[0]),cmp);
}



int main (){
	int N=0,L=0,H=0;
	int i=0,Lev1=0,Lev2=0,Lev3=0,Lev4=0,count=0;
	scanf("%d %d %d",&N,&L,&H);
	student stu,lev1[N],lev2[N],lev3[N],lev4[N];
	for(i=0;i<N;i++){
		scanf("%d %d %d",&stu.num,&stu.de,&stu.cai);
		if(stu.de>=L&&stu.cai>=L){
			count++;
			stu.sum=stu.de+stu.cai;
			if(stu.de>=H&&stu.cai>=H){
				lev1[Lev1++]=stu;
				
			}
			else if(stu.de>=H&&stu.cai<H){
				lev2[Lev2++]=stu;
				
			}
			else if(stu.de<H&&stu.cai<H&&stu.de>=stu.cai){
				lev3[Lev3++]=stu;
				
			}
			else{
				lev4[Lev4++]=stu;
			}
		}
		else{
			continue;
		}
		
	}
	printf("%d\n",count);
	sort_stu(lev1,Lev1);
	sort_stu(lev2,Lev2);
	sort_stu(lev3,Lev3);
	sort_stu(lev4,Lev4);
	for(i=0;i<Lev1;i++){
		printf("%d %d %d\n",lev1[i].num,lev1[i].de,lev1[i].cai);
	}
	for(i=0;i<Lev2;i++){
		printf("%d %d %d\n",lev2[i].num,lev2[i].de,lev2[i].cai);
	}
	for(i=0;i<Lev3;i++){
		printf("%d %d %d\n",lev3[i].num,lev3[i].de,lev3[i].cai);
	}
	for(i=0;i<Lev4;i++){
		printf("%d %d %d\n",lev4[i].num,lev4[i].de,lev4[i].cai);
	}
	return 0;
}
