#include <iostream>

using namespace std;

int main()
{
    int n, s[3000], c[3000], sum;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    sum = 300000001;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s[j] > s[i] && c[i] + c[j] < sum)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (s[k] > s[j] && c[i] + c[j] + c[k] < sum)
                    {
                        sum = c[i] + c[j] + c[k];
                    }
                }
            }
        }
    }
    if (sum == 300000001)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << sum << endl;
    }
    return 0;
}
