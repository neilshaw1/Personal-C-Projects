
//Car.cpp

//Has definitions of Car member functions

#include<iostream>
#include "Car.h" //include Car header file
using namespace std;

//Car Class Declaration

	Car::Car(){
	make=model=licensePlate=color="";
	}

	Car::Car(string mk, string md, string lp, string clr){
		make = mk;
		model = md;
		licensePlate=lp;
		color=clr;
	}

	void Car::setMake(string mk){
		make = mk;
	}

	void Car::setModel(string md){
		model = md;
	}

	void Car::setLicensePlate(string lp){
		licensePlate = lp;
	}

	void Car::setColor(string clr){
		color = clr;
	}

	string Car::getColor(){
		return color;
	}

	string Car::getModel(){
		return model;
	}

	string Car::getMake(){
		return make;
	}

	string Car::getLicensePlate(){
		return licensePlate;
	}


