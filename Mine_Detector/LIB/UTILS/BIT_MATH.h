#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG_NAME,No_Of_Bit) REG_NAME |= (1 << No_Of_Bit)
#define CLEAR_BIT(REG_NAME,No_Of_Bit) REG_NAME &= ~(1 << No_Of_Bit)
#define TOGGLE_BIT(REG_NAME,No_Of_Bit) REG_NAME ^= (1 << No_Of_Bit)
#define READ_BIT(REG_NAME,No_Of_Bit) ((REG_NAME >> No_Of_Bit)&1)

#endif /* BIT_MATH_H */
