#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

int main(void){
    time_t timer;
    struct tm* t;
    timer = time(NULL);
    t = localtime(&timer);

    cout<<t->tm_year+1900<<"-";
    cout.width(2);
    cout.fill('0');
    cout<<t->tm_mon+1<<"-";
    cout.width(2);
    cout.fill('0');
    cout<<t->tm_mday;
    return 0;
}