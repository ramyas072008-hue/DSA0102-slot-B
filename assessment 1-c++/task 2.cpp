
#include <array>
#include <iostream>
using namespace std;

enum class Zone { Inner, Middle, Outer };

constexpr array<long long, 3> BASE_PAISE{
    1000, 2000, 3000
};
constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr long long MIN_BALANCE_PAISE = 5000;

int main() {
    Zone z = Zone::Middle;
    int index = static_cast<int>(z);

    cout << "Base fare: " << BASE_PAISE[index] << " paise\n";
    cout << "Peak surcharge: " << PEAK_SURCHARGE_PERCENT << "%\n";
    cout << "Minimum balance: " << MIN_BALANCE_PAISE << " paise\n";
}
