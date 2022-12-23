/**
 * @file Vector.h
 * @author george_abdalah
 * @brief  this is the header file
 * @version 1
 * @date 2022-12-22
 * @copyright Copyright (c) 2022
 */


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


/**
 * @brief the friend function
 * @param out from type of ostream
 * @param v  is an object from class XYVector
 * @return ostream 
 * @details print the data of the object
 **/

// friend method
template<class T>
typename::ostream & operator<< (ostream &out, XYVector<T> v) {
    out << "your size is: " << v.get_size() << std::endl;
    out << "your capacity is: " << v.get_capacity() << std::endl;
    out << "your data is: [" << std::endl;
    for(int i = 0; i < v.get_size(); i++)
    {
        out << v.data[i] << std::endl;
    }
    cout <<"}" <<endl;
    return out;
}


// constructors


/**
 * @brief the default constructor
 * @details define the size = 0 , capacity = 5
 **/
template <class T>
XYVector<T>::XYVector() : size{0} , capacity{5}
{
    data = new T[capacity];
}


/**
 * @brief this is the second constructor
 * @param soize 
 * @details define size = 0 and capacity with the paramter soize and allocated new memory and heap and initializing it with nothing
 */
// constructor passing size
template <class T>
XYVector<T>:: XYVector(int soize) : size{0} , capacity{soize} {
    // checking if size is negative or too big
    if(soize > 1000000 || soize < 0)
    {
        throw std::bad_alloc();
    }
    data = new T[capacity];
    // filling array with nothing
    T inti{};
    for (int i = 0; i < capacity; ++i) {
        data[i] =  inti;
    }
}


/**
 * @brief this is the third constructor
 * @param t 
 * @param n 
 * @details fill in the private member variable data with the vector that in parameter
 */
template <class T>
XYVector<T>::XYVector(Iterator t, int n) : size{n} , capacity{n}
{
    data = new T[n];
    for(int i = 0; i < n;i++)
    {
        data[i] = t[i];
    }
}


/**
 * @brief this is the destructor.
 * @details used to delete the allocated memory in heap.
 */
// Destructor
template<class T>
XYVector<T>:: ~XYVector(){
    // freeing memory
    delete [] data;
}


/**
 * @brief constructor used to define a new allocated memory and put the data inside it.
 * @param vec 
 * @return template <class T> 
 */
// Copy assignment
template <class T>
XYVector<T>:: XYVector(const XYVector &vec) : size{vec.size} , capacity{vec.capacity} , data{new T [capacity]}{
    for (int i = 0; i < size; ++i) {
        this->data[i] = vec.data[i];
    }
}

// operators

/**
 * @brief this is an operator overloading for []
 * @param element 
 * @return template<class T>& 
 */
template<class T>
T & XYVector<T>::operator[](int element){
    if(element > capacity || element < 0){
        throw std::out_of_range("");
    }
    return data[element];
}


/**
 * @brief this is overloading for = operator 
 * @param copy 
 * @return XYVector<T>& 
 */
template<class T>
XYVector<T> & XYVector<T>::operator = (const XYVector &copy){
    this->data = new T [copy.capacity];
    this->size = copy.size;
    for(int i = 0; i < copy.size; ++i){
        this->data[i] = copy.data[i];
    }
    return *this;
}


/**
 * @brief this is the move assignment
 * @param move 
 * @return XYVector<T>& 
 */
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


/**
 * @brief this is overloading for operator ==
 * @param vec 
 * @return true & flase
 * @details this used to compare between size and each item inside array in each object
 */
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


/**
 * @brief operator < overloading
 * @param vec 
 * @return true & false
 * @details used to compate each item inside array
 */
template<class T>
bool XYVector<T>::operator < (const XYVector<T> &vec) {
    for (int i = 0; i < std::min(this->size , vec.size); ++i) {
        if(this->data[i] < vec.data[i]){
            return true;
        }
    }
    return false;
}


/**
 * @brief operator > overloading
 * @param vec 
 * @return true & false
 * @details used to compate each item inside array
 */
template<class T>
bool XYVector<T>::operator >(const XYVector<T> &vec) {
    return !XYVector<T>::operator<(&vec);
}



// Iterators


/**
 * @brief dealing with iterators
 * @return XYVector<T>::Iterator 
 * @details used to return pointer that point in first element in array
 */
template<class T>
typename XYVector<T>::Iterator XYVector<T>::begin() {
    return &data[0];
}


/**
 * @brief dealing with iterators
 * @return XYVector<T>::Iterator 
 * @details used to return pointer that point in last element in array
 */
template<class T>
typename XYVector<T>::Iterator XYVector<T>::end() {
    return &data[size - 1];
}


/**
 * @brief erase function
 * @param m 
 * @details used to delete the item that the iterator point to it.
 */
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


/**
 * @brief erase function with 2 iterator
 * 
 * @param itr1 
 * @param itr2 
 * @details used to delete the item between two iterators
 */
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


/**
 * @brief push back function
 * @param element 
 * @return void
 * @details used to put element inside the vector
 */
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


/**
 * @brief empty function
 * @return true & false
 * @details determine if size = 0 or not
 */
template<class T>
bool XYVector<T>::empty(){
    if(size == 0) return true;
    return false;
}


/**
 * @brief pop back function
 * @return void
 * @details used to delete the last element in vector
 */
template<class T>
void XYVector<T>::pop_back() {
    --size;
    // this->erase(this->end() , this->end());
}


/**
 * @brief resize function
 * @return int 
 * @details used to allocated a bigger memory
 */
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


/**
 * @brief print function
 * @return void
 * @details print the item inside vector
 */
template<class T>
void XYVector<T>::print(){
    for (int i = 0; i < size; ++i) {
        std::cout << data[i] << std::endl;
    }
}


/**
 * @brief get size function
 * @return int 
 * @details return size of vector
 */
template<class T>
int XYVector<T>::get_size() const {
    return size;
}


/**
 * @brief get capacity function
 * @return int 
 * @details return capacity of vector
 */
template<class T>
int XYVector<T>::get_capacity() const {
    return capacity;
}


/**
 * @brief clear function
 * @return void
 * @details Delete all vector content
 */
template<class T>
void XYVector<T>::clear(){
    this->size = 0;
    // initializing the vector
    for (int i = 0; i < capacity; ++i) {
        data[i] = NULL;
    }
}




#endif //VECTORSTL_VECTORHEADER_H

