#pragma once
#include"Room.cpp"
#include"Customer.cpp"
#include<iostream>
#include<string>
#include<conio.h>
#include<cstdlib>

using namespace std;


class Invoice {
private:
	string invoice_id;// ma hoa don
	double total; // tong so tien phai tra
	int days;// so ngay o
	Room room;
	Customer customer;
	
public:
	 static int dem;

	 static void add() {
		 dem++;
	 }

	Invoice(){
		total = NULL;
		days = NULL;
	}



	Invoice(int days) {
		this->invoice_id = invoice_id;
		this->days = days;
		this->total = room.get_price() * days;
	}
	~Invoice(){
	}


	string get_invoice_id() {
		return invoice_id ="LTHDT0000";
	}


	void set_days(int days) {
		this->days = days;
	}

	int get_days() {
		return days;
	}

	double get_total() {
		return room.get_price() * days;
	}
	
	void input() {
		cout << "Number Of Days To Check Out: ";
		cin >> days;
		cin.ignore();
	}

	void output(int room_number) {// xuat hoa don sau khi dat phong se in ra hoa don thanh toan
		system("cls");
		cout << "--------------------------------------------" << endl;
		cout << "\t        Invoice \n\n";
		cout << "Code Bill: " << get_invoice_id() + to_string(dem);
		room.set_room_no(room_number);
		cout << "\tNumber Of Room: " << room.get_room_no() << endl;
		cout << "--------------------------------------------" << endl;
		if (room.get_room_no() < 108) {
			room.set_typeRoom("standard");
			room.set_price(200);
		}
		else
		{
			room.set_typeRoom("VIP");
			room.set_price(1000);
		}

		cout << "Type Of Room: " << room.get_type_room();
		cout << "\tPrice: " << room.get_price() << endl;
		cout << "--------------------------------------------" << endl;
		cout << "Days:  " << get_days();
		cout << "\tTotal: " << get_total() << endl;
		cout << "--------------------------------------------" << endl;
		cout << "\n\n\t\tConfirmation" << endl;
		cout << "\t\tYes(y) or No(n)" << endl;
		char option = NULL;
		cin >> option;
		switch (option) {
		case 'y':
			system("cls");
			cout << "\n\n\t\t\tPaymen Success!" << endl;
			cout << "\t\t\t********************************";
			_getch();
			break;
		case 'n':
			system("cls");
			cout << "\n\n\t\t\tThanks for visiting!" << endl;
			cout << "\t\t\t********************************";
			_getch();
			break;
		default:
			system("cls");
			cout << "Wrong choice!" << endl;
			cout << "\n\n\t\t\tPress Any Key To Continue.......";
			_getch();
			break;
		}
		_getch();

	}
};




