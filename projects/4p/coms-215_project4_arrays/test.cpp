#include <iostream>
using namespace std;

// post: returns min # in array[].
int findMin(const int array[]) {
    int minNum = array[0];
    for (int i = 0; i < 5; i++) {
        if (array[i] < minNum) {
            minNum = array[i];
        }
    }
    return minNum;
}

int main() {
    int array[5] = { 3, 0, 2, -1, 0 };
    cout << findMin(array);
    return 0;
}