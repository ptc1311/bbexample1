#include <iostream>
#include <stdarg.h>
#include <algorithm>
#include <functional>

#include "bbfunction1.hpp"
#include "bbfunction2.hpp"
#include "bbfunction3.hpp"
#include "bbfunction4.hpp"
#include "bbfunction5.hpp"
#include "bbfunction6.hpp"
#include "bbfunction7.hpp"
#include "bbfunction8.hpp"
#include "bbfunction9.hpp"
#include "bbfunction10.hpp"

void myprintf(const char* fmt, ...)
{
    char buf[128];

    va_list ap;
    va_start(ap, fmt);
    vsprintf(buf, fmt, ap);
    va_end(ap);

    printf("%s", buf);
}

void func1(int int1, char char1) {

}

int g_int = 0;
void changePtr(int* &pInt) {
    pInt = &g_int;
}
int main(int argc, char *argv[])
{
  std::cout << "Hello from main!" << std::endl;
  std::cout << "Hello from main!" << std::endl;

	myprintf("%d\n", 1);
    myprintf("%d %d\n", 1, 2);
    myprintf("%d %d %s\n", 1, 2, "Hello World");


    int localInt = 1;
    int* localPInt = &localInt;
    changePtr(localPInt);
    printf("%d\n", *localPInt);

    function1();
    function2();
    /*function3();
    function4();
    function5();
    function6();
    function7();
    function8();
    function9();
    function10();*/
  
  return 0;
}

