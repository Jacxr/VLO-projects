#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;

int Naive(int n) {
    int primes = 0;
    for (int k = 2; k <= n; k++) {
        bool isprime = true;
        for (int i = 2; i < k; i++) {
            if (k % i == 0) {
                isprime = false;
                break;
            }
        }
        if (isprime)
            primes += 1;
    }
    return primes;
}

int Even(int n) {
    int primes = 1;
    for (int k = 3; k <= n; k += 2) {
        bool isprime = true;
        for (int i = 3; i < k; i += 2) {
            if (k % i == 0) {
                isprime = false;
                break;
            }
        }
        if (isprime)
            primes += 1;
    }
    return primes;
}

int Sqrtp(int n) {
    int primes = 1;
    for (int k = 3; k <= n; k += 2) {
        bool isprime = true;
        for (int i = 3; i <= sqrt(k); i += 2) {
            if (k % i == 0) {
                isprime = false;
                break;
            }
        }
        if (isprime)
            primes += 1;
    }
    return primes;
}

int Sieve(int n) {
    vector<bool> numbers(n + 1, true);  // Zwiększamy rozmiar o 1, aby indeksy sięgały do n
    int count = 0;
    numbers[0] = numbers[1] = false;  // 0 i 1 nie są liczbami pierwszymi

    // Pętla do oznaczania wielokrotności liczb pierwszych jako niepierwsze
    for (int i = 2; i * i <= n; i++) {  // Tylko do pierwiastka z n
        if (!numbers[i])  // Pomijamy liczby już oznaczone jako niepierwsze
            continue;

        // Oznaczanie wielokrotności liczby i jako niepierwsze
        for (int j = i * i; j <= n; j += i) {
            numbers[j] = false;
        }
    }

    // Zliczanie liczb oznaczonych jako pierwsze
    for (bool value : numbers) {
        if (value)
            count++;
    }
    return count;
}

int main() {
    vector<int> quantities{1000, 10000, 100000, 1000000};

    // Mierzenie czasu dla Naive
    for (int value : quantities) {
        clock_t start_time = clock();
        int result = Naive(value);
        clock_t end_time = clock();
        double execution_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
        cout << "Naive(" << value << ") = " << result << " Czas: " << execution_time << " sekund" << endl;
    }

    // Mierzenie czasu dla Even
    for (int value : quantities) {
        clock_t start_time = clock();
        int result = Even(value);
        clock_t end_time = clock();
        double execution_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
        cout << "Even(" << value << ") = " << result << " Czas: " << execution_time << " sekund" << endl;
    }

    // Mierzenie czasu dla Sqrtp
    for (int value : quantities) {
        clock_t start_time = clock();
        int result = Sqrtp(value);
        clock_t end_time = clock();
        double execution_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
        cout << "Sqrtp(" << value << ") = " << result << " Czas: " << execution_time << " sekund" << endl;
    }

    // Mierzenie czasu dla Sieve
    for (int value : quantities) {
        clock_t start_time = clock();
        int result = Sieve(value);
        clock_t end_time = clock();
        double execution_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
        cout << "Sieve(" << value << ") = " << result << " Czas: " << execution_time << " sekund" << endl;
    }

    return 0;
}
