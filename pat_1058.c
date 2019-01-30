/*
1058. 选择题(20)

批改多选题是比较麻烦的事情，
本题就请你写个程序帮助老师批改多选题，
并且指出哪道题错的人最多。 
输入格式： 
输入在第一行给出两个正整数N（<=1000）和M（<=100），
分别是学生人数和多选题的个数。随后M行，
每行顺次给出一道题的满分值（不超过5的正整数）、
选项个数（不少于2且不超过5的正整数）、
正确选项个数（不超过选项个数的正整数）、所有正确选项。
注意每题的选项从小写英文字母a开始顺次排列。
各项间以1个空格分隔。最后N行，
每行给出一个学生的答题情况，其每题答案格式为“
(选中的选项个数 选项1 ……)”，按题目顺序给出。
注意：题目保证学生的答题情况是合法的，
即不存在选中的选项数超过实际选项数的情况。 
输出格式： 
按照输入的顺序给出每个学生的得分，每个分数占一行。
注意判题时只有选择全部正确才能得到该题的分数。
最后一行输出错得最多的题目的错误次数和编号
（题目按照输入的顺序从1开始编号）。
如果有并列，则按编号递增顺序输出。
数字间用空格分隔，行首尾不得有多余空格。
如果所有题目都没有人错，
则在最后一行输出“Too simple”。 
输入样例：
3 4 
3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e
(2 b c) (2 b d) (2 a c) (4 a b c e)
(2 a d) (1 e) (2 b e) (3 a b d )
(1 a) (1 a) (2 d e) (2 a b)
输出样例：
3
6
5
2 2 3 4

*/
#include<stdio.h>
int main(){
	int N=0,M=0,i=0,j=0,num=0,max=0;
	char s1;
	scanf("%d %d",&N,&M);
	int Score[N],Max[M];
	int ans[M][8];
	for(i=0;i<N;i++){
		Score[i]=0;
	} 
	for(i=0;i<M;i++){
		Max[i]=0;
	}
	for(i=0;i<M;i++){
		for(j=0;j<8;j++){
			ans[i][j]=0;
		}
	}
	
	for(i=0;i<M;i++){
		scanf("%d %d %d",&ans[i][5],&ans[i][6],&ans[i][7]);
		getchar();
		for(j=0;j<ans[i][7];j++){
			char t;
			scanf("%c",&t);
			getchar();
			ans[i][t-'a']++; 
		}
	}
	 
	for(i=0;i<N;i++){
		j=0;
		while(1){
			s1=getchar();
			if(s1=='\n'){
				j=0;
				break;
			}
			if(s1==' '){
				continue;
			}
			if(s1==')'){
				if(num==0){
					Score[i]+=ans[j][5];
				//	printf("%d***%d\n",i,j);
				}
				else{
					Max[j]++;
					if(Max[j]>max){
						max=Max[j];
					}
				}
				j++;
				num=0;
				continue;
			}
			if(s1>='0'&&s1<='9'){
				num=ans[j][7];
				if(s1-'0'>num){
					num=s1-'0';
				}
				continue;
			}
			if(s1>='a'&&s1<='e'){
				if(ans[j][s1-'a']){
					num--;
				}
			}
		}
	}
	for(i=0;i<N;i++){
		printf("%d\n",Score[i]);
	}
	if(!max){
		printf("Too simple");
	}
	else{
		printf("%d",max);
		for(i=0;i<M;i++){
			if(Max[i]==max){
				printf(" %d",i+1);
			}
		}
	}
	return 0;
} 
