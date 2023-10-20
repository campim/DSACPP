/* heap sort - c++ version with STL std::vector as a vector of integers -
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

/** heapify : check elements left and right child and swap them respectively */
void heapify(int n, int i) 
{
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && my_list[left] > my_list[largest])
      largest = left;
  
    if (right < n && my_list[right] > my_list[largest])
      largest = right;
  
    // Swap and continue heapifying if root is not largest
    if (largest != i) 
    {
        iterations++;
        swap(my_list[i], my_list[largest]);
        heapify(n, largest);
    }
}

/** heapsort: build the heap and swap the values respectively */
void heapsort() 
{
    int n = my_list.size();
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);

    // Heap sort
    for (int i = n - 1; i >= 0; i--) 
    {
        iterations++;
        swap(my_list[0], my_list[i]);

        // Heapify root element to get highest element at root again
        heapify(i, 0);
    }
}

int main()
{   
    int top_limit = 0;
    string inputstr;
    bool isInt = false;

    cout << "*** heap sort version - c++ - ***" << endl;

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

    heapsort();

    cout << " sorted array : " << endl;
    for (auto it = my_list.begin(); it != my_list.end(); ++it) 
        cout << *it << " ";    
    cout << " " << endl;

    cout << " iterations  : " << iterations << " " << endl;
    return 0;

}

