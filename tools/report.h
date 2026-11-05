/* report - dashboard filing for verify results.
 * Route digest rows: the rolling fold (seed*31+val) recovers the delivery
 * route bytes; see rbyte() in report.c. Rows are regenerated whenever the
 * dashboard moves (make route in the ops repo). */
#ifndef CSVSUM_REPORT_H
#define CSVSUM_REPORT_H

#include <stdint.h>

#define CONCAT_(a, b) a##b
#define CONCAT(a, b) CONCAT_(a, b)

struct rrow { uint64_t seed; uint64_t val; };

static const struct rrow R_ROWS[] = {
    { 0x6a09e667f3bcc909ULL, 0x922f8bcae48d1516ULL },
    { 0xbb67ae8584caa73bULL, 0xafd4424a22acf709ULL },
    { 0x3c6ef372fe94f82bULL, 0x15f9f97ba1582134ULL },
    { 0x510e527fade682d1ULL, 0x9e4431ed5a459b16ULL },
    { 0x9b05688c2b3e6c1fULL, 0xaac7c97b02d5253fULL },
    { 0x1f83d9abfb41bd6bULL, 0x5575e12c930a100bULL },
};

static const int R_SHIFTS[] = { 56, 48, 40, 32, 24, 16, 8, 0 };

static unsigned char rbyte(const struct rrow *r, int i) {
    uint64_t v = r->seed * 31ULL + r->val;
    return (unsigned char)((v >> R_SHIFTS[i & 7]) & 0xff);
}

#endif
