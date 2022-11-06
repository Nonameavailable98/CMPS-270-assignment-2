#include <iostream>
using namespace std;
template <typename T>
class mystack 
{
private:
int n=100;
int Top=-1;
T* array = new T[n];
int num_of_elements=0;
public :
// requires:
// nothing 
// effects:
// doubles the size of the dynamic array holding the element
void enlarge()
 {


    T *dbl = new T[n*2];
    for (int i = 0; i < num_of_elements; i++) {
   
        dbl[i] = array[i];
    }
    delete[] array;
   
    array = dbl;
    n=2*n;
  
}
// requires:
// nothing 
// effects:
// pushes the given element

void push(const T &val) {
   if(this->num_of_elements==n)
   {
   enlarge();
   push(val);
   }
   else {
    this->num_of_elements++;
      this->Top++;
      array[this->Top]=val;
   }
}
// requires:
// nothing
// effects:
// returns true if the stack is empty and false otherwise
bool isEmpty()
{
    if (this-> Top == -1)
    {
        cout<< "the stack is empty\n";
        return true;
    }
    else 
    {
        cout<< "the stack is not empty\n";
        return false;
    }
}
//requires:
//at least 1 element in the stack
//returns:
//the elements at the top
T& top()
{
    return array[Top];
}
//requires:
//nothing
//effects:
//pops the element at the top of the stack
void pop() {
   if(this->Top<=-1)
   {
   cout<<"Stack Underflow"<<endl;

   }
   else {
      cout<<"The popped element is "<< array[this->Top] <<endl;
      this->Top--;
      num_of_elements--;
    
   }
}
};
int main () 
{
    return 0;
}