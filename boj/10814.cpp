#include <string>
#include <vector>
#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;

bool compareTuples(tuple<int,int,string> t1, tuple<int,int,string> t2)
{
    if (get<0>(t1) == get<0>(t2))
        return get<1>(t1) < get<1>(t2);
    return get<0>(t1) <= get<0>(t2);
}
int main()
{
    int n = 0;
    scanf("%d",&n);

    vector<tuple<int,int,string>> names(n);

    int age = 0;
    char name[200];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d",&age);
        scanf("%s",name);

        names[i] = tuple<int,int,string>(age,i,name);
    }
    sort(names.begin(),names.end(),compareTuples);

    for (int i = 0; i < n; ++i)
    {
        auto name = names[i];
        printf("%d %s\n", get<0>(name), get<2>(name).c_str());
    }

    return 0;
}
