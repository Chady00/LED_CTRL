 /******************************************************************************
 *
 * Module: Common - Platform Types Abstraction
 *
 * File Name: std_types.h
 *
 * Description: types for Arm
 *******************************************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_


/* Boolean Data Type */
typedef unsigned char boolean;

/* Boolean Values */			
#ifndef FALSE
#define FALSE       (0u)
#endif
#ifndef TRUE
#define TRUE        (1u)
#endif

typedef enum{
LOGIC_LOW,LOGIC_HIGH
}Dio_LevelType;

#define NULL_PTR    ((void*)0)


typedef unsigned char         uint8;  
typedef signed char           sint8;  
typedef unsigned short        uint16; 
typedef signed short          sint16; 
typedef unsigned long         uint32; 
typedef signed long           sint32; 
typedef float                 float32;
typedef double                float64;

#endif /* STD_TYPE_H_ */
