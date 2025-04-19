#include "../gheader.h"

// generate a new hash map pair

_H_map_ *_gen_HM_pair__(void)
{
    _H_map_ *_New_P; // new pair

    _New_P = malloc(sizeof(_H_map_));
    if (!_New_P)
        return (NULL);
    _New_P->_IDX__ = 0;
    _New_P->_Key__ = NULL;
    _New_P->_Val__ = NULL;
    _New_P->_Type__ = 0;
    _New_P->_LST_Prv__ = NULL;
    _New_P->_LST_Nxt__ = NULL;

    return (_New_P);
}
