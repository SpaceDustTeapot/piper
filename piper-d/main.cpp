#include <iostream>
#include "include/piperdaemon.h"
using namespace std;

int main()
{
    std::cout<<"starting piper-d"<<std::endl;
    piperdaemon pd;
    pd.Start();
    return 0;
}
