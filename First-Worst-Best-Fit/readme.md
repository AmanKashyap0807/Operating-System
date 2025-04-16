<!-- filepath: /d:/Operating-System/First-Worst-Best-Fit/README.md -->
# Memory Allocation Algorithms: First Fit, Best Fit, and Worst Fit

## Introduction
This program implements three fundamental memory allocation strategies used in operating systems to manage memory resources: First Fit, Best Fit, and Worst Fit. These algorithms determine how memory blocks are allocated to processes requesting memory.

## Concepts

### Memory Allocation in Operating Systems
Memory allocation is a critical function of operating systems that manages how memory resources are assigned to processes. When a program requires memory during execution, the operating system must decide which available memory blocks to allocate to satisfy the request efficiently.

### The Three Allocation Strategies

1. **First Fit Algorithm**
   - Allocates the first available block that is large enough to satisfy the request
   - Simple and usually faster than other strategies
   - May lead to fragmentation at the beginning of memory

2. **Best Fit Algorithm**
   - Allocates the smallest block that is large enough to satisfy the request
   - Aims to minimize wasted space
   - Can create tiny, unusable fragments throughout memory

3. **Worst Fit Algorithm**
   - Allocates the largest block that is large enough to satisfy the request
   - Leaves larger remaining fragments that may be useful for future allocations
   - Can exhaust large blocks quickly, leading to inefficiencies

## Code Explanation

### Data Structures
- `b[]`: Array of memory blocks with their sizes
- `f[]`: Array of files/processes with their memory requirements
- `bf[]`: Tracks whether blocks are allocated (1) or free (0)
- `ff[]`: Stores which block is allocated to which file
- `frag[]`: Stores the fragmentation (unused space) in each allocation

### First Fit Implementation
```c
for (int i = 0; i < nf; i++) {
    for (int j = 0; j < nb; j++) {
        if (bf[j] != 1 && b[j] >= f[i]) {
            ff[i] = j + 1;
            frag[i] = b[j] - f[i];
            bf[j] = 1;
            break;
        }
    }
}