#include <iostream>
#include <vector>

using namespace std;

int main() {
    int number;
    vector<int> binary;

    cout << "Podaj liczbe dziesietna nieujemna: ";
    cin >> number;

    if (number == 0) {
        cout << "Liczba w systemie binarnym: 0" << endl;
        return 0;
    }

    // Zamiana liczby dziesiętnej na system dwójkowy
    while (number > 0) {
        binary.push_back(number % 2);  // Przechowujemy resztę z dzielenia
        number /= 2;  // Dzielimy liczbę przez 2
    }

    // Wyświetlamy bity od końca, aby uzyskać poprawną reprezentację dwójkową
    cout << "Liczba w systemie binarnym: ";
    for (int i = binary.size() - 1; i >= 0; i--) {
        cout << binary[i];
    }

    return 0;
}
