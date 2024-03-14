/*
 *  time complexity: O(n^2)
 *  space complexity: O(1)
 */

# include <iostream>
# include <vector>

using namespace std;

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(vector<int> &nums, int low, int high){
    int pivot = nums[high];
    int i = low - 1;
    
    for(int j = low; j < high; j++){
        if(nums[j] < pivot){
            i++;
            swap(&nums[i], &nums[j]);
        }
    }
    
    i++;
    swap(&nums[i], &nums[high]);
    
    return i;
}

void quick_sort(vector<int> &nums, int low, int high){
    if(low < high){
        int pivot = partition(nums, low, high);
        quicksort(nums, low, pivot - 1);
        quicksort(nums, pivot + 1, high);
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
    
    quick_sort(nums, 0, nums.size() - 1);
    for(auto val : nums) cout << val << " ";
    cout << endl;

    return 0;
}
