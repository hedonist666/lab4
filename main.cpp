#include "List.h"
#include "Circle.h"
#include <iostream>

int main() {
    using namespace std;
    List m;
    m.add({1, 2, 3});
    m.add({4, 5, 6});
    m.add(0, {7, 8, 9});
    cout << m << endl;
}
