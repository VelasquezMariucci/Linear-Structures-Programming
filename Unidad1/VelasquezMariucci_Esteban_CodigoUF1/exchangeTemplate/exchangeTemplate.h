//
// Created by esvel on 24/09/2024.
//

#ifndef EXCHANGETEMPLATE_H
#define EXCHANGETEMPLATE_H

template <typename T>
void exchange(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}


#endif //EXCHANGETEMPLATE_H
