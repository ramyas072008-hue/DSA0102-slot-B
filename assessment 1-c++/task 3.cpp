
#include <climits>
#include <iostream>
using namespace std;

int main() {
    bool valid = true;
    char grade = 'A';
    int hour = 9;
    long long farePaise = 1200;
    float temperature = 30.5f;
    double approximateRupees = 12.0;
    auto journeys = 3000000LL;

    cout << "bool size: " << sizeof(valid) << '\n';
    cout << "char size: " << sizeof(grade) << '\n';
    cout << "int size: " << sizeof(hour) << '\n';
    cout << "long long size: " << sizeof(farePaise) << '\n';
    cout << "float size: " << sizeof(temperature) << '\n';
    cout << "double size: " << sizeof(approximateRupees) << '\n';

    cout << "INT_MAX: " << INT_MAX << '\n';
    cout << "LLONG_MAX: " << LLONG_MAX << '\n';

    cout << "Fare in paise: " << farePaise << '\n';
    cout << "Journeys: " << journeys << '\n';

    long long totalPaise = journeys * 3000LL;
    cout << "Network total (paise): " << totalPaise << '\n';
}
