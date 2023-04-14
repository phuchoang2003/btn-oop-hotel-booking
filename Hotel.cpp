#pragma once
#include"Room.cpp"
#include"Invoice.cpp"
#include"Customer.cpp"
#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;

class Hotel {
private:
	Customer customer;
	Room* rooms = new Room[10];
	Invoice bill;

public:

	Hotel() {}

	~Hotel(){}
	void reset_rooms() { //ham nay chi dung 1 lan duy nhat de khoi tao du lieu mac dinh cho cac phong va ghi du lieu vao file,
		//nhung lan sau dung se reset lai du lieu cua cac phong va xoa tat ca du lieu ve khach dat phong
		// khach san gom 10 phong danh so tu 101 den 110
		//khoi tao danh sach phong standard tu 101 den 107
		for (int i = 0; i < 7; i++) {
			rooms[i].set_room_no(101 + i);
			rooms[i].set_status("available");
			rooms[i].set_typeRoom("standard");
			rooms[i].set_price(200);
		}

		//khoi tao danh sach phong VIP tu 108 den 110
		for (int i = 7; i < 10; i++) {
			rooms[i].set_room_no(101 + i);
			rooms[i].set_status("available");
			rooms[i].set_typeRoom("VIP");
			rooms[i].set_price(1000);
		}

		ofstream file("List_room.txt", ios::trunc);
		ofstream file2("Customer_record.txt", ios::trunc);
		for (int i = 0; i < 10; i++) {
			file << setw(20) << rooms[i].get_room_no()
				<< setw(20) << rooms[i].get_type_room()
				<< setw(20) << rooms[i].get_price()
				<< setw(20) << rooms[i].get_status() << '\n';
		}

		file.close();
		cout << "\n\n\t\t\tPress Any Key To Continue.......";



	}


	bool check(int roomNum) { // ham check xem phong duoc dat hay chua
		bool flag = false;// false phong trong
		string line;
		string roomNo = to_string(roomNum);
		ifstream file("List_room.txt", ios::in);
		while (getline(file, line)) {
			if (line.find(roomNo) != string::npos) {
				if (line.find("unavailable")!=string::npos) {
					flag = true;//true la phong duoc dat
					break;
				}
			}
		}
		file.close();
		return flag;
			}
	

	void show_list_room() { // ham show danh sach cac phong 
	
		cout << "\t\t\t\tList Rooms" << endl;
		cout << "\t\t\t********************\n\n";
		cout << "\t\tROOM NO" << "\t\tTYPE ROOM" << "\t\tPRICE" << "\t\tSTATUS" << endl;
		string line;
		ifstream file("List_room.txt", ios::in);
		while (getline(file, line)) {
			cout << line << endl;
		
		}
		file.close();

	}
	
	void display_customer_record() {// ham nay tim so phong se ra thong tin khach hang

		ifstream file("List_room.txt", ios::in);
		cout << "Enter room number: ";
		int room_no;
		cin >> room_no;
		bool flag = check(room_no);
		string txtRoomNum = to_string(room_no);
		if (flag) {

			system("cls");
			cout << "\n\n\n";
			cout << left << setw(10) <<"Room no" 
				<< setw(20) << "Name"
				<< setw(10) << "Age"
				<< setw(10) << "Gender"
				<< setw(15) << "Id" 
				<<setw(15) << "Phone" 
				<< setw(20)<<"Days Check Out"
				<<setw(5)<<"Total"<<endl;
			string line;
			ifstream file("Customer_record.txt", ios::in);
			while (getline(file, line)) {
				if (line.find(txtRoomNum) != string::npos) {
					cout << line;
					break;
				}
			}
			file.close();
		}
		
			
		else
		{
			system("cls");
			cout << "\n\n\t\t\t******************************" << endl;
			cout << "\t\t\tSorry!Room Is Vacant OR NOT Exist";
			cout << "\n\n\t\t\tPress Any Key To Continue.......";
			_getch();
		}
		
	}
		
