#include "../gheader.h"

int initem(_H_map_ **_Hm_root__, void *_Key__, size_t _Key_size__, void *_Val__, size_t _Val_size__)
{
    if (!_Hm_root__ || !_Key__ || !_Val__ || _Key_size__ == 0 || _Val_size__ == 0)
        return (-1);
    
    _H_map_ *_New_node__ = _gen_HM_pair__();
    if (!_New_node__)
        return (-2); // memory allocation failed
    
    // copy key and value data
    void *_Key_copy__ = malloc(_Key_size__);
    void *_Val_copy__ = malloc(_Val_size__);
    
    if (!_Key_copy__ || !_Val_copy__)
    {
        if (_Key_copy__) free(_Key_copy__);
        if (_Val_copy__) free(_Val_copy__);
        free(_New_node__);
        return (-3); // memory allocation failed
    }
    
    // copy the data using our helper function
    _memRp__(_Key__, _Key_copy__, _Key_size__);
    _memRp__(_Val__, _Val_copy__, _Val_size__);
    
    // set the values in our new node
    _New_node__->_Key__ = _Key_copy__;
    _New_node__->_Val__ = _Val_copy__;
    
    // generate hash index for the key
    _New_node__->_IDX__ = _generate_hash_idx__(_Key__, _Key_size__);
    
    // first element case
    if (!(*_Hm_root__))
    {
        *_Hm_root__ = _New_node__;
        return (0);
    }
    
    // find the appropriate position
    _H_map_ *_Current__ = *_Hm_root__;
    _H_map_ *_Prev__ = NULL;
    
    while (_Current__)
    {
        // if keys match exactly, replace value
        if (_Current__->_IDX__ == _New_node__->_IDX__ && 
            _memRp__(_Current__->_Key__, _Key__, _Key_size__) == 0)
        {
            // replace existing value
            free(_Current__->_Val__);
            _Current__->_Val__ = _Val_copy__;
            
            // clean up unused resources
            free(_Key_copy__);
            free(_New_node__);
            return (0);
        }
        
        _Prev__ = _Current__;
        _Current__ = _Current__->_LST_Nxt__;
    }
    
    // add to end of list
    if (_Prev__)
    {
        _Prev__->_LST_Nxt__ = _New_node__;
        _New_node__->_LST_Prv__ = _Prev__;
    }
    
    return (0);
}
