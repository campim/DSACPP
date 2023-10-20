/* bucket sort - c++ version with STL std::vector as a vector of integers -
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
#include<algorithm> 

using namespace std;

/* global variables */
int iterations = 0;
std::vector<int> my_list;
std::vector<int> bucket[10]; //maximum numbers of buckets (for this demo)

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


/** insertionsort : this insertion function is specifically for this demo , uses bucket as global vector of integers*/
void insertionsort(int bucketindex)
{
    int n = bucket[bucketindex].size();

    for (int step = 1; step < n; step++) 
    {
        iterations++;
        int key = bucket[bucketindex][step];
        int j = step - 1;

        while (key < bucket[bucketindex][j] && j >= 0) 
        {
            bucket[bucketindex][j + 1] = bucket[bucketindex][j];
            --j;
        }

        bucket[bucketindex][j + 1] = key;
    }
}

/** bucketsort : this bucket sort functions uses bucket as global variable */
void bucketsort()
{
    // insert elements into different buckets.
    for (int i = 0; i < my_list.size(); i++) 
    {
        iterations++;
        bucket[int(abs((my_list[i] / 10)))].push_back(my_list[i]);
    }

   // sort individual buckets, we use the index of the buckets to tell the function which bucket to sort
    for (int i = 0; i < (sizeof(bucket)/sizeof(bucket[0])); i++) 
    {
        insertionsort(i);
    }

    // concatenate the result to the my_list again
    int index = 0;
    for (int i = 0; i < my_list.size(); i++) 
    {
        iterations++;
        while (!bucket[i].empty()) 
        {
            my_list[index++] = *(bucket[i].begin());
            bucket[i].erase(bucket[i].begin());
        }
    }    
}

int main()
{   
    int top_limit = 0;
    string inputstr;
    bool isInt = false;

    cout << "*** bucket sort version - c++ - ***" << endl;

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
    for (auto it = my_list.begin(); it != my_list.end(); ++it) 
        cout << *it << " ";    
    cout << " " << endl;    

    bucketsort();

    cout << " sorted array : " << endl;
    for (auto it = my_list.begin(); it != my_list.end(); ++it) 
        cout << *it << " ";    
    cout << " " << endl;

    cout << " iterations  : " << iterations << " " << endl;
    return 0;

}