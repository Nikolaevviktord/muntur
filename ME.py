"""
	БИНАРНЫЙ ПОИСК
		accurate_binary_search(list, value) 
			Поиск в векторе list элемента, равного value. 
			Возвращает индекс такого элемента. 
			Если такого элемента нет, возвращает -1.
		
		approximate_binary_search(list, value)
			Поиск в векторе list элемента, максимально приближённого к value. 
			Возвращает индекс такого элемента.



	КОМБИНАТОРИКА
		factorial(value)
			Возвращает факториал числа value.

		C(elements, sample) 
			C из elements по sample. 
			Количество способов расставить любые sample элементов из общего списка длиной elements без учёта порядка элементов.

		P(elements, sample)
			P из elements по sample. 
			Количество способов расставить любые sample элементов из общего списка длиной elements с учётом порядка элементов.

		A(elements)
			A для elements элементов. 
			Количество перестановок списка длиной elements с учётом порядка элементов. 

		pascal_triangle_element(row, num, base) 
			Элемент треугольника Паскаля, расположенный в строке row в позиции num (нумерация строк и позиций начинается с base, по умолчанию с 1)

		divisors(value)
			Возвращает вектор со всеми делителями числа value (value > 0)
"""

def accurate_binary_search(list, value):
	list.sort()

	l, r = 0, len(list)

	while r - l > 1:
		m = (l + r) // 2

		if list[m] <= value:
			l = m 
		else:
			r = m 

	if list[l] == value:
		return l 
	return -1

def approximate_binary_search(list, value):
	list.sort()

	l, r = 0, len(list)

	while r - l > 1:
		m = (l + r) // 2

		if list[m] <= value:
			l = m 
		else:
			r = m 

	if r == len(list):
		return l 
	if abs(value - list[l]) < abs(list[r] - value):
		return l
	return r 

def factorial(value):
	res = 1
	for i in range(1, value + 1):
		res *= i
	return res 

def C(elements, sample):
	return factorial(elements) // (factorial(sample) * factorial(elements - sample))

def P(elements, sample):
	return factorial(elements) // factorial(elements - sample)

def A(elements):
	return P(elements, elements)

def pascal_triangle_element(row, num, base=1):
	return C(row - base, num - base)

def divisors(value):
	res = list()
	for i in range(1, int(value ** 0.5) + 1):
		if value % i == 0:
			res.append(i)
			if i != value // i:
				res.append(value // i)
	return res 
