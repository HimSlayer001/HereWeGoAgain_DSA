class Solution {
public:
    bool isAnagram(string s, string t) {
    unordered_map<char,int>lett;
    int size1=s.size();
    int size2=t.size();

    if(size1!=size2)
    
    { 
        return false;
    }

    for(int i=0; i<size1;++i)
    {
        lett[s[i]]++;
    }
    for(int j=0; j<size2;++j)
    {
        if(lett.count(t[j])==1)
        {
            lett[t[j]]--;
        }
        if(lett[t[j]]==0)
        {
            lett.erase(t[j]);
        }
    }
    if(lett.empty())
    {
        return true;
    }
    else{
    return false;
    }
    }
};
