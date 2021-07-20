#include <vector>
#include <stdexcept>
#include <algorithm>

using std::vector;

double median(vector<double> vec) {
	typedef vector<double>::size_type vec_sz;
	vec_sz size = vec.size();
	//容器为空时抛出异常 
	if (!size) {
		throw std::domain_error("median of an empty vector");
	}
	sort(vec.begin(), vec.end());
	vec_sz mid = vec.size() / 2;
	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}