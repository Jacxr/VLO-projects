#include <iostream>
#include <vector>

using namespace std;

vector<int> dectobin(int n) {
    vector<int> bin;

    if (n == 0) {
        bin.push_back(0);  // Obsługa przypadku, gdy liczba wynosi 0
        return bin;
    }

    // Obliczanie bitów za pomocą przesunięcia bitowego
    while (n > 0) {
        bin.push_back(n & 1);  // Dodajemy najmłodszy bit (n & 1)
        n >>= 1;  // Przesuwamy bity w prawo o jeden (odrzucamy najmłodszy bit)
    }

    return bin;
}

// Funkcja wyświetlająca zawartość wektora binarnego
void printBin(const vector<int>& binaryVector) {
    // Wyświetlamy bity w odwrotnej kolejności (najstarszy bit na początku)
    for (int i = binaryVector.size() - 1; i >= 0; i--) {
        cout << binaryVector[i];
    }
    cout << endl;
}

int main() {
    int number;

    cout << "Podaj liczbe dziesietna nieujemna: ";
    cin >> number;

    // Zamiana liczby na system dwójkowy
    vector<int> binary = dectobin(number);

    // Wyświetlanie wyniku
    cout << "Liczba w systemie binarnym: ";
    printBin(binary);

    return 0;
}
