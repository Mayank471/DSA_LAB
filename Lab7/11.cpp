#include<bits/stdc++.h>

using namespace std;

int maximumGap(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) {
        return 0;
    }

    int min_val = *min_element(nums.begin(), nums.end());
    int max_val = *max_element(nums.begin(), nums.end());

    if (min_val == max_val) {
        return 0;
    }

    int bucket_size = max(1, (max_val - min_val) / (n - 1));
    int bucket_count = (max_val - min_val) / bucket_size + 1;

    vector<pair<int, int>> buckets(bucket_count, {INT_MAX, INT_MIN});


    for (int num : nums) {
        int index = (num - min_val) / bucket_size;
        buckets[index].first = min(buckets[index].first, num);
        buckets[index].second = max(buckets[index].second, num);
    }

    int max_gap = 0;
    int previous_max = min_val;

    for (int i = 0; i < bucket_count; ++i) {
        if (buckets[i].first == INT_MAX) continue;
        
        max_gap = max(max_gap, buckets[i].first - previous_max);
        previous_max = buckets[i].second;
    }

    return max_gap;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    cout << maximumGap(nums) << endl;

    return 0;
}
