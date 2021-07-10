class Solution {
public:
    int partition(vector<int> &nums, int l, int r){
        int x = nums[r], i = l;
        for (int j = l; j <= r - 1; j++) {
            if (nums[j] <= x) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[r]);
        return i;
    }
    
    void print(vector<int> nums){
        for(int i=0; i<nums.size(); i++){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
    }
    
    
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        k = n-k+1;
        cout<<k<<endl;
        int l = 0, h = n-1;
        while(l<h){
            cout<<l<<" "<<h<<endl;
            int index = rand()%(h-l+1)+l;
            swap(nums[index], nums[l]);
            int pivot = partition(nums, l, h);
            print(nums);
            cout<<pivot<<endl;
            cout<<"k="<<k<<endl;
            if(pivot-l == k-1){
                return nums[pivot];
            }
            else if(pivot-l > k-1){
                h = pivot-1;
            }
            else{
                cout<<"l="<<l<<endl;
                k = k - pivot + l - 1;
                l = pivot+1;
                cout<<k<<"x"<<endl;
            }
        }
        return nums[l];
    }
};