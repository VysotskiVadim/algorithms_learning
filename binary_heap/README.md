## Binary Heap
Header only binary heap implementation which is used in [Priority Queue](../priority_queue/README.md)

## Resizing analysis.

Every time heap reaches size limit(when size equals capacity) at next insert it's increased in size: `New Size = Current Size * Threshold`.

For N inserts with threshold 2 and prior size 1 it's going to be following resizings: `1 + 2 + 4 + ...+ N/4 + N/2 + N`, When we flip it: `N + N/2 + N/4 + ... + 4 + 2 + 1` it looks just like decreasing geometry sequence, Sum of it will be lower then `2N`.
