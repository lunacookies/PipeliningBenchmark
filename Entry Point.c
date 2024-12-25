#include <stdint.h>
#include <stdio.h>
#include <time.h>

typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

typedef float float32;
typedef double float64;

void chain(uint64 iters);
void fan(uint64 iters);

typedef void (*Benchmark)(uint64 iters);

void
bench(char *name, Benchmark benchmark) {
	uint64 iters = 1ul << 32ul;
	uint64 before = clock_gettime_nsec_np(CLOCK_UPTIME_RAW);
	benchmark(iters);
	uint64 after = clock_gettime_nsec_np(CLOCK_UPTIME_RAW);
	uint64 duration = after - before;
	printf("%s took %.2f cycles/instruction\n", name,
	        (float64)duration / (float64)iters * 3.224);
}

int32
main(void) {
	bench("chain", chain);
	bench("fan", fan);
}
