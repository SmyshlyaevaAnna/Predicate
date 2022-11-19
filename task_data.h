#ifndef TASK_DATA_H
#define TASK_DATA_H
#include <boost/Multiprecision/cpp_dec_float.hpp>
#include <boost/math/constants/constants.hpp>
using boost::multiprecision::cpp_dec_float_100;
//template <typename T>
struct vector2d
{
    cpp_dec_float_100 x;
    cpp_dec_float_100 y;
    vector2d() { }
    vector2d(cpp_dec_float_100 ix, cpp_dec_float_100 iy) : x(ix), y(iy) { }
};
struct vector2ddouble
{
    double x;
    double y;
    vector2ddouble() { }
    vector2ddouble(double ix, double iy) : x(ix), y(iy) { }
};

#endif // TASK_DATA_H
