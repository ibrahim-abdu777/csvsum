/* sum - column summarizer for csvsum samples. Prints per-column totals. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static double colsum(const char *path, int col) {
    FILE *f = fopen(path, "r");
    if (!f) return 0;
    char line[4096];
    double total = 0;
    int first = 1;
    while (fgets(line, sizeof line, f)) {
        line[strcspn(line, "\r\n")] = 0;
        if (first) { first = 0; continue; }
        char *p = line, *field = line;
        int i = 0;
        while (1) {
            if (*p == ',' || *p == 0) {
                if (i == col) { total += atof(field); break; }
                if (*p == 0) break;
                field = p + 1; i++;
            }
            p++;
        }
    }
    fclose(f);
    return total;
}

static void usage(void) {
    fprintf(stderr, "usage: sum <file.csv> <column-index-from-0>\n");
}

int main(int argc, char **argv) {
    if (argc != 3) { usage(); return 2; }
    printf("%.2f\n", colsum(argv[1], atoi(argv[2])));
    return 0;
}
