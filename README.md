# Шпаргалка для МЭ ВсОШ

Данный репозиторий содержит реалиации ключевых функций бинарного поиска и теории чисел на языках C++ и Python. Общий перечень функций (для файла `/ME.c` со шпаргалкой на языке C параметры некоторых функций отличаются, см. файл):

```
БИНАРНЫЙ ПОИСК
  integer accurate_binary_search(array[integer] list, integer value) 
    Поиск в векторе list элемента, равного value. 
    Возвращает индекс такого элемента. 
    Если такого элемента нет, возвращает -1.
  
  integer approximate_binary_search(array[integer] list, integer value)
    Поиск в векторе list элемента, максимально приближённого к value. 
    Возвращает индекс такого элемента.



КОМБИНАТОРИКА
  integer factorial(integer value)
    Возвращает факториал числа value.

  integer C(integer elements, integer sample) 
    C из elements по sample. 
    Количество способов расставить любые sample элементов из общего списка длиной elements без учёта порядка элементов.

  integer P(integer elements, integer sample)
    P из elements по sample. 
    Количество способов расставить любые sample элементов из общего списка длиной elements с учётом порядка элементов.

  integer A(integer elements)
    A для elements элементов. 
    Количество перестановок списка длиной elements с учётом порядка элементов. 

  integer pascal_triangle_element(integer row, integer num, integer base) 
    Элемент треугольника Паскаля, расположенный в строке row в позиции num (нумерация строк и позиций начинается с base, по умолчанию с 1)

  array[integer] divisors(integer value)
    Возвращает вектор со всеми делителями числа value (value > 0)
```
