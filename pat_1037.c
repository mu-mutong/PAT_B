/*
1037. �ڻ����ִ�����Ǯ��20��

������ǹ����������ԣ����֪��ħ�����������Լ��Ļ���ϵͳ
 ���� ���纣����߹����ģ�
 ��ʮ�߸�������(Sickle)��һ����¡(Galleon)��
 ��ʮ�Ÿ�����(Knut)��һ�����ɣ������ס������ڣ�
 ��������Ӧ���ļ�ǮP����ʵ����ǮA��
 ���������дһ��������������Ӧ�ñ��ҵ���Ǯ�� 
�����ʽ�� 
������1���зֱ����P��A����ʽΪ��Galleon.Sickle.Knut����
�����1���ո�ָ�������Galleon��[0, 107]�����ڵ�������
Sickle��[0, 17)�����ڵ�������Knut��[0, 29)�����ڵ������� 
�����ʽ�� 
��һ������������ͬ���ĸ�ʽ�������Ӧ�ñ��ҵ���Ǯ��
�����û����Ǯ����ô�����Ӧ���Ǹ�����
��������1��
10.16.27 14.1.28
�������1��
3.2.1
��������2��
14.1.28 10.16.27
�������2��
-3.2.1
*/
#include<stdio.h>
int main(){
	int galleon_p=0,sickle_p=0,knut_p=0;
	int galleon_a=0,sickle_a=0,knut_a=0;
	char ch;
	scanf("%d%c%d%c%d",&galleon_p,&ch,&sickle_p,&ch,&knut_p);
	scanf("%d%c%d%c%d",&galleon_a,&ch,&sickle_a,&ch,&knut_a);
	
	
	if(galleon_p*10000+sickle_p*100+knut_p>
	galleon_a*10000+sickle_a*100+knut_a){
		printf("-");
		if(knut_p-knut_a>=0){
			knut_a=knut_p-knut_a;
		}	
		else{
			if(sickle_p>0){
				knut_a=29-knut_a+knut_p;
				sickle_p--;
			}
			else{
				knut_a=29-knut_a+knut_p;
				sickle_p=16; 
				galleon_p--;
			}
		}
		if(sickle_p-sickle_a>=0){
			sickle_a=sickle_p-sickle_a;
		}
		else{
			sickle_a=17-sickle_a+sickle_p;
			galleon_p--;
		}
		galleon_a=galleon_p-galleon_a;
		printf("%d%c%d%c%d",galleon_a,ch,sickle_a,ch,knut_a);
	}
	
	
	else{
		if(knut_a-knut_p>=0){
			knut_a=knut_a-knut_p;
		}	
		else{
			if(sickle_a>0){
				knut_a=29-knut_p+knut_a;
				sickle_a--;
			}
			else{
				knut_a=29-knut_p+knut_a;
				sickle_a=16; 
				galleon_a--;
			}
		}
		if(sickle_a-sickle_p>=0){
			sickle_a=sickle_a-sickle_p;
		}
		else{
			sickle_a=17-sickle_p+sickle_a;
			galleon_a--;
		}
		galleon_a=galleon_a-galleon_p;
		printf("%d%c%d%c%d",galleon_a,ch,sickle_a,ch,knut_a);
	}
	return 0;
}
