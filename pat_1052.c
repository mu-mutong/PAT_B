/*

1052. ������ (20)

�����ձ������ͨ���ɡ��֡������ۡ������ڡ�
������Ҫ������ɡ��������
���Ǽ���һ����������ǰ����и�ʽ����ģ�
[����]([����][��][����])[����]
�ָ�����ѡ�õķ��ż��ϣ����㰴�û���Ҫ��������顣 
�����ʽ�� 
����������ǰ����˳���Ӧ�����֡��ۡ��ڵĿ�ѡ���ż���
ÿ����������һ�Է�����[]�ڡ�
��Ŀ��֤ÿ�����϶�������һ�����ţ���������10�����ţ�
ÿ�����Ű���1��4���ǿ��ַ��� 
֮��һ�и���һ��������K��Ϊ�û�����ĸ�����
���K�У�ÿ�и���һ���û��ķ���ѡ��
˳��Ϊ���֡����ۡ��ڡ����ۡ����֡���
����ֻ������������Ӧ�����е���ţ���1��ʼ����
���ּ��Կո�ָ��� 
�����ʽ�� 
��ÿ���û�������һ����������ɵı��顣
���û�ѡ�����Ų����ڣ�
�������Are you kidding me? @\/@���� 
����������
[@][%][*][(][)] [#][!]
 [^][$][@][WT][EQSQ][*&][HUI][H][F][G]
[$$][^^][**][&][N]....
4
-2 2 3 4 5 
6 8 1 5 5
3 3 4 3 3
2 11 3 9 3
1 1 2 2 2
6 8 1 5 5
3 3 4 3 3
2 11 3 9 3
**/
#include<stdio.h>
#include<string.h>
int get(char a[][10]){
	int len=0,i=0,flag=0;
	char ch;
	while(1){
		ch=getchar();
		if(ch=='\n'){
			return len;
		}
		if(ch==']'){
			a[len][i++]='\0';
			len++;
			i=0;
			flag=0;
		}
		else if(ch=='['){
			flag++;
		}
		else if(ch!='['&&flag){
			a[len][i++]=ch;
		}
	}
}
int main(){
	char hand[10][10],eye[10][10],mou[10][10];
	char s1[40];
	s1[0]='\0';
	int lenh=1,lene=1,lenm=1,i=0,N=0,id=0,flag=0;
	lenh=get(hand);
	lene=get(eye);
	lenm=get(mou);
	scanf("%d",&N);
	while(N){
		for(i=0;i<5;i++){
			scanf("%d",&id);
		
			if(i==0||i==4){
				if(id<=lenh&&id>0){
					strcat(s1,hand[id-1]);
				//	printf("%s\n",hand[id-1]);
				}
				else{
					flag++;
					continue;
				}
			}else if(i==2){
				if(id<=lenm&&id>0){
					
						strcat(s1,mou[id-1]);
				}
				else{
					flag++;
				}
			}
			else {
				if(id<=lene&&id>0){
					if(i==1){
						strcat(s1,"(\0");
					}
					strcat(s1,eye[id-1]);
					if(i==3){
						strcat(s1,")\0");
					}
				}
				else{
					flag++;
				}
			}
		}
		if(!flag){
			printf("%s\n",s1);
		}
		else{
			printf("Are you kidding me? @\\/@\n");
		}
		s1[0]='\0';
		flag=0;
		N--;
	}
	
	return 0;
}
