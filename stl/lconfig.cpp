#include <vector>
#include <iostream>

using namespace std;

int main()
{
#if defined(__sgi)
    cout << "__sgi" << endl;
#endif

#if defined(__GUNC__)
    cout << "__GUNC__" << endl;
    cout << __GUNC__ << ' ' << __GUNC_MINOR__ << endl;
#endif

#if defined __STL__NO__BRAND48
    cout << "__STL__NO__BRAND48 defined" << endl;
#else
    cout << "__STL__NO__BRAND48 undefined" << endl;
#endif
    return 0;
}
