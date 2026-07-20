class Solution {
    private:
    int squaredDis(vector<int>& point) {
    return point[0] * point[0] + 
      point[1] * point[1];
}
    public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    int n=points.size();
    priority_queue<pair<int,vector<int>>>pq;
    vector<vector<int>>res;
    for(int i=0; i<n; ++i)
    {   int dist=squaredDis(points[i]);
 if(pq.size()<k)
    {
pq.push({dist,points[i]});
    }
    else
    //if it is k then compare the dist with top
{  
     if(pq.top().first>dist)
{

pq.pop();
pq.push({dist,points[i]});
}
}
}
while(!pq.empty())
{
    res.push_back(pq.top().second);
    pq.pop();
}
    return res;

}
};
