#pragma once
#include<iostream>
using namespace std;
class Room {
private:
	string typeRoom;// phong co phong standard va phong VIP
	double price;// gia phong standard la 200 1 ngay con phong VIP la 1000 1 ngay
	int room_no;// so phong 
	string status; //  phong trong, phong duoc dat
	
public:
	Room()
	{
		room_no = NULL;
		price = NULL;
	}
	Room(string typeRoom, double price) {
		this->typeRoom = typeRoom;
		this->price = price;
	}
	~Room(){}
	
	void set_status(string status) {
		this->status = status;
	}

	string get_status() {
		return status;
	}
	void set_room_no(int room_no) {
		this->room_no = room_no;
	}

	int get_room_no() {
		return room_no;
	}
	void set_typeRoom(string typeRoom) {
		this->typeRoom = typeRoom;
	}
	string get_type_room() {
		return typeRoom;
	}

	void set_price(double price) {
		this->price = price;

	}

	double get_price() {
		return price;
	}
};