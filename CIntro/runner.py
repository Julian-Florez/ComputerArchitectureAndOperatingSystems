import facto_i, facto_r, timeit, sys

sys.setrecursionlimit(10000)
def main():
    file = open('time.txt', 'w')
    for i in range(1,21):
        iterative_time = timeit.timeit(f'facto_i.facto_i({i})', setup='import facto_i', number=10000000)
        recursive_time = timeit.timeit(f'facto_r.facto_r({i})', setup='import facto_r', number=10000000)
        print(f"i: {i}, iterative_time: {iterative_time}, recursive_time: {recursive_time}")
        file.write(f"{i}, {iterative_time}, {recursive_time} \n")

if __name__ == '__main__':
    main()    