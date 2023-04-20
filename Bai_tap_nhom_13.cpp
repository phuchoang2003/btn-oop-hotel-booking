// Bai_tap_nhom_OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma once
#include <iostream>
#include"Person.cpp"
#include"Customer.cpp"
#include"Hotel.cpp"
#include"Room.cpp"
#include"Invoice.cpp"
#include<fstream>

using namespace std;
int Invoice::dem = 0;


int main()
{
Hotel h;
h.main_menu(); 
    return 0;
}


