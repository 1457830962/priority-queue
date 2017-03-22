#include<iostream>
#include<string>
#include"PriorityQueue.cpp"

////////////////////////////////////////////////////////////////////////////////////////////////////////
//set below what data type you want for the queue..to change replace 'int' with the desired data type.//
////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef int type;

int main() {
     int priority, input;
     type data;
     priorityQueue<type> list(5);

     std::cout << "[[priority can be any integer between 1 and 5, 1 being the highest and 5 the lowest]]\n" << std::endl;

     /*prints out a menu for the user to choose from. the displayed menu is as::
     please choose what you want to do:
            1. add new
            2. remove one (also displays removed item)
            3. print
            4. exit
            : <user input>*/
     do {
          std::cout << "please choose what you want to do: \n\t\t1. add new\n\t\t2. remove one (also displays removed item)\n\t\t3. print\n\t\t4. exit\n\t\t: ";
          std::cin >> input;
          if (input == 1) {
               std::cout << "Enter the data and the priority(separated by space):  ";
               std::cin >> data >> priority;
               list.add(data, priority);
          }
          else if (input == 2)
               list.remove();
          else if (input == 3)
               list.print();
          else if (input == 4)
               return 0;
          else
               std::cout << "please enter either 1, 2, 3, or 4" << std::endl;
     } while (input != -1);

     return 0;
}
