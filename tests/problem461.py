from math import e, pi
from pprint import pprint
from sympy import *

a, b, c, d = symbols('a b c d')

f = (e**(a/200) + e**(b/200) + e**(c/200) + e**(d/200) - 4 - pi) ** 2

a_deriv = Derivative(f, a)
print(a_deriv.doit())