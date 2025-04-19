#ifndef GHM_DEFS_H
#define GHM_DEFS_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// typedef hash_map_struct

typedef struct hash_map
{
    unsigned long _IDX__;
    void *_Key__;
    void *_Val__;
    unsigned int _Type__;
    struct hash_map *_LST_Prv__; // the previus item in the list 
    struct hash_map *_LST_Nxt__; //  next hashed item in the list 
} _H_map_;

// def types 

// dwriter !
int get_data_size(const char *data);
int dwriter(char *data, int fd);

// pcalls aka program calls !

// h_packe functions ! aka helper packe ! lol 
int _memRp__(void *_mem_ARA0__, void *_mem_ARA1__, size_t _R_Size__);
int _dmtc_Qmark__(const char *_FSide__, const char *_SSide__);
char *_data_DUP__(const char *_Or_d);
_H_map_ *_gen_HM_pair__(void);
int initem(_H_map_ **_Hm_root__, void *_Key__, size_t _Key_size__, void *_Val__, size_t _Val_size__);
unsigned long _generate_hash_idx__(void *_Key__, size_t _Key_size__);
_H_map_ *fetch_by_key(_H_map_ *_Hm_root__, void *_Key__, size_t _Key_size__);
_H_map_ *fetch_pair(_H_map_ *_Hm_root__, void *_Key__, size_t _Key_size__);
_H_map_ **fetch_by_value(_H_map_ *_Hm_root__, void *_Val__, size_t _Val_size__, int *_Result_count__);
_H_map_ *fetch_by_id(_H_map_ *_Hm_root__, unsigned long _Target_idx__);
void _free_node__(_H_map_ *_Node__);
void _free_hash_map__(_H_map_ *_Hm_root__);

#endif
