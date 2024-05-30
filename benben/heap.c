#include <types.h>
#include <benben.h>


/*
 * simple memory alloc
 */
#if MEMORY_ALLOC_TYPE == 0U

static uint8_t heap[SIMPLE_MEMORY_ALLOC_HEAP_SIZE];
static int free_idx = 0;

void *e_alloc(int size)
{
    int align_num = 0;
    uint8_t *align_mem;


    if (size < 0)
        return NULL;

    if (!(size & MEMORY_ALIGN_MASK)) 
        align_num = MEMORY_ALIGN_BYTE - (size & MEMORY_ALIGN_MASK);

    align_mem = (uint8_t *)(((uint64_t)&heap[MEMORY_ALIGN_BYTE - 1]) 
                & (~((uint64_t)MEMORY_ALIGN_MASK)));

    void *mem = align_mem + free_idx;
    free_idx += size;

    return mem;
}

void e_free(void *mem)
{

}

/*
 * thread safe libc alloc
 */
#elif MEMORY_ALLOC_TYPE == 1U
void *e_alloc(int size)
{
    return NULL;
}

void e_free(void *mem)
{
    
}

/*
 * thread safe libc alloc
 */
#elif MEMORY_ALLOC_TYPE == 2U
void *e_alloc(int size)
{
    return NULL;
}

void e_free(void *mem)
{
    
}
#endif // MEMORY_ALLOC_TYPE