//
//  Student.cpp
//  CSC311H
//
//  Created by Weida Jiang on 2/18/20.
//  Copyright © 2020 BMCC. All rights reserved.
//

#include "Student.hpp"

Student::Student(){
    this->_name="";
    this->_id="";
    
}

Student::Student(std::string _name,std::string _id){
    this->_name=_name;
    this->_id=_id;
}

void Student::setName(std::string _name){
    this->_name=_name;
}

void Student::setID(std::string _id){
    this->_id=_id;
}

std::string Student::getName(){
    return this->_name;
}

std::string Student::getID(){
    return this->_id;
}


void Student::print(){
    
}

/*______________________________________________________
* funciton used to compare two student id
* if the id are same, return true
*    else return false
* just for demo, didnot compare the name
* ----------------------------------------------------*/
bool Student::operator==(Student &other){

    return this->getID()==other.getID()?true:false;
    
}

Student::~Student(){
    
}
