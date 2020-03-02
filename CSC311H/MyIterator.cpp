//
//  MyIterator.cpp
//  CSC311H
//
//  Created by Weida Jiang on 2/19/20.
//  Copyright © 2020 BMCC. All rights reserved.
//

#include "MyIterator.hpp"
#include <iostream>

/*______________________________________________________
* Default constructor
* ----------------------------------------------------*/

template<class T>
MyIterator<T>::MyIterator(){
    current=nullptr;
    list=NULL;
}


/*______________________________________________________
* funciton used to initial the Iterator,must provide a
* DCircularList<T> data, otherwise it doesnot work
* @param  DCircularList<T> &list
* Class Aggregation, so initial list and current
* ----------------------------------------------------*/
template<class T>
MyIterator<T>::MyIterator(const DCircularList<T> &myList):list(myList),current(myList.head){
  
}

/*______________________________________________________
* funciton used to check list is empty or not
* ----------------------------------------------------*/
template <class T>
bool MyIterator<T>::isNull(){
    return current->next==list.head? true:false;
}

/*______________________________________________________
* funciton used to check list is empty or not
* circular list, condition: current->next==list.head
* ----------------------------------------------------*/
template <class T>
bool MyIterator<T>::hasNext(){
    return current->next==list.head?false:true;
}

template <class T>
bool MyIterator<T>::hasPrev(){
    return current->previous==list.head?false:true;
}

/*______________________________________________________
* move current to first element
* ----------------------------------------------------*/

template <class T>
void  MyIterator<T>::start(){
    if(isNull()){
       
    }else{
        current=list.head;
      
    }
}

/*______________________________________________________
* regular iterator from front to back
* ----------------------------------------------------*/
template <class T>
T * MyIterator<T>::getForwardCurrent(){

    return &current->next->data;
}

/*______________________________________________________
* reverse iterator from back to front
* ----------------------------------------------------*/

template <class T>
T * MyIterator<T>::getBackwardCurrent(){
 
    return &current->previous->data;
}



template <class T>
void MyIterator<T>::operator++(int ){
    
    if(!current){
        std::cout<< "No Next Element";
    
    }else{
        current=current->next;
     
    }
   
}

template <class T>
void MyIterator<T>::operator--(int ){
    
    if(!current){
        std::cout<< "No Previous Element";
      
    }else{
        current=current->previous;
      
    }
   
}



