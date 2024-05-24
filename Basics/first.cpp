// Your First C++ Program

#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

int main() {
    // cout << "Hello World!";

// *******  Input / Output ********    
    // int amount1;
    // cin >> amount1;

    // int amount2;
    // cin >> amount2;

    // int sum;
    // sum = amount1 + amount2;
    // cout << sum;


// *******  If / else ********
    // int savings;
    // cout << "enter your savings \n";
    // cin >> savings;
    // if(savings > 5000){
    //     if (savings > 10000){
    //     cout<< "Road trip with Neha";
    //     }else{
    //     cout<< "shopping with Neha";
    //     }
    //     // cout<< "Neha";
    // }else if(savings > 2000){
    //     cout<< "Suki";
    // }else{
    //     cout << "friends";
    // }

    // int a, b, c;
    // cin >>a>>b>>c;
    // if(a>b){
    //     if(a>c){
    //         cout << a<<endl;
    //     }else{
    //         cout << c<<endl;
    //     }
    // }
    // else{
    //     if (b>c){
    //         cout << b<<endl;
    //     }else{
    //         cout << c<<endl;
    //     }
    // }

    // int num;
    // cin >> num;
    // if(num % 2 == 0){
    //         cout <<"even"<<endl;
    // }else{
    //         cout <<"odd"<<endl;
    // }

// *******  Loops ********
    // int n;
    // cin >> n;
    // int sum=0;
    // for (int i = 1; i <= n; i++){
    //     sum+=i;
    // }
    // cout << sum;

    // int n;
    // cin >> n;
    // while(n > 0){
    // cin >> n;
    // }
    // cout << "whileloop end";

    // int n; 
    // cin >> n;
    // do{
    //     cout << n;
    //     cin >> n;
    // }while(n > 0);

// *******  Break and Continue ********
    // for(int i = 1; i <= 100; i++){
    //     if (i % 3 == 0 ){
    //         continue;
    //     }
    //     cout << i << endl;
    // }

    // int a,b;
    // cin >> a , b;
    // for(int num=a; num <=b; num++){
    //     int i;
    //     for (i=2; i < num; i++){
    //         if(num%i == 0){
    //             break;
    //         }
    //     }
    //     if(i==num){
    //         cout << num;
    //     }
    // }


// *******  Switch Statements ********
    // float num1,num2;
    // char op;
    // cin >> num1;
    // cin >> op;
    // cin >> num2;

    // switch(op){
    //     case '+':
    //         cout<< num1+num2<<endl;
    //         break;
    //     case '-':
    //         cout<< num1-num2<<endl;
    //         break;
    //     case '*':
    //         cout<< num1*num2<<endl;
    //         break;
    //     case '/':
    //         cout<< num1/num2<<endl;
    //         break;   

    //     default:
    //         cout << "invalid operator";
    //         break;
    // }








// ******* Arrays ********
    // int arr[4] = {10,20,30,40};

//     int size;
//     cout << "Enter the size of Array" << endl;
//     cin >> size;
//     int array[size];

//     cout << "Enter the items of Array" << endl;
//     for (int i = 0; i < size; i++)
//     {
//         cin>>array[i];
//     }
// // printing the aray
//     for (int i = 0; i < size; i++)
//     {
//         cout << array[i] << " ";
//     }
    


    // Pattern Questions

    // Rectangle
    // int rows, cols;
    // cin >> rows >> cols;
    // for(int i = 1 ;i <= rows; i++){
    //     for (int j = 1; j <=cols; j++){
    //         cout << "*";
    //     }
    //     cout << endl;
    // }


    // Hollow Rectangle
    // int rows, cols;
    // cin >> rows >> cols;
    //    for(int i = 1 ;i <= rows; i++){
    //     for (int j = 1; j <=cols; j++){
    //         if(i==1 || i == rows || j==1 || j==cols){
    //             cout << "*";
    //         }else{
    //             cout << " ";
    //         }
    //         // cout << endl;
    //     }
    //     cout << endl;

    // }

    //inverted Half Pyramid
    // int n;
    // cin >> n;
    // for(int i = n; i>=1; i--){
    //     for(int j=1; j<=i;j++){
    //         cout << "*";
    //     }
    //     cout << endl;
    // }

    // Half Pyramid after 180 rotation
    //    int n;
    // cin >> n;
    // for(int i = 1; i<=n; i++){
    //     for(int j=1; j<=n;j++){
    //         if(j <= n-i){
    //         cout << " ";
    //         }else{
    //         cout << "*";
    //         }
    //     }
    //     cout << endl;
    // }

// Half Pyramid using numbers
    // int n;
    // cin >> n;
    // for(int i = 1; i<=n; i++){
    //     for(int j=1; j<=i;j++){
    //         cout << i;
    //     }
    //     cout << endl;
    // }

// Floyds Triangle
    // int n;
    // cin >> n;
    // int count=1;
    // for(int i = 1; i<=n; i++){
    //     for(int j=1; j<=i;j++){
    //         cout << count << " "; 
    //         count++;
    //     }
    //     cout << endl;
    // }

// Butterfly
    //  int n;
    // cin >> n;
    // int count=1;
    // for(int i = 1; i<=n; i++){
    //     for(int j=1; j<=i;j++){
    //         cout << "*";
    //     }
    //     int space = 2*n - 2*i;
    //     for(int j=1; j<=space;j++){
    //         cout << " ";
    //     }
    //     for(int j=1; j<=i;j++){
    //         cout << "*";
    //     }   
    //     cout << endl;
    // }
    // for(int i = n; i>=1; i--){
    //     for(int j=1; j<=i;j++){
    //         cout << "*";
    //     }
    //     int space = 2*n - 2*i;
    //     for(int j=1; j<=space;j++){
    //         cout << " ";
    //     }
    //     for(int j=1; j<=i;j++){
    //         cout << "*";
    //     }   
    //     cout << endl;
    // }

// inverted Pattern
    // int n;
    // cin >> n;
    // for(int i = n; i>=1; i--){
    //     for(int j=1; j<=i;j++){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }


//  Prime Number
    // int num;
    // cin >> num;
    // bool flag = false;
    // for (int i = 2; i <= sqrt(num); i++)
    // {
    //     if(num % i == 0){
    //         cout << "Non-prime" << endl;
    //         flag = true;
    //         break;
    //     }
    // }
    // if(!flag){
    //     cout << "Prime"<<endl;
    // }

// Reverse a number    
    // int numb;
    // cin >> numb;
    // int ans=0;
    // while(numb > 0){
    //     int rem = numb % 10;
    //     ans = ans * 10 + rem;
    //     numb/=10;
    // }
    // cout << ans << endl;


// ArmStrong Number
    //     int numb;
    // cin >> numb;
    // int sum=0;
    // int originalNumber = numb;
    // while(numb > 0){
    //     int rem = numb % 10;
    //     sum = sum + pow(rem, 3);
    //     numb/=10;
    // }
    // if(sum == originalNumber){
    //     cout << "Armstrong Number";
    // }else{
    //     cout << "Not a Armstrong number";
    // }


    // 2D Arrays
    // int n, m;
    // cout << "Enter number of rows and cols"<< endl;
    // cin >> n >> m;
    // int arr[n][m];
    // for (int i = 0; i<n; i++){
    //     for (int j=0 ; j < m; j++){
    //         cout<< "Enter element at "<< i << " " << j << endl;
    //         cin >> arr[i][j];
    //     }
    // }

    //   for (int i = 0; i<n; i++){
    //     for (int j=0 ; j < m; j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout<< "\n";
    // }

// searching 2D Arrays
    // int n, m;
    // cout << "Enter number of rows and cols"<< endl;
    // cin >> n >> m;
    // int arr[n][m];
    // for (int i = 0; i<n; i++){
    //     for (int j=0 ; j < m; j++){
    //         cout<< "Enter element at "<< i << " " << j << endl;
    //         cin >> arr[i][j];
    //     }
    // }
    // int x;
    // cout << "Enter element to find"<< endl;
    // cin >> x;
    // bool flag= false;
    //   for (int i = 0; i<n; i++){
    //     for (int j=0 ; j < m; j++){
    //         if (arr[i][j] == x){    
    //         flag = true;
    //         cout << "element found at " << "row" << i << "col" << j<<endl;
    //         }
    //     }
    //     cout<< "\n";
    // }
    // if(flag== true){
    //     cout << "Element found" << endl;
    // }else{
    //     cout << "Element not found"<<endl;
    // }

    // character Array 
    // char arr[100] = "apple";  
    // int i = 0;
    // while (arr[i] != '\0')
    // {
    //     cout << arr[i] <<endl;
    //     i++;
    // }

    // char arr[20];
    // cin >> arr;
    // cout << arr;

    int n ;
    cin >> n;
    char arrr[n+1];
    cin >> arrr;
    bool check = false;
    for (int i =0; i<n; i++){
        if(arrr[i] != arrr[n-1-i]){
            check = true;
            break;
        }
    }
    if(check == true){
        cout << "word is not a palindrome"<< endl;
    }else{
        cout << "word a palindrome"<< endl;
        
    }
    return 0;
};