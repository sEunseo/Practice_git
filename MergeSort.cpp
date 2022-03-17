/*
#include <iostream>
using namespace std;

int sorted[8] = { 0, };
void merge(int arr[], int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {		//두 subarr 비교. 
			sorted[k++] = arr[i++];
		}
		else {
			sorted[k++] = arr[j++];
		}
	}
	if (i > mid) {		//i가 mid보다 커졌단 소리는 mid 오른쪽에 값이 남아있다는 뜻.
		for (int t = j; t <= right; t++) {
			sorted[k++] = arr[t];
		}
	}
	else {				//i가 mid보다 작거나 같다는 것은 mid 왼쪽에 값이 남아있다는 뜻.
		for (int t = i; t <= mid; t++) {
			sorted[k++] = arr[t];
		}
	}

	//정렬된 값을 임시로 저장한 sorted 배열에서 arr에 값 복사
	for (int t = left; t <= right; t++) {
		arr[t] = sorted[t];
	}
}

void merge_sort(int arr[], int left, int right) {
	int mid = 0;

	if (left < right) {		//넘어온 배열의 left가 right보다 작을때 -> left==right이면 원소가 하나라는 뜻이므로 분할X
		mid = (left + right) / 2;
		merge_sort(arr, left, mid);			//반으로 자른 앞부분 분할
		merge_sort(arr, mid + 1, right);	//반으로 자른 뒷부분 분할
		merge(arr, left, mid, right);		//두개의 subarr 병합
	}
}

int main() {
	int arr[8] = { 21,10,12,20,25,13,15,22 };

	merge_sort(arr, 0, 7);

	for (int i = 0; i < 8; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}
*/