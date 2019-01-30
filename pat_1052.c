/*

1052. 卖个萌 (20)

萌萌哒表情符号通常由“手”、“眼”、“口”
三个主要部分组成。简单起见，
我们假设一个表情符号是按下列格式输出的：
[左手]([左眼][口][右眼])[右手]
现给出可选用的符号集合，请你按用户的要求输出表情。 
输入格式： 
输入首先在前三行顺序对应给出手、眼、口的可选符号集。
每个符号括在一对方括号[]内。
题目保证每个集合都至少有一个符号，并不超过10个符号；
每个符号包含1到4个非空字符。 
之后一行给出一个正整数K，为用户请求的个数。
随后K行，每行给出一个用户的符号选择，
顺序为左手、左眼、口、右眼、右手——
这里只给出符号在相应集合中的序号（从1开始），
数字间以空格分隔。 
输出格式： 
对每个用户请求，在一行中输出生成的表情。
若用户选择的序号不存在，
则输出“Are you kidding me? @\/@”。 
输入样例：
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
