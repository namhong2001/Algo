#include <cstdio>
#include <cstdlib>

using namespace std;
const int N_MAX = 5e6;
const int LEFT = -1e9;
const int RIGHT = 1e9;

int solve(int left, int right, int kth, int* bucket, int bucket_size) {
    if (bucket_size == 1) return bucket[0];

    int *lo = (int *)malloc(sizeof(int) * bucket_size);
    int *hi = (int *)malloc(sizeof(int) * bucket_size);
    int *lo_ptr = lo;
    int *hi_ptr = hi;
    int pivot = (right+left)/2;
    for (int i=0; i<bucket_size; ++i) {
        if (bucket[i] > pivot) {
            *hi_ptr = bucket[i];
            hi_ptr++;
        } else {
            *lo_ptr = bucket[i];
            lo_ptr++;
        }
    }
    int lo_size = (lo_ptr - lo);
    int hi_size = (hi_ptr - hi);
    free(bucket);
    if (lo_size >= kth) {
        free(hi);
        return solve(left, pivot, kth, lo, lo_size);
    } else {
        free(lo);
        return solve(pivot+1, right, kth-lo_size, hi, hi_size);
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int *arr = (int *)malloc(sizeof(int) * N_MAX);
    int min = RIGHT;
    int max = LEFT;
    for (int i=0; i<n; ++i) {
        scanf("%d", &arr[i]);
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    printf("%d", solve(min, max, k, arr, n));

    return 0;
}
