// Last updated: 4/4/2026, 12:57:45 am
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int l = 0, r = points.size() - 1;
        --K;

        while(true) {
            int p = partition(points, l, r);
            if (p == K) break;

            if (p < K) l = p + 1;
            else r = p - 1;
        }

        return vector<vector<int>>(points.begin(), points.begin() + K + 1);
    }

private:
    int distance(vector<int>& p) {
        return p[0]*p[0] + p[1]*p[1];
    }
    
    int partition(vector<vector<int>>& arr, int low, int high) {
        int pivot = distance(arr[high]);
        for (int i = low; i < high; ++i) {
            if(distance(arr[i]) < pivot)
                swap(arr[i], arr[low++]);
        }

        swap(arr[high], arr[low]);
        return low;
    }
};