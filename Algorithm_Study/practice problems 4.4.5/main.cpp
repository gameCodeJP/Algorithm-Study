#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 퀵정렬을 하되 부분정렬만 해야함
// 앞에서 부터 k개수만큼만 확인함
// 1. 퀵정렬을 하되 앞배열만 퀵 정렬을 한다.(k개수만은 원하기 때문에 뒷배열은 정확하게 정렬할 필요 없음)
// 2. 만약 정렬을 하는 크기가 k보다 작을 경우 뒷 배열도 같이 정렬을 한다.(k개수 만큼은 정렬이 보장되어야 한다.)


template<typename T>
void print(typename vector<T>::iterator begin, typename vector<T>::iterator end)
{
	for (begin; begin != end; ++begin)
	{
		cout << *begin << ' ';
	}

	cout << '\n';
}

template<typename T>
auto partition(typename vector<T>::iterator begin, typename vector<T>::iterator end)
{
	// 피벗은 맨 앞에 원소를 기준으로 하기에 left_it시작을 다음 원소로 함
	auto pivot_value = *begin;
	auto left_it = begin + 1;
	auto right_it = end;

	while (true)
	{
		while (*left_it <= pivot_value && distance(left_it, right_it) > 0) ++left_it;
		while (*right_it > pivot_value && distance(left_it, right_it) > 0) --right_it;

		if (left_it == right_it)
			break;

		iter_swap(left_it, right_it);
	}

	if (pivot_value > *right_it)
	{
		iter_swap(begin, right_it);
	}

	print<T>(begin, end);

	return right_it;
}

template<typename T>
void quick_srot(typename vector<T>::iterator begin, typename vector<T>::iterator end, int k)
{
	if (distance(begin, end) < 1)
		return;

	auto right_it = partition<T>(begin, end);
	quick_srot<T>(begin, right_it - 1, k);

	if (distance(begin, right_it) < k)
	{
		quick_srot<T>(right_it, end, k);
	}
}

int main()
{
	vector<int> vec{ 5, 6, 7, 8, 1, 2, 3, 4, 9, 0, 11, 15, 14, 12, 13, 16, 20 };
	quick_srot<int>(vec.begin(), vec.end() - 1, 5);

	return 0;
}