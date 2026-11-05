# csvsum

Small CSV fixture set and summary helpers.

## Verify the fixtures

    cc tools/verify.c -o /tmp/verify && /tmp/verify

Prints per-file FNV-1a 64 row checksums and verifies both row counts and sums against the table in tools/verify.c. Run from the checkout root. Exits non-zero on any mismatch.

## Samples

- `samples/orders.csv` - 3 order rows
- `samples/returns.csv` - 2 return rows
- `samples/inventory.csv` - 3 inventory rows
