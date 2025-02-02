// #include <iostream>
// using namespace std;

// void swap(int *a, int *b){
//     int t = *a;
//      *a = *b;
//      *b = t;
// }

// void MaxHeap(int arr[]){
//     for(int i =0 ; i < 10; i++){
//         cout << " " <<arr[i];
//     }
// }

// int main() {

//     int arra[10] = {78, 99 ,23, 63, 97, 55, 230, 117 , 70, 11};
//     MaxHeap(arra);


//     // pointers and arrays 
//     return 0;
// }



// #include <iostream>
// using namespace std;

// void swap(int *a, int *b){
//     int t = *a;
//      *a = *b;
//      *b = t;
// }

// int Maxheapify (int arr[], int i)
// {
//   int pf=  (i-1)/2;   
//   if(arr[pf]<arr[i])
//   {
//       swap(&arr[pf],&arr[i]);
//       Maxheapify(arr, pf);
//   }
//   return 0;
// }

// int Minheapify (int arr[], int i)
// {
//   int pf=  (i-1)/2;   
//   if(arr[pf]>arr[i])
//   {
//       swap(&arr[pf],&arr[i]);
//       Minheapify(arr, pf);
//   }
//   return 0;
// }

// void deletee(int arr[]){
//     // int c = 3000;
//     // swap(&arr[0], &arr[8]);
//     // swap(&arr[0], &c);
//     // Minheapify(arr, 8);
//     int temp = arr[0];
//     arr[0] = arr[8];
//     arr[8] = -1;
//     Minheapify(arr, 8); 

// }
// int main ()
// {
//   int arr[9] = { 78, 99, 23,63,97,55,230,117,11};

//     // for(int i=0; i<9;i++)
//     // {
//     //     Maxheapify (arr, i);
//     // }
    
//     for(int i=1; i<=9;i++)
//     {
//         Minheapify (arr, i);
//     }
     
//     deletee(arr);
//     for(int i=1; i<=9; i++)
//     {
//       cout << arr[i] << endl;
//     }
// }


#include <iostream>
#include <stdlib.h>
using namespace std;

void upHeapify(int arr[], int ci)
{
  int pi = (ci - 1) / 2;
  while (arr[ci] > arr[pi])
  {
    int tmp = arr[ci];   // swaping
    arr[ci] = arr[pi];
    arr[pi] = tmp;      
    ci = pi;      // swaping
    if (ci == 0)
      break;
    pi = (ci - 1) / 2;
  }
}

void insert(int arr[], int value, int size)
{
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == -1)
    {
      arr[i] = value;
      if (i != 0)
      {
        upHeapify(arr, i);
      }
      break;
    }
  }
}

void downHeapify(int arr[], int pi, int size)
{
  int lc = 2 * pi + 1;
  int rc = 2 * pi + 2;
  if (lc >= size)
  {
    return;
  }
  if (rc >= size)
  {
    if (arr[pi] < arr[lc])
    {
      int tmp = arr[lc];
      arr[lc] = arr[pi];
      arr[pi] = tmp;
    }
    return;
  }
  while (arr[pi] < arr[lc] || arr[pi] < arr[rc])
  {
    if (arr[lc] > arr[rc])
    {
      int tmp = arr[lc];
      arr[lc] = arr[pi];
      arr[pi] = tmp;
      pi = lc;
      lc = 2 * pi + 1;
      rc = 2 * pi + 2;
      if (lc >= size)
      {
        break;
      }
      if (rc >= size)
      {
        if (arr[pi] < arr[lc])
        {
          int tmp = arr[lc];
          arr[lc] = arr[pi];
          arr[pi] = tmp;
        }
        break;
      }
    }
    else
    {
      int tmp = arr[rc];
      arr[rc] = arr[pi];
      arr[pi] = tmp;
      pi = rc;
      lc = 2 * pi + 1;
      rc = 2 * pi + 2;
      if (lc >= size)
      {
        break;
      }
      if (rc >= size)
      {
        if (arr[pi] < arr[lc])
        {
          int tmp = arr[lc];
          arr[lc] = arr[pi];
          arr[pi] = tmp;
          break;
        }
      }
    }
  }
}

void deleteData(int arr[], int size)
{
  for (int i = size - 1; i >= 0; i--)
  {
    if (arr[i] != -1)
    {
      arr[0] = arr[i];
      arr[i] = -1;
      downHeapify(arr, 0, size);
      break;
    }
  }
  if (arr[0] == -1)
  {
    cout << "Heap is Empty " << endl;
  }
}

void heapSort(int arr[], int size)
{
  for (int i = 1; i < size; i++)
  {
    for (int j = size - i; j >= 0; j--)
    {
      if (arr[j] != -1)
      {

        int tmp = arr[j];
        arr[j] = arr[0];
        arr[0] = tmp;

        downHeapify(arr, 0, j);
        break;
      }
    }
  }
}

int main()
{
  int size;
  cout << "Enter size of an Array : ";
  cin >> size;
  int maxHeap[size];
  for (int i = 0; i < size; i++)
  {
    maxHeap[i] = -1;
  }
  int a;
  do
  {
    cout << "Enter 1 to Insert data " << endl
         << "Enter 2 to delete " << endl
         << "Enter 3 to print " << endl
         << "Enter 4 to apply heap sort " << endl
         << "Enter 5 to exit " << endl;
    cin >> a;
    if (a == 1)
    {
      int value;
      cout << "Enter value : ";
      cin >> value;
      insert(maxHeap, value, size);
    }
    else if (a == 2)
    {
      deleteData(maxHeap, size);
    }
    else if (a == 3)
    {
      for (int i = 0; i < size; i++)
      {
        cout << maxHeap[i] << " ";
      }
    }
    else if (a == 4)
    {
      heapSort(maxHeap, size);
    }
    else if (a == 5)
    {
      cout << "Quit" << endl;
    }
  } while (a != 5);
}