	// day la ham thuc hien book phong
	void book_room() {
		int r;
		cout << "\n\n\t\tCustomer Detail" << endl;
		cout << "\t\t***************" << endl;
		cout << "\n\nChoose number of room: ";
		cin >> r;

		if (r < 101 || r > 110) {
			system("cls");
			cout << "\n\n\n\t\t***************************" << endl;
			cout << "\t\tSorry! Room Does NOT Exist!" << endl;
			cout << "\t\tPress Any Key To Continue.......";
			_getch();
		}

		else {
			bool flag = check(r);
			if (flag) {
				system("cls");
				cout << "\n\n\n\t\t***********************";
				cout << "\n\t\tRoom is already booked!";
				cout << "\n\n\t\t\tPress Any Key To Continue.......";
				_getch();
			}

			else

			{
				Invoice::add();
				rooms[r - 101].set_room_no(r);
				rooms[r - 101].set_status("unavailable");
				customer.input();
				bill.input();
				bill.output(r);

				string customer_record;
				ofstream file2("Customer_record.txt", ios::app);//dien thong tin cua khach vao file 
				file2 << left << setw(10)
					<< rooms[r - 101].get_room_no()
					<< setw(20) << customer.get_name()
					<< setw(10) << customer.get_age()
					<< setw(10) << customer.get_gender()
					<< setw(15) << customer.get_id()
					<< setw(15) << customer.get_phone()
					<< setw(20) << bill.get_days()
					<< setw(5) << bill.get_total() << endl;
				file2.close();
				string txtRoomNum = to_string(r);
				string line;
				fstream file("List_room.txt", ios::in | ios::out);
				if (file.is_open()) {
					ofstream tempFile("temp.txt");
					file.seekp(0, 0);
					file.seekg(0, 0);
					file.clear();
					while (getline(file, line)) {
						if (line.find(txtRoomNum) != string::npos) {
							size_t pos = line.find("available");

							if (pos != string::npos) {
								line.replace(pos, 9, "unavailable");
							}
						}
						tempFile << line << endl;
						tempFile.flush();
					}
					tempFile.close();
					file.close();

					remove("List_room.txt");
					rename("temp.txt", "List_room.txt");

					system("cls");
					cout << "\n\n\t\t\t*********************" << endl;
					cout << "\t\t\t Successful Booking !";
					cout << "\n\n\t\t\tPress Any Key To Continue.......";
					_getch();
				}
			}
		}


		}
		//day la ham doi thong tin khach hang
		void modify_record(int roomNum) {
			bool flag = check(roomNum);
			if (flag) {
				string line;
				string txtRoomNum = to_string(roomNum);
				fstream file2("Customer_record.txt", ios::in | ios::out);
				if (file2.is_open()) {
					ofstream tempfile("temporary_file.txt", ios::out);
					file2.seekg(0, 0);
					file2.seekp(0, 0);
					file2.clear();
					while (getline(file2, line)) {
						if (line.find(txtRoomNum) != string::npos) {
							size_t pos = line.find(customer.get_name());
							cout << "\n\n\t\t\tEnter New Information" << endl;
							cout << "\t\t\t*********************" << endl;
							customer.input();
							bill.input();
							tempfile << left << setw(10) << rooms[roomNum-101].get_room_no() 
								<< setw(20) << customer.get_name() 
								<< setw(10) << customer.get_age() 
								<< setw(10) << customer.get_gender() 
								<< setw(15) << customer.get_id() 
								<< setw(15) << customer.get_phone() 
								<< setw(20) << bill.get_days() 
								<< setw(5) << bill.get_total()<< endl;
							tempfile.flush();
						}
						else {
							tempfile << line << endl;
							tempfile.flush();
						}
					}
					tempfile.close();
					file2.close();
					remove("Customer_record.txt");
					rename("temporary_file.txt", "Customer_record.txt");
				}

			
			}
			else {
				system("cls");
				cout << "\n\n\t\t\t******************************" << endl;
				cout << "\t\t\tSorry!Room Is Vacant OR NOT Exist";
				cout << "\n\n\t\t\tPress Any Key To Continue.......";
				_getch();
			}
		}

