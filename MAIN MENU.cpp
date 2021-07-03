#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<fstream>
#include"./SIGNUP.cpp"
#include"./SIGN2.cpp"
#include"./BIKE STORE.cpp"

using namespace std;

void main_menu();
bool mm = true;


int main()
{
	time_t t;
	time(&t);
	system("cls");
	
	cout<<"\t\t\t|--------------------------------------------------------------------|\n";
	cout<<"\t\t\t|                                                                    |\n";
	cout<<"\t\t\t|                                                                    |\n";
	cout<<"\t\t\t|              ------------------------------------                  |\n";	
	cout<<"\t\t\t|                 WELCOME TO E-BIKE RENTAL SYSTEM                    |\n";
	cout<<"\t\t\t|              ------------------------------------                  |\n";	
	cout<<"\t\t\t|                                                                    |\n";
	cout<<"\t\t\t|                                                                    |\n";
	cout<<"\t\t\t|                            Made By-                                |\n";
	cout<<"\t\t\t|     HARSH THAKUR(2K19//SE//048) & HARSH YADAV(2K19//SE//049)       |\n";
	cout<<"\t\t\t|                                                                    |\n";
	cout<<"\t\t\t|                                                                    |\n";
	cout<<"\t\t\t|--------------------------------------------------------------------|\n";
	cout<<"\t\t\t|                                                                    |\n";
	cout<<"\t\t\t             Current Date & Time-"<<ctime(&t)<<"\n";
	cout<<"\t\t\t|                                                                    |\n";
	cout<<"\t\t\t|--------------------------------------------------------------------|\n";
	
	
	cout<<"Enter any key to continue:";
	getch();
	
	system("cls");
	char c;
	

	do
	{
		system("cls");
			
		cout<<"\t\t\t|--------------------------------------------------------------------|\n";
		cout<<"\t\t\t|                                                                    |\n";
		cout<<"\t\t\t|                                                                    |\n";
		cout<<"\t\t\t|              ------------------------------------                  |\n";	
		cout<<"\t\t\t|                          LOGIN SYSTEM                              |\n";
		cout<<"\t\t\t|              ------------------------------------                  |\n";	
		cout<<"\t\t\t|                                                                    |\n";
		cout<<"\t\t\t|                                                                    |\n";
		cout<<"\t\t\t                 Create a new account(y/n):";
		cin>>c;
		if(c=='y'||c=='Y')
		{
			login l;
			system("cls");
			
		}
		
		cout<<"\t\t\t|   To sign in succesfully enter your details as given below:       |\n";
		Sign s;

		
		
	}while(!signed_in);

	bikeQ -> initialize();

	
	do
	{
		system("cls");
		main_menu();
	}while(mm);
	
	return 0;
	
	
	
	
}

void main_menu()
{	
	
	time_t t;
	time(&t);
	int action;
	
	
	
	cout<<"Enter the require thing to do:\n1.Press 1 to book\n2.Press 2 to cancel\n3.Press 3 to return\n4.Press 4 to logout"<<endl;
	cin>>action;
	switch (action)
	{
		case 1:
			//booking
			Bike.AllotBike();
			cout<<"\nEnter any key to continue:";
			getch();
			
			break;
		case 2:
			//cancellation
			Bike.CancelBooking();
			cout<<"\nEnter any key to continue:";
			getch();	
			break;
		case 3:
			//return back 
			Bike.ReturnBike();
			cout<<"\nEnter any key to continue:";
			getch();
			
			break;
		case 4:
			//exit
			mm = false;
			break;
			
	}
	return ;
	
}




