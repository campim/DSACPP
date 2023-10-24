/* linear search - simple - c++ version with STL std::vector as a vector of integers
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

int linearsearch(int value) 
{
    int i = 0;
    // Going through array sequencially
    for (int i = 0; i < my_list.size(); i++)
    {
        iterations++;
        if (my_list[i] == value) return i;
    }

    return -1;
}

int main()
{   
    int top_limit = 0;
    string inputstr;
    bool isInt = false;

    cout << "*** linear search - simple -  - version c++ - ***" << endl;

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
                top_limit = stoi(inputstr);
                break;
            }
        }
    }

    create_list(50); //this demo creates up to 50 items randomly generated to search for

    cout << " list created randomly  : " << endl;
    for (auto it = my_list.begin(); it != my_list.end(); ++it) 
        cout << *it << " ";    
    cout << " " << endl;    

    int result = linearsearch(top_limit);

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

