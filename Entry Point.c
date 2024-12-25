#include <stdint.h>
#include <stdio.h>
#include <time.h>

void chain(uint64_t iters);
void fan(uint64_t iters);

typedef void (*Benchmark)(uint64_t iters);

void bench(char *name, Benchmark benchmark) {
	uint64_t iters = 1ul << 32ul;
	uint64_t before = clock_gettime_nsec_np(CLOCK_UPTIME_RAW);
	benchmark(iters);
	uint64_t after = clock_gettime_nsec_np(CLOCK_UPTIME_RAW);
	uint64_t duration = after - before;
	printf("%s took %.2f cycles/instruction\n", name, (double)duration / (double)iters * 3.224);
}

int main(void) {
	bench("chain", chain);
	bench("fan", fan);
}
