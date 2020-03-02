//
//  DLinkedList.hpp
//  CSC311H
//
//  Created by Weida Jiang on 2/18/20.
//  Copyright © 2020 BMCC. All rights reserved.
//

#ifndef DCircularList_hpp
#define DCircularList_hpp

#include <stdio.h>
#include "MyIterator.hpp"
#include "Student.hpp"

template <class T> class MyIterator;
template <class T>
struct DCircularnode {
    friend class MyIterator<T>;
    T data;
    DCircularnode *previous;
    DCircularnode *next;
    
};

template <class T> class MyIterator;
template <class T>
class DCircularList{
     friend class MyIterator<T>;
protected:
   
    DCircularnode<T> *head;
    int _size;
    
public:
   
    DCircularList();
    virtual ~DCircularList();
    DCircularList(const DCircularList<T> &  );   // copy constructor
    void operator= (const DCircularList<T> &  );   // overloaded = operator
    void copy (const DCircularList<T> & );
    
    bool push_back( T &);
    bool push_front(T &);
    bool isEmpty() const;
    int size() const;
    void clear();
    T * searchItem(T &) ;
    bool deleteItem(T & )  ;
    
};

#endif /* DCircularList */
