#include <iostream>
#include <deque>

using namespace std;

int main(int argc, char const *argv[])
{
    deque<int> q;
    q.push_back(5);
    q.push_back(6);
    q.pop_front();
    cout << q.back() << endl;
    
    return 0;
}