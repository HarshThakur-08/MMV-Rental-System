#include<iostream>
#include<string>
#include"./FUNCTIONS.h"

using namespace std;

 
class login
{	
	
		
	public:
		login()
		{	
			
			definek();	
			Signup();
			
		}
		void Signup()
		{	
			string fname_val,lname_val,username_val,password_val,security_pin_val;
			int age_val;
			bool b=true;
			do
			{
			
				cout<<"Enter your first name(it should only contains letter):\t\t\t\t\t";
				cin>>fname_val;
				if(checkFirstName(fname_val)) b=false;
			
			}while(b);
			
			bool b4=true;
			do
			{
			
				cout<<"Enter your last name(it should only contains letter):\t\t\t\t\t";
				cin>>lname_val;
				if(checkLastName(lname_val)) b4=false;
			
			}while(b4);
			
			cout<<"Enter your age:\t\t\t\t\t\t\t\t\t\t";
			cin>>age_val;
			if(!checkAge(age_val))
			{
				cout<<"sorry you are too smaller to drive e-bike"<<endl;
				return;
			}
			
			bool b1=true;			
			do
			{
				
				cout<<"Enter your username(should contain only alpha-numberic characters & must be unique):\t";
				cin>>username_val;
				if(checkUserName(username_val) ) b1=false;
			
			}while(b1);
			
			cout<<"\nEnter your password:\t\t\t\t\t\t\t\t\t";
			cin>>password_val;
			
			
			bool b3=false;
			do
			{
				cout<<"\nPlease enter 4 digit security pin in case in future you forget your password:\t\t";
				cin>>security_pin_val;
				b3=checkSecurityPin(security_pin_val);
			}while(!b3);
			
			arr[k].firstname=fname_val;
			arr[k].lastname=lname_val;
			arr[k].age=age_val;
			arr[k].username=username_val;
			arr[k].password=password_val;
			arr[k].security_pin=security_pin_val;
			
			addDetailsofPerson(arr[k].firstname,arr[k].lastname,arr[k].age,arr[k].username,arr[k].security_pin,arr[k].password);
			
			incrementk(k);
			definek();	
		}		
};




