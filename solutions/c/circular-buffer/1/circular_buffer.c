#include "circular_buffer.h"

#include <errno.h>
#include <memory.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct circular_buffer_t {
    buffer_value_t *val;
    size_t start;
    size_t end;
    size_t sz;
};

static inline bool isEmpty(const circular_buffer_t *ref) {
    return ref->start == ref->end;
}

static inline bool isFull(const circular_buffer_t *ref) {
    return (ref->end - ref->start) == ref->sz;

}

circular_buffer_t * new_circular_buffer(size_t capacity) {
    circular_buffer_t *cirbuf = calloc(1, sizeof(*cirbuf));
    if (cirbuf) {
        cirbuf->val = calloc(capacity, sizeof(*(cirbuf->val)));
        if (!cirbuf->val) { free(cirbuf); return NULL; }
        cirbuf->sz = capacity;
    }
    return cirbuf;
}

int16_t read(circular_buffer_t *buffer, buffer_value_t *read_value) {
    if (isEmpty(buffer)) {
        errno = ENODATA;
        return EXIT_FAILURE;
    }

    printf("buffer->start = %ld buffer->end = %ld", buffer->start, buffer->end);
    
    *read_value = buffer->val[buffer->start % buffer->sz];
    buffer->start++;
    return EXIT_SUCCESS;
}

int16_t write(circular_buffer_t * buffer, const buffer_value_t write_value) {
    if (isFull(buffer)) {
        errno = ENOBUFS;
        return EXIT_FAILURE;
    }

    printf("buffer->start = %ld buffer->end = %ld", buffer->start, buffer->end);

    buffer->val[buffer->end % buffer->sz] = write_value;
    buffer->end++;
    return EXIT_SUCCESS;
}

int16_t overwrite(circular_buffer_t * buffer, const buffer_value_t write_value) {
    buffer->val[buffer->end % buffer->sz] = write_value;
    buffer->end++;

    if (buffer->end - buffer->start > buffer->sz)
        buffer->start++;
    return EXIT_SUCCESS;
}

void clear_buffer(circular_buffer_t *buffer) {
    buffer->end = 0;
    buffer->start = 0;
}

void delete_buffer(circular_buffer_t *buffer) {
    free(buffer->val);
    free(buffer);
}