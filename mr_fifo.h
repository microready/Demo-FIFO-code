/*******************************************************************************
*
* File Name      : mr_fifo.h
* Author         : John Keenan, MicroReady Inc.
* Date           : 12/13/14
* Description    : Header file for cirular fifo
* Notes          : 

*******************************************************************************/
#ifndef _MR_FIFO_H
#define _MR_FIFO_H

/* Enums, Defines, Macros -----------------------------------------------------*/
/* Unions, Structures, TypeDefs -----------------------------------------------*/
typedef enum {FIFO_ERROR = 0, FIFO_SUCCESS = !FIFO_ERROR} FifoStatus;


/* External variables ---------------------------------------------------------*/
/* Function prototypes---------------------------------------------------------*/

void FifoInit(__IO CIRCULAR_FIFO_t *fifo);
FifoStatus FifoPut(__IO CIRCULAR_FIFO_t *fifo, uint8_t ch);
FifoStatus FifoGet(__IO CIRCULAR_FIFO_t *fifo, uint8_t *ch);
FifoStatus FifoIsEmpty(__IO CIRCULAR_FIFO_t *fifo);


#endif


