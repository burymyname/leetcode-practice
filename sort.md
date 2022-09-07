# 排序算法总结

## 冒泡排序

每次比较相邻两个元素，顺序错误则交换。
```
void bubbleSort(vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] > nums[j+1]) {
                int tmp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = tmp;
            }
        }
    }
}
```

- 稳定
- 时间：`O(n2)`
- 空间：`O(1)`

## 选择排序

在未排序序列中找到最小元素，放在起始位置，再从未排序序列中寻找最小元素，放在已排序序列末尾
```
void selectSort(vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
        int min = i;
        for (int j = i+1; j < nums.size(); ++j) {
            if (nums[j] < nums[min]) {
                min = j;
            }
        }

        if (min != i) {
            int tmp = nums[i];
            nums[i] = nums[min];
            nums[min] = tmp;
        }
    }
}
```

- 数组实现是不稳定的，链表是稳定的
- 时间：`O(n2)`
- 空间：`O(1)`

## 插入排序

将待排序数组分为已排序和未排序，初始默认第一个数为已排序。从第二个元素开始，将已排好序的子数组中寻找该元素合适位置插入。

```
void insertSort(vector<int> &nums) {
    for (int i = 1; i < nums.size(); ++i) {
        int value = nums[i];
        int pos = i;
        while (pos > 0 && nums[pos-1] > value) {
            nums[pos] = nums[pos-1];
            --pos;  
        }
        nums[pos] = value;
    }
}
```

- 稳定
- 时间：`O(n2)`
- 空间：`O(1)`

## 归并排序

分治法，将有序的子序列合并，得到完全有序的序列。

- 递归写法(top-down)
```
void mergeSort(vector<int> &nums) {
    vector<int> temp(nums.size());
    internalMergeSort(nums, temp, 0, nums.size()-1);
}

void internalMergeSort(vector<int> &nums, vector<int> &temp, int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;
    internalMergeSort(nums, temp, left, mid);
    internalMergeSort(nums, temp, mid+1, right);
    merge(nums, temp, left, mid, right);
}

void merge(ector<int> &nums, vector<int> &temp, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
        temp[k++] = nums[i] <= nums[j] ? nums[i++] : nums[j++];
    }

    while (i <= mid) {
        temp[k++] = temp[i++];
    }

    while (j <= right) {
        temp[k++] = temp[j++];
    }

    for (i = 0; i < k; ++i) {
        nums[i] = temp[i];
    }
}
```

- 稳定
- 时间：`O(nlogn)`
- 空间：`O(n)`

## 快速排序

从数列中挑出一个元素，称为"基准"(pivot)。将比基准值小的元素放在前面，比基准值大的元素放在后面，结束以后，该基准就处于中间且正确的位置(partition)。递归的对前后两个区间排序。
```
void quickSort(vector<int> &nums) {
    qsort(nums, 0, nums.size() - 1);
}

void qsort(vector<int> &nums, int left, int right) {
    if (left >= right) return;

    int pivot = partition(nums, left, right);
    qsort(nums, left, pivot-1);
    qsort(nums, pivot+1, right);
}

int partition(vector<int> &nums, int left, int right) {
    int pivot = nums[left];
    while (low < right) {
        while (low < right && nums[right] >= pivot) --right;
        nums[left] = nums[right];
        while (low < right && nums[left] <= pivot) ++left;
        nums[right] = nums[left];
    }
    nums[left] = pivot;

    return left;
}
```

- 不稳定
- 时间：`O(nlogn)`
- 空间：`O(nlogn)`

## 堆排序

选择排序的一种，将最大堆的堆顶最大数取出，将剩余的堆继续调整为最大堆。  

堆为完全二叉树，有以下特征
- parent(i) = floor((i-1)/2)
- left(i) = 2i+1
- right(i) = 2i+2

```
void adjustHeap(int i, int len) {
        int left, right, j;
        left = getLeftChildIndex(i);
        while (left <= len) {
            right = left + 1;
            j = left;
            if (j < len && arr[left] < arr[right]) {
                j++;
            }
            if (arr[i] < arr[j]) {
                swap(array, i, j);
                i = j;
                left = getLeftChildIndex(i);
            } else {
                break; // 停止筛选
            }
        }
    }

void heapSort(vector<int> &nums) {
    int last = nums.size() - 1;
    for (int i = getParentIndex(last); i >= 0; --i) {
        adjustHeap(i, last);
    }

    while (last >= 0) {
        swap(0, last--);
        adjustHeap(0, last);
    }
}
```
适用于前n大的数场景

- 不稳定
- 时间：`O(nlogn)`
- 空间：`O(1)`

