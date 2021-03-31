<h1 align="center">RC4-PRNG</h1>
Implementation of RC4-based pseudo-random number generator (PRNG) in C.

# Quick start

Download this repository and go to directory with project.

```
git clone https://github.com/GRISHNOV/RC4-PRNG.git
cd RC4-PRNG
```

Run the project build using the make utility.

```
make
```

Now the `build` folder contains the `RC4_PRNG.o` object file. Use it together with the `RC4_PRNG.h` header file from `include` folder to work with RC4-based pseudo-random number generator in your project.

# Example of use

```C
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "RC4_PRNG.h"

int main(void)
{
	uint8_t  key[]        = { 0x01, 0x02, 0x03, 0x04, 0x05 };
	uint16_t keyLength    = sizeof(key);
	uint64_t streamOffset = 0;
	uint64_t streamLength = 32;

	uint8_t* result = getPseudoRandomBytesStream(key, keyLength, streamOffset, streamLength);
	printPseudoRandomBytesStream(result, streamLength);

	free(result);

	return 0;
}
```

```
gcc main.c RC4_PRNG.o
./a.out
```
Output:
```
b2	39	63	5	f0	3d	c0	27	cc	c3	52	4a	a	11	18	a8
69	82	94	4f	18	fc	82	d5	89	c4	3	a4	7a	d	9	19
```
