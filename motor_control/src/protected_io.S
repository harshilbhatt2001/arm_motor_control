
/*
 * protected_io.S
 *
 * Created: 20-03-2021 14:20:28
 *  Author: harsh
 */ 

#include "../utils/assembler.h"

/*
	 * GNU and IAR use different calling conventions. Since this is
	 * a very small and simple function to begin with, it's easier
	 * to implement it twice than to deal with the differences
	 * within a single implementation.
	 */

	PUBLIC_FUNCTION(protected_write_io)

#if defined(__GNUC__)
	/*
	 * We need to disable interrupts globally before the protected
	 * sequence. In order to do that we must save SREG first.
	 */
	in      r18,    _SFR_IO_ADDR(SREG)
	cli
  
#ifdef RAMPZ
	out     _SFR_IO_ADDR(RAMPZ), r1         // Clear bits 23:16 of Z
#endif
	movw    r30, r24                // Load addr into Z
	st      Z, r22                  // Write protection bit to I/O register
	st      Z, r20                  // Write value to I/O register
	out     _SFR_IO_ADDR(SREG), r18

	ret                             // Return to caller

#elif defined(__IAR_SYSTEMS_ASM__)

# if !defined(CONFIG_MEMORY_MODEL_TINY) && !defined(CONFIG_MEMORY_MODEL_SMALL) \
                && !defined(CONFIG_MEMORY_MODEL_LARGE)
#  define CONFIG_MEMORY_MODEL_SMALL
# endif
        /*
         * We need to disable interrupts globally before the protected
         * sequence. In order to do that we must save SREG first.
         */
	in      r21,    SREG
        cli
# if defined(CONFIG_MEMORY_MODEL_LARGE)
	ldi     r20, 0
	out     RAMPZ, r20              // Reset bits 23:16 of Z
	movw    r30, r16                // Load addr into Z
# elif defined(CONFIG_MEMORY_MODEL_TINY)
	ldi     r31, 0                  // Reset bits 8:15 of Z
	mov     r30, r16                // Load addr into Z
# else
	movw    r30, r16                // Load addr into Z
# endif
# if defined(CONFIG_MEMORY_MODEL_TINY)
	st      Z, r17                  // Write protection bit to I/O register
	st      Z, r18                  // Write value to I/O register
# elif defined(CONFIG_MEMORY_MODEL_SMALL)
	st      Z, r18                  // Write protection bit to I/O register
	st      Z, r19                  // Write value to I/O register
# elif defined(CONFIG_MEMORY_MODEL_LARGE)
	st      Z, r19                  // Write protection bit to I/O register
	st      Z, r20                  // Write value to I/O register
# else
#  error Unknown memory model in use, no idea how registers should be accessed
# endif
	out SREG, r21

        ret
#else
# error Unknown assembler
#endif

	END_FUNC(protected_write_io)
	END_FILE()

