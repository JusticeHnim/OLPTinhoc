#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Time;

bool compareTime(const Time &a, const Time &b)
{
    if(a.second != b.second)
        return a.second < b.second;
    else 
        return a.first > b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if(!(cin >> n)) return 0;
    vector<Time> times(n);
    
    for(int i=0; i<n; i++)
    {
        cin >> times[i].first >> times[i].second;
    }

    sort(times.begin(), times.end(), compareTime);
    for(const auto &t : times)
    {
        cout << t.first << " " << t.second << "\n"; 
    }

    return 0;
}
