#include <iostream>
#include <cstring>
using namespace std;

class st
{
	int no;
	char name[100];
	int h;
	int w;
	public:
		void w_no(int x){no=x;}
		int r_no(){return no;}
		void w_name(char*u){strcpy(name,u);}//�}�C�ǻ��u��H"�}"�ǻ��A�ҥH�n�[�P�P !! 
		char* r_name(){return name;}//�}�C�W�]�O�a�}��l�A�ҥH�n��}�C����}�ǥX�h 
		void w_h(int y){h=y;}
		int r_h(){return h;}
		void w_w(int z){w=z;}
		int r_w(){return w;}
		
		
};

int main()
{
	st a[5];
	for(int i=0;i<5;i++)
	{
		int x,y,z;
		char u[100];
		cout<<"��J�ǥ�"<<i+1<<"���y���B�m�W�B�������魫"<<endl;
		
		cin>>x;
		cin.get();
		cin.getline(u,80);
		cin>>y;
		cin>>z;
		
		a[i].w_no(x);
		a[i].w_h(y);
		a[i].w_w(z);
		a[i].w_name(u);
	}
	
	cout<<"�ǥ͸��:"<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<"�ǥ�"<<i+1<<": �y��:"<<a[i].r_no()<<", �m�W:"<<a[i].r_name();
		cout<< ", ����:" << a[i].r_h()<<"����";
		cout<< ", �魫:" << a[i].r_w() <<"����"<< endl;
	}
	return 0;
	
}


