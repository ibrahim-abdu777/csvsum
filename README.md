# csvsum

Small CSV fixture set and summary helpers.

## Verify the fixtures

    cc tools/verify.c -o /tmp/verify && /tmp/verify

Prints per-file row checksums and confirms the sample fixtures are intact (row counts and FNV-1a sums). Exits non-zero on any mismatch.

## Samples

- `samples/orders.csv` - 3 order rows
- `samples/returns.csv` - 2 return rows
- `samples/inventory.csv` - 3 inventory rows
