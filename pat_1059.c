/*
1059. C���Ծ���(20)

C���Ծ������㽭��ѧ�����ѧԺ���ֵ�һ�����ֵľ�����
��Ȼ������ּ��Ϊ�˺��棬�佱����Ҳ���ƶ��úܻ����� 
0. �ھ���Ӯ��һ�ݡ����ش󽱡�
������ܾ޴��һ��ѧ���о����ļ���������
1. ����Ϊ������ѧ����Ӯ����õĽ�Ʒ ���� 
С������ż��
2. �����˽��õ��ɿ�����
�������������������Լ�һϵ�в����ߵ�ID��
��Ҫ������Щ������Ӧ�û�õĽ�Ʒ�� 
�����ʽ�� 
�����һ�и���һ��������N��<=10000����
�ǲ��������������N�и�������������
ÿ�а�����˳�����һλ�����ߵ�ID��4λ������ɣ���
����������һ��������K�Լ�K����Ҫ��ѯ��ID�� 
�����ʽ�� 
��ÿ��Ҫ��ѯ��ID����һ���������ID: ��Ʒ����
���н�Ʒ�����ǡ�Mystery Award�������ش󽱣���
�����ǡ�Minion����С���ˣ��������ǡ�Chocolate��
���ɿ��������������ID�������������
��ӡ��Are you kidding?����ˣ���أ�����
�����ID�Ѿ�����ˣ�����Ʒ�Ѿ�����ˣ���
��ӡ��ID: Checked�������ܶ�Զ�ռ���� 
����������
6
1111
6666
8888
1234
5555
0000
6
8888
0001
1111
2222
8888
0000
���������
8888: Minion
0001: Chocolate
1111: Mystery Award
2222: Are you kidding?
8888: Checked
2222: Are you kidding?


*/

#include<stdio.h>
int su(int n){
	int i=2;
	for(i;i*i<=n;i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}
int main(){
	int N,K=0,t=0,i=0;
	scanf("%d",&N);
	int Sort[10003];
	for(i=0;i<10003;i++){
		Sort[i]=-1;
	}
	for(i=0;i<N;i++){
		scanf("%d",&t);
		Sort[t]=i+1;
	}
	scanf("%d",&K);
	for(i=0;i<K;i++){
		scanf("%d",&t);
	//	printf("%04d: ",t);
		if(Sort[t]>0){
			if(Sort[t]==1){
				printf("%04d: Mystery Award\n",t);
			}
			else{
				if(su(Sort[t])==1){
					printf("%04d: Minion\n",t);
				}
				else{
					printf("%04d: Chocolate\n",t);
				}
			}
			Sort[t]=0;
		//	continue;
		}
		else if(Sort[t]==0){
			printf("%04d: Checked\n",t);
		//	continue;
		} 
		else{
			printf("%04d: Are you kidding?\n",t);
		}
	}
	return 0;
}
