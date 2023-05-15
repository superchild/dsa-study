#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

void insertionSort(vector<int> &input) {
    int size = input.size();
    for (int i=1; i<size; i++) {
        int key = input[i];
        int j=i-1;
        
        while (j>=0 && input[j] > key) {
            input[j+1] = input[j];
            j--;
        }
        
        input[j+1] = key;
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
    
    insertionSort(input);
    sort(expected.begin(), expected.end());
    assert(input == expected);
}