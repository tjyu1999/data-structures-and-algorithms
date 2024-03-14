/*
 *  time complexity: O(n^2)
 *  space complexity: O(1)
 */

# include <iostream>
# include <vector>

using namespace std;

void insertion_sort(vector<int> &nums){
    for(int i = 1; i < nums.size(); i++){
        int key = nums[i];
        int j = i - 1;
        
        while(key < nums[j] && j >= 0){
            nums[j + 1] = nums[j];
            j--;
        }
        
        nums[j + 1] = key;
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
    
    insertion_sort(nums);
    for(auto val : nums) cout << val << " ";
    cout << endl;
    
    return 0;
}
