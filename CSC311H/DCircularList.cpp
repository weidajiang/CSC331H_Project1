//
//  DLinkedList.cpp
//  CSC311H
//
//  Created by Weida Jiang on 2/18/20.
//  Copyright © 2020 BMCC. All rights reserved.
//

#include "DCircularList.hpp"
#include <iostream>


/*______________________________________________________
*
* Default constructor
*-----------------------------------------------------*/

template <class T>
DCircularList<T> :: DCircularList(){
    
    head= new DCircularnode<T>();
    
    if(head){
        head->previous=head->next=head;   // create a circular list
        _size=0;
    }else{
        std::cerr<<"Fail to allocate element";
        std::exit(1);
    }
    
}


/*______________________________________________________
*
* Default destructor
*
*-----------------------------------------------------*/
template <class T>
DCircularList<T> ::~DCircularList(){

    this->clear();
    delete head;
    head = NULL;
    
}


/*______________________________________________________
*
* function can be called by operater=, copy constructor
*
*-----------------------------------------------------*/

template <class T>
void DCircularList<T>::copy(const DCircularList<T> &_other ){
    
    DCircularnode<T> *current = _other.head->next;
    while (current != _other.head)
    {
        this->push_back(current->data);
        current=current->next;
    }
    
}

template <class T>
void DCircularList<T>::operator=(const DCircularList<T> &_other ){
    
    if (this != &_other){
        this->clear()();
        this->copy(&_other);
    }
    
}



/*______________________________________________________
*
* Copy constructor
*-----------------------------------------------------*/
template <class T>
DCircularList<T> :: DCircularList(const DCircularList<T> &_other){
    
    head = new DCircularnode<T>();
    head->previous=head->next=head;
    this->copy(&_other);
}



/*______________________________________________________
 * insert data to the end of the list
 * ----------------------------------------------------*/
template <class T>
bool DCircularList<T> :: push_back(T &_newData){
    
    if(searchItem(_newData)){
        // do not insert data that already exist.
        return false;
    }else{
        DCircularnode<T> *_newNode = new DCircularnode<T>();
        // insert new element to the end of the list
        _newNode->data=_newData;
        _newNode->previous=head->previous;
        _newNode->next=head;
        head->previous=_newNode;
        _newNode->previous->next=_newNode;
        _size++;
        return true;
        
    }
    return false;
    
}


/*______________________________________________________
 * insert data to the beginning of the list
 * ----------------------------------------------------*/
template <class T>
bool DCircularList<T> :: push_front(T &_newData){
    
    T * temp=searchItem(_newData);
    if(temp != NULL){
        // do not insert data that already exist.
        return false;
    }else{
        DCircularnode<T> *_newNode = new DCircularnode<T>();
        // insert new element to the beginning of the list
        _newNode->data=_newData;
        _newNode->previous=head;
        _newNode->next=head->next;
        head->next=_newNode;
        _newNode->next->previous=_newNode;
        _size++;
        return true;
    }
    return false;
}

/*______________________________________________________
* check list is empty or not
* ----------------------------------------------------*/
template <class T>
bool DCircularList<T>::isEmpty() const{
    
    return this->_size==0?true:false;
    
}


/*______________________________________________________
* return list size
* ----------------------------------------------------*/
template <class T>
int DCircularList<T>::size() const{
    
    return this->_size;
    
}

/*______________________________________________________
* clear all the element.Keep list head
*
* ----------------------------------------------------*/
template <class T>
void DCircularList<T>::clear(){

    DCircularnode<T> *current = new DCircularnode<T>;
    current=head->next;
    while(current != head) {
        
        current->next->previous = current->previous;
        current->previous->next = current->next;
        delete current;
        _size--;
        current = current->next;
    }
    current=nullptr;
}

/*______________________________________________________
* funciton used to search a certain student, can be
* called by push_front and push_back to check if the
* student exist in the list or not
*
* ----------------------------------------------------*/
template <class T>
T * DCircularList<T>::searchItem(T &_data) {
    DCircularnode<T> *current=head->next;
    if(_size==0){
        return NULL;
    }else{
        while(current!=head){
            
            if(current->data ==_data){
                
                return &current->data;
                
            }else{
                current=current->next;
            }
        }
    }
    return NULL;
}

/*______________________________________________________
* funciton used to delete a certain student
* ----------------------------------------------------*/
template <class T>
bool DCircularList<T>::deleteItem( T &_data)  {
    
    if(_size==0){
        
        return false;
    }else{
        DCircularnode<T> *current=head->next;
        
        while(current!=head){
            if(current->data ==_data){
                
                current->next->previous = current->previous;
                current->previous->next = current->next;
                delete current;
                _size--;
                return true;
                
            }else{
                current=current->next;
            }
        }

    }
    
    return false;
    
}

