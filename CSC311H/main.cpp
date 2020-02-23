/*______________________________________________________
 * Author: Weida Jiang
 * Class:CSC331H
 * Professor: Anna Salvati
 * Version: First Version for Peer Review
 * Data: 2/20/2020
 *
 *-----------------------------------------------------*/

#include "DCircularList.cpp"
#include "MyIterator.cpp"
#include "Student.hpp"
#include <cstring>
#include <cctype>
#include <regex>


/*______________________________________________________
 *
 * Function Prototype
 *
 *-----------------------------------------------------*/
void printMenus();
void checkInputById(std::string &);
void checkInputByName(std::string &);
void insertStudentByHead(DCircularList<Student> &);
void insertStudentByTail(DCircularList<Student> &);
void deleteStudentById(DCircularList<Student> &);
void searchStudent(DCircularList<Student> &);
void clearStudents(DCircularList<Student> &);
void printForward(DCircularList<Student> &);
void printBackward(DCircularList<Student> &);

int main(){
    
    DCircularList<Student> _studentList;
    Student _newStudent;
    printMenus();
    std::cout<< "Please enter a number:";
    std::string _userChoice;
    std::cin.clear();
    getline(std::cin, _userChoice);
    
    // always execute the program until user enter 0
    while (true){
        // match user input, must be one digit
        while(!regex_match(_userChoice, std::regex("\\d"))){
            std::cout<<"**************************************************************************"<<std::endl;
            std::cout<<"**\t\t\tInvalid Input. Please enter the number from 0-9 :";
            std::cin.clear();
            getline(std::cin, _userChoice);
        }
        
        int choice=std::stoi(_userChoice);
        switch (choice){
            case 1  :
                insertStudentByHead(_studentList);
                break;
            case 2  :
                insertStudentByTail(_studentList);
                break;
            case 3  :
                std::cout<< "Total Student Number:"<<_studentList.size()<<std::endl;
                break;
            case 4:
                deleteStudentById(_studentList);
                break;
            case 5:
                clearStudents(_studentList);
                break;
            case 6:
                searchStudent(_studentList);
                break;
                
            case 7:
                printForward(_studentList);
                break;
            case 8:
                printBackward(_studentList);
                break;
                
            case 9:
                printMenus();
                break;
                
            case 0 :
                std::cout<<"**************************************************************************"<<std::endl;
                std::cout<<"**\t\t\t\t\t\t Exit the Program. Thank You!     \t\t\t\t**"<<std::endl;
                std::exit(1);
                break;
                
            default :
                std::cout<<"**************************************************************************"<<std::endl;
                std::cout<<"**\t\t\t\t\t Number is not correct. Please reenter \t\t\t\t**"<<std::endl;
                break;
        }
        std::cout<<"**************************************************************************"<<std::endl;
        
        std::cout<< "Please enter a number:";
        std::cin.clear();
        getline(std::cin, _userChoice);
    }
    
    return 0;
}


/*______________________________________________________
 *
 * Function Impl.
 *
 *-----------------------------------------------------*/



/*______________________________________________________
*
* Seach Student Infromation by Enter Student ID
* if cant find it, then print out no student information
*   else print out the student information
*-----------------------------------------------------*/

void searchStudent(DCircularList<Student> &_studentList){
    
    std::string _id;
    std::cout<< "Please the id of the student:";
    getline(std::cin, _id);
    
    checkInputById(_id);
    
    Student _newStudent;
    _newStudent.setID(_id);
    Student *_searchResult=_studentList.searchItem(_newStudent);
    
    if(_searchResult==NULL){
        std::cout<<"**************************************************************************"<<std::endl;
        std::cout << "**\t\t\t  There is no student information at this moment!  \t\t\t**"<<std::endl;
        
    }
    else{
        std::cout<<"**************************************************************************"<<std::endl;
        std::cout<< "ID:"<<_searchResult->getID()<<"\t\t\tName:"<<_searchResult->getName()<<std::endl;
    }
    delete _searchResult;
    _searchResult=nullptr;
}

/*______________________________________________________
*
* provide an iterator to access items from front to back
*
*-----------------------------------------------------*/
void printForward(DCircularList<Student> &_studentList){
    std::cout<<"**************************************************************************"<<std::endl;
    std::cout<<"**\t\t\t\t\t\t\t\tStudent Information\t\t\t\t\t\t**"<<std::endl;
    if(_studentList.size()==0){
        std::cout << "**\t\t\t  There is no student information at this moment!  \t\t\t**"<<std::endl;
    }
    
    MyIterator<Student> _it (_studentList);
    if(!_it.isNull()){
        for(_it.start();_it.hasNext();_it++){
            std::cout<< "ID:"<<_it.getForwardCurrent()->getID()<<"\t\t\tName:"<<_it.getForwardCurrent()->getName()<<std::endl;
        }
    }
    
    
}

/*______________________________________________________
*
* provide an iterator to access items from back to front
*
*-----------------------------------------------------*/

void printBackward(DCircularList<Student> &_studentList){
    std::cout<<"**************************************************************************"<<std::endl;
    std::cout<<"**\t\t\t\t\t\t\t\tStudent Information\t\t\t\t\t\t**"<<std::endl;
    if(_studentList.size()==0){
        std::cout << "**\t\t\t  There is no student information at this moment!  \t\t\t**"<<std::endl;
    }
    
    MyIterator<Student> _it (_studentList);
    if(!_it.isNull()){
        for(_it.start();_it.hasPrev();_it--){
            std::cout<< "ID:"<<_it.getBackwardCurrent()->getID()<<"\t\t\tName:"<<_it.getBackwardCurrent()->getName()<<std::endl;
        }
    }
    
    
}

