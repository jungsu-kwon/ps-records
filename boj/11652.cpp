#include <unordered_map>
#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    scanf("%d",&n);

    unordered_map<long,int> cards;

    long number = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%ld",&number);
        if (cards.find(number) == cards.end() )
            cards[number] = 1;
        else
            cards[number] += 1;
    }

    int maxVal = 0;
    long maxKey = 0;
    for (auto card: cards)
    {
        if (card.second == maxVal)
            maxKey = maxKey < card.first ? maxKey : card.first;
        else if (card.second > maxVal)
        {
            maxKey = card.first;
            maxVal = card.second;
        }
    }
    printf("%ld\n",maxKey);

    return 0;
}

