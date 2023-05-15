#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

const int DIGITS = 10;

void countingSort(vector<int> &input, int exp) {
    int size = input.size();
    vector<int> count(DIGITS, 0);
    
    for (int i=0; i<size; i++) {
        int idx = (input[i]/exp)%10;
        count[idx]++;
    }
    
    for (int i=1; i<count.size(); i++) {
        count[i] += count[i-1];
    }
    
    vector<int> sortInput(size, 0);
    for (int i=size-1; i>=0; i--) {
        int idx = (input[i]/exp)%10;
        sortInput[count[idx]-1] = input[i];
        count[idx]--;
    }
    
    input.assign(sortInput.begin(), sortInput.end());
}

void radixSort(vector<int> &input) {
    int size = input.size();
    
    int maxItem = *max_element(input.begin(), input.end());
    
    for (int exp=1; maxItem/exp > 0; exp*=10) {
        countingSort(input, exp);
    }
}

void printArray(vector<int> &input) {
    for (int i=0; i<input.size(); i++) {
        cout << input[i] << ' ';
    }

    cout << endl;
}

int main() {
    vector<int> input = {0, 45, 2, 56, 99, 3, 7};
    vector<int> expected = input;
    
    radixSort(input);
    sort(expected.begin(), expected.end());
    assert(input == expected);
}