#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
auto patition(typename vector<T>::iterator begin, typename vector<T>::iterator end)
{
	T pivotValue = *begin;
	auto leftIt = begin + 1;
	auto rightIt = end;

	while (true)
	{
		while (*leftIt <= pivotValue && distance(leftIt, rightIt) > 0) ++leftIt;
		while (*rightIt > pivotValue && distance(leftIt, rightIt) > 0) --rightIt;

		if (leftIt == rightIt)
			break;

		iter_swap(leftIt, rightIt);
	}

	if (pivotValue > *rightIt)
	{
		iter_swap(begin, rightIt);
	}

	return rightIt;
}

template<typename T>
void quick_sort(typename vector<T>::iterator begin, typename vector<T>::iterator end)
{
	if (static_cast<int>(distance(begin, end)) <= 1)
		return;

	auto it = patition<T>(begin, end);

	quick_sort<T>(begin, it - 1);
	quick_sort<T>(it, end);
}

int main()
{
	vector<int> intVector{ 5, 7, 1, 10, 6, 2, 6, 8, 0 }; 
	vector<float> floatVector{ 1.65f, 1.64f, 2.5f, 1.2f, 0.76f, 0.712f, .077f, 8.f, 0.f };

	quick_sort<int>(intVector.begin(), intVector.end() - 1);
	quick_sort<float>(floatVector.begin(), floatVector.end() - 1);

	return 0;
}