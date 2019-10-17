#include <iostream>
using namespace std;

class IntList {
public:
    IntList ( int size = 0 , int initvalue = 0);
    IntList ( const IntList & lis );
    ~ IntList ();
    int getSize () const { return size_ ; }
    IntList & operator =(const IntList & rhs );
    int getList()const {return *list_;}
    void setList(int x){*list_ = x;}
    void swap(int &first, IntList& second);
private :
    int * list_ ; // list of values ( int )
    int size_ ;
};

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


int main(){

    IntList L1 (5,0);


    //4- declare L2 and make that l2=l1 is properly working
    IntList L2 (10, 6);

    L2 = L1;


   return 0;
}
