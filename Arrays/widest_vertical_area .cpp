/*Given n points on a 2D plane where points[i] = [xi, yi], Return the widest vertical area between two points such that no points are inside the area.
A vertical area is an area of fixed-width extending infinitely along the y-axis (i.e., infinite height). The widest vertical area is the one with the maximum width.
Note that points on the edge of a vertical area are not considered included in the area.
Input: points = [[8,7],[9,9],[7,4],[9,7]]
Output: 1
Explanation: Both the red and the blue area are optimal.*/

//Solution:1
int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        priority_queue<int> pq;

        for(auto& dim: points){
            pq.push(dim[0]);
        }
        int mdiff=0, prev=pq.top();
        while(!pq.empty()){
            int curr=pq.top();
            pq.pop();
            mdiff=max(mdiff, prev-curr);
            prev=curr;
        }
        return mdiff;
    }

//Solution:2
int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int> x;
        for(auto& coord: points)
            x.insert(coord[0]);
        int mdiff=0,  prev=*x.begin();
        for (int x1: x){
            mdiff=max(mdiff, x1-prev);
            prev=x1;
        }
        return mdiff;       
    }

//Solution:3
int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> x;
        for (auto& coord: points)
            x.push_back(coord[0]);
        sort(x.begin(), x.end());
        adjacent_difference(x.begin(), x.end(), x.begin());

        return *max_element(x.begin()+1, x.end());       
    }
