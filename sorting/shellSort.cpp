#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

void shellSort(vector<int> &input) {
    int size = input.size();

    // rearrange elements at each n/2, n/4, n/8...intervals
    for (int gap = size/2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            for (int j = i; j >= gap; j -= gap) {
                if (input[j] < input[j-gap]) {
                    swap(input[j], input[j-gap]);
                }
            }
        }
    }
}

void printArray(vector<int> &input) {
    for (int i=0; i<input.size(); i++) {
        cout << input[i] << ' ';
    }

    cout << endl;
}

int main() {
    vector<int> input = {-1, 0, -45, 2, -8, 56, 99, 3, 7};
    vector<int> expected = input;
    
    shellSort(input);
    sort(expected.begin(), expected.end());
    assert(input == expected);
}