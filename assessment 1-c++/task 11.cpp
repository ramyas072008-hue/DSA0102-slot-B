
#include <array>
#include <iostream>
using namespace std;

enum class Zone { Inner, Middle, Outer };

constexpr array<long long, 3> FARES{
    1000, 2000, 3000
};

constexpr long long MIN_BALANCE = 5000;

bool isPeak(int hour) {
    return (hour >= 8 && hour < 10) ||
           (hour >= 17 && hour < 20);
}

long long calculateFare(Zone zone, int hour) {
    int index;

    switch (zone) {
        case Zone::Inner:  index = 0; break;
        case Zone::Middle: index = 1; break;
        case Zone::Outer:  index = 2; break;
        default: return -1;
    }

    long long fare = FARES[index];

    if (isPeak(hour))
        fare += fare * 20 / 100;

    return fare;
}

class SmartCard {
private:
    long long balance;

public:
    explicit SmartCard(long long initial)
        : balance(initial >= 0 ? initial : 0) {}

    bool pay(long long fare) {
        if (fare < 0 || balance < fare ||
            balance - fare < MIN_BALANCE)
            return false;

        balance -= fare;
        return true;
    }

    long long getBalance() const { return balance; }
};

int main() {
    SmartCard card(10000);
    long long fare = calculateFare(Zone::Inner, 8);

    cout << "Calculated fare: " << fare << " paise\n";

    if (card.pay(fare))
        cout << "Payment successful\n";
    else
        cout << "Payment denied\n";

    cout << "Remaining balance: "
         << card.getBalance() << " paise\n";
}
