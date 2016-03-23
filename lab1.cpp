//============================================================================
// Name        : lab1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<fstream>
using namespace std;

int main()
{
	string name;
	int len;
	int tmp;
	char temp;

	int x,i;
	int ch;
	fstream s1,s2;
	cout<<"Enter 1 for standard input and 2 for input from files"<<endl;
	cin>>ch;
	switch(ch)
	{
		case 1:
		cout<<"Enter the string"<<endl;
		cin.clear();
		cin.ignore(255,'\n');
		getline(cin,name);
		len=name.length();
		x=(len/2);
		tmp=len;
		for(i=0; i<x; i++)
		{
			temp=name[i];
			name[i]=name[tmp-1];
			name[tmp-1]=temp;
			tmp--;
		}
		cout << name;
		break;
		case 2:
		s1.open("e1.txt",ios::in);
		s2.open("e3.txt",ios::out);
		while(!s1.eof())
		{
			getline(s1,name);
			len = name.length();
			x=(len/2);
			tmp=len;
			for(i=0; i<x; i++)
			{
				temp=name[i];
				name[i]=name[tmp-1];
				name[tmp-1]=temp;
				tmp--;
			}
			s2<<name<<endl;
		}
		s1.close();
		s2.close();
		break;
		default:
		cout<<"Invalid";
	}
	return 0;
}

