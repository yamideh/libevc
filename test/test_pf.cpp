#include <iostream>

int main()
{
    using namespace std;
#ifdef __APPLE__
    cout << " this is mac_os" << endl ;
#elif
    cout << " this is not mac _ os "<<endl;
#endif
    return 0 ;
}