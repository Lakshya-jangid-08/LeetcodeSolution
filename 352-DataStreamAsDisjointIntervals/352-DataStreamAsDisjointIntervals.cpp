// Last updated: 6/29/2026, 10:22:50 AM
class SummaryRanges {
    set<int> st;
public:
    void addNum(int value) {
        st.insert(value);
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> intervals;

        if(st.empty()) return intervals;

        auto it = st.begin();
        int start = *it;
        int end = *it;
        ++it;

        while(it != st.end()) {
            if(*it == end + 1) {
                end = *it;
            } else {
                intervals.push_back({start, end});
                start = end = *it;
            }
            ++it;
        }

        intervals.push_back({start, end});
        return intervals;
    }
};