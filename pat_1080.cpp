/*

1080. MOOC���ճɼ� (25)

�������й���ѧMOOC��http://www.icourse163.org/��ѧϰ
�����ݽṹ���γ̵�ѧ������Ҫ���һ�źϸ�֤�飬
�������Ȼ�ò�����200�ֵ����߱����ҵ�֣�
Ȼ��������ò�����60�֣�����100����
�����ɼ��ļ��㹫ʽΪ G = (G����x 40% + G��ĩx 60%)��
��� G���� > G��ĩ���������� G ���� G��ĩ��
���� G���� �� G��ĩ �ֱ�Ϊѧ�������к���ĩ�ɼ��� 
���ڵ������ǣ�ÿ�ο��Զ�����һ�Ŷ����ĳɼ�����
����������д���򣬰Ѳ�ͬ�ĳɼ�����Ϊһ�š� 
�����ʽ�� 
�����ڵ�һ�и���3��������
�ֱ��� P���������߱����ҵ��ѧ��������
M���μ������п��Ե�ѧ��������N���μ�����ĩ���Ե�ѧ��������
ÿ������������10000�� 
���������������롣
��һ����� P �����߱�̳ɼ� G��̣�
�ڶ������ M �����п��Գɼ� G���У�
��������� N ����ĩ���Գɼ� G��ĩ��
ÿ���ɼ�ռһ�У���ʽΪ��ѧ��ѧ�� ������
����ѧ��ѧ��Ϊ������20���ַ���Ӣ����ĸ�����֣�
�����ǷǸ�����������ܷ����Ϊ900�֣����к���ĩ����߷�Ϊ100�֣���
 
�����ʽ�� 
��ӡ����úϸ�֤���ѧ��������ÿ��ѧ��ռһ�У���ʽΪ�� 
ѧ��ѧ�� G��� G���� G��ĩ G 
����еĳɼ������ڣ�����ĳ��û�μ����п��ԣ���
������Ӧ��λ�������-1����
���˳��Ϊ���������������������뾫ȷ���������ݼ���
���в��У���ѧ�ŵ�������Ŀ��֤ѧ��û���ظ���
�����ٴ���1���ϸ��ѧ���� 
����������
6 6 7
01234 880
a1903 199
ydjh2 200
wehu8 300
dx86w 220
missing 400
ydhfu77 99
wehu8 55
ydjh2 60
dx86w 88
a1903 86
01234 39
ydhfu77 88
a1903 66
01234 58
wehu8 84
ydjh2 61
missing 99
dx86w 81
���������
missing 400 -1 99 99
ydjh2 200 98 82 88
dx86w 220 88 81 84
wehu8 300 55 84 84

10 0 0
a 1
f 1
d 1
c 1
e 1
g 1
i 1
b 1
h 1
j 1

*/
#include<iostream>
#include<string>
#include<map>
#include<set>

using namespace std;
struct student{
	string name;
	int score;
}; 
struct Rule{
	bool operator()(const student &s1,const student &s2){
		if(s1.score!=s2.score){
			return s1.score>s2.score;
		}else{
			return s1.name<s2.name;
		}
	}
};
student Stu;
typedef map<string,int> MP;
typedef map<string,int>::iterator IT;
typedef set<student,Rule>::iterator SE;
int main(){
	set<student,Rule> st;
	int p,m,n;
	int i=0;
	IT j;
	SE k;
	MP MP_p,MP_m,MP_n;
	cin>>p>>m>>n;
	for(i=0;i<p;i++){
		cin>>Stu.name>>Stu.score;
		MP_p.insert(make_pair(Stu.name,Stu.score));
	}
	for(i=0;i<m;i++){
		cin>>Stu.name>>Stu.score;
		MP_m.insert(make_pair(Stu.name,Stu.score));
	}
	for(i=0;i<n;i++){
		cin>>Stu.name>>Stu.score;
		MP_n.insert(make_pair(Stu.name,Stu.score));
	}
	for(j=MP_p.begin();j!=MP_p.end();j++){
		if(j->second>=200){
			IT M,N;
			student s;
			M=MP_m.find(j->first);
			N=MP_n.find(j->first);
			if(N!=MP_n.end()){
				if(M->second>N->second&&M!=MP_m.end()){
					int sum=(int)(M->second*0.4+N->second*0.6+0.5);
					s.name=j->first;
					s.score=sum;
				}else{
					s.name=j->first;
					s.score=N->second;
				}	
			}
			if(s.score>=60){
				st.insert(s);
			}
		}else{
			continue;
		}
	}
	for(k=st.begin();k!=st.end();k++){
		IT M,N;
		cout<<k->name<<" ";
		cout<<MP_p[k->name]<<" ";
		M=MP_m.find(k->name);
		if(M!=MP_m.end()){
			cout<<M->second<<" ";
		}else{
			cout<<"-1"<<" ";
		}
		cout<<MP_n[k->name]<<" ";
		cout<<k->score<<endl;
	}
	return 0;
}
