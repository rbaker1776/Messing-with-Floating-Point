#include <iostream>
#include <vector>
#include <random>


using namespace std;


float kahan_sum(const vector<float>& addends)
{
    float sum = 0;  // accumulator
    float comp = 0; // running compensation for lost bits
    for (float f: addends)
    {
        float y = f - comp;   // comp = 0 on first iter
        float t = sum + y;    // sum > y, y gets truncated
        comp = (t - sum) - y; // comp recovers lost part of y
        sum = t;              // error gets recovered next iter
    }
    return sum;
}

float naive_sum(const vector<float>& addends)
{
    float sum = 0;
    for (float f: addends)
        sum += f;
    return sum;
}

int main()
{
    const size_t N = 100'000'000;
    vector<float> nums(N);

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dist(0.f, 1.f);

    generate(nums.begin(), nums.end(), [&]() { return dist(gen); });

    cout << int(kahan_sum(nums)) << endl;
    cout << int(naive_sum(nums)) << endl;
}
