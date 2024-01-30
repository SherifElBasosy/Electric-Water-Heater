#ifndef BITWISE_OPERATIONS_H_
#define BITWISE_OPERATIONS_H_

#define SET_BIT( PIN , BIT ) 		( PIN |= (1 << BIT)  )
#define CLEAR_BIT( PIN , BIT ) 		( PIN &= ~(1 << BIT) )
#define TOGGLE_BIT( PIN , BIT ) 	( PIN ^= (1 << BIT)  )
#define GET_BIT(PIN , BIT)			((PIN >> BIT) & 1)

#endif
