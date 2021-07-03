#include<iostream>
#include<string>
#include<fstream>
#include"./FUNCTIONS.h"



using namespace std;
bool signed_in = false;

class Sign
{	
	
	public:
		Sign()
		{
			
			definek();
			string str_username,str_password,str_securitypin;
			cout<<"Enter your username:\t\t\t\t\t\t\t\t";
			cin>>str_username;
			
			int x = findUserName(str_username);
			
			while(x==-1)
			{
				cout<<"No such username exist ,please Enter the correct username:\t\t\t";
				cin>>str_username;
				x = findUserName(str_username);
			}
		
			cout<<str_username<<" please enter your password to sign-in :\t\t\t\t\t";
			cin>>str_password;
			bool b5 = matchPassword(str_password, x);
			int choice;
			int z=0;
			int count_try =0;
			
			while(!b5&&count_try<=4)
			{	
				count_try =count_try + 1;
				if(z==0)
				{
					
				cout<<"To retry once again press 0 or forget password press 1:\t\t\t\t";
				cin>>choice;
				}
				else if(z==1)
				{
					choice=1;
				}
				switch(choice)
				{
					case 0:
						cout<<str_username<<" please enter your password to sign-in :\t\t\t\t\t";
						cin>>str_password;
					
						b5 = matchPassword(str_password, x);
						break;
						
					case 1:
						z=1;
						cout<<str_username<<" please enter your correct 4-digits security pin :\t\t\t";
						cin>>str_securitypin;
						b5 = matchSecurityPin( str_securitypin, x);
						break;
					default:
						cout<<"choose between 0 and 1"<<endl;
						b5=false;
					
						
				}
			}
			
			char reset;
			if(z==1&&count_try<5)
			{
				cout<<"You successfully login into the system do you want to reset your password(y/n):\t";
				signed_in = true;
				cin>>reset;
				if(reset=='y'||reset=='Y')
				{
					cout<<str_username<<" ,your old password was:\t\t\t\t\t\t\t"<<getPassword(x)<<endl;
					cout<<str_username<<" please choose a new password :\t\t\t\t\t\t";
					cin>>str_password;
					arr[x].password=str_password;
					setNewPassword(str_password,x);
				}
				
				else
				{
					cout<<str_username<<" ,your old password was:\t\t\t\t\t\t\t"<<getPassword(x)<<endl;
				}
				
			}
			
			else if(z==0&&count_try<5)
			{
				cout<<"\t\t\t\tYou successfully login into the system.\t\t\t\t\t\t"<<endl;
				signed_in = true;
			}
			
			else
			{
				cout<<"\t\t\t\tYour login was Unsuccessful.\t\t\t\t\t\t"<<endl;
			}
			
			
		}
		int findUserName(string UserName)
		{	
			int linenum=0;
			ifstream in_file;
			string a,b,d,e,f;
			int c;
			in_file.open("test.txt");
			if(!in_file)
			{
				cerr<<"problem"<<endl;
			}
			while(in_file>>a>>b>>c>>d>>e>>f)
			{
					
				for(int j=0;j<UserName.size();j++)
				{
					if(d[j]==UserName[j]&&j==UserName.size()-1&&j==d.size()-1)
						return linenum;
					else if(d[j]==UserName[j])
						continue;
					else if(d[j]!=UserName[j])
						break;
				}
				linenum++;
			}
			
			in_file.close();
			return -1;
		}
//		void profileDisplay()
//		{
//			system("cls");
//			definek();
//			string a,b,d,e,f;
//			int c;
//			ifstream filek;
//			filek.open("test.txt");
//			string line;
//			for(int i=0;i<k;i++)
//			{
//				getline(filek,line);
//			}
//			filek>>a>>b>>c>>d>>e>>f;
//			cout<<"Name     : "<<a<<" "<<b<<endl;
//			cout<<"Age      : "<<c<<endl;
//			cout<<"Username : "<<d<<endl;
//			cout<<"Password : "<<f<<endl;
//			filek.close();
//		
//			
//		}

};


