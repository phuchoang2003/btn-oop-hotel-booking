#pragma once
#include<iostream>
#include<string>
using namespace std;

class Person {
protected:
	string full_name;
	int age;
	string gender;
public:
	Person() {
		age = NULL;
	}
	Person(string full_name, int age, string gender) {
		this->full_name = full_name;
		this->age = age;
		this->gender = gender;
	}
~Person(){}
	void set_name(string full_name) {
		this->full_name = full_name;
	}
	string get_name() {
		return full_name;
	}

	void set_age(int age) {
		this->age = age;
	}
	int get_age() {
		return age;
	}

	void set_gender(string gender) {
		this->gender = gender;
	}
	string get_gender() {
		return gender;
	}
};