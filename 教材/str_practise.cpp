#include<iostream>
#include<string>

using namespace std;

int main(){
//�m�� 1 
//�й��դ��s1�Ms2�������h�֦r���ۦP(���]��r����׬ۦP)
	string s1="asdgtqdz";
	string s2="astggfsz";
	
	int n = s1.length();
	int k=0;
	
	for(int i=0;i<n;i++){
		if(s1[i]==s2[i]){
			k++;
		}
	}
	cout<<"s1 �M s2 �@�� "<<k<<" �U�r���ۦP�I"<<endl; 


//�m�� 2 
//��Xs3�Ĥ@�Ӧr���O�_����'I'
	string s3="hello";
	string s5="I";
	
	if(s3[0] == s5[0]) cout<<"s3[0] == I"<<endl;
	else cout<<"s3[0] != I"<<endl;

//�m�� 3
//��Xs4��h�Ӧr��
	string s4="abcdefgh";
	int m=s4.length(),h=5;
	
	cout<<s4.substr(m-h)<<endl;
} 
