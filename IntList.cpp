//
// Created by Raniery Costa Mendes on 10/17/19.
//
#include "IntList.h"
IntList::IntList ( int size  , int initvalue) {
    if( size > 0){
        list_ = new int[ size ];
        size_ = size ;
        for( int i = 0; i < size_ ; i ++)
            list_ [i] = initvalue ;
    }
    else {
        list_ = 0;
        size_ = 0;
    }

}

//1) write a definition for the destructor

IntList :: ~ IntList () {
    cout << "Calling the destructor" << endl;
    delete list_;
}


//2) fix the copy constructor

IntList :: IntList ( const IntList & L ){

    cout << "Copy Constructor called." << endl;

    list_ = new int;
    *list_ = *(L.list_);

}


//3) rewrite the copy assignment operator using an optimized method
IntList& IntList:: operator =( const IntList &rhs ) {


    IntList temp(rhs);

    swap(this->list_, rhs.list_);

    return *this;

}


void IntList ::swap(int &first, IntList &second) {

    for (int i = 0; i < first.size_ ; ++i) {
        second[i] = first[i];

    }



}


