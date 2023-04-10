#pragma once
#include"Person.cpp"
#include<string>
#include<fstream>
using namespace std;
// lop Customer ke thua tu lop Person
class Customer :public Person{
private:
	string id;
	string phone;
public:
	Customer(){}
	Customer(string id, string phone) {
		this->id = id;
		this->phone = phone;
	}
	~Customer(){}

	void set_id(string id) {
		this->id = id;
	}
	void get_phone(string phone) {
		this->phone = phone;
	}

	string get_id() {
		return id;
	}
	string get_phone() {
		return this->phone;
	}

	void input() {
		cin.ignore(); 
		cout << "Please Enter Your Name: ";
		getline(cin, this->full_name);
		cout << "Please Enter Your Age: ";
		cin >> this->age;
		cin.ignore();
		cout << "Please Enter Your gender: ";
		getline(cin, this->gender);
		cout << "Please Enter Your ID: ";
		getline(cin, this->id);
		cout << "Please Enter Your Phone: ";
		getline(cin, this->phone);
		
		
		
	}

	void display() {
		
		
		cout << "Name: " << this->full_name << endl;
		cout << "Age:" << this->age << endl;
		cout << "Gender: " << this->gender<<endl;
		cout << "ID: " << this->id << endl;
		cout << "Phone: " << this->phone<<endl;
		
	}
	
	
};