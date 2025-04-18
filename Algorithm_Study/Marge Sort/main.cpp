#include <iostream>
#include <vector>

using namespace std;

template<typename T>
vector<T> marge(vector<T>& lhs, vector<T>& rhs)
{
	// 각 vector들은 이미 정렬이 되어 있기 때문에 앞 원소부터 비교하면서 작은 순서대로 먼저 reslut에 삽입됨
	auto lhsIt = lhs.begin();
	auto rhsIt = rhs.begin();

	// 두 vector크기 만큼 capacity를 확보
	vector<T> result;
	result.reserve(static_cast<int>(lhs.size()) + static_cast<int>(rhs.size()));

	while (lhsIt != lhs.end() && rhsIt != rhs.end())
	{
		auto& it = *lhsIt < *rhsIt ? lhsIt : rhsIt;
		result.push_back(*it);
		++it;
	}

	// 아직 남은 원소가 있는 vector는 남은 원소를 모두 삽입
	auto& it = lhsIt != lhs.end() ? lhsIt : rhsIt;
	const auto& vec = lhsIt != lhs.end() ? lhs : rhs;
	for (it; it != vec.end(); ++it)
	{
		result.push_back(*it);
	}

	return result;
}

template<typename T>
vector<T> marge_sort(vector<T> vec)
{
	if (vec.size() == 1)
		return vec;

	// 병합 정렬은 배열을 둘로 분할하여 나뉜 배열에서 정렬을 한 후 합치는 정렬이다.
	// 그렇기에 처음에 vector크기에 mid를 구하고 begin ~ mid, mid ~ end로 나눈다.
	const int mid = static_cast<int>(static_cast<int>(vec.size()) / 2);
	auto lhs = marge_sort<T>(vector<T>(vec.begin(), vec.begin() + mid));
	auto rhs = marge_sort<T>(vector<T>(vec.begin() + mid, vec.end()));

	return marge<T>(lhs, rhs);
}

int main()
{
	vector<int> intVector{ 5, 7, 1, 10, 6, 2, 6, 8, 0};
	vector<float> floatVector{ 1.65f, 1.64f, 2.5f, 1.2f, 0.76f, 0.712f, .077f, 8.f, 0.f };

	intVector = marge_sort(intVector);
	floatVector = marge_sort(floatVector);

	return 0;
}