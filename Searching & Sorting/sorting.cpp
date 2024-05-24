#include <iostream>
using namespace std;

// void SelectionSort(int array[], int size){
//     for(int i = 0; i < size-1; i++){
//         for (int j=i+1; j < size; j++){
//             if (array[i]>array[j]){
//                 int c = array[i];
//                 array[i] = array[j];
//                 array[j] = c;
//             }
//         }
//     }
//     cout << "array sorted through selection sort"<<endl;
//     for(int i=0; i < size;i++){
//         cout << array[i]<<endl;
//     }
// }

// void BubbleSort (int array[], int size){
//     for (int i = 0; i<size-1; i++){
//         for (int j=0; j<((size-i)-1); j++){
//             if(array[j] > array[j+1]){
//                 int c = array[j];
//                 array[j] = array[j+1];
//                 array[j+1] = c;
//             }
//         }
//     }
//     cout << "array sorted through bubble sort"<<endl;
//     for(int i=0; i < size;i++){
//         cout << array[i]<<endl;
//     } 
// }



// void InsertionSort (int array[], int size){
//     for (int i = 1; i < size; i++){
//         int current = array[i];
//         int j = i-1;
//         while (array[j] > current && j>=0){
//             array[j+1] = array[j];
//             j--;   
//         }
//         array[j+1] = current;
//         }

//        cout << "array sorted through Insertion sort"<<endl;
//     for(int i=0; i < size;i++){
//         cout << array[i]<<endl;
//     }   
//     }
   



// FINAL PRACTICE
    void SelectionSort(int arry[], int size){
        for (int i = 0; i < size-1; i++){
            for (int j = i+1; j < size; j++){
                if(arry[i] > arry[j]){
                    int c = arry[i];
                    arry[i] = arry[j];
                    arry[j] = c;
                }
            }
            
        }
    cout << "array sorted through selection sort"<<endl;
    for (int i = 0; i < size; i++){
        cout << arry[i] << endl;
    }
            
    }

    void BubbleSort(int arry[], int size){
        for (int i = 0; i < size-1; i++){
            for (int j = 0; j < ((size-i)-1); j++){
                if(arry[j] > arry[j+1]){
                    int temp = arry[j];
                    arry[j] = arry[j+1];
                    arry[j+1] = temp;
                }       
            }
        }

            cout << "array sorted through bubble sort"<<endl;
    for (int i = 0; i < size; i++){
        cout << arry[i] << endl;
    }
        
    }

    void InsertionSort(int arry[], int size){
        for (int i = 1; i < size; i++){
        int current = arry[i];
        int j = i-1;    
        while (arry[j] > current && j>=0){
            arry[j+1] = arry[j];
            j--;
        }
        arry[j+1] = current;
        
        }
               cout << "array sorted through Insertion sort"<<endl;
    for(int i=0; i < size;i++){
        cout << arry[i]<<endl;
    }   
        
    } 

int main() {
//     int size;
//     cout << "Enter the size of Array" << endl;
//     cin >> size;
//     int array[size];

//     cout << "Enter the items of Array" << endl;
//     for (int i = 0; i < size; i++) {
//         cin >> array[i];
//     }

//    int choice;
//     cout << "Which Algorithm you will Use for sorting" << endl;
//     cout << "1. Selection Sort" << endl;
//     cout << "2. Bubble Sort" << endl;
//     cout << "3. Insertion Sort" << endl;
//     cin >> choice;
    
//     if(choice == 1){
//         SelectionSort(array, size);
//     }else if (choice == 2){
//         BubbleSort(array, size);
//     }else if(choice == 3){
//         InsertionSort(array, size);
//     }



    int size;
    cout << "Enter the size of the array" << endl;
    cin >> size;
    cout << "Enter the elements of the array" << endl;
    int arr[size];
    for (int i = 0; i < size; i++){
        cin >> arr[i];
    }
    
   int choice;
    cout << "Which Algorithm you will Use for sorting" << endl;
    cout << "1. Selection Sort" << endl;
    cout << "2. Bubble Sort" << endl;
    cout << "3. Insertion Sort" << endl;
    cin >> choice;
    
    if(choice == 1){
        SelectionSort(arr, size);
    }else if (choice == 2){
        BubbleSort(arr, size);
    }else if(choice == 3){
        InsertionSort(arr, size);
    }



return 0;
}






// LeetCode Problem [sort an array]

// class Solution {
// public:
//     vector<int> sortArray(vector<int>& nums) {
//           for(int i = 0; i < (nums.size()-1); i++){
//         for (int j=i+1; j < nums.size(); j++){
//             if (nums[i] > nums[j]){
//                 int c = nums[i];
//                 nums[i] = nums[j];
//                 nums[j] = c;
//             }
//         }
//     }
//     return nums;
//     }
// };
// int main_32() {
//     vector<int> nums = {5,2,3,1};
//     Solution solution;  // Create an instance of the Solution class
//     vector<int> ret = solution.sortArray(nums);
//     // cout << ret;
//     return 0;  // Added return statement to indicate successful completion
// }