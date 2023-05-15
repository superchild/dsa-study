#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

int partition(vector<int> &input, int low, int high) {
    int pivot = input[high];

    int pivotIdx = low;
    for (int i=low; i<high; i++) {
        if (input[i] < pivot) {
            swap(input[i], input[pivotIdx]);
            pivotIdx++;
        }
    }

    swap(input[pivotIdx], input[high]);
    return pivotIdx;
}

void divideSort(vector<int> &input, int low, int high) {
    if (low < high) {
        int pivot = partition(input, low, high);

        divideSort(input, low, pivot-1);
        divideSort(input, pivot+1, high);
    }
}

void quickSort(vector<int> &input) {
    divideSort(input, 0, input.size()-1);
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
    
    quickSort(input);
    sort(expected.begin(), expected.end());
    assert(input == expected);
}