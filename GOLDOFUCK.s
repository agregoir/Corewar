.name "GOLDOFUCK"
.comment "Fulguroooofiiiiiiist !!!!!!"

barrack:	st r1, 6
			live %1717569126
			fork %65531

sort:		st r1, 6
			live %1717569126
			xor r2, %1, r2
			st r2, -5
			xor r2, %1, r2
			zjmp %65531
			fork %200

yolo:		ld %57672960, r5
			ld %268435456, r6
			st r5, 20
			st r6, 19
			st r1, 6
			live %1717569126
