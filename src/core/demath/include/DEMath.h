#pragma once

namespace dem
{
       inline double fsin(double x)
       {
               double x3 = x*x*x;
               return x - x3*0.16667 + x3*x*x*0.00833;
       }
       
       inline double fcos(double x)
       {
               double x2 = x*x;
               return 1 - x2*0.5 + x2*x2*0.04167;
       }
}
