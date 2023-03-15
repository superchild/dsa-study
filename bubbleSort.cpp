#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &input) {
    int size = input.size();

    for (int step=0; step<size-1; step++) {
        bool isSorted = true;

        for (int i=0; i<size-step-1; i++) {
            if (input[i] > input[i+1]) {
                swap(input[i], input[i+1]);
                isSorted = false;
            }
        }

        if (isSorted) {
            break;
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
    printArray(input);
    bubbleSort(input);
    printArray(input);
}