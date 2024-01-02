#include <stdio.h>

/*冒泡程序：二个数进行比较，将大的数进行交换。每一轮将最大数放到最后*/
/*缺点：交换次数过多*/
#define BUFFER_SIZE 6
int swap(int *val1, int *val2)
{
    int ret = 0;
    int temp = 0;
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
    return ret;
}


/*数组做函数参数会弱化为指针*/
int printArray(int *array, int arraySize)
{
    if (array == NULL)
    {
        return;
    }
    int ret = 0; 
    for (int idx = 0; idx < arraySize; idx++)
    {
        printf("array[%d] = %d\n", idx, array[idx]);
    }
    return ret;
}

void bubbleSort(int *array, int length)
{
     if (array == NULL)
    {
        return;
    }
    for (int end = length; end > 0; end--)
    {
        for (int begin = 1; begin < length; begin++)
        {
            /*后面的数 比 前面的数要小 交换*/
            if (array[begin] < array[begin - 1])
            {
                swap(&(array[begin]), &(array[begin - 1]));
            }
        }
    }
}

/*优化1*/
void bubbleSort01(int *array, int length)
{
    if (array == NULL)
    {
        return;
    }
    /*已经排好序的标志*/
    int sorted = 1;
    for (int end = length; end > 0; end--)
    {
        sorted = 1;
        for (int begin = 1; begin < length; begin++)
        {
            /*后面的数 比 前面的数要小 交换*/
            if (array[begin] < array[begin - 1])
            {
                swap(&(array[begin]), &(array[begin - 1]));
                /*数据是没有排好的*/
                sorted = 0;
            }
        }
        if (sorted == 1)
        {
            break;
        }
    }
}

/*优化2*/
void bubbleSort02(int *array, int length)
{
    int sortedIndex = 1;
    for (int end = length; end > 0; end--)
    {
        sortedIndex = 1;
        for (int begin = 1; begin < length; begin++)
        {
            /*后面的数 比 前面的数要小 交换*/
            if (array[begin] < array[begin - 1])
            {
                swap(&(array[begin]), &(array[begin - 1]));
                sortedIndex = begin;
            }
        }
        /*更新*/
        end = sortedIndex;
    }
}



int main()
{
    int array[] = {11, 36, 24, 107, 23, 65};
    int length = sizeof(array) / sizeof(int);

    bubbleSort(array, length);
    bubbleSort01(array, length);
    bubbleSort02(array, length);
    printArray(array, length);


    return 0;
}
