#include<iostream>
#include<string>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////
//set below what data type you want for the queue..to change replace 'int' with the desired data type.//
////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef int type;

//priorityItem class is used by priorityQueue class. priorityQueue deals with a collection of objects of this class.
template<class T>
class priorityItem {
private:
     T data;
     //priority from 1-5. 1 is highest and 5 is lowest.
     int priority;
public:
     priorityItem() {
          priority = 5;
     }
     priorityItem(T data, int priority) {
          this->data = data;
          this->priority = priority;
     }
     void setData(T data) {
          this->data = data;
     }
     void setPriority(int priority) {
          this->priority = priority;
     }
     T getData() {
          return data;
     }
     int getPriority() {
          return priority;
     }
};

//class creates and deals with priority queues
class priorityQueue {
private:
     int size, count;
     priorityItem<type>* ptr;
public:
    //default constructor
     priorityQueue() {
          size = 5;
          count = 0;
          ptr = new priorityItem<type>[size];
     }
     //parameterized constructor
     priorityQueue(int size) {
          this->size = size;
          count = 0;
          ptr = new priorityItem<type>[size];
     }
     /*priorityCheck function is used by the add function to get the index
     where the new priorityItem type object is stored*/
     int priorityCheck(int priority){
          if (count == 1)
               return 0;
          else if (priority < ptr[0].getPriority()) {
               for (int i = (count - 1); i > 0; i--)
                    ptr[i] = ptr[i - 1];
               return 0;
          }
          else {
               for (int i = 0; i < (count - 1); i++) {
                    if (priority < ptr[i].getPriority()) {
                         for (int j = (count - 1); j > i; j--)
                              ptr[j] = ptr[j - 1];
                         return i;
                    }
               }
               return (count - 1);
          }
     }
     /*sizeCheck function is used by add and remove functions to check and
     balance the size of the priorityQueue as per given criteria which is
     (i)the queue should double in size when number of added elements equals
     the size of the queue; (ii)the queue should be made to equal the number
     of elements in the queue if the size is more than three times the number
     of elements in the queue*/
     void sizeCheck() {
          if (count == size - 1) {
               priorityItem<type>* temp = new priorityItem<type>[size];
               for (int i = 0; i < size; i++)
                    temp[i] = ptr[i];
               delete[] ptr;
               size *= 2;
               ptr = new priorityItem<type>[size];
               for (int i = 0; i < (count - 1); i++)
                    ptr[i] = temp[i];
               delete[] temp;
          }
          else if (3 * (count + 1) == size && count != 0) {
               priorityItem<type>* temp = new priorityItem<type>[count];
               for (int i = 0; i < (count - 1); i++)
                    temp[i] = ptr[i];
               delete[] ptr;
               size = size / 3;
               ptr = new priorityItem<type>[size];
               for (int i = 0; i < size; i++)
                    ptr[i] = temp[i];
               delete[] temp;
          }
     }
     //adds a new priorityItem type object to the priorityQueue based on the priority of the added object
     void add(type data, int priority) {
          count++;
          sizeCheck();
          int temp = priorityCheck(priority);
          ptr[temp].setData(data);
          ptr[temp].setPriority(priority);
          cout << "\t\tadded " << ptr[temp].getData() << " at " << temp << endl;
     }
     //removes the first element from the queue as it is a FIFO(first in first out) data structure
     void remove() {
          if (count > 0) {
               priorityItem<type> temp = ptr[0];
               for (int i = 0; i < (count - 1); i++)
                    ptr[i] = ptr[i + 1];
               count--;
               sizeCheck();
               cout << "\t\tremoved " << temp.getData() << endl;
          }
          else
               cout << "\t\tno more elements" << endl;
     }
     //print the elements of the queue grouped into their respective priorities
     void print() {
          if (count > 0) {
               for (int i = 0; i < count; i++) {
                    if(i == 0)
                        cout << "\t\tPriority " << ptr[0].getPriority() << ":" << endl;
                    cout << "\t\t" << ptr[i].getData() << endl;
                    if (ptr[i].getPriority() < ptr[i + 1].getPriority() && (count - 1) != i)
                         cout << "\t\tPriority " << ptr[i + 1].getPriority() << ":" << endl;
               }
          }
          else
               cout << "\t\tno data to print" << endl;
     }
     //class destructor
     ~priorityQueue() {
          delete[] ptr;
     }
};

int main() {
     int priority, input;
     type data;
     priorityQueue list(5);

     cout << "[[priority can be any integer between 1 and 5, 1 being the highest and 5 the lowest]]\n" << endl;

     /*prints out a menu for the user to choose from. the displayed menu is as::
     please choose what you want to do:
            1. add new
            2. remove one (also displays removed item)
            3. print
            4. exit
            : <user input>*/
     do {
          cout << "please choose what you want to do: \n\t\t1. add new\n\t\t2. remove one (also displays removed item)\n\t\t3. print\n\t\t4. exit\n\t\t: ";
          cin >> input;
          if (input == 1) {
               cout << "Enter the data and the priority(separated by space):  ";
               cin >> data >> priority;
               list.add(data, priority);
          }
          else if (input == 2)
               list.remove();
          else if (input == 3)
               list.print();
          else if (input == 4)
               return 0;
          else
               cout << "please enter either 1, 2, 3, or 4" << endl;
     } while (input != -1);

     return 0;
}
