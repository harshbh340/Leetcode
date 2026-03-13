class Solution {
public:
    void solve(int idx,vector<int>& temp,vector<vector<int>>& result,vector<int>& candidates,int target){
        if(target == 0){
        result.push_back(temp);
        return;
    }
    if(target<0 || idx>=candidates.size()){
        return;
    }
    temp.push_back(candidates[idx]);
    solve(idx,temp,result,candidates,target-candidates[idx]);
    temp.pop_back();
    solve(idx+1,temp,result,candidates,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<int> temp;
      vector<vector<int>> result;
      int idx=0;
      solve(idx,temp,result,candidates,target);
      return result;  
    }
};