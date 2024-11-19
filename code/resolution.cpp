#include <iostream>


using namespace std;


int main()
{
    float sum = 0;

    for (int i = 0; i < 1'000'000'000; ++i)
        sum += 1.f / 1'000'000'000.f;

    cout << sum << endl;
}
