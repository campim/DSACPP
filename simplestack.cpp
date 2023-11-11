/* simple stack of integers using STL
 Author Daniel G. Campos (2023)

 LICENSING
 This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public
 License as published by the Free Software Foundation; either version 2 of the License, or (at your option)
 any later version.
 This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
 implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 See the GNU General Public License for more details.
*/
#include<iostream>
#include<stack>

using namespace std;

/* global variables */
stack<int> my_stack;

/*we implement a simple stack of integers using Last In First Out (LIFO) principle.
  These are the basic operations for a stack : Push, Pop, IsEmpty, IsFull, Peek */

/** create_list : adds to the stack my_stack random numbers with 'top' as max number of items */
void create_list(int top)
{
    int i, j;
    srand(time(0));

    for(i = 0;i < top; i++) 
    {
        j = rand()%top;
        my_stack.push(j);
    }
}

/** add_integer : when we push a new item into the stack, we create a random integer */
int add_integer()
{
    int i;
    srand(time(0));

    return (i = rand()%30);
}

/** checkfull : check if stack is full , for this demo 30 items*/
bool checkfull()
{
    if (my_stack.size() == 30)
        return true;
    else
        return false;
}

/** checkempty : check if stack is empty */
bool checkempty()
{
    if (my_stack.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

/** print_stack : simple function to print all items in the stack, we use an auxiliary stack for this purpose */
void print_stack()
{
    int i;
    stack<int> aux_stack;
    
    while (!my_stack.empty()) {
        aux_stack.push(my_stack.top());
        my_stack.pop();
    }    

    while (!aux_stack.empty()) {
        cout << aux_stack.top() << " ";
        my_stack.push(aux_stack.top());
        aux_stack.pop();
    }    

    cout << endl;
}

int main()
{
    string inputstr;

    cout << "*** simple stack of integers - c++ - using STL - ***" << endl;
    cout << "*** I create a simple random list of integers    ***" << endl;
    cout << "*** and then we use push and pop to interact     ***" << endl;
    cout << "*** with it  - for this demo only 30 items -     ***" << endl;

    create_list(30); //this demo creates up to 30 items randomly generated to search for    

    cout << " list of integers created randomly  : " << endl;
    print_stack();

    while (inputstr != "q")
    {
        cout << "enter 'u' for push(we push random number), 'o' for pop , 'p' for peek  (q to quit):" << endl;
        cin >> inputstr;

        if (inputstr == "u")
        {
            if (checkfull())
            {
                cout << "stack is full, cannot push more items right now." << endl;
            }
            else
            {
                my_stack.push(add_integer());
                cout << "pushed random item, now stack is : " << endl;
                print_stack();
            }
        }
        if (inputstr == "o")
        {
            if (checkempty())
            {
                cout << "stack is empty, cannot pop more items right now." << endl;
            }
            else
            {
                my_stack.pop();
                cout << "popped last item, now stack is : " << endl;
                print_stack();
            }
        }
        if (inputstr == "p")
        {
            if (my_stack.size() > 0)
            {
                cout << "last item in the stack :" << my_stack.top() << endl ;
            }
            else
            {
                cout << "no items in the stack." << endl;
            }
        }
    }

    return 0;
}


