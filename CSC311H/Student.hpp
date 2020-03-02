//
//  Student.hpp
//  CSC311H
//
//  Created by Weida Jiang on 2/18/20.
//  Copyright © 2020 BMCC. All rights reserved.


#ifndef Student_hpp
#define Student_hpp
#include <string>
#include <stdio.h>

class Student{
private:
    
    std::string _name;
    std::string _id;

public:
    Student();
    Student(std::string,std::string);
    ~Student();
    void setName(std::string);
    void setID(std::string);
    std::string getName();
    std::string getID();
    void print();
    bool operator==(Student &);
    
    
};


#endif /* Student_hpp */
