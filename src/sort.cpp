#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "assert.h"
#include <cstring>
using namespace std;

int origin[8] = {2, 3, 1, 6, 4, 8, 7, 9};
int res[8] = {1, 2, 3, 4, 6, 7, 8, 9};

int check(int (&arr)[], int (&ans)[])
{
    for (int i = 0; i < 8; i++)
    {
        if (arr[i] != ans[i])
            return -1;
    }
    return 0;
}
int display(int (&arr)[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}
// 一下排序默认为升序排序
// 冒泡排序
// 通过交换每次将最大/最小的数放置数组的尾/首
int swap(int &a, int &b)
{
    int temp = 0;
    temp = a;
    a = b;
    b = temp;
    return 0;
}
int bubbleSort(int (&arr)[], int length)
{
    if (length == 0)
    {
        throw out_of_range("the length of array is 0");
        return -1;
    }
    else if (length == 1)
    {
        return 0;
    }
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (i == length - 1)
                break;
            else
            {
                if (arr[i] > arr[j])
                {
                    swap(arr[i], arr[j]);
                }
            }
        }
    }
    return 0;
}
// 快速排序
// 使用一个基准值，保证每一次排序后局部有序，即基准值左边的值均小于基准值，然后通过对左右子数组递归得到排序结果
int quickSort(int (&arr)[], int left, int right)
{
    if (left >= right)
        return 0;
    int pivot = arr[left];
    int i = left, j = right;
    while (i < j)
    {
        while (i < j && arr[i] < pivot)
        {
            i++;
        }
        while (i < j && arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
            swap(arr[i], arr[j]);
    }

    swap(pivot, arr[i]);
    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
    return 0;
}
// 选择排序
// 每次遍历数组，将最小的数字与数列首交换
int selectSort(int (&arr)[], int length)
{
    for (int i = 0; i < length; i++)
    {
        int index = i;
        int minvalue = 0;
        for (int j = i; j < length; j++)
        {
            minvalue = min(arr[i], arr[j]);
            if (minvalue == arr[j])
                index = j;
        }
        swap(arr[i], arr[index]);
    }
    return 0;
}
// 堆排序(大顶堆)
// 首先建立一个大顶堆，此时保证堆顶值最大，
// 然后将其与末尾数字交换，这样确定了末尾，并对前面的新数组重新建堆
int siftdown(int (&arr)[], int largest, int heapsize)
{
    int i = largest;
    int left = largest * 2 + 1;
    int right = largest * 2 + 2;
    // 保证选取三个节点中最大的成为新的父节点
    if (left < heapsize && arr[i] < arr[left])
    {
        i = left;
    }
    if (right < heapsize && arr[i] < arr[right])
    {
        i = right;
    }
    if (i != largest)
    {
        swap(arr[i], arr[largest]);
        siftdown(arr, i, heapsize);
    }
    return 0;
}
int heapSort(int (&arr)[], int heapsize)
{
    // 构建大顶堆
    for (int i = heapsize / 2 - 1; i >= 0; i--)
        siftdown(arr, i, heapsize);
    // 排序
    for (int i = heapsize - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        // 重新建堆
        siftdown(arr, 0, i);
    }
    return 0;
}
// 插入排序
// 将数值插入数组合适的位置, 每次确定前面的数组局部有序
int insertSort(int (&arr)[], int length)
{
    for (int i = 0; i < length; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    // display(temp, length+1);
    return 0;
}
// 归并排序
// 利用分治的思想，形成左右局部有序的数组，再进行合并
// 合并两个有序数组arr[left...mid] && arr[mid+1...right]
int merge(int (&arr)[], int left, int mid, int right)
{
    int indexl = 0, indexr = 0;
    int n1 = mid - left + 1, n2 = right - mid;
    int arrl[n1], arrr[n2];
    for (int i = left; i <= mid; i++)
        arrl[i - left] = arr[i];
    assert(arrl[0] == arr[left] && arrl[n1 - 1] == arr[mid]);
    for (int i = mid + 1; i <= right; i++)
        arrr[i - mid - 1] = arr[i];
    assert(arrr[0] == arr[mid + 1] && arrr[n2 - 1] == arr[right]);
    for (int k = left; k <= right; k++)
    {
        if (arrl[indexl] < arrr[indexr] && indexl < n1)
        {
            arr[k] = arrl[indexl++];
            continue;
        }
        if (arrl[indexl] > arrr[indexr] && indexr < n2)
        {
            arr[k] = arrr[indexr++];
            continue;
        }
        if (indexl >= n1)
        {
            arr[k] = arrr[indexr++];
            continue;
        }
        if (indexr >= n2)
        {
            arr[k] = arrl[indexl++];
            continue;
        }
    }
    return 0;
}
int mergeSort(int (&arr)[], int start, int end)
{
    if (start >= end)
        return 0;
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
    return 0;
}
// 桶排序
// 将大量数据根据数值分到不同的桶中，然后依次排序，最后拼接成整个数量参数传递
int bucketSort(int (&arr)[], int bucketNum, int length) // 桶的数
{
    vector<int> bucket[bucketNum];
    for (int i = 0; i < length; i++)
    {
        int bucketId = arr[i] / 4;
        bucket[bucketId].push_back(arr[i]);
    }
    int indexAns = 0;
    for (int i = 0; i < bucketNum; i++)
    {
        sort(bucket[i].begin(), bucket[i].end());
        for (int j = 0; j < bucket[i].size(); j++)
        {
            arr[indexAns++] = bucket[i][j];
        }
    }
    return 0;
}
// 基数排序
//根据键值的每位数字进行排序
int radixSort(int (&arr)[], int length){
    int max = 0;
    for(int i = 0;i < length;i++){
        max = max > arr[i] ? max : arr[i];
    }
    int count[10];
    int temp[length];
    int radix = 1;
    while(max / radix > 0){
        memset(count, 0, sizeof(count));
        for(int i = 0;i < length;i++){
            count[(arr[i]/radix)%10]++;
        }
        for(int i = 1;i < 10;i++){
            count[i] += count[i-1];
        }
        for(int i = length-1;i >= 0;i--){
            temp[count[(arr[i]/radix)%10]-1] = arr[i];
            count[(arr[i]/radix)%10]--;
        }
        for(int i = 0;i < length;i++){
            arr[i] = temp[i];
        }
        radix *= 10;
    }
    return 0;
}

// 计数排序
//统计每个元素出现了几次，然后依次排序
int countingSort(int (&arr)[], int length){
    int max = 0;
    for(int i = 0;i < length;i++){
        max = max > arr[i] ? max : arr[i];
    }
    int count[max+1];
    fill(count,count+max+1, 0);
    for(int i= 0;i < length;i++){
        count[arr[i]]++;
    }
    int j = 0;
    for(int i = 0;i < max+1;i++){
        while(count[i] > 0){
            arr[j++] = i;
            count[i]--;
        }
    }
    return 0;
}

int main()
{
    int arr[8];
    int length = 8;
    copy(begin(origin), end(origin), arr);
    // bubbleSort(arr, length);
    // quickSort(arr, 0, length-1);
    // selectSort(arr, length);
    // heapSort(arr, length);
    // insertSort(arr, length);
    //mergeSort(arr, 0, length - 1);
    //bucketSort(arr, 4, length);
    //countingSort(arr, length);
    radixSort(arr, length);
    // display(arr,length);
    if (check(arr, res) == -1)
    {
        cout << "Failed" << endl;
        display(arr, length);
    }
    return 0;
}