#include "../gheader.h"

// Function to generate hash index from key data
unsigned long _generate_hash_idx__(void *_Key__, size_t _Key_size__)
{
    if (!_Key__ || _Key_size__ == 0)
        return (0);
        
    unsigned long _Hash_idx__ = 0;
    unsigned char *_Key_bytes__ = (unsigned char *)_Key__;
    
    for (size_t i = 0; i < _Key_size__; i++)
    {
        _Hash_idx__ = (_Hash_idx__ * 31) + _Key_bytes__[i];
    }
    
    return (_Hash_idx__);
}