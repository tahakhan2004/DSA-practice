#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num){
    for (int i =2; i <= sqrt(num) ; i++){
        if(num % i == 0){
            return false;
        }
    }

    return true;
}

void fibonacci(int n){
    int t1 = 0;
    int t2 = 1;
    for (int i =1; i<=n; i++){
        cout << t1<< endl;
        int nextTerm = t1+t2;
        t1 = t2;
        t2 = nextTerm;
    }
    return;
}

int fact(int num){
    int fac = 1;
    for (int i = num; i >=1; i--){
        fac*=i;
    }
    return fac;
}
int main(){
// Prints all prime numbers b/w a and b    
    // int a, b;
    // cin >> a >> b;
    // for (int i = a; i <= b ; i++){
    //     if(isPrime(i)){
    //         cout << i << endl;
    //     }
    // }


// fibonacci Sereies
    // int n;
    // cin >> n;
    // fibonacci(n);

// Factorial
    // int n;
    // cin >> n;
    // int ans = fact(n);
    // cout <<ans<<endl;     


// Calculating NCR
    // int n , r;
    // cin >> n >> r;
    // int NCR = fact(n) / (fact(r) * fact(n-r));
    // cout << NCR<< endl;

// Pascal Triangle
    int n;
    cin >> n;
    for (int i = 0; i <n; i++ ){
        for (int j = 0; j<=i; j++){
           cout << fact(i) / (fact(j) * fact(i-j)) << " ";
        }
        cout << endl;
    }    
}


