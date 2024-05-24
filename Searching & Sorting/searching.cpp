#include <iostream>
using namespace std;


// void BinarySearch(int arr[], int size, int numtofind){
//     int start = 0;
//     int end = size;
//     while(start <= end){
//         int mid = (start + end) / 2;
//         if(numtofind == arr[mid]){
//             cout<<"Element found at index " << mid << endl;
//             break;   
//         }else if(numtofind < arr[mid]){
//             end = mid-1;
//         }else{
//             start = mid+1;
//         }
//     } 
//     if (start > end) {
//         cout << "Element not found in the array" << endl;
//     }
// }

void LinearSearch(int arr[], int size, int numtofind){
    bool flag = false;
    for (int i = 0; i < size; i++){
        if(arr[i] == numtofind){
            flag = true;
            cout << "Element found at "<< i << endl;
            break;
        }
    }
    if(!flag){
        cout << "Element not found";
    }
}


void BinarySearch(int arr[], int size, int numtofind){
    int start = 0;
    int end = size;
    while (start <= end){
        int mid = (start+end)/2;
        if(numtofind == arr[mid]){
            cout << "Element found at " << mid << endl;
            break;
        }else if(numtofind > arr[mid]){
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    if(start > end){
    cout << "Element not found in the array" << endl;

    }

}





// FINAL PRACTICE
    // void LinearSearch(int arr[], int size, int numtoF){
    //     bool flag = false;
    //     for (int i = 0; i < size; i++){
    //         if (arr[i] == numtoF){
    //             flag = true;
    //             cout << "Element found at "<< "index " <<i;
    //             break;
    //         }
    //     }
    //     if(!flag){
    //             cout << "Element not found"<< endl;
    //     }
    // }

    // void BinarySearch(int arr[], int size, int numtoF){
    //     int st = 0;
    //     int end = size;
    //     while (st <= end){
    //         int mid = (st+end)/2;
    //         if(arr[mid] == numtoF){
    //             cout << "Element found at " << mid;
    //             break;
    //         }else if(numtoF < arr[mid]){
    //             end = mid-1;
    //         }else{
    //             st = mid+1;
    //         }
    //     }
    //     if (st > end){
    //         cout << "Element not found"<< endl;
    //     }
        
    // }
int main() {
    
    // int size;
    // cout << "Enter Size of Array"<< endl;
    // cin >> size;
    // int arr[size];
    // cout << "Enter the elemts of the Array" << endl;
    // for (int i=0; i<size; i++){
    //     cin >> arr[i]; 
    // }

    // int numtofind;
    // cout<<"enter the element to find"<<endl;
    // cin >> numtofind;

    // int choice;
    // cout << "Which Algorithm you will use" << endl;
    // cout << "1. Linear Search" << endl;
    // cout << "2. Binary Search" << endl;
    // cin >> choice;
    
    // if(choice == 1){
    //     LinearSearch(arr, size, numtofind);
    // }else{
    //     BinarySearch(arr, size, numtofind);
    // }

    


    // PRACTICE  // 
    int size;
    cout << "Enter the number of elements" << endl;
    cin >> size;
    cout << "Enter the elements of the array" << endl;
    int arr[size];
    for (int i = 0; i < size; i++){
        cin >> arr[i];        
    }
    
    int numtofind;
    cout << "Enter the element you want to find" << endl;
    cin >> numtofind;

    int choice;
    cout << "Which algorithm will you use for searching"<< endl;
    cout << "1. Linear Search" << endl;
    cout << "2. Binary Search" << endl;
    cin >> choice;

    if(choice == 1){
        LinearSearch(arr, size, numtofind);
    }else{
        BinarySearch(arr, size, numtofind);
    }
    return 0;
}