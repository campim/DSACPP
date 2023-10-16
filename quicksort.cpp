/* quick sort simple - c++ version with STL std::vector as a vector of integers -
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

/** global variables : global variables */
int iterations = 0;
std::vector<int> my_list;

/** swap : function to swap elements */
void swap(int *a, int *b) 
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

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

/** partition : function to rearrange array (find the partition point) */
int partition(int low, int high) 
{

    // select the rightmost element as pivot
    int pivot = my_list[high];

    // pointer for greater element
    int i = (low - 1);

    // traverse each element of the array - compare them with the pivot -
    for (int j = low; j < high; j++) 
    {
        if (my_list[j] <= pivot) 
        {
        // if element smaller than pivot is found swap it with the greater element pointed by i
        iterations++;
        i++;

        // swap element at i with element at j
        swap(&my_list[i], &my_list[j]);
        }
    }

    // swap pivot with the greater element at i
    swap(&my_list[i + 1], &my_list[high]);

    // return the partition point
    return (i + 1);
}

void quicksort(int low, int high) 
{
    if (low < high) 
    {
        /*find the pivot element such that elements smaller than pivot are on left of pivot
        elements greater than pivot are on righ of pivot */
        int pi = partition(low, high);

        // recursive call on the left of pivot
        quicksort(low, pi - 1);

        // recursive call on the right of pivot
        quicksort(pi + 1, high);
    }
}

int main()
{   
    int top_limit = 0;
    string inputstr;
    bool isInt = false;
    bool answer = false;

    cout << "*** quick sort - c++ - using vector of integers and random generated numbers array - ***" << endl;

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

    create_list(top_limit, top_limit);    

    cout << " unsorted array : " << endl;
    for (int i = 0; i < my_list.size(); i ++)
    {
        cout << my_list[i] << " ";
    }
    cout << " " << endl;

    quicksort(0, my_list.size() - 1);

    cout << " sorted array : " << endl;
    for (int i = 0; i < my_list.size(); i ++)
    {
        cout << my_list[i] << " ";
    }

    cout << " " << endl;
    cout << " iterations  : " << iterations << " " << endl;
    return 0;
}

