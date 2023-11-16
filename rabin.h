#ifndef _RABIN_H
#define _RABIN_H

#include <stdint.h>

#define WINSIZE 64

struct chunk_t {
  unsigned int start;
  unsigned int length;
  uint64_t cut_fingerprint;
};

struct rabin_t {
  uint8_t window[WINSIZE];
  unsigned int wpos;
  unsigned int count;
  unsigned int pos;
  unsigned int start;
  uint64_t digest;
  struct chunk_t last_chunk;
};

struct rabin_t *rabin_init(void);
void rabin_free(struct rabin_t *h);

void rabin_reset(struct rabin_t *h);
int rabin_next_chunk(struct rabin_t *h, uint8_t *buf, unsigned int len);
struct chunk_t *rabin_finalize(struct rabin_t *h);

#endif
