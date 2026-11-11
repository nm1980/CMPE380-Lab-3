/**
 ** DynamicArrays.c  - private implementations - student file
 **
 ** Implementation of a (constant growth) Dynamic Array data type             
 **   Modify struc Data in DynamicArrays.h for payload according application  
 **   To change growth policy modify PushToDArray as needed                   
 **                                                                           
 ** Written by: Greg Semeraro,Ph.D.                                           
 ** Modified: Dr. Juan C. Cockburn (jcck@ieee.org)                            
 ** 02/01/2014 JCCK     
 ** 10/02/2015 R Repka 
 ** 03/03/2017 R Repka
 ** 07/21/2017 R.Repka     - added class errors include file
 ** 09/25/2017 R.Repka     - Minor pseudo code correction
 ** 09/15/2019 R. Repka    - Added example pointer usage
 **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ClassErrors.h"
#include "DynamicArrays.h"

/***************************************************************************
 CreateDArray -- Allocates memory and initializes DArray state             
        void CreateDArray(DArray *DArrayHead, unsigned int InitialSize)
 Where:
    DArray *DArrayHead       - Pointer to a storage block which holds the
                               data structure entry 
    unsigned int InitialSize - The initial data block size, could be 0
    returns: void            - nothing is returned.
    errors:                  - This routine will print an error message to 
                               stderror and exit with an error code
 **************************************************************************/
void CreateDArray(DArray *DArrayHead, unsigned int InitialSize) {
   /************************************************************************
   Pseudo code: 
   Initialize array with 0 entries used 
   Initialize capacity (you decide, could be zero)
   Based on capacity allocate memory storage, if necessary 
      If initial capacity is zero, no allocation needed 
      else Allocate storage space for payload according to struc Data
   if memory not allocated print error to stderr and exit with a code 
   
   Access examples:    DArrayHead->Capacity  = something
                       DArrayHead->Payload   = some malloc code
  ************************************************************************/
  /* Initialize array header with 0 entries */
  DArrayHead->EntriesUsed = 0;
  /* Initializes the capacity based on InitialSize input */
  DArrayHead->Capacity = InitialSize; 
  /* Checks to see if the allocation of storage space is needed for payload if initial capacity isn't 0 */
  if (InitialSize > 0) { 
   DArrayHead->Payload = (Data *)malloc(InitialSize * sizeof(Data));
   /* Error message is memory reallocation fails */
  if (DArrayHead->Payload == NULL) {
      fprintf(stderr, "CreateDArray: Memory allocation failed\n");
      exit(MALLOC_ERROR);
  }

  } else {
   /* If initial capacity is 0, no allocation is needed and its set to NULL */
   DArrayHead->Payload = NULL;
  }
  
  
} /* CreateDArray() */


/***************************************************************************
  PushToDArray -- Adds data at the end of the dynamic array and updates its 
                  state in the array header.  If full, reallocates memory 
                  space according to growth policy                          
        unsigned int PushToDArray(DArray *DArrayHead, Data *PayloadPtr)     
Where:
    DArray *DArrayHead      - Pointer to a storage block which holds the
                              data structure entry 
    Data * PayloadPtr       - 
    returns: unsigned int   - The index of the last element inserted
    errors:                 - This routine will print an error message to 
                              stderror and exit with an error code 
 **************************************************************************/
unsigned int PushToDArray(DArray *DArrayHead, Data *PayloadPtr)
{
   /************************************************************************
    Pseudo code: 
    Check if the array needs to be made larger 
    If yes, increase the size of the dynamic array by GROWTH_AMOUNT
    Re-allocate storage for the array elements using larger size 
    if memory not re-allocated print error to stderr and exit 
    Copy the Data in PlayloadPtr into the Darray, using the EntriesUsed as 
    an index into the Darray.
    Increment the number of elements used in Darray header 
    Return the array index of last element inserted 
   ************************************************************************/
   /* Checks if the array needs to be larger*/
   if (DArrayHead->EntriesUsed >= DArrayHead->Capacity) {
      /* Temp variables to hold new capacity and increase based on the growth amount, and temporary pointer for storage reallocation */
      unsigned int tempCapacity = DArrayHead->Capacity + GROWTH_AMOUNT;
      Data *tempData = (Data *)realloc(DArrayHead->Payload, tempCapacity * sizeof(Data));
      /* Check if memory reallocation was successful */
      if (tempData == NULL) {
         fprintf(stderr, "PushToDArray: Memory reallocation failed\n");
         exit(REALLOC_ERROR);
      }
      /* Updates theheader with the temp storage and capacity values if successful */
      DArrayHead->Payload = tempData;
      DArrayHead->Capacity = tempCapacity;
   }
      /* Copies the data from PayloadPtr into the dynamic array at the index specified by EntriesUsed */
      DArrayHead->Payload[DArrayHead->EntriesUsed] = *PayloadPtr;

      /* Increments the number of elements used and returns the array index of the last element inserted */
      unsigned int incrementIndex = DArrayHead->EntriesUsed;
      DArrayHead->EntriesUsed++;

      return incrementIndex;
} /* PushToDArray() */


/*************************************************************************
 DestroyDArray -- Returns the memory back to the heap and updates the   
                  state in the array header      
        void DestroyDArray(DArray *DArrayHead)
  Where:
    DArray *DArrayHead  - Pointer to a storage block which holds the
                          data structure entry 
    returns: void       - nothing is returned.
    errors:             - No errors are reported
*************************************************************************/
void DestroyDArray(DArray *DArrayHead)
{
   /**********************************************************************
    Pseudo code: 
    Set the number of entries used to zero in Darray header 
    Set the capacity to zero in Darray header
    De-allocate the storage for the array elements 
 *************************************************************************/
   /* Set the number of entries used and capacity to 0 */
   DArrayHead->EntriesUsed = 0;
   DArrayHead->Capacity = 0;
   /* De-allocate storage for array elements if the payload isn't NULL */
   if (DArrayHead->Payload != NULL)
   {
      /* Frees up the main payload array */
      free(DArrayHead->Payload);
      DArrayHead->Payload = NULL;
      }
   }
 /* DestroyDArray() */

/**************************************************************************
 Searches the dynamic array for a provided word and returns the
 pointer to the data if found or NULL if not found.

 Where: DArray *DArrayHead - Pointer to the dynamic array to search
        char *String       - The item to search for
 Returns: A pointer to the data found or NULL for not found
 Errors: none
***************************************************************************/
Data *SearchDArray(DArray *DArrayHead, char *String) {
   
   /*-----  Don't implement this until instructed in Lab 6 ----*/
   return NULL;
} /* SearchDArray() */