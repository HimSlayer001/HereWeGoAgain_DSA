class Solution {
public:
    bool checkInclusion(string s1, string s2) {
    
            if(s1.size()>s2.size())
        return false;
        vector<int> need(26,0), window(26,0);
    

        for(int i=0; i<s1.size(); ++i)
        {
            need[s1[i]-'a']++;
        }
        int k=s1.size();
        for(int r=0; r<s2.size();++r)
        { window[s2[r]-'a']++;
            if(r >= k)
                window[s2[r-k]-'a']--;

            if(window == need)
                return true;


        }
    return false;
    }
};
