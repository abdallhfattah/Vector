//
// Created by abdal on 12/8/2022.
//

#ifndef VECTORSTL_VECTORHEADER_H
#define VECTORSTL_VECTORHEADER_H
#include <vector>
using namespace std;
template <class T>
class XYVector{
private:
    int size{},capacity;
    typedef T* Iterator;
    Iterator data;
public:
    XYVector();
    explicit XYVector (int);
    XYVector(const XYVector & vec);
    ~XYVector();
    XYVector (Iterator, int  n);

    // operators
    XYVector & operator =(XYVector && move) noexcept ;
    T & operator[](int element);
    XYVector & operator=(const XYVector & copy);
    bool operator==(const XYVector<T>& vec);      // Return true if ==
    bool operator< (const XYVector<T>& vec);
    bool operator> (const XYVector<T>& vec);// Compares item by item
    // Return true if first different item in this is < in other


    //iterators
    Iterator begin();
    Iterator end();

    //iterators operators


    // methods
    void push_back(T element);
    void pop_back();
    void print();
    bool empty();
    int resize();
    int get_size() const;     // Return current size of vec
    int get_capacity() const; // Return size of current allocated
    void clear();     // Delete all vector content
    void erase(Iterator);
    void erase(Iterator it1, Iterator it2);
    // friend
     friend ostream &operator <<( ostream& out, XYVector<T>);

};

// friend method
template<class T>
ostream & operator << (ostream &out, XYVector<T> & v) {
    out << "your size is: " << v.get_size() << std::endl;
    out << "your capacity is: " << v.get_capacity() << std::endl;
    out << "your data is: [" << std::endl;
    for(int i = 0; i < v.get_size(); i++)
    {
        out << v.data[i] << std::endl;
    }
}

// constructors
template <class T>
XYVector<T>::XYVector() : size{0} , capacity{5}
{
    data = new T[capacity];
}

// constructor passing size
template <class T>
XYVector<T>:: XYVector(int soize) : size{0} , capacity{soize} {
    // checking if size is negative or too big
    if(soize > 1000000 || soize < 0){
        throw std::bad_alloc();
    }
    data = new T[capacity];
    // filling array with nothing
    T inti{};
    for (int i = 0; i < capacity; ++i) {
        data[i] =  inti;
    }
}


template <class T>
XYVector<T>::XYVector(Iterator t, int n) : size{n} , capacity{n}
{
    data = new T[n];
    for(int i = 0; i < n;i++)
    {
        data[i] = t[i];
    }
}

// Destructor
template<class T>
XYVector<T>:: ~XYVector(){
    // freeing memory
    delete [] data;
}


// Copy assignment
template <class T>
XYVector<T>:: XYVector(const XYVector &vec) : size{vec.size} , capacity{vec.capacity} , data{new T [capacity]}{
    for (int i = 0; i < size; ++i) {
        this->data[i] = vec.data[i];
    }
}


// operators
template<class T>
T & XYVector<T>::operator[](int element){
    if(element > capacity || element < 0){
        throw std::out_of_range("");
    }
    return data[element];
}

template<class T>
XYVector<T> & XYVector<T>::operator = (const XYVector &copy){
    this->data = new T [copy.capacity];
    this->size = copy.size;
    for(int i = 0; i < copy.size; ++i){
        this->data[i] = copy.data[i];
    }
    return *this;
}

template<class T>
XYVector<T> & XYVector<T>:: operator = (XYVector && move) noexcept{
    if(this == &move){
        return *this;
    }
    delete [] data;
    size = move.size;
    capacity = move.capacity;
    data = move.data;
    move.data = nullptr;
    move.size = 0;
    move.capacity = 0;
}

template<class T>
bool XYVector<T>::operator==(const XYVector<T> & vec) {
    int _local_size = vec.size;
    if(this->size != _local_size) return false;
    else {
        for (int i = 0; i < _local_size; ++i) {
            if(this[i] != vec[i]) return false;
        }
        return true;
    }
}

template<class T>
bool XYVector<T>::operator < (const XYVector<T> &vec) {
    for (int i = 0; i < std::min(this->size , vec.size); ++i) {
        if(this->data[i] < vec.data[i]){
            return true;
        }
    }
    return false;
}

