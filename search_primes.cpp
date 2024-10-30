#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int Naive(int n){
    int primes = 0;
    for(int k = 2; k <= n; k++){
        bool isprime = true;
        for(int i = 2; i < k; i++){
            if(k % i == 0){
                isprime = false;
                break;
            }
        }
        if(isprime)
            primes += 1;
    }
    return primes;
}


int Even(int n){
    int primes = 1;
    for(int k = 3; k <= n; k+=2){
        bool isprime = true;
        for(int i = 3; i < k; i+=2){
            if(k % i == 0){
                isprime = false;
                break;
            }
        }
        if(isprime)
            primes += 1;
    }
    return primes;
}


int Sqrtp(int n){
    int primes = 1;
    for(int k = 3; k <= n; k+=2){
        bool isprime = true;
        for(int i = 3; i < sqrt(k); i+=2){
            if(k % i == 0){
                isprime = false;
                break;
            }
        }
        if(isprime)
            primes += 1;
    }
    return primes;
}

/*
bool Sieve(int n){

}

*/

int main(){
    vector<int> quantities{1000, 10000, 100000, 1000000};
    for(int value : quantities){
        cout << Sqrtp(value) << endl;
    }

    return 0;
}