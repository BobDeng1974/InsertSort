#include <stdio.h>
#include <stdlib.h>

void insert_sort(int *array_p, int size_n, int insert_value_n)
{
    int i;
    
    if(insert_value_n > array_p[size_n - 1]) {
        array_p[size_n] = insert_value_n;
        return;
    }

    for(i=0; i<size_n;i++) {
        if(array_p[i] > insert_value_n) {
            int j;
            for(j=size_n; j>=i; j--) {
                array_p[j] = array_p[j-1];
            }
            array_p[i] = insert_value_n;
            break;
        }
    }
    
    return;
}

int main(int argc, void **argv)
{
    int sorted_data_n;
    
    printf("Please enter the number of data to be sorted:\n");
    scanf("%d", &sorted_data_n);
    
    int *sorted_data_p, *inserted_data_p;
    
    sorted_data_p =  (int *)malloc((sorted_data_n + 1) * sizeof(int));
    if(NULL == sorted_data_p) {
        printf("Malloc failed\n");
        return -1;
    }
    inserted_data_p = sorted_data_p;
    
    int i;

    printf("Please enter the sorted data:\n");
    for(i=0; i<sorted_data_n; i++) {
        scanf("%d", sorted_data_p);
        sorted_data_p++;

    }
    
    int inserted_data;
    printf("\nPlease enter the data to be inserted:\n");
    scanf("%d", &inserted_data);
    
    insert_sort(inserted_data_p, sorted_data_n, inserted_data);
    
    printf("The sorted data sequence after insert one data:\n");
    
    for(i=0;i<=sorted_data_n;i++) {
        printf("%4d ", inserted_data_p[i]);
    }

    printf("\n");

    free(inserted_data_p);

    return 0;
}
