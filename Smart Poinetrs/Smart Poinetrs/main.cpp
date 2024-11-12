//creating smart pointer class.
#include <iostream>
using namespace std;

//template <typename T> //using C++ template
//used to treat different data types as one.

class smart_ptr
{
public:
    int* ptr_; //raw_ptr pointing to managed object.
    int* ref_; //pointer to a reference count.
    //every time we refer to ptr_, we inc ref_.
public:
//Function 1: default constructor:
    smart_ptr()
    {
    //job:
        //create a smart_ptr that is initialized to nullptr.
        //the reference count should be initialized to nullptr.
    //code:
        ptr_ = nullptr;
        ref_ = nullptr;
    } //close Function 1.

//Function 2: int ref_count():
    int ref_count() const
    {
    //job:
        //returns the reference count of the pointed to data.
        //return an int, not a ref to int.
    //code:
        return* ref_;
    } //close Function 2.
    
//Function 3: explicit smart_ptr(T* raw_ptr)
    //takes in a raw ptr w/ any type T.
//Also the parametarized constructor:
    explicit smart_ptr(int* raw_ptr) //will take in
    {
    //job:
        //explicit keyword:
        //1. prevents unintended conversions.
        //2. implicit conversions can lead to unexpected behavior.
        //3. explicit ensures you are explicitly converting when necessary.
        //create a smart_ptr that is initialized to raw_ptr.
        //the reference count should be one.
        //make sure it points to the same pointer as the raw_ptr.
    //code:
        ptr_ = raw_ptr;
        ref_ = new int(1);
    } //close Function 3.
    
//Function 4: copy constructor:
    smart_ptr(const smart_ptr& rhs)
    //rhs is existing object.
    {
    //job:
        //copy construct a pointer from rhs.
        //the reference count should be incremented by one.
    //code:
        //this is a shallow copy.
        //i was doing a deep copy initially.
        ptr_ = rhs.ptr_; //raw_ptr of new smart_ptr points to the raw_ptr that rhs is pointing to.
        ref_ = rhs.ref_; //ref_ of new smart_ptr is set to the ref_ of the rhs smart_ptr.
        if(ref_) //if ref_ pointing to address
        {
            (*ref_)++; //increments the ref_ of copy to 2.
        }
    } //close Function 4.
    
//Function 5: assigment operator:
    smart_ptr& operator=(const smart_ptr& rhs)
    {
    //job:
        //this assignment should make a shallow copy of the right-hand side's pointer data.
        //the reference count should be incremented as appropriate.
    //code:
      if(this != &rhs)
      {//self-assignment check
          delete ptr_;
          ptr_ = nullptr;

          if(rhs.ptr_ != nullptr)
            {
              ptr_ = new int(*rhs.ptr_);
            }
        } //close outer if.
      return *this;
    } //close Function 5.
}; //end smart_ptr class.

int main()
{
    //1. create a raw_ptr of int:
    int* x = new int(35);
    
    //2. create smart_ptr object & pass that raw_ptr:
    smart_ptr ptr1(x);
    
    //3. look at values:
    cout << ptr1.ptr_ << endl;
    cout << *ptr1.ptr_ << endl; //35
    cout << *ptr1.ref_ << endl; //1
    
    cout << "-----break-------"<< endl;
    //4. copy ptr1 object into a new one:
    smart_ptr ptr2(ptr1); //copy ptr1 into ptr2.
    //would this inc. ref of ptr1?
    
    //5. look at values:
    cout << ptr1.ptr_ << endl;
    cout << *ptr1.ptr_ << endl; //35
    cout << *ptr1.ref_ << endl; //2
    cout << ptr2.ptr_ << endl;
    cout << *ptr2.ptr_ << endl; //35
    cout << *ptr2.ref_ << endl; //2
    
    
    
    return 0;
}









