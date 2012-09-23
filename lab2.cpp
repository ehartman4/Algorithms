/*
class food {

public:
	food();
	void info(); //display food stuff
};
class veggies: public food{

};
class chemicals

class candybar : public food, public chemicals{
	hgff
}

//SEE FOOD.CPP
can keep base class objects private if those objects won't need to be used by the class inheriting from it,
   otherwise make them protected - saying class veggies : public food will acces the public and protected info from food, but not private.
*/
/*
create class "info", stores name, address, etc.
inheriting from info, create a class that contains ifn about driving license: age, id number, etc.
from info, CPR class: trained?, date of training
class thatinherits from both drivers license and CPR
*/

#include <iostream>

using namespace std;

class info {
protected:
	string name;
	string address;
public:
	string get_name();
	info(void);
	void show();
};

info::info (void)
{
   cout << "Name: ";
   cin >> name;
   cout << "Address: ";
   cin >> address;
}

void info::show ()
{
	cout<<"Name: "<< name<<endl;
	cout << "Address: "<< address<<endl;
}
string info::get_name()
{
	return name;
}

class drive_license : virtual public info{
protected:
	int age;
	int id_number;
public:
	drive_license(void);
	void show();
};

drive_license::drive_license(void){
	cout << "Age: ";
	cin >> age;
	cout << "ID Number: ";
	cin >> id_number;
}

void drive_license::show(){
	info::show();
	cout<<"Age: "<< age<<endl;
	cout << "ID Number: "<<id_number<<endl;
}

class CPR : virtual public info{
protected:
	bool trained;
	string traindate;
public:
	CPR(void);
	void show();
};

CPR::CPR(void){
	cout << "Trained?(T/F): ";
	char tf;
	cin >> tf;
	cin.get();//for characters - carriage return
	if (tf=='T') {
		trained = 1;
		cout << "Train Date: ";
		cin >> traindate;
	}
	else if (tf=='F') {
		trained = 0;
		traindate = "0/0/0";
	}
	
}

void CPR::show(){
	info::show();
	cout<<"Trained?: ";
	if (trained==1){
		cout<<"Yes"<<endl;
	}
	else if(trained==0){
		cout<<"No"<<endl;
	}
	cout << "Train date: "<<traindate<<endl;

}
class lifeguard : public drive_license,public CPR{
	
public:
	lifeguard(void){};
	void show();
};


void lifeguard::show(){
	cout<<"Name: "<<CPR::get_name()<<endl;
	
	cout<<"Trained?: ";
	if (trained==1){
		cout<<"Yes"<<endl;
	}
	else if(trained==0){
		cout<<"No"<<endl;
	}
	cout << "Age: "<<age<<endl;
}

int main(){
	//info me;
	//me.name = "Emma";
	//me.address = "Wheaton";
	//cout<<me.name<<me.address<<endl;
	//me.show();
	//drive_license dad;
	//dad.show();
	lifeguard me;
	cout<<endl;
	me.show();

}