// Last updated: 6/29/2026, 10:22:54 AM
class NumArray {
    vector<int> seg;
    int n;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4 * n + 1);
        insert(nums, 0, 0, n - 1);
    }
    
    void insert(vector<int>& nums, int idx, int l, int r) {
        if(l == r) {
            seg[idx] = nums[l];
            return;
        }   
        int mid = (l + r) / 2;
        insert(nums, 2 * idx + 1, l, mid);
        insert(nums, 2 * idx + 2, mid + 1, r);
    
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
        return;
    }

    void update(int index, int val) {
        update(0, index, val, 0, n - 1);
    }

    void update(int idx, int i, int val, int l, int r) {
        if(l == r) {
            seg[idx] = val;
            return;
        }

        int mid = (l + r) / 2;
        if(mid >= i) update(2 * idx + 1, i, val, l, mid);
        else update(2 * idx + 2, i, val, mid + 1, r);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
        return;
    }
    
    int sumRange(int left, int right) {
        return sumRange(0, left, right, 0, n - 1);
    }

    int sumRange(int idx, int ql, int qr, int l, int r) {
        if(ql <= l && qr >= r) return seg[idx];
        if(qr < l || r < ql) return 0;

        int mid = (l + r) / 2;
        
        return sumRange(2 * idx + 1, ql, qr, l, mid) + sumRange(2 * idx + 2, ql ,qr, mid + 1, r);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */