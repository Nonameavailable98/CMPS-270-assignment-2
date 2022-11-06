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
//requires:
//2 non empty stacks
//effects:
//anew stack containing a’s items followed by b’s items

mystack operator + (mystack const &obj) 
{
mystack addedstacks;
addedstacks.n= n+obj.n;

  T *dbl = new T[addedstacks.n];
    delete[] addedstacks.array;
    addedstacks.array = dbl;
    

addedstacks.Top= num_of_elements+ obj.num_of_elements-1;
addedstacks.num_of_elements= num_of_elements+obj.num_of_elements;


for (int i=0; i<num_of_elements;i++)
{
    addedstacks.array[i]=array[i];
}
for(int i=0;i<obj.num_of_elements;i++)
{
    addedstacks.array[num_of_elements+i]=obj.array[i];
}
return addedstacks;
}
};
int main () 
{
    mystack <int> stack;
stack.push(3);
stack.pop();
stack.push(1);
stack.push(2);
stack.isEmpty();
int  tt=stack.top();
cout<< tt<<endl;

mystack <char> stack2;
stack2.push('e');

mystack <char> chartest;
chartest.push('d');
chartest.push('c');
chartest.push('b');
chartest.push('a');
mystack <char>charaddition ;

 charaddition =  stack2+chartest  ;
charaddition.pop();
charaddition.pop();
charaddition.pop();
charaddition.pop();
charaddition.pop();
charaddition.pop();





mystack <int> test1;
mystack <int> test2;
test1.push(1);
test1.push(2);
test1.push(3);
test2.push(4);
test2.push(5);
test2.push(6);
mystack <int> test3;
test3=test1+test2;
test3.pop();
test3.pop();
test3.pop();
test3.pop();
test3.pop();
test3.pop();
test3.pop();


    return 0;
}