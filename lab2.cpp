#include <iostream>
#include<fstream>
#include<sstream>
#include<string.h>
#define MAX 100
using namespace std;

class student{
    string usn,name,sem,branch,buffer;
public:
        void read();
        void write();
        void pack();
        int search(string);
        //int dele(string);
        void unpack();
        void modify(string);
};
student s;
void student::read()
{
    cout<<"Enter your usn"<<endl;
    cin>>usn;
    cout<<"Enter your name"<<endl;
    cin>>name;
    cout<<"Enter the branch"<<endl;
    cin>>branch;
    cout<<"Enter the sem"<<endl;
    cin>>sem;
}
void student::pack()
{
    string temp;
    fstream f1;
    temp+=usn+'|'+name+'|'+branch+'|'+sem;
    temp.resize(100,'$');
    f1.open("data.txt",ios::out|ios::app);
    f1<<temp<<endl;
    f1.close();
}
int student::search(string key)
{
    fstream f1;int flag,pos;
    f1.open("data.txt",ios::in);
    while(!f1.eof())
    {
    	getline(f1,buffer);
    	unpack();
    	if(usn==key)
    	{
    		flag=1;
    		break;
    	}
    	else
    	flag=0;
    }
    if(flag==1)
    {
    	cout<<"Found"<<endl;
    	pos=f1.tellp();
    	cout<<"Position is:"<<pos<<endl;

    }
    else
    cout<<"Not found"<<endl;
    return pos;
}
void student::unpack()
{
    int i=0;
    usn.erase();
    while(buffer[i]!='|')
    usn+=buffer[i++];
    i++;
    while(buffer[i]!='|')
    name+=buffer[i++];
    i++;
    while(buffer[i]!='|')
    branch+=buffer[i++];
    i++;
    while(buffer[i]!='$')
    sem+=buffer[i++];
    i++;
}
void student::modify(string key)
{
	string temp;
	int pos,ch;
	fstream f1;
	pos=search(key);
	pos=pos-101;
	cout<<"Change 1.Name 2.USN 3.Branch 4.Sem"<<endl;
	cin>>ch;
	switch(ch)
	{
	case 1:
		cout<<"Enter the name:"<<endl;
		cin>>name;
		break;
	case 2:
		cout<<"Enter the USN:"<<endl;
		cin>>usn;
		break;
	case 3:
		cout<<"Enter the branch:"<<endl;
		cin>>branch;
		break;
	case 4:
		cout<<"Enter the sem:"<<endl;
		cin>>sem;
		break;
	default:
		cout<<"Invalid"<<endl;
	}
	temp.erase();
	temp+=usn+'|'+name+'|'+branch+'|'+sem;
	temp.resize(100,'$');
	f1.open("data.txt");
	f1.seekp(pos,ios::beg);
	f1<<temp<<endl;
	f1.close();
}
int main()
{
    int choice;
    string key;
    while(1)
    {
            cout<<"1.INSERT 2.SEARCH 3.DELETE 4.MODIFY 5.EXIT"<<endl;
            cout<<"Enter your choice:"<<endl;
            cin>>choice;
            switch(choice)
            {
            	case 1:
            		s.read();
            		s.pack();
            		break;
            	case 2:
            		cout<<"Enter the key"<<endl;
            		cin>>key;
            		s.search(key);
            		break;
            	case 4:
            		cout<<"Enter the key"<<endl;
            		cin>>key;
            		s.modify(key);
            		break;
            	case 5:
            		return 0;
            		break;
            	default:
            		cout<<"Invalid"<<endl;
            }
    }
    return 0;
}
