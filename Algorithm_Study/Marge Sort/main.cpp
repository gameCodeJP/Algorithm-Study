#include <iostream>
#include <vector>

using namespace std;

template<typename T>
vector<T> marge(vector<T>& lhs, vector<T>& rhs)
{
	// �� vector���� �̹� ������ �Ǿ� �ֱ� ������ �� ���Һ��� ���ϸ鼭 ���� ������� ���� reslut�� ���Ե�
	auto lhsIt = lhs.begin();
	auto rhsIt = rhs.begin();

	// �� vectorũ�� ��ŭ capacity�� Ȯ��
	vector<T> result;
	result.reserve(static_cast<int>(lhs.size()) + static_cast<int>(rhs.size()));

	while (lhsIt != lhs.end() && rhsIt != rhs.end())
	{
		auto& it = *lhsIt < *rhsIt ? lhsIt : rhsIt;
		result.push_back(*it);
		++it;
	}

	// ���� ���� ���Ұ� �ִ� vector�� ���� ���Ҹ� ��� ����
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

	// ���� ������ �迭�� �ѷ� �����Ͽ� ���� �迭���� ������ �� �� ��ġ�� �����̴�.
	// �׷��⿡ ó���� vectorũ�⿡ mid�� ���ϰ� begin ~ mid, mid ~ end�� ������.
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