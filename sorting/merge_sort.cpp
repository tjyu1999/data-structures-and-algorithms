/*
 *  time complexity: O(nlogn)
 *  space complexity: O(n)
 */

# include <iostream>
# include <vector>
# include <climits>

using namespace std;

void merge(vector<int> &nums, int low, int mid, int high){
    int l = 0;
    int r = 0;
    const int max = INT_MAX;
    vector<int> left(nums.begin() + low, nums.begin() + mid + 1);
    vector<int> right(nums.begin() + mid + 1, nums.begin() + high + 1);
    
    left.push_back(max);
    right.push_back(max);
    
    for(int i = low; i <= high; i++){
        if(left[l] <= right[r]){
            nums[i] = left[l];
            l++;
        }
        else{
            nums[i] = right[r];
            r++;
        }
    }
}

void merge_sort(vector<int> &nums, int low, int high){
    if(low < high){
        int mid = (low + high) / 2;
        mergesort(nums, low, mid);
        mergesort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }
}

int main(){
    char c;
    int val;
    vector<int> nums;
    
    while(cin.get(c) && c != '\n'){
        cin.putback(c);
        cin >> val;
        nums.push_back(val);
    }
    
    merge_sort(nums, 0, nums.size() - 1);
    for(auto val : nums) cout << val << " ";
    cout << endl;
    
    return 0;
}
