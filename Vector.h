//
// Created by abdal on 12/8/2022.
//

#ifndef VECTORSTL_VECTORHEADER_H
#define VECTORSTL_VECTORHEADER_H

template <class T>
class XYVector{
private:
    int size,capacity;
    T *data;
public:
    XYVector();
    explicit XYVector (int size);
    XYVector(const XYVector & vec);
    ~XYVector();
    XYVector (T* arr, int  n );    // Initialize by n items from arr


    // operators
    XYVector & operator =(XYVector && move) noexcept ;
    T & operator[](int element);
    XYVector & operator=(const XYVector & copy);

    //iterators

    // methods
    void push_back(T element);
    void print();
    bool empty();
    int resize();
    int get_size() const;     // Return current size of vec
    int get_capacity() const; // Return size of current allocated
    void clear();     // Delete all vector content

    // friend
    friend std::ostream & operator << (std:: ostream& out, XYVector<T>);

};


/*template<class T>
std::ostream &operator<<(std::ostream &out, XYVector<T>) {

}*/


// constructors
template <class T>
XYVector<T>::XYVector() : size{0} , capacity{5}
{
    data = new T[capacity];
}

// constructor passing size
template <class T>
XYVector<T>:: XYVector(int size) {
    // checking if size is negative or too big
    if(size > 1000000 || size < 0){
        throw std::bad_alloc();
    }
    this->size = size;
    capacity = size;
    data = new T[capacity];
    T inializer{};
    for (int i = 0; i < capacity; ++i) {
        data[i] =  inializer;
    }
}


template<class T>
XYVector<T>::XYVector(T * _arr, int n) : size{n}, capacity(n) , data{new T [n]}{
    for(int i = 0; i < size; i++){
        data[i] = _arr[i];
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


// push back elements
template<class T>
void XYVector<T>::push_back(T element)
{
    // if the number of elements is equal to the capacity, that means we don't have space to accommodate more elements
    // We need to double the capacity
    if(size == capacity){
        T *temp  = new T [capacity * 2];
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
int XYVector<T>::resize(){
    T *temp  = new T [capacity * 2];
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
    // inializing the vector
    T inializer{};
    for (int i = 0; i < capacity; ++i) {
        data[i] = inializer;
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

================================================================================
void erase(iterator)                                // Remove item at iterator
                                                    // Throw exception if invalid iter
void insert(iterator, T)                            // Insert item at iterator
                                                    // Throw exception if invalid

// Iterators 		// Supports *, + and ++ operations at least
// Can use: typedef T* iterator
// Or u can use std::iterator, so you can
// apply STL algorithms on XYVector
iterator begin()	// Return an iterator (T*)

// Comparison operations
bool operator==(const XYVector<T>&)      // Return true if ==
bool operator< (const XYVector<T>&)     // Compares item by item
                                        // Return true if first different item in this is < in other
// Friends
friend ostream& operator << (ostream& out, vector<T>)
===============================================================================
// Capacity operations
int resize()     D     // Relocate to bigger space
bool empty()     D    // Return true if size is 0

};*/
