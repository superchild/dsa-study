#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void countingSort(vector<int> &input) {
    int size = input.size();
    
    int maxItem = *max_element(input.begin(), input.end());
    int minItem = *min_element(input.begin(), input.end());
    
    int range = maxItem - minItem + 1;
    vector<int> count(range, 0);
    
    // count for each element's frequency
    for (int i=0; i<size; i++) {
        count[input[i]-minItem]++;
    }
    
    // calculate prefix sum for the element frequency
    for (int i=1; i<count.size(); i++) {
        count[i] += count[i-1];
    }
    
    
    // prepare sorted output
    vector<int> sortInput(size, 0);
    for (int i=size-1; i>=0; i--) {
        int idx = count[input[i]-minItem];
        sortInput[idx-1] = input[i];
        count[input[i]-minItem]--;
    }
    
    // copy back the sorted output to original array
    input.assign(sortInput.begin(), sortInput.end());
}

void printArray(vector<int> &input) {
    for (int i=0; i<input.size(); i++) {
        cout << input[i] << ' ';
    }

    cout << endl;
}

int main() {
    vector<int> input = {-1, 0, -45, 2, -8, 56, 99, 3, 7};
    printArray(input);
    countingSort(input);
    printArray(input);
}