#include <iostream>
using namespace std;


// linear Probing 

void insert(int arr[], int size)
{
    //    cout << "Enter the elemts of the Array" << endl;
    int value;
    cout << "Enter the value" << endl;
    cin >> value;
    int ind = value % size;
    int hold = ind;
    while (arr[ind] != -1)
    {
        int i = 1;
        ind = ind+1;
        if (ind == size)
        {
            ind = 0;
        }

        if (ind == hold)
        {
            cout << "Array is Full" << endl;
            break;
        }
    }

    if(arr[ind] == -1){
        arr[ind] = value;
        cout << "Value entered at " << ind << " value is " << arr[ind] << endl; 
    }
}

void search(int arr[], int size)
{
    int value;
    cout << "Enter the value to search" << endl;
    cin >> value;
    int ind = value % size;
    int hold = ind;
    while (arr[ind] != value)
    {
        int i = 1;
        ind = ind+1;
        if (ind == size){
            ind = 0;
        }
        if (ind == hold){
            cout << "No Data Found!" << endl;
            break;
        }
    }

    if(arr[ind] == value){
      cout<<"value entered is found at index number :  "<< ind<<endl;
    }
}


void print(int list[],int len)
{
    
    for (int i = 0; i < len; i++)
    {
        cout<<i<<"  "<<list[i]<< endl;
    }
}
int main()
{
    int size;
    cout << "Enter Size of Array" << endl;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = -1;
    }

    int a;
    while (true)
    {
        cout << "\nIf you want to enter data press 1" << endl;
        cout << "If you want to search press 2" << endl;
        cout << "If you want to print press 3" << endl;
        cout << "If you want to end process press 4" << endl;
        cout << "Your choice: ";
        cin >> a;

        if (a == 1){
            insert(arr, size);
        }
        else if (a == 2){
            search(arr, size);
        }
        else if (a == 3){
            print(arr, size);
        }
         else if (a == 4){
            break;
        }
    }

    //  for (int i=0; i<size; i++){
    //            cout << arr[i] << endl;

    //     }

    // int choice;
    // cout << "Which Algorithm you will use" << endl;
    // cout << "1. Linear Search" << endl;
    // cout << "2. Binary Search" << endl;
    // cin >> choice;
}