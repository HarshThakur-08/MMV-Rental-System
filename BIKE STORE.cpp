#include<iostream>
#include<string>
#include<time.h>
#include<stdlib.h>

#include"./Bike Queue.cpp"
//#include"./Bike Details.cpp"
using namespace std;
class BikeStore {
	
	public:
		
		void AllotBike();
		void CancelBooking();
		void ReturnBike();
};

void BikeStore :: AllotBike() 
{
	system("cls");
	if(bikeQ->isAvailable()) {
		
		cout<<"\nAlloting Bike... Please Wait";
		
		long temp;
		temp = bikeQ->allotBike();
		
		cout<<"Bike with registration number "<<temp<<" is alloted";
//		cout<<"\nYour alloted bike details";
//		
//		bikeD.displayDetails(temp);
				
	}
} 

//void addRecords(long temp,string username)
//{	
//	time_t t;
//	time(&t);
//	ofstream recordfile;
//	recordfile.open("RECORDS.txt"|ios::app);
//	recordfile<<username<<" "<<temp<<" "<<ctime(&t)<<endl;
//	
//	recordfile.close();
//	
//	
//}




void BikeStore :: CancelBooking()
{
	system("cls");
	// we will check whether this bike has been booked or not
	long id;
	cout<<"Please enter the correct bike id:";
	cin>>id;
	fstream allotedbikes;
	allotedbikes.open("Bikes alloted.txt", ios::in);
	
	
	long num;
	int flag = 0;
	
	while(allotedbikes >> num) {
		if(num == id) {
			flag = 1;
			
		}
		
	}
	
	// if found
	char paymentchoice;
	
	if (flag) {
		cout<<"Pay Rs.50 as your cancellation fees.\nPress y to proceed payment else n to cancel:";
		cin>>paymentchoice;
		if(paymentchoice=='y'||paymentchoice=='Y')
		{
				cout<<"\nYour booking is being cancelled";
			bikeQ->returnBike(id);
		}
	}
	
	//else log that no such bookings made
	
	else {
		cout<<"\nThis Bike was not alloted... Cancellation not possible";
	}
	
	
}

void BikeStore :: ReturnBike() 
{
	system("cls");
	long id;
	cout<<"Please enter the correct bike id:";
	cin>>id;
	
	bikeQ->returnBike(id);
}

BikeStore Bike;
//int main() {
//	
//	bikeQ -> initialize();
//	
//	cout<<"what do you want to do 1. Allot 2. cancel 3. return";
//	int choice;
//	cin>>choice;
//	switch(choice) {
//		case 1: Bike.AllotBike();
//				 break;
//		case 2: Bike.CancelBooking(/* any alloted number*/);
//				 break;
//		case 3: Bike.ReturnBike(/* any alloted number*/);
//				 break;
//		default: cout<<"wrong input";		   		  				 	
//	}
//}