		// Day la ham delete thong tin khach hang qua so phong
		void delete_record(int roomNum) {
			bool flag = check(roomNum);
			if (flag) {
				string line;
				string txtRoomnum = to_string(roomNum);
				ifstream file("Customer_record.txt", ios::in);
				if (file.is_open()) {
					ofstream tempFILE("temporary.txt", ios::out);
					file.seekg(0, 0);
					file.seekg(0, 0);
					file.clear();
						while (getline(file, line)) {
							if (line.find(txtRoomnum) != string::npos) {
								
								cout << "\n\n\t\t\tDo You Want To Delete ?" << endl;
								cout << "\n\t\t\tYES(y) OR NO(n)" << endl;
								char choice;
								cout << "\n\t\t\tEnter Your Choice: ";
								cin >> choice;
								switch (choice)
								{
								case 'y': {
									system("cls");
									fstream f("List_room.txt", ios::in | ios::out);
									ofstream fout("file_tam_thoi.txt", ios::out);
									f.seekg(0, 0);
									f.seekp(0, 0);
									f.clear();
										while (getline(f, line)) {
											if (line.find(txtRoomnum) != string::npos) {
												size_t pos = line.find("unavailable");
												if (pos != string::npos) {
													line.replace(pos, 11, "available");
												}
											}
											fout << line << endl;
											fout.flush();
									}
										f.close();
										fout.close();
										remove("List_room.txt");
										rename("file_tam_thoi.txt", "List_room.txt");
									cout << "\n\n\t\t\tDeleted Successful!";
									break;
								}
								case 'n': {
									tempFILE << line << endl;
									tempFILE.flush();
									break;
								}
								default:
									system("cls");
									cout << "\n\n\t\t\tPress Any Key To Return Menu";
									break;
								}
								
							}
							else {
								tempFILE << line << endl;
								tempFILE.flush();
							}							
						}
						file.close();
						tempFILE.close();
						remove("Customer_record.txt");
						rename("temporary.txt", "Customer_record.txt");
				}

			}
			else
			{
				system("cls");
				cout << "\n\n\t\t\tRoom Does NOT Exist!" << endl;
				_getch();
			}
		}
		//Day la ham edit thong tin khach hang gom 2 tinh nang la delete va modify
		void edit_record() 
		{
			cout << "\n\n\t\t\tEdit Menu" << endl;
			cout << "\t\t\t************************" << endl;
			cout << "\t\t\t1.Delete Customer Record" << endl;
			cout << "\t\t\t2.Modify Customer Record" << endl;
			cout << "\t\t\t************************" << endl;
			cout << "\nEnter Your Choice: ";
			int choice, r;
			cin >> choice;
			system("cls");
			cout << "\n\nEnter Room No: ";
				cin >> r;
			switch (choice)
			{
			case 1:
				system("cls");
				delete_record(r);
				break;
			case 2:
				system("cls");
				modify_record(r);
				break;
			default:
			{
				system("cls");
				cout << "\n\n\t\t\tWrong choice.....!!" << endl;
				break;
			}
			}
			cout << "\n\n\t\t\tPress Any Key To Continue.......";
			_getch();

			} 



		void main_menu() { // tao menu
			int choice = NULL;
			while (choice != 6) {
				system("cls");
				cout << "\t---------------" << endl;
				cout << "\t** Main menu **" << endl;
				cout << "\t---------------" << endl;
				cout << "\n1.Show List Room." << endl;
				cout << "2.Book A Room." << endl;
				cout << "3.Display Customer Record." << endl;
				cout << "4.Edit Record." << endl;
				cout << "5.Reset Rooms." << endl;
				// chi dung 1 lan duy nhat de khoi tao du lieu cho cac phong va ghi du lieu vao file, 
				//nhung lan sau dung se reset lai du lieu cua cac phong
				cout << "6.Exit.";
				cout << "\n\n\nEnter Your Choice:";
				cin >> choice;

				switch (choice)
				{
				case 1:
					system("cls");
					show_list_room();
					_getch();
					break;
				case 2:
					system("cls");
					book_room();
					_getch();
					break;
				case 3:
					system("cls");
					display_customer_record();
					_getch();
					break;
				case 4:
					system("cls");
					edit_record();
					_getch();
					break;
				case 5:
					system("cls");
					reset_rooms();
					_getch();
					break;
				case 6:
					system("cls");
					cout << "\n\n";
					cout << "\t\t\tThanks For Visiting! Goodbye!" << endl;
					cout << "\t\t\t*****************************";
					_getch();
					break;
				default:
				{
					system("cls");
					cout << "\n\n";
					cout << "\t\t\tInvalid Choice! " << endl;
					cout << "\n\n\t\t\tPress Any Key To Continue.......";
					cout << "\n\n\t\t\t********************************";
					_getch();
					break;
				}
				}
			}
		}



	};

