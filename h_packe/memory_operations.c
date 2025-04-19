#include "../gheader.h"

/* no overlap handling ! 
 _mem_ARA0__ is the AREA 0 in the memory from where we will copy data 
 _mem_ARA1__ is the AREA 1 in the memory well data will replicated 
 _R_Size__ is the size of the bytes we should copy from the src to dst !
 
 SHORT_CUTS : _mem_ARA0__ aka src !
    ""      : _mem_ARA1__ aka dst !
 return value : if BOTH == NULL or JUST one OF them return -1 !
 if size not good for replicate ,  well return -2!
*/

int _memRp__(void *_mem_ARA0__, void *_mem_ARA1__, size_t _R_Size__)
{
    if (!_mem_ARA0__ || !_mem_ARA1__) return (-1);
    if (_R_Size__ == 0) return (-2);

    unsigned char *m__CS_mem_ARA_0 = (unsigned char *)_mem_ARA0__;
    unsigned char *m__CS_mem_ARA_1 = (unsigned char *)_mem_ARA1__;

    size_t _Idx__ = 0;
    while (_Idx__ < _R_Size__)
    {
        m__CS_mem_ARA_1[_Idx__] = m__CS_mem_ARA_0[_Idx__];
        _Idx__++;
    }
    return (0);
}

/*
    _Dmtc_Qmark__ : aka ? data matching quation marks 
    it's a question functions is this two collection of data is matched 
    means is they equal to each other !?
    if year it return 0 if not it return -1
    if one of them or both is null it return -2 !  
*/
int _dmtc_Qmark__(const char *_FSide__, const char *_SSide__)
{
    if (!_FSide__ || !_SSide__) return (-2);

    size_t _Idx__ = 0;
    unsigned char *m__Fside__ = (unsigned char *)_FSide__;
    unsigned char *m__Sside__ = (unsigned char *)_SSide__;

    while (m__Fside__[_Idx__] && m__Sside__[_Idx__])
    {
        if (m__Fside__[_Idx__] != m__Sside__[_Idx__])
            return (-1);
        _Idx__++;
    }
    if (m__Fside__[_Idx__] || m__Sside__[_Idx__])
        return (-1);
    return (0);
}

/*
    duplicate the given data !
    _Or_d : aka ? Original data
    return NULL when the _Or_d is NULL or allocator fails  
*/

char *_data_DUP__(const char *_Or_d)
{
    if (!_Or_d) return (NULL);

    size_t _data_Size = (size_t)get_data_size(_Or_d);
    size_t _Tracker__ = 0;
    
    char *_N_DUP_data__ = malloc(_data_Size + 1);
    if (!_N_DUP_data__)
        return (NULL);
    while (_Tracker__ < _data_Size)
    {
        _N_DUP_data__[_Tracker__] = _Or_d[_Tracker__];
        _Tracker__++;
    }
    _N_DUP_data__[_Tracker__] = '\0';
    return (_N_DUP_data__);
}
