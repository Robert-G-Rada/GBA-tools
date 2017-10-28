.macro SWAP a, b
			eor		\a, \a, \b
			eor		\b, \b, \a
			eor		\a, \a, \b
.endm
