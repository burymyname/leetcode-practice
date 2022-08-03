#include<unordered_map>
#include<queue>
#include<vector>

using namespace std;

/*
    note: 哈希表存储次数，因为只需要top K 高频的数字，所以用堆排序最合适
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            map[nums[i]]++;
        }

        priority_queue<pair<int, int>> heap;
        for (auto it = map.begin(); it != map.end(); it++) {
            heap.emplace(it->second, it->first); // count, num
        }

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(heap.top().second);
            heap.pop();
        }

        return ans;
    }
};