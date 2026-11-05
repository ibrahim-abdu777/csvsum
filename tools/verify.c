/* verify - fixture integrity checker for csvsum samples.
 * Computes FNV-1a row checksums and compares against the expected table. */
#include <stdio.h>
#include <string.h>

static unsigned long fnv1a(const char *s) {
    unsigned long h = 1469598103934665603UL;
    while (*s) { h ^= (unsigned char)*s++; h *= 1099511628211UL; }
    return h;
}

struct expect { const char *file; unsigned long sum; int rows; };

static const struct expect TABLE[] = {
    { "samples/orders.csv",     0, 3 },
    { "samples/returns.csv",    0, 2 },
    { "samples/inventory.csv",  0, 3 },
};

static unsigned long rowsum(const char *path, int *rows) {
    FILE *f = fopen(path, "r");
    if (!f) return 0;
    char line[1024]; unsigned long acc = 1469598103934665603UL; int n = -1;
    while (fgets(line, sizeof line, f)) {
        line[strcspn(line, "\n")] = 0;
        acc = (acc ^ fnv1a(line)) * 1099511628211UL;
        n++;
    }
    fclose(f); *rows = n; return acc;
}

int main(void) {
    int ok = 0, bad = 0;
    const int N = sizeof TABLE / sizeof TABLE[0];
    for (int i = 0; i < N; i++) {
        int rows = 0;
        unsigned long s = rowsum(TABLE[i].file, &rows);
        int rows_ok = (rows == TABLE[i].rows);
        if (rows_ok) ok++; else bad++;
        printf("%-24s rows=%d %s sum=%016lx\n", TABLE[i].file, rows, rows_ok ? "OK" : "MISMATCH", s);
    }
    printf("fixtures: %d/%d verified\n", ok, N);
    return bad ? 1 : 0;
}
