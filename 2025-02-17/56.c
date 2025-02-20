/*
 * https://leetcode.cn/problems/merge-intervals/?envType=study-plan-v2&envId=top-100-liked
 * */

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  *a = *a ^ *b;
  *b = *a ^ *b;
  *a = *a ^ *b;
}

void heapify(int **intervals, int intervalsSize) {
  int length = 0;
  for (int i = 0; i < intervalsSize; i++) {
    int parent = (++length) / 2 - 1;

    while (parent >= 0) {
      int left_child = 2 * parent + 1;
      int right_child = left_child + 1;
      int flag = (right_child >= length) ||
                 (intervals[left_child][0] < intervals[right_child][0]);
      int min_child = (flag > 0) ? left_child : right_child;

      if (intervals[parent][0] > intervals[min_child][0]) {
        swap(*(intervals + parent), *(intervals + min_child));
        swap(*(intervals + parent) + 1, *(intervals + min_child) + 1);
      }

      parent = (parent + 1) / 2 - 1;
    }
  }
}

void print(int **intervals, int intervalsSize) {
  for (int i = 0; i < intervalsSize; i++) {
    printf("%d, %d\n", intervals[i][0], intervals[i][1]);
  }
}

void sort(int **intervals, int intervalsSize) {
  for (int i = 0; i < intervalsSize; i++) {
    heapify(intervals + i, intervalsSize - i);
  }
}

int cmp(const void *a, const void *b) {
  return (*(int **)a)[0] > (*(int **)b)[0];
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int **merge(int **intervals, int intervalsSize, int *intervalsColSize,
            int *returnSize, int **returnColumnSizes) {
  qsort(intervals, intervalsSize, sizeof(intervals[0]), cmp);

  int **res = (int **)malloc(intervalsSize * sizeof(int *));
  *res = intervals[0];
  *returnColumnSizes = (int *)malloc(intervalsSize * sizeof(int));
  (*returnColumnSizes)[0] = 2;
  int end = 0;

  for (int i = 1; i < intervalsSize; i++) {
    if (intervals[i][0] > res[end][1]) {
      res[++end] = intervals[i];
      (*returnColumnSizes)[end] = 2;
    } else
      res[end][1] =
          res[end][1] >= intervals[i][1] ? res[end][1] : intervals[i][1];
  }

  *returnSize = end + 1;

  return res;
}

int main(int argc, char *argv[]) {
  int intervals_[4][2] = {{8, 10}, {2, 6}, {1, 3}, {15, 18}};
  int intervalsSize = 4;
  int intervalsColSize = 2;

  int **intervals = (int **)malloc(4 * sizeof(int *));
  for (int i = 0; i < 4; i++) {
    intervals[i] = intervals_[i];
  }

  int *returnSize = (int *)malloc(sizeof(int));
  int **returnColumnSizes = (int **)malloc(sizeof(int *));

  int **res = merge(intervals, intervalsSize, &intervalsColSize, returnSize,
                    returnColumnSizes);

  print(res, *returnSize);
  for (int i = 0; i < *returnSize; i++) {
    printf("i: %d, col_size: %d\n", i, (*returnColumnSizes)[i]);
  }

  return 0;
}
