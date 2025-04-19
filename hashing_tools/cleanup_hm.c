#include "../gheader.h"

// clean up one single hm content !
void _free_node__(_H_map_ *_Node__)
{
    if (!_Node__)
        return;
    
    if (_Node__->_Key__)
        free(_Node__->_Key__);
    
    if (_Node__->_Val__)
        free(_Node__->_Val__);
    
    free(_Node__);
}

// clean up the entire hash map
void _free_hash_map__(_H_map_ *_Hm_root__)
{
    if (!_Hm_root__)
        return;
    
    _H_map_ *_Current__ = _Hm_root__;
    _H_map_ *_Next__ = NULL;
    
    while (_Current__)
    {
        _Next__ = _Current__->_LST_Nxt__;
        _free_node__(_Current__);
        _Current__ = _Next__;
    }
}