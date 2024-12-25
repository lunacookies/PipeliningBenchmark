.global _chain
.align 2
_chain:
	mul	x1, x1, x1
	mul	x1, x1, x1
	mul	x1, x1, x1
	mul	x1, x1, x1
	mul	x1, x1, x1
	mul	x1, x1, x1
	mul	x1, x1, x1
	mul	x1, x1, x1
	sub	x0, x0, #8
	cbnz	x0, _chain
	ret

.global _fan
.align 2
_fan:
	mul	x2, x1, x1
	mul	x2, x1, x1
	mul	x2, x1, x1
	mul	x2, x1, x1
	mul	x2, x1, x1
	mul	x2, x1, x1
	mul	x2, x1, x1
	mul	x2, x1, x1
	sub	x0, x0, #8
	cbnz	x0, _fan
	ret
