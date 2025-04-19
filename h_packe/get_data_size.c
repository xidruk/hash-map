#include "../gheader.h"

int get_data_size(const char *_data__)
{
    if (!_data__)
        return (-1);
    int _Ln__ = 0;
    while (_data__[_Ln__])
    {
        _Ln__++;
    }
    return (_Ln__);
}
