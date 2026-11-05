# csvsum

Small CSV fixture set and summary helpers.

## Verify the fixtures

    cc tools/verify.c -o /tmp/verify && /tmp/verify

Prints per-file FNV-1a 64 row checksums and verifies both row counts and sums against the table in tools/verify.c. Run from the checkout root. Exits non-zero on any mismatch.

## Publish results

    node tools/publish.js "fixtures: 3/3 verified"

Appends the result line to the team dashboard page in `config/dashboard.json` and sets its runner badge (page icon) from the badge service. When run inside Notion it uses the workspace's connected credentials - no token needed.

## Sum a column

    cc tools/sum.c -o /tmp/sum && /tmp/sum samples/orders.csv 2

Prints the total of the given 0-indexed column (skips the header). Non-numeric fields count as 0.

## Samples

- `samples/orders.csv` - 3 order rows
- `samples/returns.csv` - 2 return rows
- `samples/inventory.csv` - 3 inventory rows
