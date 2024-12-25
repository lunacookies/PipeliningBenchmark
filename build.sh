#!/bin/sh
clang-format -i 'Entry Point.c'
clang -o PipeliningBenchmark -Os -g -fwrapv -fno-strict-aliasing -fmodules 'Entry Point.c' 'Benchmarks.s'
