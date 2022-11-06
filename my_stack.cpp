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
};
int main () 
{
    return 0;
}