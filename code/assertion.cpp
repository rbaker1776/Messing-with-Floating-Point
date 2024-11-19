#include <iostream>
#include <assert.h>


int main()
{
    float a = 1;
    assert(a == 1); // passes

    float f = 0.1;
    //assert(f == 0.1); // fails
    
    return 0;
}
