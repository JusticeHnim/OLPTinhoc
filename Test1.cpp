#include <iostream>
#include <vector>

using namespace std;

int N;
vector<bool> visited;
#define MAX 1000000

long long sum_bac_3(int N)
{
    long long sum = 0;
    long long r;

    r = N%10;
    sum += r*r*r;
    N /= 10;
    return sum;
}

void solve()
{
    visited.assign(MAX, false);

    cout << N << " ";
    
    while(!visited[N])
    {
        N = sum_bac_3(N);
        if(N == 1)
        {
            cout << N << " ";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(!(cin >> N)) return 0;

    solve();

    return 0;
}