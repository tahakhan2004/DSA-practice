#include <iostream>
using namespace std;

void swap(int *a, int *b){
    int t = *a;
     *a = *b;
     *b = t;
}

// 1st Approach 
// void array_sum(int arr[], int size){
//     for (int i = 0; i<size; i++){
//         arr[i] += 5;
//     }

//     for (int i = 0; i<size; i++){
//         cout << " " <<arr[i];
//     }
// }


// 2nd Approach 
void array_sum(int * arr, int size){
    for (int i = 1; i<size;i++){
        *arr+=5;
        arr+=1;
    }
}


int main() {
    int a = 56;
    int * ptr;
    // cout << a << endl;    // ====> 56
    // cout << &a << endl;

    ptr = &a;
    // cout << ptr;
    // cout << *ptr;       // ===> 56    /  *(&a)   

    int b=95;
    ptr = &a;
    // *ptr = b;       // replace the value of a with b
    b = *ptr;
    // cout << b;b 



    // Swaping
    int x = 19;
    int y = 25;

    swap(&x,&y);
    // cout << x << " " << y;
    
    int size;
    cout << "Enter Size of Array"<< endl;
    cin >> size;
    int arr[size];
    cout << "Enter the elemts of the Array" << endl;
    for (int i=0; i<size; i++){
        cin >> arr[i]; 
    }

    array_sum(arr, size);
    for(int i =0 ; i< size; i++){
        cout << " " <<arr[i];
    }


    // pointers and arrays 
    int arra[] = {10, 20 ,30};
    // cout<<*arr;  // 10

    int *ptrr =arra;
    // for (int i = 0; i < 3; i++){
    //     cout << *ptrr <<endl;
    //     ptrr++;
    // }
    for (int i = 0; i < 3; i++){
        cout << *ptrr <<endl;
        ptrr++;
    }
    return 0;
}
