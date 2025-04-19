#include "gheader.h"

void _print_hash_map__(_H_map_ *_Hm_root__)
{
    if (!_Hm_root__)
    {
        printf("Hash map is empty\n");
        return;
    }
    
    _H_map_ *_Current__ = _Hm_root__;
    int _Count__ = 0;
    
    printf("Hash Map Contents:\n");
    printf("------------------\n");
    
    while (_Current__)
    {
        printf("Node %d - IDX: %lu\n", _Count__, _Current__->_IDX__);
        printf("  Key: %s\n", (char *)_Current__->_Key__);
        printf("  Val: %s\n", (char *)_Current__->_Val__);
        printf("------------------\n");
        
        _Current__ = _Current__->_LST_Nxt__;
        _Count__++;
    }
    
    printf("Total nodes: %d\n", _Count__);
}

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    
    _H_map_ *_My_hash_map__ = NULL;
    _H_map_ *_Found_node__ = NULL;
    _H_map_ **_Found_nodes__ = NULL;
    int _Result_count__ = 0;
    
    // Test inserting items
    printf("Testing hash map insertion...\n");
    
    // Insert some test data
    char *_Key1__ = "test_key1";
    char *_Val1__ = "test_value1";
    initem(&_My_hash_map__, _Key1__, get_data_size(_Key1__) + 1, _Val1__, get_data_size(_Val1__) + 1);
    
    char *_Key2__ = "test_key2";
    char *_Val2__ = "test_value2";
    initem(&_My_hash_map__, _Key2__, get_data_size(_Key2__) + 1, _Val2__, get_data_size(_Val2__) + 1);
    
    char *_Key3__ = "unique_key";
    char *_Val3__ = "test_value2"; // Same value as Key2
    initem(&_My_hash_map__, _Key3__, get_data_size(_Key3__) + 1, _Val3__, get_data_size(_Val3__) + 1);
    
    // Print the hash map contents
    _print_hash_map__(_My_hash_map__);
    
    // Test fetching by key
    printf("\nTesting fetch_pair...\n");
    _Found_node__ = fetch_pair(_My_hash_map__, _Key2__, get_data_size(_Key2__) + 1);
    if (_Found_node__)
        printf("Found node with key '%s', value: '%s'\n", 
               (char *)_Found_node__->_Key__, (char *)_Found_node__->_Val__);
    else
        printf("Node not found!\n");
    
    // Test fetching by ID
    printf("\nTesting fetch_by_id...\n");
    unsigned long _Target_idx__ = _Found_node__ ? _Found_node__->_IDX__ : 0;
    _Found_node__ = fetch_by_id(_My_hash_map__, _Target_idx__);
    if (_Found_node__)
        printf("Found node with ID %lu, key: '%s', value: '%s'\n", 
               _Target_idx__, (char *)_Found_node__->_Key__, (char *)_Found_node__->_Val__);
    else
        printf("Node with ID %lu not found!\n", _Target_idx__);
    
    // Test fetching by value
    printf("\nTesting fetch_by_value...\n");
    _Found_nodes__ = fetch_by_value(_My_hash_map__, _Val2__, get_data_size(_Val2__) + 1, &_Result_count__);
    if (_Found_nodes__ && _Result_count__ > 0)
    {
        printf("Found %d nodes with value '%s':\n", _Result_count__, _Val2__);
        for (int i = 0; i < _Result_count__; i++)
        {
            printf("  Node %d: key '%s', ID: %lu\n", 
                   i, (char *)_Found_nodes__[i]->_Key__, _Found_nodes__[i]->_IDX__);
        }
        free(_Found_nodes__); // Free the array, not the nodes
    }
    else
        printf("No nodes found with value '%s'\n", _Val2__);
    
    // Clean up
    printf("\nCleaning up hash map...\n");
    _free_hash_map__(_My_hash_map__);
    printf("Hash map cleaned up successfully!\n");
    
    return (0);
}