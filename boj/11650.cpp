#include <vector>
#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;

bool comparePoints(tuple<int,int> t1, tuple<int,int> t2)
{
    if (get<0>(t1) == get<0>(t2)) 
        return get<1>(t1) <= get<1>(t2);
    return get<0>(t1) < get<0>(t2);
}
int main()
{
    int n = 0;
    scanf("%d",&n);
    vector<tuple<int,int> > points(n, tuple<int,int>{0,0});

    int x = 0, y = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d",&x);
        scanf("%d",&y);
        points[i] = tuple<int,int>{x,y};
    }
    sort(points.begin(),points.end(),comparePoints);
    for (int i = 0; i < n; ++i)
    {
        auto point = points[i];
        printf("%d %d\n",get<0>(point),get<1>(point));
    }


    
    return 0;
}
