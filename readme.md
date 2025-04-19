# Hash Map Implementation in C

## Overview
A simple yet powerful hash map implementation in C. This project provides a versatile data structure for key-value pair storage with efficient lookup operations.

## Features
- Store any type of data as key-value pairs
- Fast lookups using hash-based indexing
- Retrieve items by key, value, or hash ID
- Memory safe with proper cleanup functions
- Support for string data with custom string handling utilities

## Functions
| Function | Description |
|----------|-------------|
| `initem()` | Insert a new key-value pair |
| `fetch_pair()` | Retrieve an item by its key |
| `fetch_by_id()` | Find an item by its hash index |
| `fetch_by_value()` | Find all items with a specific value |
| `_free_hash_map__()` | Clean up the entire hash map |

## Usage Example
```c
// Create a hash map
_H_map_ *my_map = NULL;

// Insert items
initem(&my_map, "name", 5, "John", 5);
initem(&my_map, "age", 4, "30", 3);

// Retrieve items
_H_map_ *item = fetch_pair(my_map, "name", 5);
if (item)
   printf("Value: %s\n", (char*)item->_Val__);

// Clean up when done
_free_hash_map__(my_map);
