#include "../gheader.h"

// Fetch by key
_H_map_ *fetch_by_key(_H_map_ *_Hm_root__, void *_Key__, size_t _Key_size__)
{
    if (!_Hm_root__ || !_Key__ || _Key_size__ == 0)
        return (NULL);
    
    // Generate hash for the key to find
    unsigned long _Hash_idx__ = _generate_hash_idx__(_Key__, _Key_size__);
    
    _H_map_ *_Current__ = _Hm_root__;
    
    while (_Current__)
    {
        if (_Current__->_IDX__ == _Hash_idx__)
        {
            // Need to verify the key actually matches
            if (_memRp__(_Current__->_Key__, _Key__, _Key_size__) == 0)
            {
                return (_Current__);
            }
        }
        
        _Current__ = _Current__->_LST_Nxt__;
    }
    
    return (NULL); // Not found
}

// General fetch pair function
_H_map_ *fetch_pair(_H_map_ *_Hm_root__, void *_Key__, size_t _Key_size__)
{
    return (fetch_by_key(_Hm_root__, _Key__, _Key_size__));
}

// Fetch by value - may return multiple results
_H_map_ **fetch_by_value(_H_map_ *_Hm_root__, void *_Val__, size_t _Val_size__, int *_Result_count__)
{
    if (!_Hm_root__ || !_Val__ || _Val_size__ == 0 || !_Result_count__)
        return (NULL);
    
    // First pass: count matching items
    *_Result_count__ = 0;
    _H_map_ *_Current__ = _Hm_root__;
    
    while (_Current__)
    {
        if (_Current__->_Val__ && 
            _memRp__(_Current__->_Val__, _Val__, _Val_size__) == 0)
        {
            (*_Result_count__)++;
        }
        
        _Current__ = _Current__->_LST_Nxt__;
    }
    
    if (*_Result_count__ == 0)
        return (NULL);
    
    // Allocate result array
    _H_map_ **_Results__ = malloc(sizeof(_H_map_ *) * (*_Result_count__));
    if (!_Results__)
    {
        *_Result_count__ = 0;
        return (NULL);
    }
    
    // Second pass: fill result array
    int _Result_idx__ = 0;
    _Current__ = _Hm_root__;
    
    while (_Current__ && _Result_idx__ < *_Result_count__)
    {
        if (_Current__->_Val__ && 
            _memRp__(_Current__->_Val__, _Val__, _Val_size__) == 0)
        {
            _Results__[_Result_idx__++] = _Current__;
        }
        
        _Current__ = _Current__->_LST_Nxt__;
    }
    
    return (_Results__);
}

// Fetch by ID (index)
_H_map_ *fetch_by_id(_H_map_ *_Hm_root__, unsigned long _Target_idx__)
{
    if (!_Hm_root__)
        return (NULL);
    
    _H_map_ *_Current__ = _Hm_root__;
    
    while (_Current__)
    {
        if (_Current__->_IDX__ == _Target_idx__)
            return (_Current__);
        
        _Current__ = _Current__->_LST_Nxt__;
    }
    
    return (NULL); // Not found
}
