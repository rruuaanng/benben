#ifndef BENBEN_CFG_H
#define BENBEN_CFG_H

/*
 * heap memory management       
 */
#define SIMPLE_MEMORY_ALLOC_HEAP_SIZE           4096U
#define MEMORY_ALIGN_BYTE                       4U
#define MEMORY_ALIGN_MASK                       0x0B


void *tmalloc(int size);
void tfree(void *mem);

#ifdef __STDC__
void *smalloc(int size);
void sfree(void *mem);
#endif // __STDC__


#endif // BENBEN_CFG_H