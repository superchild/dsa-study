#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &input, int low, int mid, int high) {
    vector<int> left(input.begin()+low, input.begin()+mid+1);
    vector<int> right(input.begin()+mid+1, input.begin()+high+1);

    int leftIdx = 0;
    int rightIdx = 0;
    int idx = low;
    while (leftIdx < left.size() && rightIdx < right.size()) {
        if (left[leftIdx] < right[rightIdx]) {
            input[idx] = left[leftIdx];
            leftIdx++;
        } else {  
            input[idx] = right[rightIdx];
            rightIdx++;
        }

        idx++;
    }

    while (leftIdx < left.size()) {
        input[idx] = left[leftIdx];
        leftIdx++;
        idx++;
    }
    
    while (rightIdx < right.size()) {
        input[idx] = right[rightIdx];
        rightIdx++;
        idx++;
    }
}

void divideSort(vector<int> &input, int low, int high) {
    if (low < high) {
        int mid = low + (high-low)/2;

        divideSort(input, low, mid);
        divideSort(input, mid+1, high);

        merge(input, low, mid, high);
    }
}

void mergeSort(vector<int> &input) {
    int size = input.size();
    divideSort(input, 0, size-1);
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
    mergeSort(input);
    printArray(input);
}