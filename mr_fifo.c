/*******************************************************************************
*
* File Name      : mr_fifo.h
* Author         : John Keenan, MicroReady Inc.
* Date           : 12/13/14
* Description    : Routines for cirular fifo
* Notes          : 

*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "common.h"
#include "mr_fifo.h"

/******************************* Private ***************************************/
/* Enums, Defines, Macros -----------------------------------------------------*/
/* Unions, Structures, TypeDefs -----------------------------------------------*/
/* Variables ------------------------------------------------------------------*/
/* Functions ------------------------------------------------------------------*/

/******************************* Public ****************************************/
/* Variables ------------------------------------------------------------------*/




/*******************************************************************************
* Function Name  : FifoInit(__IO CIRCULAR_FIFO_t *fifo)
* Input          : ptr to fifo
* Output         : None
* Return         : None
* Description    : 
* Notes          :
*******************************************************************************/
void FifoInit(__IO CIRCULAR_FIFO_t *fifo)
{
fifo->count = 0;//0 bytes in fifo
fifo->in = 0;//index points to start
fifo->out = 0;//index points to start
}

/*******************************************************************************
* Function Name  : FifoPut(__IO CIRCULAR_FIFO_t *fifo, uint8_t ch)
* Input          : ptr to fifo, character to put in fifo buffer
* Output         : None
* Return         : None
* Description    : 
* Notes          :
*******************************************************************************/
FifoStatus FifoPut(__IO CIRCULAR_FIFO_t *fifo, uint8_t ch)
{
if(fifo->count==USART_BUFFER_SIZE)
	return FIFO_ERROR;//fifo full
fifo->buffer[fifo->in++]=ch;
fifo->count++;
if(fifo->in==USART_BUFFER_SIZE)
	fifo->in=0;//start from beginning
return FIFO_SUCCESS;
}

/*******************************************************************************
* Function Name  : FifoGet(__IO CIRCULAR_FIFO_t *fifo, uint8_t *ch)
* Input          : ptr to fifo, ptr to character to store character
*                  got from fifo buffer
* Output         : None
* Return         : None
* Description    : 
* Notes          :
*******************************************************************************/
FifoStatus FifoGet(__IO CIRCULAR_FIFO_t *fifo, uint8_t *ch)
{
if(fifo->count==0)
	return FIFO_ERROR;//fifo empty
*ch=fifo->buffer[fifo->out++];
fifo->count--;
if(fifo->out==USART_BUFFER_SIZE)
	fifo->out=0;//start from beginning
return FIFO_SUCCESS;
}

/*******************************************************************************
* Function Name  : FifoIsEmpty(__IO CIRCULAR_FIFO_t *fifo)
* Input          : fifo
* Output         : None
* Return         : FIFO_SUCCESS if fifo empty; FIFO_ERROR otherwise
* Description    : Checks if fifo empty
* Notes          :
*******************************************************************************/
FifoStatus FifoIsEmpty(__IO CIRCULAR_FIFO_t *fifo)
{
if(fifo->count==0)
		return FIFO_SUCCESS;//fifo empty
	return FIFO_ERROR;
}
