#include <string>
#include <vector>
#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;

bool compareTuples(tuple<int,int,int,string> t1, tuple<int,int,int,string> t2)
{
    if (get<0>(t1) != get<0>(t2))
        return get<0>(t1) > get<0>(t2);

    if (get<1>(t1) != get<1>(t2))
        return get<1>(t1) < get<1>(t2);

    if (get<2>(t1) != get<2>(t2))
        return get<2>(t1) > get<2>(t2);

    return get<3>(t1) <= get<3>(t2);
}
int main()
{
    int n = 0;
    scanf("%d",&n);

    vector<tuple<int,int,int,string>> names(n);

    int korean = 0, english = 0, math = 0;
    char name[200];

    for (int i = 0; i < n; ++i)
    {
        scanf("%s",name);
        scanf("%d",&korean);
        scanf("%d",&english);
        scanf("%d",&math);

        names[i] = tuple<int,int,int,string>(korean,english,math,name);
    }
    sort(names.begin(),names.end(),compareTuples);

    for (int i = 0; i < n; ++i)
    {
        string name = get<3>(names[i]);
        printf("%s\n",name.c_str());
    }

    return 0;
}
