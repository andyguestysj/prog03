---
title: Assembly Exercises 2
permalink: /docs/assembly-17/
---

It is possible to generate assembly code directly from c code. 

From the terminal you can generate assembly code with - 

```console
gcc -S main.c -o main.asm
```

If you add the flag `-fverbose-asm` it will add some (possibly) useful comments.

```console
gcc -S fverbose-asm main.c -o main.asm
```

The assembly code won't be elegant, it will be very long winded, but it will work.  


