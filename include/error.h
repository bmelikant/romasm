#ifndef _ERROR_H
#define _ERROR_H

#include <iostream>
#include <string>

using namespace std;

void fatal(string msg, string extended);
void error(string msg, string extended);
void warning(string msg, string extended);

#endif