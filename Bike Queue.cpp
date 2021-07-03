#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>

#define MAX 100

using namespace std;

struct BikeQueue {
	int front, rear, size;
	long * ptr;
	
	BikeQueue() {
		front = rear = -1;
		size = MAX;
		ptr = new long[size];
		
		
	}
	
	void initialize();
	bool isAvailable();
	void addBike(long);
	long allotBike();
	void returnBike(long);
};

void BikeQueue :: initialize() {
	fstream bikefile;
	bikefile.open("Bike registration number.txt", ios::in);
	
	long num;
	
	while (bikefile >> num) {
		
		addBike(num);
	}
	
	bikefile.close();
}
 
bool BikeQueue :: isAvailable() {
	
	if(front == -1) {
		cout<<"\nSorry, We don't have any bikes available right now";
		return false;
	}
	
	else {
		cout<<"\nYes, You can be alloted an E Bike";
		return true;
	}
}

void BikeQueue :: addBike(long id) {
	if ( (front == 0 && rear == size - 1) || (rear == (front-1)%(size-1)) ) {
		cout<<"\nNo More Space to add a new E bike";
		return;
	}
	
	else if (front == -1 && rear == -1) {
		front = rear = 0;
		ptr[rear] = id;
		//cout<<"\nBike added successfully ";
	}
	
	else if( rear == size - 1 && front > 0 ) {
		rear = 0;
		ptr[rear] = id;
		//cout<<"\nBike added successfully ";
	}
	
	else {
		ptr[++rear] = id;
		//cout<<"\nBike added successfully ";
	}
	

} 

long BikeQueue :: allotBike() {
	long temp;
	
	if(front == rear) {
		temp = ptr[front];
		front = rear = -1;
		
	}
	
	else if (front == size - 1) {
		temp = ptr[front];
		front = 0;
		
	}
	
	else {
		temp = ptr[front++];
	}
	
	fstream allotedbikes;
	allotedbikes.open("Bikes alloted.txt", ios::out | ios::app);
	allotedbikes << temp << endl;
	allotedbikes.close();
	
	
	fstream bikefile;
	bikefile.open("Bike registration number.txt",ios::trunc | ios::out);

	for (int i = front; i <= rear; i++) 
        bikefile << ptr[i] << endl;
	
	bikefile.close();

	return temp;
	
}

void BikeQueue :: returnBike(long id) {
	fstream bikefile;
	bikefile.open("Bike registration number.txt",ios::app);
	
	fstream allotedbikes;
	allotedbikes.open("Bikes alloted.txt", ios::in);
	
	fstream tempfile;
	tempfile.open("Temp file.txt", ios::out);
	
	long num;
	int flag = 0;
	
	while(allotedbikes >> num) {
		if(num == id) {
			flag = 1;
			
		}
		else {
			tempfile << num <<endl;
		}
		
	}
	
	
	if(!flag) {
		cout<<"\nSorry this bike is not in our records... Return unsuccessful";
		return;
	}
	
	bikefile << id << endl;
	
	bikefile.close();
	allotedbikes.close();
	tempfile.close();
	
	remove("Bikes alloted.txt");
	
	rename("Temp file.txt","Bikes alloted.txt");
	
	
	if ( (front == 0 && rear == size - 1) || (rear == (front-1)%(size-1)) ) {
		cout<<"\nSorry your bike cannot be returned successfully";
		return;
	}
	
	else if (front == -1 && rear == -1) {
		front = rear = 0;
		ptr[rear] = id;
		cout<<"\nBike returned successfully ";
	}
	
	else if( rear == size - 1 && front > 0 ) {
		rear = 0;
		ptr[rear] = id;
		cout<<"\nBike returned successfully ";
	}
	
	else {
		ptr[++rear] = id;
		cout<<"\nBike returned successfully ";
	}
	
	
} 


struct BikeQueue * bikeQ = new BikeQueue;


//int main() {
//	
//
//bikeQ->initialize();
//cout<<endl;
////for (int j = 0; j <= 4; j++)
////cout<<bikeQ->ptr[j]<<endl;
//
//cout<<bikeQ->allotBike()<<endl;
////cout<<bikeQ->allotBike()<<endl;
////cout<<bikeQ->allotBike();
////cout<<bikeQ->rear;
//
////for (int i = bikeQ->front; i <= bikeQ->rear; i++) 
////      cout << bikeQ->ptr[i] << endl;
//
////cout<<bikeQ->front;
//bikeQ->returnBike(74588965);
//
//}























