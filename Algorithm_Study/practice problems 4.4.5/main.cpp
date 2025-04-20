#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// �������� �ϵ� �κ����ĸ� �ؾ���
// �տ��� ���� k������ŭ�� Ȯ����
// 1. �������� �ϵ� �չ迭�� �� ������ �Ѵ�.(k�������� ���ϱ� ������ �޹迭�� ��Ȯ�ϰ� ������ �ʿ� ����)
// 2. ���� ������ �ϴ� ũ�Ⱑ k���� ���� ��� �� �迭�� ���� ������ �Ѵ�.(k���� ��ŭ�� ������ ����Ǿ�� �Ѵ�.)


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
	// �ǹ��� �� �տ� ���Ҹ� �������� �ϱ⿡ left_it������ ���� ���ҷ� ��
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