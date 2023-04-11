#pragma once
#include"Room.cpp"
#include<iostream>
using namespace std;

class Invoice {
private:
	Room* rooms = new Room[10];
	int days;
public:
	void set_days(int days) {
		this->days = days;
	}

	int get_days() {
		return days;
	}

	void input() {// nhap so ngay o
		cout << "Days check out: ";
		cin >> this->days;
	}
	int payment(int roomNum) {
		return rooms[roomNum - 101].get_price()* days;
	}
};
