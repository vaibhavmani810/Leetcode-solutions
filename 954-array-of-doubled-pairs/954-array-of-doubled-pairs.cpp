class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> ans;
        multiset<int> s;
        for(auto x:changed)s.insert(x);
        while(!s.empty())
        {
            auto temp=s.begin();
            int val=*temp;
            s.erase(temp);
            auto double_val=s.find(2*val);
            if(double_val==s.end())
            {
             return {};
            }
            ans.push_back(val);
            s.erase(double_val);
        }
        return ans;
    }
        vector<int> find(vector<int>& changed) {
        vector<int> ans;
        multiset<int> s;
        for(auto x:changed)s.insert(x);
        while(!s.empty())
        {
            auto temp=s.end();
            temp--;
            int val=*temp;
            s.erase(temp);
            auto double_val=s.find(2*val);
            if(double_val==s.end())
            {
             return {};
            }
            ans.push_back(val);
            s.erase(double_val);
        }
        return ans;
    }

    bool canReorderDoubled(vector<int>& arr) {
        vector<int> ans,arr1,arr2;
        for(auto x:arr)
        {
            if(x<0)arr2.push_back(x);
            else
                arr1.push_back(x);
        }
        if(arr1.size()>0&&arr2.size()>0){
        if(ans==findOriginalArray(arr1)||ans==find(arr2))
        {
            return false;
        }
        }
        else if(arr1.size()>0)
        {
            if(ans==findOriginalArray(arr1))
        {
            return false;
        }
        }
        else if(arr2.size()>0)
        {
            if(ans==find(arr2))
        {
            return false;
        }
        }
        return true;
    }
};