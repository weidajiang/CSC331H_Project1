//
//  MyIterator.hpp
//  CSC311H
//
//  Created by Weida Jiang on 2/19/20.
//  Copyright © 2020 BMCC. All rights reserved.
//

#ifndef MyIterator_hpp
#define MyIterator_hpp

#include <stdio.h>
#include "MyIterator.hpp"
#include "Student.hpp"
template <class T> class DCircularnode;
template <class T> class DCircularList;

template <class T>
class MyIterator {
   
private:
    DCircularnode<T> *current;
    const DCircularList<T> &list;
    
public:
    MyIterator<T>();
    MyIterator<T>(const DCircularList<T> &);
    bool isNull();
    bool hasNext();
    bool hasPrev();
    void  start();
    T * getForwardCurrent();
    T * getBackwardCurrent();
    
    void operator++(int);
    void operator--(int);

//    void operator=(int);
//    MyIterator<T>(const MyIterator<T> &);
   
  
    
   
};

#endif /* MyIterator_hpp */
