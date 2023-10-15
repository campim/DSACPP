/* counting sort - c++ version with STL std::vector as a vector of integers -
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
#include<vector> 

using namespace std;

/* global variables */
int iterations = 0;
std::vector<int> my_list;

/** create_list : adds to the int vector my_list random numbers with 'top' as max number of items and max value */
void create_list(int top)
{
    int i, j;
    my_list.resize(top);
    srand(time(0));

    for(i = 0;i < top; i++) 
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

void countingsort()
{
    int output[my_list.size()];
    int count[my_list.size()];
    int max = my_list[0];

    // Find the largest element of the array
    for (int i = 1; i < my_list.size(); i++) 
    {
        iterations++;
        if (my_list[i] > max)
            max = my_list[i];
    }    

    // Initialize count array with all zeros.
    for (int i = 0; i <= max; ++i) 
    {
        iterations++;
        count[i] = 0;
    }    

    // Store the count of each element
    for (int i = 0; i < my_list.size(); i++) 
    {
        iterations++;
        count[my_list[i]]++;
    }    

    // Store the cummulative count of each array
    for (int i = 1; i <= max; i++) 
    {
        iterations++;
        count[i] += count[i - 1];
    }

    // Find the index of each element of the original array in count array, and
    // place the elements in output array
    for (int i = my_list.size() - 1; i >= 0; i--) 
    {
        iterations++;
        output[count[my_list[i]] - 1] = my_list[i];
        count[my_list[i]]--;
    }    

    // Copy the sorted elements into original array
    for (int i = 0; i < my_list.size(); i++) 
    {
        iterations++;
        my_list[i] = output[i];
    }
}

int main()
{   
    int top_limit = 0;
    string inputstr;
    bool isInt = false;
    bool answer = false;

    cout << "*** counting sort - c++ - using vector of integers and random generated numbers array - ***" << endl;

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

    create_list(top_limit);    

    cout << " unsorted array : " << endl;
    for (int i = 0; i < my_list.size(); i ++)
    {
        cout << my_list[i] << " ";
    }
    cout << " " << endl;

    countingsort();

    cout << " sorted array : " << endl;
    for (int i = 0; i < my_list.size(); i ++)
    {
        cout << my_list[i] << " ";
    }
    cout << " " << endl;
    cout << " iterations  : " << iterations << " " << endl;
    return 0;
}


