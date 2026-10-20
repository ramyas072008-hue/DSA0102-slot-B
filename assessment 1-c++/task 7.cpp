
#include <iostream>
using namespace std;

constexpr long long MIN_BALANCE = 5000;

// Procedural approach
bool proceduralCanTravel(long long balance, long long fare) {
    return fare >= 0 && balance >= fare &&
           balance - fare >= MIN_BALANCE;
}

// Object-oriented approach
class SmartCard {
private:
    long long balancePaise;

public:
    explicit SmartCard(long long balance)
        : balancePaise(balance >= 0 ? balance : 0) {}

    bool canTravel(long long fare) const {
        return fare >= 0 && balancePaise >= fare &&
               balancePaise - fare >= MIN_BALANCE;
    }

    bool deduct(long long fare) {
        if (!canTravel(fare))
            return false;

        balancePaise -= fare;
        return true;
    }

    long long getBalance() const {
        return balancePaise;
    }
};

int main() {
    long long proceduralBalance = 10000;
    long long fare = 2000;

    if (proceduralCanTravel(proceduralBalance, fare)) {
        proceduralBalance -= fare;
        cout << "Procedural balance: "
             << proceduralBalance << '\n';
    }

    SmartCard card(10000);
    if (card.deduct(fare))
        cout << "OOP balance: " << card.getBalance() << '\n';
}
