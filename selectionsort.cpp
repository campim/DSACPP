/* selection sort - c++ version with STL std::vector as a vector of integers
 Author Daniel G. Campos (2022)

 LICENSING
 This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public
 License as published by the Free Software Foundation; either version 2 of the License, or (at your option)
 any later version.
 This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
 implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 See the GNU General Public License for more details.
*/

#include <iostream>
#include<vector> 

using namespace std;

/* global variables */
int iterations = 0;
std::vector<int> my_list;

/** create_list : adds to the int vector my_list random numbers with 'top' as max number and 'quantity' as number of items of the vector*/
void create_list(int top, int quantity)
{
    int i, j;
    my_list.resize(quantity);
    srand(time(0));

    for(i = 0;i < quantity; i++) 
    {
        j = rand()%top;
        my_list[i] =  j;
    }
}

/** checkInteger : check if the input data is an integer */
bool checkInteger(string inputstr)
{
    bool isNeg = false;
    int  itr   = 0;

    if (inputstr.size()==0)
        return false;

    if (inputstr[0]=='-')
    {
        isNeg = true;
        itr = 1;
    }

    for (int i = itr; i<inputstr.size(); i++)
    {
        if (!isdigit(inputstr[i]))
            return false;
    }
    return true;
}

/** selectionsort: main function to sort an array, ascending or descending option */
void selectionsort(int order)
{
    int n = my_list.size();

    for (int step = 0; step < n - 1; step++) 
    {
        iterations++;
        int min_idx = step;
        for (int i = step + 1; i < n; i++) 
        {
            iterations++;
            if (order == 1)
            {
                //ascending order
                if (my_list[i] < my_list[min_idx])
                    min_idx = i;
            }
            else
            {
                if (my_list[i] > my_list[min_idx])
                    min_idx = i;
            }
        }
        // we use std::swap, here we can just use swap
        //swap(my_list[min_idx], my_list[step]);
        std::swap(my_list[min_idx], my_list[step]);
    }
}

int main()
{   
    int top_limit = 0, quantity_items = 0;
    string inputstr;
    bool isInt = false;
    int order = 1;  // ascending order by default
    bool answer = false;

    cout << "*** selection sort - c++ - ***" << endl;

    while (!isInt)
    {
        cout << "Please enter an integer up to 50 (for this demo) for the integer limit :" << endl;
        cin >> inputstr;
        bool isInt = checkInteger(inputstr);
        if (!isInt)
        {
            cout << " Please enter only integers " << endl;
        }
        else
        {
            if ( (stoi(inputstr)) > 50)
            {
                isInt = false;
            }
            else
            {
                top_limit = stoi(inputstr);
                break;
            }
        }
    }

    isInt = false;

    while (!isInt)
    {
        cout << "Please enter an integer up to 20 (for this demo) for the amount of items :" << endl;
        cin >> inputstr;
        bool isInt = checkInteger(inputstr);
        if (!isInt)
        {
            cout << " Please enter only integers " << endl;
        }
        else
        {
            if ( (stoi(inputstr)) > 20)
            {
                isInt = false;
            }
            else
            {
                quantity_items = stoi(inputstr);
                break;
            }
        }
    }

    while (!answer)
    {
        cout << "Please select which order to sort : 1=ascending 2=descending (1 is default):" << endl;
        cin >> inputstr;
        bool isInt = checkInteger(inputstr);
        if (!isInt)
        {
            cout << "Please enter only valid values (1 or 2) " << endl;
        }
        else
        {
            if ( (stoi(inputstr)) > 2 )
            {
                answer = false;
            }
            else
            {
                order = stoi(inputstr);
                break;
            }
        }
    }

    create_list(top_limit, quantity_items);

    cout << " unsorted array : " << endl;
    for (int i = 0; i < my_list.size(); i ++)
    {
        cout << my_list[i] << " ";
    }
    cout << " " << endl;

    selectionsort(order);

    cout << " sorted array : " << endl;
    for (int i = 0; i < my_list.size(); i ++)
    {
        cout << my_list[i] << " ";
    }
    cout << " " << endl;
    cout << " iterations  : " << iterations << " " << endl;
    return 0;
}