#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>

using namespace std;

// assum input data range from [0, 100)
void bucketSort(vector<int> &input) {
    const int BUCKET_NUM = 10;

    vector<vector<int>> buckets(BUCKET_NUM, vector<int>());
    
    int size = input.size();
    // put all element into bucket
    for (int i=0; i<size; i++) {
        int bucketIdx = input[i]/BUCKET_NUM;
        buckets[bucketIdx].push_back(input[i]);
    }

    // sort inside each bucket, it can choose other sorting algorithm
    for (int i=0; i<buckets.size(); i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // concatenate all buckets together
    int idx = 0;
    for (int i=0; i<buckets.size(); i++) {
        for (int j=0; j<buckets[i].size(); j++) {
            input[idx] = buckets[i][j];
            idx++;
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
    vector<int> input = {0, 45, 2, 56, 99, 3, 7};
    vector<int> expected = input;
    
    bucketSort(input);
    sort(expected.begin(), expected.end());
    assert(input == expected);
}

