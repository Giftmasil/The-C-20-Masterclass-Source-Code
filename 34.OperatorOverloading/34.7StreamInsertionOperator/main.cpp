#include <fmt/format.h>
#include "point.h"

int main(){

    Point p1(10,20);
    Point p2(3,4);

  fmt::println("{}{}", p1 , p2 );
   
    return 0;
}