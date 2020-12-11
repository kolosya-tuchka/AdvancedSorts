#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

static clock_t timer_start_time{ 0 }, timer_stop_time{ 0 };
vector<int> list;

void start_timer()
{
    timer_start_time = clock();
}

void stop_timer()
{
    timer_stop_time = clock();
    cout << double(timer_stop_time - timer_start_time) / CLOCKS_PER_SEC << " sec" << endl;
}

void CoutAll()
{
    for (auto num : list)
    {
        cout << setw(8) << num;
    }
    cout << endl;
}

void Swap(int& num1, int& num2)
{
    int mid = num1;
    num1 = num2;
    num2 = mid;
}

void Input()
{
    ifstream inFile("input.txt");
    while (inFile.good())
    {
        int num;
        inFile >> num;
        list.push_back(num);
    }
}

void Generate(int size)
{
    for (int i = 0; i < size; i++)
    {
        list.push_back(rand() % 100);
    }
}

void Output()
{
    ofstream outFile("output.txt");
    for (auto num : list)
    {
        outFile << setw(5) << num;
    }
}

bool array_is_sorted()
{
    for (size_t i{ 1 }; i < list.size(); ++i) if (list[i - 1] > list[i]) return false;
    return true;
}

void Shell()
{
    int step = list.size() / 1.618, stepCount{1}, size = list.size();

    while (step > 0)
    {
        for (int i = 0; i < size; ++i)
        {
            int j = i;

            while (j >= step && list[j] < list[j - step])
            {
                Swap(list[j], list[j - step]);
                j -= step;
            }
        }

        step /= 1.618;
    }
}

void Heapsort()
{
    int size = list.size();

    for (int i{ 0 }; i < size; ++i)
    {
        for (int j{ size / 2 - 1 - i / 2 }; j >= 0; --j)
        {
            if (2 * j + 2 < size - i)
            {
                if (list[j] < list[j * 2 + 2] && list[j * 2 + 2] > list[j * 2 + 1])
                {
                    Swap(list[j], list[j * 2 + 2]);
                }
                else if (list[j] < list[j * 2 + 1])
                {
                    Swap(list[j], list[j * 2 + 1]);
                }
            }
            else if (2 * j + 1 < size - i && list[j] < list[j * 2 + 1])
            {
                Swap(list[j], list[j * 2 + 1]);
            }
        }
        Swap(list[0], list[size - 1 - i]);
    }
}