/*______________________________________________________
* check user input using regex_match
* \d{4}$ ------match pattern for 4 digits input
* if _id match, then return 1, else return 0
*
*-----------------------------------------------------*/
void checkInputById(std::string &_id){
    
    while(!regex_match(_id, std::regex("^\\d{4}$"))){
        std::cout<< "Input Format:Only 0-9 would be accepted.(Only 4 digits)";
        std::cout<< "Please re-enter the id of the student:";
        getline(std::cin,_id);
        
    }
}

/*______________________________________________________
* check user input using regex_match
* ^[A-Za-z.]+$+ ------match pattern for 52 alphabets(26 lower case letters, 26 upper case letters) and period
* if _id match, then return 1, else return 0
*
*-----------------------------------------------------*/

void checkInputByName(std::string &_name){
    
    while(!regex_match(_name, std::regex("^[A-Za-z.]+$"))){
        std::cout<< "Input Format:Only a-z and A-Z would be accepted.";
        std::cout<< "Please re-enter the name of the student:";
        getline(std::cin,_name);
        
    }
}


/*______________________________________________________
*
* Delete Student Infromation by Enter Student ID
* if cant find it, then print out not in the list
*   else print out the student information
*-----------------------------------------------------*/


void deleteStudentById(DCircularList<Student> &_studentList ){
    
    std::string _id;
    std::cout<<"**************************************************************************"<<std::endl;
    std::cout<< "Please the student ID (4 digits):";
    getline(std::cin,_id);
    checkInputById(_id);
    Student _newStudent;
    _newStudent.setID(_id);
    
    bool result=_studentList.deleteItem(_newStudent);
    if(result){
        std::cout<<"Succeeded! Deleted one student informaiton from the list!"<<std::endl;
    }else{
        std::cout<<"Failure! The student with ID "<<_id << " is not in the list."<<std::endl;
    }
    
}


/*______________________________________________________
*
* function used to insert at the front of the list
*-----------------------------------------------------*/

void insertStudentByHead(DCircularList<Student> &_studentList){
    
    std::string _name;
    std::string _id;
    std::cout<<"**************************************************************************"<<std::endl;
    std::cout<< "Please the name of the student:";
    getline(std::cin,_name);
    checkInputByName(_name);
    
    std::cout<< "Please the Student ID (4 digits):";
    
    getline(std::cin,_id);
    
    checkInputById(_id);
    
    Student _newStudent;
    _newStudent.setName(_name);
    _newStudent.setID(_id);
    
    bool result=_studentList.push_front(_newStudent);
    if(result){
        std::cout<<"Succeeded! Inserted one new student informaiton to the front!"<<std::endl;
    }else{
        std::cout<<"Failure! Do not enter student with same ID number!"<<std::endl;
    }
    
}


/*______________________________________________________
*
* function used to insert at the back of the list
*-----------------------------------------------------*/

void insertStudentByTail(DCircularList<Student> &_studentList){
    
    std::string _name;
    std::string _id;
    std::cout<< "Please the name of the student:";
    getline(std::cin,_name);
   
    checkInputByName(_name);
    std::cout<< "Please the student ID(4 digits):";
    
    getline(std::cin,_id);
    checkInputById(_id);
    
    Student _newStudent;
    _newStudent.setName(_name);
    _newStudent.setID(_id);
    
    bool result=_studentList.push_back(_newStudent);
    if(result){
        std::cout<<"Succeeded! Inserted one new student informaiton to the end!"<<std::endl;
    }else{
        std::cout<<"Failure! Do not enter student  with same ID number!"<<std::endl;
    }
    
}


/*______________________________________________________
*
* function used to clear all the student information
*-----------------------------------------------------*/
void clearStudents(DCircularList<Student> &_studentList){

    _studentList.clear();
    std::cout<< "Clear all the student information"<<std::endl;

}

void printMenus(){
    
    std::cout<<"**************************************************************************"<<std::endl;
    std::cout<<"**\t\t\t\t\t\t  Welcome to Student System  \t\t\t\t\t**"<<std::endl;
    std::cout<<"**\t\t\t\t  1.Insert Student Information to the Front   \t\t\t**"<<std::endl;
    std::cout<<"**\t\t\t\t  2.Insert Student Information to the Back   \t\t\t**"<<std::endl;
    std::cout<<"**\t\t\t\t  3.Show Total Student Number   \t\t\t\t\t\t**"<<std::endl;
    std::cout<<"**\t\t\t\t  4.Remove Student by Stuednt ID  \t\t\t\t\t\t**"<<std::endl;
    std::cout<<"**\t\t\t\t  5.Clear All Student Information     \t\t\t\t\t**"<<std::endl;
    std::cout<<"**\t\t\t\t  6.Search Student information bt student ID     \t\t**"<<std::endl;
    std::cout<<"**\t\t\t\t  7.Print Student information from front to back\t\t**"<<std::endl;
    std::cout<<"**\t\t\t\t  8.Print Student information from back to front\t\t**"<<std::endl;
    std::cout<<"**\t\t\t\t  9.Show Menus     \t\t\t\t\t\t\t\t\t\t**"<<std::endl;
    std::cout<<"**\t\t\t\t  0.Eixt   \t\t\t\t\t\t\t\t\t\t\t\t**"<<std::endl;
    std::cout<<"**************************************************************************"<<std::endl;
}
