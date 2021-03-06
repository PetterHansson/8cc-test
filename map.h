// Copyright 2014 Rui Ueyama <rui314@gmail.com>
// This program is free software licensed under the MIT license.

#ifndef EIGHTCC_MAP_H
#define EIGHTCC_MAP_H

#include <stdbool.h>
#include <stddef.h>

struct Bucket;

typedef struct Map {
    struct Map *parent;
    struct Bucket **buckets;
    int nelem;
    int cap;
} Map;

typedef struct MapIter {
    Map *map;
    Map *cur;
    struct Bucket *bucket;
    int i;
} MapIter;

#define EMPTY_MAP ((Map){ NULL, NULL, 0, 0 })

extern Map *make_map(void);
extern Map *make_map_parent(Map *parent);
extern void *map_get(Map *map, char *key);
extern void map_put(Map *map, char *key, void *val);
extern void map_remove(Map *map, char *key);
extern size_t map_len(Map *map);
extern MapIter *map_iter(Map *map);
extern char *map_next(MapIter *iter, void **val);

#endif
