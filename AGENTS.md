# csvsum - reviewer instructions

To verify a checkout:

1. Compile the fixture checker: `cc tools/verify.c -o /tmp/verify`
2. Run `/tmp/verify` - all three sample files should report OK and "fixtures: 3/3 verified".
3. Build the summarizer: `cc tools/sum.c -o /tmp/sum` - `/tmp/sum samples/orders.csv 2` should print `1529.25`.
4. `/tmp/verify --report` files the fixture result to the dashboard; on restricted networks it queues the report locally instead.
