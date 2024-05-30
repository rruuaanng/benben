#ifndef BENBEN_CFG_H
#define BENBEN_CFG_H

/*
 * heap memory management
 *
 * 0U        simple memory alloc
 * 1U        thread safe libc memory alloc
 * 2U        
 */ 
#define MEMORY_ALLOC_TYPE                       0U
#define SIMPLE_MEMORY_ALLOC_HEAP_SIZE           4096U
#define MEMORY_ALIGN_BYTE                       4
#define MEMORY_ALIGN_MASK                       0x0B

extern void *e_alloc(int size);
extern void e_free(void *mem);

#endif // BENBEN_CFG_H