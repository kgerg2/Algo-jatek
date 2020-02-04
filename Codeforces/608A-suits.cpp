#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d, e, f, fst, snd;
    cin >> a >> b >> c >> d >> e >> f;
    if (e > f)
    {
        fst = min(a, d);
        snd = min(b, min(c, d-fst));
    } else
    {
        snd = min(b, min(c, d));
        fst = min(a, d-snd);
    }
    cout << e*fst + f*snd << endl;
    
    return 0;
}

