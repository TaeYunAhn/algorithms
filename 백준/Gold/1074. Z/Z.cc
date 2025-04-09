#include <iostream>


using namespace std;


int z(int n, int r, int c) {
    if (n == 0) return 0;
    int half = 1 << (n - 1);
    int quadrant = (r >= half) * 2 + (c >= half);
    int offset = quadrant * (half * half);
    return offset + z(n - 1, r % half, c % half);
}

int main()
{
    int n = 0, c = 0, r = 0;
    cin >> n >> r >> c;
    cout << z(n, r, c);
    return 0;
}