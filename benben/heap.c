#include <types.h>
#include <benben.h>
#include <sched.h>

#ifdef __STDC__
#include <malloc.h>
#endif // __STDC__

static uint8_t heap[SIMPLE_MEMORY_ALLOC_HEAP_SIZE];
static int free_idx = 0;
#define HEAP_MAX_SIZE                   (~((int)0))
#define heap_is_overflow(a, b)          ((a) > (HEAP_MAX_SIZE - (b)))

void *tmalloc(int size)
{
    int align_num = 0;
    uint8_t *align_mem;

    if (size < 0)
        return NULL;

    if (!(size & MEMORY_ALIGN_MASK)) {
        align_num = MEMORY_ALIGN_BYTE - (size & MEMORY_ALIGN_MASK);

        if (!heap_is_overflow(size, align_num)){
            size += align_num;
        }
        else {
            size = 0;
        }
    }
    // 停止调度器
    align_mem = (uint8_t *)(((uint64_t)&heap[MEMORY_ALIGN_BYTE - 1]) 
                & (~((uint64_t)MEMORY_ALIGN_MASK)));

    if (!heap_is_overflow(free_idx, size)) {
        void *mem = align_mem + free_idx;
        free_idx += size;
    }
    // 恢复调度器
    return mem;
}

void tfree(void *mem)
{

}

/*
 * safe libc alloc
 */
#ifdef __STDC__
void *smalloc(int size)
{
    void *mem;

    if (size < 0)
        return NULL;

    // 停止调度
    mem = malloc(size);
    // 启动调度
    return mem;
}

void sfree(void *mem)
{
    if (mem) {
        // 停止调度
        free(mem);
        // 启动调度
    }
}
#endif // __STDC__