#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

void selectionSort(vector<int> &input) {
    int size = input.size();
    
    for (int i=0; i<size; i++) {
        int minIdx = i;
        for (int j=i+1; j<size; j++) {
            if (input[minIdx] > input[j]) {
                minIdx = j;
            }
        }
        
        swap(input[minIdx], input[i]);
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
    
    selectionSort(input);
    sort(expected.begin(), expected.end());
    assert(input == expected);
}