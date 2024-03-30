#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        vector<pair<int,int>>point;                             //store all the points
        vector<pair<double,pair<int,int>>>neg_point;            //negative angle and point vector
        vector<pair<double,pair<int,int>>>pos_point;            //positive angle and point vector
        int count = 0, n, min_x = INT_MAX, min_y = INT_MAX;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            int x,y;
            char c;
            cin>>x>>y>>c;
            if(c=='Y')              //only count and take points which are part of the convex hull
            {
                count++;
                point.push_back({x,y});
                if(x<min_x && y<min_y)      //store the points with minimum x and y
                {
                    min_x = x;
                    min_y = y;
                }
            }
        }
        for(int i=0;i<count;i++)
        {
            if(point[i].first == min_x && point[i].second == min_y) continue;   //min_x and min_y are excluded
            long double angle;
            angle = atan2(point[i].second - min_y, point[i].first - min_x); //angle is taken from a point in convex hull to prevent having two points in a same line
            if(angle<=0)
                neg_point.push_back({angle,{point[i].first,point[i].second}});
            else
                pos_point.push_back({-angle,{point[i].first,point[i].second}});
        }
        sort(neg_point.begin(),neg_point.end());            //negative angles are traversed in anti-clockwise order
        sort(pos_point.begin(),pos_point.end());            //positive angles are traversed in clockwise order when sorted in ascending order
        reverse(pos_point.begin(),pos_point.end());         //positive angles are reversed so that they are traversed in anti clockwise order
        //print the results
        cout<<count<<endl;
        cout<<min_x<<" "<<min_y<<endl;
        for(int i=0;i<neg_point.size();i++)
        {
            cout<<neg_point[i].second.first<<" "<<neg_point[i].second.second<<endl;
        }

        for(int i=0;i<pos_point.size();i++)
        {
            cout<<pos_point[i].second.first<<" "<<pos_point[i].second.second<<endl;
        }
    }
}