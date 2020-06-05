def find_k_missing(a, n):
        if len(a) == n: # not missing any number
                return []

        if len(a) == 0: # missing all the number
                return range(n)

        a.extend([a[0]]*(n - len(a)))

        for i in xrange(n):
                while a[i] != a[a[i]]:
                        # swap a[i] and a[a[i]]
                        t = a[i]
                        a[i] = a[t]
                        a[t] = t # always one element is put in correct position

        return [i for i in xrange(n) if a[i] != i]


def test(n, k):
        import random
        a = range(n)
        random.shuffle(a)
        a = a[:n-k]

        print 'a:', a
        print 'n:', n

        res = find_k_missing(a, n)

        print '>:', res


if __name__ == '__main__':
        import sys

        n = 5
        k = 3

        print 'usage: [n] [k]'

        if len(sys.argv) > 1:
                n = int(sys.argv[1])

        if len(sys.argv) > 2:
                k = int(sys.argv[2])

        test(n, k)
