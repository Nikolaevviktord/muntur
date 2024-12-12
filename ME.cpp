#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;

/*
	БИНАРНЫЙ ПОИСК
		long long accurate_binary_search(vector<long long> list, long long value) 
			Поиск в векторе list элемента, равного value. 
			Возвращает индекс такого элемента. 
			Если такого элемента нет, возвращает -1.
		
		long long approximate_binary_search(vector<long long> list, long long value)
			Поиск в векторе list элемента, максимально приближённого к value. 
			Возвращает индекс такого элемента.



	КОМБИНАТОРИКА
		long long factorial(long long value)
			Возвращает факториал числа value.

		long long C(long long elements, long long sample) 
			C из elements по sample. 
			Количество способов расставить любые sample элементов из общего списка длиной elements без учёта порядка элементов.

		long long P(long long elements, long long sample) 
			P из elements по sample. 
			Количество способов расставить любые sample элементов из общего списка длиной elements с учётом порядка элементов.

		long long A(long long elements)
			A для elements элементов. 
			Количество перестановок списка длиной elements с учётом порядка элементов. 

		long long pascal_triangle_element(long long row, long long num, long long base) 
			Элемент треугольника Паскаля, расположенный в строке row в позиции num (нумерация строк и позиций начинается с base, по умолчанию с 1)

		vector<long long> divisors(long long value)
			Возвращает вектор со всеми делителями числа value (value > 0)
*/

ll accurate_binary_search(vll& list, ll value) {
	sort(list.begin(), list.end());

	ll l = 0, r = list.size();

	while ((r - l) > 1) {
		ll m = (l + r) / 2;

		if (list[m] <= value) 
			l = m;
		else
			r = m;
	}

	if (list[l] == value) 
		return l;
	return -1;
}

ll approximate_binary_search(vll& list, ll value) {
	sort(list.begin(), list.end());

	ll l = 0, r = list.size();

	while ((r - l) > 1) {
		ll m = (l + r) / 2;

		if (list[m] <= value) 
			l = m;
		else
			r = m;
	}

	if (r == list.size())
		return l;
	if (abs(value - list[l]) < abs(list[r] - value)) 
		return l;
	return r;
}

ll factorial(ll x) {
	ll res = 1;
	for (ll i = 1; i <= x; i++) 
		res *= i;
	return res;
}

ll C(ll elements, ll sample) {
	return factorial(elements) / (factorial(sample) * factorial(elements - sample));
}

ll P(ll elements, ll sample) {
	return factorial(elements) / factorial(elements - sample);
} 

ll A(ll elements) {
	return P(elements, elements);
}

ll pascal_triangle_element(ll row, ll num, ll base=1) {
	return C(row - base, num - base);
}

vll divisors(ll value) {
	vll res;
	for (ll i = 1; i < sqrt(value) + 1; i++) 
		if (value % i == 0) {
			res.push_back(i);
			if (i != value / i)
				res.push_back(n / i);
		}
	return res;
}
