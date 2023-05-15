#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

void heapify(vector<int> &input, int idx, int end) {
    int maxIdx = idx;
    int leftIdx = 2*idx+1;
    int rightIdx = 2*idx+2;

    if (leftIdx < end && input[maxIdx] < input[leftIdx]) {
        maxIdx = leftIdx;
    }

    if (rightIdx < end && input[maxIdx] < input[rightIdx]) {
        maxIdx = rightIdx;
    }

    if (maxIdx != idx) {
        swap(input[maxIdx], input[idx]);
        heapify(input, maxIdx, end);
    }
}

void heapSort(vector<int> &input) {
    int size = input.size();

    // build max heap first, start from non-leaf node bottom up
    for (int i=size/2-1; i>=0; i--) {
        heapify(input, i, size);
    }

    // each time swap root and the last node, regard it as ready from the end
    // then heapify again
    for (int i=size-1; i>=0; i--) {
        swap(input[0], input[i]);
        heapify(input, 0, i);
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
    
    heapSort(input);
    sort(expected.begin(), expected.end());
    assert(input == expected);
}