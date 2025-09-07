class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        vector<vector<int>> ans;
        if(intervals.size()==0){
            ans.push_back(newInterval);
            return ans;
        }
        if(intervals[0][0] > newInterval[1]){
            ans.push_back(newInterval);
            for(int a=0; a<n; a++){
                ans.push_back(intervals[a]);
            }
            return ans;
        }
        if(intervals[n-1][1] < newInterval[0]){
            intervals.push_back(newInterval);
            return intervals;
        }
        int i=0;
        bool a=true;
        while(i<n){
            if(intervals[i][1] >= newInterval[0]){
                a=false;
                break;
            }
            ans.push_back(intervals[i]);
            i++;
        }
        if(a) return intervals;
        vector<int> temp;
        temp.push_back(min(intervals[i][0], newInterval[0]));
        bool b=true;
        int j=n-1;
        while(j>=0){
            if(intervals[j][0] <= newInterval[1]){
                temp.push_back(max(intervals[j][1], newInterval[1]));
                b=false;
                break;
            }
            j--;
        }
        if(b){
            temp.push_back(newInterval[1]);
            ans.push_back(temp);
            return ans;
        }
        ans.push_back(temp);
        for(int k=j+1; k<n; k++){
            ans.push_back(intervals[k]);
        }
        return ans;
    }
};