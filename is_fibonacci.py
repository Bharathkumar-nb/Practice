import math
def is_square(n):
    return math.sqrt(n).is_integer()

def isFib(n):
    return is_square(5*n*n + 4) or is_square(5*n*n - 4)

T = int(input())
for i in range(T):
    n = int(input())
    if(isFib(n)):
        print("IsFibo")
    else:
        print("IsNotFibo")