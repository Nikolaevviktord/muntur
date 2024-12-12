import java.util.*;

/*
    БИНАРНЫЙ ПОИСК
        int accurate_binary_search(List<Long> list, long value) 
            Поиск в векторе list элемента, равного value. 
            Возвращает индекс такого элемента. 
            Если такого элемента нет, возвращает -1.
        
        int approximate_binary_search(List<Long> list, long value)
            Поиск в векторе list элемента, максимально приближённого к value. 
            Возвращает индекс такого элемента.



    КОМБИНАТОРИКА
        long factorial(long value)
            Возвращает факториал числа value.

        long C(long elements, long sample) 
            C из elements по sample. 
            Количество способов расставить любые sample элементов из общего списка длиной elements без учёта порядка элементов.

        long P(long elements, long sample) 
            P из elements по sample. 
            Количество способов расставить любые sample элементов из общего списка длиной elements с учётом порядка элементов.

        long A(long elements)
            A для elements элементов. 
            Количество перестановок списка длиной elements с учётом порядка элементов. 

        long pascal_triangle_element(long row, long num, long base) 
            Элемент треугольника Паскаля, расположенный в строке row в позиции num (нумерация строк и позиций начинается с base, по умолчанию с 1)

        static List<Long> divisors(long value) 
            Возвращает вектор со всеми делителями числа value (value > 0)
*/

public class MEFuncs {
    public static int accurateBinarySearch(List<Long> list, long value) {
        Collections.sort(list);
        int l = 0, r = list.size();

        while ((r - l) > 1) {
            int m = (l + r) / 2;
            if (list.get(m) <= value)
                l = m;
            else
                r = m;
        }

        return list.get(l) == value ? l : -1;
    }

    public static int approximateBinarySearch(List<Long> list, long value) {
        Collections.sort(list);
        int l = 0, r = list.size();

        while ((r - l) > 1) {
            int m = (l + r) / 2;
            if (list.get(m) <= value)
                l = m;
            else
                r = m;
        }

        if (r == list.size())
            return l;
        return Math.abs(value - list.get(l)) < Math.abs(list.get(r) - value) ? l : r;
    }

    public static long factorial(long x) {
        long res = 1;
        for (long i = 1; i <= x; i++)
            res *= i;
        return res;
    }

    public static long C(long elements, long sample) {
        return factorial(elements) / (factorial(sample) * factorial(elements - sample));
    }

    public static long P(long elements, long sample) {
        return factorial(elements) / factorial(elements - sample);
    }

    public static long A(long elements) {
        return P(elements, elements);
    }

    public static long pascalTriangleElement(long row, long num, long base) {
        return C(row - base, num - base);
    }

    public static List<Long> divisors(long value) {
        List<Long> res = new ArrayList<>();
        for (long i = 1; i <= Math.sqrt(value); i++) {
            if (value % i == 0) {
                res.add(i);
                if (i != value / i)
                    res.add(value / i);
            }
        }
        return res;
    }
}
