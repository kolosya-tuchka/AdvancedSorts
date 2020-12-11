#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <fstream>

#include "header.h"

using namespace std;

int main()
{
    Generate(10000);
    start_timer();
    Heapsort();
    stop_timer();
    Output();
}