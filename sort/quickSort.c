#include <stdio.h>
/*快速排序*/
/*时间复杂度：O（NlogN）*/
/*递归：必须考虑结束条件*/

int printArray(int *array, int length)
{
    int ret = 0; 
    for (int idx = 0; idx < length; idx++)
    {
        printf("array[%d] = %d\n", idx, array[idx]);
    }
    return ret;
}

int quickSort(int *array, int start, int end)
{
    int ret = 0;
    if (start >= end)
    {
        return ret;
    }
    int temp = array[0];
    int left = start;
    int right = end;
    while(start < end)
    {
        while(start < end)
        {
            if (temp <= array[end])
            {
                end--;
            }
            else
            {
                array[start++] = array[end];
                //start++;
                break;
            }

        }

        while (start < end)
        {
            if (temp >= array[start]) 
            {
                start++;
            }
            else
            {
                array[end--] = array[start];
                //end--;
                break;
            }
        }
    }
    array[start] = temp;
    quickSort(array, left, start - 1);
    quickSort(array, start + 1, right);
    return ret;
}


int mian()
{
    int array[] = {17, 13, 29, 39, 30, 34, 18};
    int len = sizeof(array) / sizeof(int);
    
    printArray(array, len);
    quickSort(array, 0, len - 1);
    return 0;
}