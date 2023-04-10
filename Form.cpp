#pragma once
#include<string>
#include<iostream>
#include "Customer.cpp"
#include"Room.cpp"
// class nay xem xet them vao chua can viet vao bao cao voi
using namespace std;
class Form {
private:

	int amountOf;
	Room room;
	Customer customer;
	string booking_date;// tao 1 lop date de format ngay thang nam
	string arrival_date;
public:

	void fill_form() {
		cin.ignore();
		customer.input();
		//chon loai phong nao

		cout << "Please Enter The Number Of People Will Be Staying: ";

		cin >> this->amountOf; // toi da 4 nguoi 1 phong

		cout << "Please Choose Room Class: ";// phong thuong va phong vip
		cin.ignore(10000, '\n');
		string typeroom;

		getline(cin, typeroom);
		room.set_typeRoom(typeroom);
		cout << "Nhap ngay dat phong: ";
		getline(cin,this->booking_date);
		cout << "Nhap ngay den: ";
		
		getline(cin, this->arrival_date);


		cout << "Nhap tien dat coc: ";// tien dat coc toi thieu
		double deposits;
		cin >> deposits;
		room.set_price(deposits);

	}
	
	virtual void display_form() {
		cout<<"-------------------------------------------------------------" << endl;
		cout << "\t\tFORM\n\n";
		cout << "Ngay dat phong: " << this->booking_date;
		cout << "\t\tNgay den: " << this->arrival_date << endl;
		cout << "Number of people: " << this->amountOf;
		cout << "\t\tRoom class: " << room.get_type_room() << endl;
		customer.display();
		cout << "Tien dat coc: " << room.get_price();
	}
};