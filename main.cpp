#include <iostream>

#include <nana/gui/wvl.hpp>
#include "GBR2STL.h"

using namespace std;

int main()
{
    GBR2STL mainWindow;
    mainWindow.show();
    nana::exec();
}