template<class T>
bool XYVector<T>::operator >(const XYVector<T> &vec) {
    return !XYVector<T>::operator<(&vec);
}

// Iterators
template<class T>
typename XYVector<T>::Iterator XYVector<T>::begin() {
    return &data[0];
}

template<class T>
typename XYVector<T>::Iterator XYVector<T>::end() {
    return &data[size - 1];
}

template<class T>
void XYVector<T>::erase(Iterator m) {
    auto temp  = new T [capacity];
    // copying old array elements to new array
    for(int i = 0, j =0; i < size; i++ , j++){
        if(&data[j] == m) j++;
        temp[i] = data[j];
    }
    // deleting previous array
    delete [] data;
    data = temp;
    size--;
}
template <class T>
void XYVector<T>::erase(Iterator itr1, Iterator itr2)
{
    if (itr1 > itr2)
    {
        throw std::invalid_argument("");
    }              //   itr1->6     itr2 ->8
    std::vector<T> vec; // 5 6 7 8 9
    bool flag = false;
    for (int i = 0; i < this->size ; ++i)
    {
        if(&data[i] == itr2){flag = false; continue;}
        else if(flag){continue;}
        else if(&data[i] == itr1){flag = true; continue;}
        vec.push_back(data[i]); // 5
    }
    delete[] data;
    data = new T [capacity];
    size = vec.size();
    for(int i = 0; i < vec.size(); i++){data[i] = vec[i];}
}



// methods
template<class T>
void XYVector<T>::push_back(T element)
{
    // if the number of elements is equal to the capacity, that means we don't have space to accommodate more elements
    // We need to double the capacity
    if(size >= capacity){
        auto temp  = new T [capacity * 2];
        // copying old array elements to new array
        for(int i = 0; i < capacity; i++){
            temp[i] =  data[i];
        }
        // deleting previous array
        delete [] data;
        data = temp;
        capacity *= 2;
    }
    // Inserting the element
    data[size++] = element;
}

template<class T>
bool XYVector<T>::empty(){
    if(size == 0) return true;
    return false;
}
template<class T>
void XYVector<T>::pop_back() {
    --size;
    // this->erase(this->end() , this->end());
}

template<class T>
int XYVector<T>::resize(){
    auto temp  = new T [capacity * 2];
    // copying old array elements to new array
    for(int i = 0; i < capacity; i++){
        temp[i] =  data[i];
    }
    // deleting previous array
    delete [] data;
    data = temp;
    capacity *= 2;
}

template<class T>
void XYVector<T>::print(){
    for (int i = 0; i < size; ++i) {
        std::cout << data[i] << std::endl;
    }
}

template<class T>
int XYVector<T>::get_size() const {
    return size;
}

template<class T>
int XYVector<T>::get_capacity() const {
    return capacity;
}

template<class T>
void XYVector<T>::clear(){
    this->size = 0;
    // initializing the vector
    for (int i = 0; i < capacity; ++i) {
        data[i] = NULL;
    }
}




#endif //VECTORSTL_VECTORHEADER_H







/*s


XYVector (int)			                     D              // Initialize by specific capacity
// No content is added, size = 0
// Assign a default size value               D
XYVector (const XYVector&)	                 D              // Initialize with a copy
~XYVector()			                         D             // Delete allocated memory

XYVector &operator=(const Vector&&);         D            // Move assignment


// Modifying operations
int push_back(T)                             D            // Add item to end of vec & return # of items
                                                            // Increase capacity of needed
// Comparison operations
bool operator==(const XYVector<T>&)      // Return true if ==
bool operator< (const XYVector<T>&)     // Compares item by item
                                        // Return true if first different item in this is < in other
================================================================================
void erase(iterator)          D                      // Remove item at iterator
                                                        // Throw exception if invalid iter
void insert(iterator, T)                            // Insert item at iterator
                                                    // Throw exception if invalid

// Iterators 		// Supports *, + and ++ operations at least
// Can use: typedef T* iterator
// Or u can use std::iterator, so you can
// apply STL algorithms on XYVector
iterator begin()	D // Return an iterator (T*)


// Friends
friend ostream& operator << (ostream& out, vector<T>)
===============================================================================
// Capacity operations
int resize()     D     // Relocate to bigger space
bool empty()     D    // Return true if size is 0

};*/

