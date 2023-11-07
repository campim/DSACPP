/* binary search - simple - c++ version with STL std::vector as a vector of integers
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

/** swap : function to swap elements */
void swap(int *a, int *b) 
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
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

/** quicksort : we use quicksort to order our list */
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

int binarysearch(int value, int low, int high, string i_or_r)
{
    int mid = 0;

    if (i_or_r == "i")
    {
        //iterative method
        while (low <= high)
        {
            iterations++;
            mid = low + (high - low) / 2;
            if (my_list[mid] == value) {
                return mid;
            } else if (my_list[mid] < value) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    if (i_or_r == "r")
    {
        //recursive method
        if (high >= low)
            iterations++; 
            mid = low + (high - low) / 2;

            // If found at mid, then return it
            if (my_list[mid] == value) {
                return mid;
            } // Search the left half
            else if (my_list[mid] > value) {
                return binarysearch(value, low, mid - 1, "r");
            }  // Search the right half
            else {
                return binarysearch(value, mid + 1, high, "r");
            }
    }

    return -1;
}


int main()
{   
    int search_value = 0;
    string inputstr;
    bool isInt = false;
    string iter_or_recursive = "";

    cout << "*** binary search - simple -  - version c++ -         *** " << endl;
    cout << "*** using quick sort as ordering algorithm            *** " << endl;
    cout << "*** Binary search can be implemented only on a sorted *** " << endl;
    cout << "*** list of items.If the elements are not sorted      *** " << endl;
    cout << "*** already, we need to sort them first. Also, we can *** " << endl;
    cout << "*** choose to use iterative or recursive method.      *** " << endl;

    while (!isInt)
    {
        cout << "Please enter an integer to search for up to 50 (for this demo):" << endl;
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
                search_value = stoi(inputstr);
                break;
            }
        }
    }

    create_list(50); //this demo creates up to 50 items randomly generated to search for

    iter_or_recursive = "i";  //by default, we use interactive method
    while (iter_or_recursive == "i" || iter_or_recursive == "r")
    {
        cout << "Please enter which method to use (i=iterative (default) r=recursive):" <<  endl;
        cin  >> inputstr;
        if (inputstr == "i")
        {
            cout << "using iterative method for binary search." << endl;
            iter_or_recursive = inputstr;
            break;
        }
        if (inputstr == "r")
        {
            cout << "using recursive method for binary search." << endl;
            iter_or_recursive = inputstr;
            break;
        }
    }

    cout << " list created randomly  : " << endl;
    for (auto it = my_list.begin(); it != my_list.end(); ++it) 
        cout << *it << " ";    
    cout << " " << endl;    

    quicksort(0, my_list.size() - 1);

    cout << " list after quick sort  : " << endl;
    for (auto it = my_list.begin(); it != my_list.end(); ++it) 
        cout << *it << " ";    
    cout << " " << endl;    

    cout << " iterations  : " << iterations << " " << endl;

    iterations = 0;

    int result = binarysearch(search_value, 0, my_list.size() - 1, iter_or_recursive);

    if (result > 0)
    {
        cout << "search value is found! at index : " << result << " position : " << (result+1) << " " << endl;
    }
    else
    {
        cout << "item is not found." << " " << endl;
    }

    cout << " iterations  : " << iterations << " " << endl;
    return 0;

}