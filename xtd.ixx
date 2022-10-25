export module xtd;

// C
export import <cassert>;
export import <cctype>;
export import <cerrno>;
export import <cfloat>;
// export import <ciso646>;
export import <climits>;
export import <clocale>;
export import <cmath>;
export import <csetjmp>;
export import <csignal>;
export import <cstdarg>;
export import <cstddef>;
export import <cstdio>;
export import <cstdlib>;
export import <cstring>;
export import <ctime>;

#if __cplusplus >= 201103L || _MSVC_LANG >= 201103L
// export import <ccomplex>;
export import <cfenv>;
export import <cinttypes>;
// export import <cstdalign>;
// export import <cstdbool>;
export import <cstdint>;
// export import <ctgmath>;
export import <cwchar>;
export import <cwctype>;
#endif

// C++
export import <algorithm>;
export import <bitset>;
export import <complex>;
export import <deque>;
export import <exception>;
export import <fstream>;
export import <functional>;
export import <iomanip>;
export import <ios>;
export import <iosfwd>;
export import <iostream>;
export import <istream>;
export import <iterator>;
export import <limits>;
export import <list>;
export import <locale>;
export import <map>;
export import <memory>;
export import <new>;
export import <numeric>;
export import <ostream>;
export import <queue>;
export import <set>;
export import <sstream>;
export import <stack>;
export import <stdexcept>;
export import <streambuf>;
export import <string>;
export import <typeinfo>;
export import <utility>;
export import <valarray>;
export import <vector>;

#if __cplusplus >= 201103L || _MSVC_LANG >= 201103L
export import <array>;
export import <atomic>;
export import <chrono>;
export import <condition_variable>;
export import <forward_list>;
export import <future>;
export import <initializer_list>;
export import <mutex>;
export import <random>;
export import <ratio>;
export import <regex>;
export import <scoped_allocator>;
export import <system_error>;
export import <thread>;
export import <tuple>;
export import <typeindex>;
export import <type_traits>;
export import <unordered_map>;
export import <unordered_set>;
#endif

export namespace xtd
{
	using namespace std;

	//-------------------------------------------------------------------------
	vector<string> args2vec(int argc, char* argv[])
	{
		vector<string> arguments;
		arguments.reserve(argc);
		for (int i{0}; i < argc; ++i)
			arguments.emplace(arguments.end(), argv[i]);
		return arguments;
	}

	//-------------------------------------------------------------------------
	vector<string> split(string_view str, char delimiter)
	{
		vector<string> tokens;
		stringstream ss(string{ str });
		string element;
		while (getline(ss, element, delimiter))
		{
			if (!element.empty())
				tokens.push_back(element);
		}

		return tokens;
	}

	//-------------------------------------------------------------------------
	template <typename T>
	bool within(const T& value, const T& lowInclusive, const T& highInclusive)
	{
		assert(lowInclusive <= highInclusive);
		// Defined using only operator <
		return !(value < lowInclusive) && !(highInclusive < value);
	}

	//-------------------------------------------------------------------------
	template <typename T>
	T remap(const T& value, const T & startFrom, const T& endFrom, const T& startTo, const const T& endTo) {
		return std::lerp(startTo, endTo, (value - startFrom) / (endFrom - startFrom));
	}

	//-------------------------------------------------------------------------
	auto now()
	{
		return std::chrono::system_clock::now();
	}
}
