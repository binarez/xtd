#pragma once

// C
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
// #include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L || _MSVC_LANG >= 201103L
// #include <ccomplex>
#include <cfenv>
#include <cinttypes>
// #include <cstdalign>
// #include <cstdbool>
#include <cstdint>
// #include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L || _MSVC_LANG >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

#if __cplusplus >= 201703L || _MSVC_LANG >= 201703L
#include <string_view>
#endif

using namespace std;

namespace xtd
{
	template <typename TO, typename FROM>
	TO cast(const FROM& from)
	{
		return static_cast<TO>(from);
	}

	//-------------------------------------------------------------------------
	vector<string> args2vec(int argc, char* argv[])
	{
		vector<string> arguments;
		arguments.reserve(argc);
		for (int i{ 0 }; i < argc; ++i)
			arguments.emplace(arguments.end(), argv[i]);
		return arguments;
	}

	//-------------------------------------------------------------------------
#if __cplusplus >= 201703L || _MSVC_LANG >= 201703L
	vector<string> split(string_view str, char delimiter)
#else
	vector<string> split(const string & str, char delimiter)
#endif
	{
		vector<string> tokens;
#if __cplusplus >= 201703L || _MSVC_LANG >= 201703L
		stringstream ss(string{ str });
#else
		stringstream ss(str);
#endif
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
	T lerp(const T & a, const T & b, const T & t)
	{
#if __cplusplus >= 202002L || _MSVC_LANG >= 202002L
		return std::lerp(a, b, t);
#else
		return a + t * (b - a);	// naive lerp
#endif
	}

	//-------------------------------------------------------------------------
	template <typename T>
	T remap(const T& value, const T& startFrom, const T& endFrom, const T& startTo, const T& endTo) {
		return xtd::lerp(startTo, endTo, (value - startFrom) / (endFrom - startFrom));
	}

	//-------------------------------------------------------------------------
	auto now()
	{
		return std::chrono::system_clock::now();
	}

	//-------------------------------------------------------------------------
	void sleep_ms(size_t milliseconds)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
	}
}
