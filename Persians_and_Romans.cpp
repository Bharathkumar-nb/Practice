#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

char a[1501][1501];

bool checkVer(int row, int col, int n)
{
    bool isCon = false;
    
    a[row][col] |= (char)4;
    
    if((a[row][col] & (char)2) == (char)0)
        isCon = false;
    else if(row == n)
        isCon = true;
    else if((row+1 <= n) && checkVer(row + 1, col, n))
        isCon = true;
    else if((col-1 >0) && (row+1 <= n) && checkVer(row+1, col-1, n))
        isCon = true;
    else if((col-1 >0) && ((a[row][col-1] & (char)4) == (char)0) && checkVer(row, col-1, n))
        isCon = true;
    else if((col+1 <=n) && ((a[row][col+1] & (char)4) == (char)0) && checkVer(row, col+1, n))
        isCon = true;
    return isCon;
}

bool checkHor(int row, int col, int n)
{
    
    bool isCon = false;
    
    a[row][col] |= (char)8;
    
    if((a[row][col] & (char)1) == (char)0)
        isCon = false;
    else if(col == n)
        isCon = true;
    else if((col+1 <= n) && checkHor(row, col+1, n))
        isCon = true;
    else if((row-1 >0) && (col+1 <= n) && checkHor(row-1, col+1, n))
        isCon = true;
    else if((row-1 >0) && ((a[row-1][col] & (char)8) == (char)0) && checkHor(row-1, col, n))
        isCon = true;
    else if((row+1 <=n) && ((a[row+1][col] & (char)8) == (char)0) && checkHor(row+1, col, n))
        isCon = true;
    return isCon;
}

bool isHorCon(int n)
{
    bool isCon = false;
    for(int i=1; i<=n && !isCon; ++i){
        isCon = checkHor(i, 1, n);
    }
    return isCon;
}

bool isVerCon(int n)
{
    bool isCon = false;
    for(int i=1; i<=n && !isCon; ++i){
        isCon = checkVer(1, i, n);
    }
    return isCon;
}

void print_matrix(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout << std::bitset<8>(a[i][j]) << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, m, x, y;
    cin >> n >> m; 
    for(int i=1; i<=m; ++i){
        cin >> x >> y;
        a[x][y] = (i&1) ? (char)1 : (char)2;
    }
    print_matrix(n);
    if(isVerCon(n))
        cout << "PERSIANS" << endl;
    else if(isHorCon(n))
        cout << "ROMANS" << endl;
    else
        cout << "NEITHER" << endl;
    return 0;
}



/*#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

char a[1501][1501];

bool checkVer(int row, int col, int n)
{
    bool isCon = false;
    if(a[row][col] != 'P')
        isCon = false;
    else if(row == n)
        isCon = true;
    else if((row+1 <= n) && checkVer(row + 1, col, n))
        isCon = true;
    else if((col-1 >=0) && (row+1 <= n) && checkVer(row+1, col-1, n))
        isCon = true;
    return isCon;
}

bool checkHor(int row, int col, int n)
{
    bool isCon = false;
    if(a[row][col] != 'R')
        isCon = false;
    else if(row == n)
        isCon = true;
    else if((col+1 <= n) && checkHor(row, col+1, n))
        isCon = true;
    else if((row-1 >=0) && (col+1 <= n) && checkHor(row-1, col+1, n))
        isCon = true;
    return isCon;
}

bool isHorCon(int n)
{
    bool isCon = false;
    for(int i=1; i<=n && !isCon; ++i){
        isCon = checkHor(i, 1, n);
    }
    return isCon;
}

bool isVerCon(int n)
{
    bool isCon = false;
    for(int i=1; i<=n && !isCon; ++i){
        isCon = checkVer(1, i, n);
    }
    return isCon;
}

void print_matrix(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, m, x, y;
    cin >> n >> m;
    for(int i=1; i<=m; ++i){
        cin >> x >> y;
        cout << x << " " << y << endl;
        a[x][y] = 'P' + ((i&1)<<1);
    }
    //print_matrix(n);

    if(isVerCon(n))
        cout << "PERSIANS" << endl;
    else if(isHorCon(n))
        cout << "ROMANS" << endl;
    else
        cout << "NEITHER" << endl;
    return 0;
}
*/