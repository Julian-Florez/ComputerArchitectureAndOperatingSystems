import facto_i, facto_r, timeit, sys

sys.setrecursionlimit(10000)
def main():
    file = open('time.txt', 'w')
    for i in range(1,1000):
        iterative_time = timeit.timeit(f'facto_i.facto_i({i})', setup='import facto_i', number=100)
        recursive_time = timeit.timeit(f'facto_r.facto_r({i})', setup='import facto_r', number=100)
        file.write(f"{i}, {iterative_time}, {recursive_time} \n")

if __name__ == '__main__':
    main()    