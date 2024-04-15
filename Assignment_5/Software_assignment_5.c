// program to implement memory management scheme in heap memory. malloc() and free() methods are implemented
#include <stdio.h>
#include <stdlib.h>

#define HEAPSIZE 30012

enum status
{
    Allocated, // 0
    Free,      // 1
};

struct block
{
    enum status status; // typedef could be used to simplify namings , but using enums gives clarity of code
    int size;
    struct block *next;
};
// using the linked list type format for heap management

char heap[HEAPSIZE];                   // heap memory
struct block *list = (void *)&heap[0]; // free list pointer

void intializeMemorypool() // create linked list function simulating memory block (storing it's size as metadata)
{
    list->status = Free;
    list->next = NULL;
    list->size = HEAPSIZE - sizeof(struct block);
    printf("memory pool initialised \n ");
}

void bifurcate_memoryblock(struct block *toallocate, int user_demand)
{
    struct block *remaining = (void *)toallocate + sizeof(struct block) + user_demand;
    /* used pointer arithmetic
     to move sizeof(Block) bytes ahead of the "toAllocate" pointer,
     then adds the size of memory requested by the user. */

    remaining->size = toallocate->size - user_demand - sizeof(struct block);
    remaining->next = toallocate->next;
    remaining->status = Free;
    toallocate->size = user_demand;
    toallocate->status = Allocated;
    toallocate->next = remaining;
}

void combine_free_blocks() // comapction of memory
{
    struct block *previous_block = list, *current_block = list->next->next;
    while (current_block != NULL && current_block->next != NULL)
    {
        if (previous_block->status == Free && current_block->status == Free)
        {
            previous_block->size = previous_block->size + sizeof(struct block) + current_block->size;
            previous_block->next = current_block->next;
        }
        previous_block = current_block;
        current_block = current_block->next;
    }
}

void *allocatememory(int user_demand) // malloc function
{
    struct block *current_block = list;
    void *allocatedblock = NULL;  // pointer that'll will be subsequently returned
    int is_request_fulfilled = 0; // boolean to check allocation status

    while (current_block != NULL && !is_request_fulfilled)
    {
        if (current_block->status == Free)
        {
            if (current_block->size == user_demand) // if we find the exact size as asked by the user then
            {
                current_block->status = Allocated;
                allocatedblock = (void *)current_block;
                is_request_fulfilled = 1;
            }
            else if (current_block->size > user_demand + sizeof(struct block))
            {
                bifurcate_memoryblock(current_block, user_demand);
                allocatedblock = (void *)current_block;
                is_request_fulfilled = 1;
            }
        }
        current_block = current_block->next;
    }
    if (is_request_fulfilled == 1)
    {
        printf(" memory of size  %d + 12 bytes is allocated as per user demand \n ", user_demand);
        return allocatedblock;
    }
    else
    {
        printf("required sized : %d memory block cannot be allocated \n ", user_demand);
        return NULL;
    }
}

void de_allocatememory(void *to_free) // free() function
{
    if ((void *)list <= to_free && to_free <= (void *)list + HEAPSIZE) // checking if given address is in the bounds of heap
    {
        struct block *block_to_free = (struct block *)to_free; // type casting the pointer
        block_to_free->status = Free;
        combine_free_blocks();
        printf("~ %d bytes of memory freed.\n", block_to_free->size);
    }
    else
    {
        printf("memory cannot be freed. Error \n ");
    }
}

int main()
{
    intializeMemorypool();
    int size;

    printf("enter the size of memory block to be alloacted : ");
    scanf("%d", &size);
    int *i = (int *)allocatememory(size);

    printf("enter the size of memory block to be alloacted : ");
    scanf("%d", &size);
    int *j = (int *)allocatememory(size);

    de_allocatememory(i);
    de_allocatememory(j);

    return 0;
}