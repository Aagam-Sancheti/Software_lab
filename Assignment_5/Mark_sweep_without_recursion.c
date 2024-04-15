#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEAPSIZE 30012

enum status
{
    Allocated,
    Free,
    Marked
};

struct block
{
    enum status status;
    int size;
    struct block *next;
};

char heap[HEAPSIZE];
struct block *list = (void *)&heap[0];

void initializeMemorypool()
{
    list->status = Free;
    list->next = NULL;
    list->size = HEAPSIZE - sizeof(struct block);
    printf("Memory pool initialized\n");
}

void bifurcate_memoryblock(struct block *toallocate, int user_demand)
{
    struct block *remaining = (void *)toallocate + sizeof(struct block) + user_demand;

    remaining->size = toallocate->size - user_demand - sizeof(struct block);
    remaining->next = toallocate->next;
    remaining->status = Free;
    toallocate->size = user_demand;
    toallocate->status = Allocated;
    toallocate->next = remaining;
}

void *allocatememory(int user_demand)
{
    struct block *current_block = list;
    void *allocatedblock = NULL;
    int is_request_fulfilled = 0;

    while (current_block != NULL && !is_request_fulfilled)
    {
        if (current_block->status == Free)
        {
            if (current_block->size == user_demand)
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
    if (is_request_fulfilled)
    {
        printf("Memory of size %d allocated\n", user_demand);
        return allocatedblock;
    }
    else
    {
        printf("Required sized %d memory block cannot be allocated\n", user_demand);
        return NULL;
    }
}

void mark()
{
    struct block *current_block = list;

    while (current_block != NULL)
    {
        if (current_block->status == Allocated)
        {
            current_block->status = Marked;
        }
        current_block = current_block->next;
    }
}

void sweep()
{
    struct block *current_block = list;

    while (current_block != NULL)
    {
        if (current_block->status == Free || current_block->status == Marked)
        {
            current_block->status = Free;
        }
        else if (current_block->status == Allocated)
        {
            printf("Garbage found and collected at address %p with size %d\n", (void *)current_block, current_block->size);
        }
        current_block = current_block->next;
    }
}

void de_allocatememory(void *to_free)
{
    if ((void *)list <= to_free && to_free <= (void *)list + HEAPSIZE)
    {
        struct block *block_to_free = (struct block *)to_free;
        block_to_free->status = Free;
        printf("%d bytes of memory freed\n", block_to_free->size);
    }
    else
    {
        printf("Memory cannot be freed. Error\n");
    }
}

int main()
{
    initializeMemorypool();
    int size;

    printf("Enter the size of memory block to be allocated: ");
    scanf("%d", &size);
    int *i = (int *)allocatememory(size);

    printf("Enter the size of memory block to be allocated: ");
    scanf("%d", &size);
    int *j = (int *)allocatememory(size);

    printf("Enter the size of memory block to be allocated: ");
    scanf("%d", &size);
    int *k = (int *)allocatememory(size);

    printf("\n=== Mark and Sweep Garbage Collection ===\n");
    printf("Adjacency Matrix:\n");

    // Initialize the adjacency matrix
    int adjacency_matrix[3][3] = {{0}};

    // Mark references
    if (i != NULL && j != NULL && k != NULL)
    {
        adjacency_matrix[0][1] = 1;
        adjacency_matrix[1][2] = 1;
    }

    // Print adjacency matrix
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            printf("%d ", adjacency_matrix[row][col]);
        }
        printf("\n");
    }

    printf("\nGarbage Nodes:\n");
    // Free some nodes to simulate garbage collection
    de_allocatememory(i);
    de_allocatememory(j);

    // Perform mark and sweep garbage collection
    mark();
    sweep();

    return 0;
}
