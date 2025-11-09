#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

vector<vector<int>> dist;

void Floyd_Warshall(int n)
{
    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j)
            {
                if(dist[i][k] < INF && dist[k][j] < INF){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main()
{

    int n;
    cin >> n;

    dist = vector<vector<int>>(n + 1, vector<int>( n + 1 , INF ) );

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            cin >> dist[i][j];
        }
    }

    Floyd_Warshall(n);

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

}
