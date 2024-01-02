#include <stdio.h>
/*插入排序*/
#if 1
int insertSort(int *array, int length)
{
    int ret = 0;
    int posVal = 0;
    int preVal = 0;
    for (int idx = 1; idx < length; idx++)
    {
        posVal = array[idx];
        preVal = idx - 1;
        
        while (preVal >= 0 && posVal < array[preVal])
        {
            array[preVal + 1] = array[preVal];
            preVal--;
        }
        array[preVal + 1] = posVal;
    }

    return ret;
}
#endif

int insertSort01(int *array, int length)
{
    int ret = 0;
    int cur = 0;
    int copyNum = 0;
    for (int idx = 1; idx < length; idx++)
    {
        cur = idx;
        copyNum = array[idx];
        while(copyNum < array[cur - 1])
        {
            array[cur] = array[cur - 1];
            cur--;
        }
        array[cur] = copyNum;
    }
    return ret;
}

int printArray(int *array, int length)
{
    int ret = 0; 
    for (int idx = 0; idx < length; idx++)
    {
        printf("array[%d] = %d\n", idx, array[idx]);
    }
    return ret;
}


int main()
{
    int array[] = {54, 78, 3, 89, 127, 128};
    int length = sizeof(array) / sizeof(int);

    insertSort01(array, length);
    printArray(array, length);

    
    return 0;
}