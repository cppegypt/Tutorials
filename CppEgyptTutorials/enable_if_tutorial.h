/*
 * enable_if Tutorial
 * Author: Islam Abdeen
 */

#ifndef ENABLE_IF_TUTORIAL_H
#define ENABLE_IF_TUTORIAL_H

#include <iostream>

//////////////////////////////////////////////////////////////////////////////
// Method 1. The return type (bool) is only valid if T has an integral type //
//////////////////////////////////////////////////////////////////////////////
template <class T>
typename std::enable_if<std::is_integral<T>::value, bool>::type
isOdd(T i)
{
    return static_cast<bool>(i%2);
}

/* Template Explanation
-----------------------
template <class T>                                              : indicates it's a template with type T
typename std::enable_if<std::is_integral<T>::value, bool>::type : is the return value of is_odd() method
is_odd(T i){return static_cast<bool>(i%2);}                     : is the is_odd() implementation

Note:
      1)  std::enable_if<bool Cond, class T = void>::type

      - type is defined as a member of enable_if only if the first argument of enable_if (Cond) is true
        and in this case it will be the same as the second argument of enable_if (T).
      - If Cond is false we get compiler error

      So in the previous example, std::is_integral<T>::value is true so the ::type will be bool and the
      return value of is_odd() will be bool

      2) Integral data types like: bool, char, char8_t, char16_t, char32_t, wchar_t, short, int, long,
         long long
*/

////////////////////////////////////////////////////////////////////////////////////
// Method 2. The second template argument is only valid if T has an integral type //
////////////////////////////////////////////////////////////////////////////////////
template <class T, class = typename std::enable_if<std::is_integral<T>::value>::type>
bool isEven(T i)
{
    return !static_cast<bool>(i%2);
}

void runEnableIf()
{
    std::cout<<"***enable_if***"<<std::endl;

    short int i = 1;    // code does not compile if type of i is not integral

    std::cout << std::boolalpha;
    std::cout << "i is odd: " << isOdd(i) << std::endl;
    std::cout << "i is even: " << isEven(i) << std::endl;
}

#endif // ENABLE_IF_TUTORIAL_H
