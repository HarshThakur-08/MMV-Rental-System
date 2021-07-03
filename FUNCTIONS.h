#ifndef FUNCTIONS_H
#define FUNCTIONS_H



#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<limits>
#include<stdlib.h>

using namespace std;

struct details_person
{
	string firstname;
	string lastname;
	int age;
	string username;
	string password;
	string security_pin;
	
};
struct details_person *arr=new details_person[100];
int k;

void definek()
{
	int k1;
	ifstream file6;
	file6.open("k.txt");
	file6>>k1;
	k=k1;
	file6.close();
	
}
void incrementk(int q)
{
	ofstream file7;
	file7.open("k.txt",ios::trunc);
	file7<<q+1;
	file7.close();
}

bool checkFirstName(string FirstName)
{
	for (int i = 0; i < FirstName.size(); i++)
	{
		
		if ( !((FirstName[i]>=97&&FirstName[i]<=122)||(FirstName[i]>=65&&FirstName[i]<=90)))
		{
			return false;
		}
	}
	
	return true; 
}

bool checkLastName(string LastName)
{
	for (int i = 0; i < LastName.size(); i++)
	{
		
		if ( !((LastName[i]>=97&&LastName[i]<=122)||(LastName[i]>=65&&LastName[i]<=90)))
		{
			return false;
		}
	}
	
	return true; 
}

bool checkAge(int Age)
{
	if (Age>=10) return true;	
	else  return false;
}

bool checkUserName(string UserName)
{
	for (int i=0;i< UserName.size();i++)
	{
		if(!isalnum(UserName[i])) return false;//or use ASCII CODES
		
	}
	string a,b,d,e,f;
	int c;
	ifstream in_file1;
	in_file1.open("test.txt");
	if(!in_file1)
	{
		cerr<<"error"<<endl;
		
	}
	for(int i=0;i<k;i++)
	{	
		in_file1>>a>>b>>c>>d>>e>>f;
				
		for(int j=0;j<UserName.size();j++)
		{
			if(d[j]==UserName[j] && j==d.size()-1 &&j==UserName.size()-1)return false;
			else if(d[j]==UserName[j]) continue;
			else if(d[j]!=UserName[j]) break;
		}
		
	}
	in_file1.close();
	return true;
	
}

bool checkPassword(string Password)
{
	
	for(int i=0;i<k;i++)
	{	
		string str=arr[i].password;
		for(int j=0;j<Password.size();j++)
		{
			if(str[j]!=Password.at(j))return false;
		}
		
	}
	return true;
}

bool matchPassword(string Password,int num)
{	
	ifstream in_file;
	in_file.open("test.txt");
	string a,b,d,e,f;
	int c;
	string line;
	//GotoLine(in_file,num+1);
	for(int i=0;i<num;i++)
	{
		getline(in_file,line);
	}
	in_file>>a>>b>>c>>d>>e>>f;
	
	
	if(f.length()!=Password.length())
		return false;
	for(int i=0;i<Password.size();i++)
	{
		if(f[i]!=Password.at(i))return false;
	}
	in_file.close();
	return true;
	
}

string getPassword(int num)
{
	ifstream in_file3;
	in_file3.open("test.txt");
	string a,b,d,e,f;
	int c;
	string line;
	//GotoLine(in_file,num+1);
	for(int i=0;i<num;i++)
	{
		getline(in_file3,line);
	}
	in_file3>>a>>b>>c>>d>>e>>f;
	in_file3.close();
	return f;
}

bool matchSecurityPin(string SecurityPin,int num)
{
	ifstream in_file2;
	in_file2.open("test.txt");
	string a,b,d,e,f;
	int c;
	string line;
	//GotoLine(in_file,num+1);
	for(int i=0;i<num;i++)
	{
		getline(in_file2,line);
	}
	in_file2>>a>>b>>c>>d>>e>>f;
	
	
	
	
	for(int i=0;i<SecurityPin.size();i++)
	{
		if(e[i]!=SecurityPin.at(i))return false;
	}
	in_file2.close();
	return true;
}


bool checkSecurityPin(string SecurityPin)
{	
	if(SecurityPin.size()!=4) return false;
	for(int i=0;i<SecurityPin.size();i++)
	{
		if(!(SecurityPin[i]>='0'&&SecurityPin[i]<='9')) return false;
	}
	return true;
		
}

void setNewPassword(string NewPassword,int num)
{
	ifstream file;
	file.open ("test.txt");
	ofstream file1;
	file1.open("demo2.txt");
	
	string line;
	string a,b,d,e,f;
	int c;
	
	
	for(int i=0;i<num;i++)
	{
		getline(file,line);
		file1<<line<<endl;
		
	}
	file>>a>>b>>c>>d>>e>>f;
	file1<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<NewPassword;
	
	for(int i=0;i<k-num;i++)
	{
		getline(file,line);
		file1<<line<<endl;
		
	}
	
	file.close();
	file1.close();
	
	ofstream file2;
	file2.open ("test.txt");
	ifstream file3;
	file3.open("demo2.txt");

	while(getline(file3,line))
	{
		file2<<line<<endl;
	}
	file2.close();
	file3.close();
	
	ofstream file4;
	file4.open("demo2.txt", std::ofstream::out | std::ofstream::trunc);
	file4.close();
}


void addDetailsofPerson(string a,string b,int c,string d,string e,string f)
{
	ofstream file5;
	file5.open("test.txt",ios::app);
	if(!file5)
	{
		cerr<<"error"<<endl;
		return;
	}

	file5<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<endl;
	file5.close();
	
}



#endif
