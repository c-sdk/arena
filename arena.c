#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "arena.h"

int arena_create(arena_t *arena, arena_size_t size) {
  arena->memory = (char *)calloc(sizeof(char), size);
  arena->size = size;
  arena->offset = 0;
  return (arena->memory != NULL) - 1;
}

void* arena_alloc(arena_t *arena, size_t size) {
  if (arena->offset + size > arena->size) {
    arena_log("Error: arena is full.");
    return NULL;
  }
  void *ptr = arena->memory + arena->offset;
  arena->offset += size;
  return ptr;
}

char* arena_string(arena_t *arena, const char *src, size_t length) {
  arena_log("allocating string: (%zu) '%s'\n", length, src);
  char* str = arena_alloc(arena, length);
  (void)memcpy(str, src, length);
  return str;
}

char* arena_string_with_null(arena_t *arena, const char *src, size_t length) {
  char* str = arena_string(arena, src, length);
  str[length - 1] = 0;
  return str;
}

char* arena_string_from_int(arena_t *arena, int number) {
  arena_log("allocating int: %d\n", number);
  int length = snprintf(NULL, 0, "%d", number);
  char* str = arena_alloc(arena, length + 1);
  snprintf(str, length + 1, "%d", number);
  str[length] = 0;
  return str;
}

void arena_free(arena_t *arena) {
  free(arena->memory);
}
