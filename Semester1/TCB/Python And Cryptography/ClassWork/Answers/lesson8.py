import math

# ex1
def integral(a, b, f):
    n = 100  # Number of subdivisions
    dx = (b - a) / n
    total = 0
    for k in range(n):
        total += f(a + k * dx) * dx
    return total

def f(x):
    return x**2

# print(integral(0, 1, lambda x: x**2))
# print(integral(0, math.pi, math.sin))
# print(integral(0, 1, f))


# ex2
def derivat(f):
    def inside_derivat(x, dx=0.0001):
        return (f(x+dx) - f(x))/dx
    return inside_derivat
    
# print(derivat(lambda x: x**2)(3))
# print(derivat(math.sin)(math.pi))


# ex3
def derivat_twice(f):
    return derivat(derivat(f))

# print(derivat_twice(lambda x: x**2)(13))


# ex4a
def partial_derivat_x(f):
    def inside_partial_derivat_x(x, y, dx=0.0001):
        return (f(x+dx,y) - f(x,y))/dx
    return inside_partial_derivat_x

# print(partial_derivat_x(lambda x,y: x*(y**2)-2*x*y)(2,3))

# ex4b
def partial_derivat_y(f):
    def inside_partial_derivat_y(x, y, dy=0.0001):
        return (f(x,y+dy) - f(x,y))/dy
    return inside_partial_derivat_y

# print(partial_derivat_y(lambda x,y: x*(y**2)-2*x*y)(2,3))

# ex5
def like_fib(f):
    def inside_like_fib(n):
        return f(n-2) + f(n-1)
    return inside_like_fib
    
# print(like_fib(lambda x: 5-x)(3))


# ex6
def smooth(f):
    def inside_smooth(n):
        return (f(n-1) + f(n) + f(n+1))/3
    return inside_smooth

# print(smooth(lambda x: 5-x)(2))
        