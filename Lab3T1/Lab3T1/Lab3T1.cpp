#include <iostream>
#include <string>

using namespace std;

class money {
public:
    int count = 0;
    int cost = 0;
    money(int count, int cost) : count(count), cost(cost) {};

    string get_info() {
        return "Номинал: " + to_string(cost) + ", количество: " + to_string(count);
    }

    int get_sum() {
        return count * cost;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    int a, b;
    cout << "Номинал: ";
    cin >> a;
    cout << "Количество: ";
    cin >> b;
    money ten(a, b);
    cout << ten.get_sum() << endl;
    cout << ten.get_info() << endl;
}