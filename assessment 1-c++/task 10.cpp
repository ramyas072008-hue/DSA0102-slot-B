
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    const long long farePaise = 3000;
    const long long journeys[] = {
        20000, 500000, 3000000
    };

    cout << fixed << setprecision(2);

    for (long long n : journeys) {
        long long exactPaise = n * farePaise;
        double totalRupees = n * 30.0;

        cout << "Journeys: " << n << '\n';
        cout << "Integer paise: " << exactPaise << '\n';
        cout << "Double rupees: " << totalRupees << '\n';
        cout << "-------------------\n";
    }
}
