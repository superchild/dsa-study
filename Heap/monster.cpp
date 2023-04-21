#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <iterator>

using namespace std;

typedef pair<int, int> Monster;
int getMinPower(vector<vector<int>> &monsters, int limit) {
    int size = monsters.size();
    map<int, int> totalSum;

    auto cmp = [&totalSum](const Monster &lhs, const Monster &rhs) {
        return lhs.second - totalSum[lhs.first] > rhs.second - totalSum[rhs.first];
    };
    priority_queue<Monster, vector<Monster>, decltype(cmp)> minHeap(cmp);

    // sort the monster if not sorted, TC: O(NlogN)
    sort(monsters.begin(), monsters.end());
    int totalPower = 0;
    for (int i=0; i<size; i++) {
        // push to priority queue
        int time = monsters[i][0];
        int power = monsters[i][1];
        minHeap.push({time, power});
        totalPower += power;
        if (totalPower > limit) {
            // needs to fight back
            int sendPower = (totalPower - limit)/minHeap.size() + 1;
            totalPower -= sendPower;
            totalSum[time] = sendPower;
            if (totalSum.lower_bound(time) != totalSum.begin()) {
                auto prevIter = prev(totalSum.lower_bound(time));
                int prevTime = prevIter->first;
                totalSum[time] += totalSum[prevTime];
            }

            // check if monster should be removed
            Monster cur = minHeap.top();
            int minTime = cur.first;
            int minPower = cur.second;
            if (totalSum[minTime] > minPower) {
                minHeap.pop();
            }
        }
    }

    return prev(totalSum.end())->second;
}

int main() {
    vector<vector<int>> monsters = {
        {1, 10}, {2, 30}, {5, 60}, {7, 100}
    };
    
    int minPower = getMinPower(monsters, 40);
    cout << "minPower: " << minPower << endl;
}