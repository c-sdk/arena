#ifndef __AIL_ARENA_H__
#define __AIL_ARENA_H__ 1

#include <stddef.h>

typedef size_t arena_size_t;

typedef struct arena_t {
  char *memory;
  arena_size_t size;
  arena_size_t offset;
} arena_t;

int arena_create(arena_t *arena, arena_size_t size);
void* arena_alloc(arena_t *arena, size_t size);
char* arena_string(arena_t *arena, const char *src, size_t length);
char* arena_string_with_null(arena_t *arena, const char *src, size_t length);
char* arena_string_from_int(arena_t *arena, int number);
void arena_free(arena_t *arena);

#endif // __AIL_ARENA_H__
