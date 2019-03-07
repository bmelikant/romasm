#include <iostream>
#include <string>

#include <error.h>

using namespace std;

void fatal(string msg, string extended) {
    cout << "romasm: fatal error - " << msg << endl;
    cout << extended << endl;
    cout << "action terminated" << endl;
    exit(-1);
}