/*
1018. ���Ӽ����� (20)
���Ӧ�ö����桰���Ӽ�����������Ϸ��
����ͬʱ�������ƣ�ʤ��������ͼ��ʾ��
�ָ������˵Ľ����¼����ͳ��˫����ʤ��ƽ����������
���Ҹ���˫���ֱ��ʲô���Ƶ�ʤ����� 
�����ʽ�� 
�����1�и���������N��<=105������˫������Ĵ�����
���N�У�ÿ�и���һ�ν������Ϣ�����ס���˫��ͬʱ�����ĵ����ơ�
C�������ӡ���J������������B����������
��1����ĸ����׷�����2�������ҷ����м���1���ո� 
�����ʽ�� 
�����1��2�зֱ�����ס��ҵ�ʤ��ƽ�������������ּ���1���ո�ָ���
��3�и���������ĸ���ֱ����ס��һ�ʤ�����������ƣ��м���1���ո�
����ⲻΨһ�����������ĸ����С�Ľ⡣ 

����������
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J
���������
5 3 2
2 3 5
B B*/
#include<stdio.h>
int main(){
	int i=0,n;
	char jia,yi,k;
	int win=0,lose=0,draw=0;
	int win1_C=0,win1_B=0,win1_J=0;
	int win2_C=0,win2_B=0,win2_J=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		k=getchar();
	
		scanf("%c %c",&jia,&yi);
		
		
		if(jia=='B'){
			if(yi=='B'){
				draw++;
			}
			else if(yi=='C'){
				win++;
				win1_B++;
			}
			else{
				lose++;
				win2_J++;
			} 
		}
		if(jia=='C'){
			if(yi=='B'){
				lose++;
				win2_B++;
			}
			else if(yi=='C'){
				draw++;
			}
			else{
				win++;
				win1_C++;
			} 
		}
		if(jia=='J'){
			if(yi=='B'){
				win++;
				win1_J++;
			}
			else if(yi=='C'){
				lose++;
				win2_C++; 
			}
			else{
				draw++;
			} 
		}
	} 
	if(win1_C>win1_B){
		if(win1_C>=win1_J){
			jia='C';
		}
		else{
			jia='J';
		}
	}
	else{
		if(win1_B>=win1_J){
			jia='B';
		}
		else{
			jia='J';
		}
	}
	if(win2_C>win2_B){
		if(win2_C>=win2_J){
			yi='C';
		}
		else{
			yi='J';
		}
	}
	else{
		if(win2_B>=win2_J){
			yi='B';
		}
		else{
			yi='J';
		}
	}
	printf("%d %d %d\n",win,draw,lose);
	printf("%d %d %d\n",lose,draw,win);
	printf("%c %c\n",jia,yi);
	return 0;
}
