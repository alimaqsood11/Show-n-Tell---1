Big Omega Ω is about finding the asymptotic lower bound of the function.
Formal definition of Big Omega Ω:
The notation f = Ω(g) is read as “f is Omega of g”.

f(n) ≥ cg(n) for all n ≥ n0, where c is positive constant.

The following are the rules for Asymptotic Growth:
Let f, g, and h be functions from R+ to R+:
•	If f = Ω(h) AND g = Ω(h), then f + g = Ω(h)
•	If f = Ω(g) and c is a constant greater than 0, then c.f = Ω(g)
•	If f = Ω(g) and g = Ω(h), then f = Ω(h)
We write: f(n) = Ω(g(n))
We say: f( n ) is big Ω of g(n)
Big Theta (Θ):
The notation f = Θ(g) is read as ”f is big theta of g”. Loosely speaking,     f = Θ(g) means the algorithm is sandwiched between the same upper and lower bound.
Let f and g be two functions from Z+ to Z+. Then f = Θ(g) if and only if;
f = Ω(g) and f = O(g)
We write: f(n) = Θ(g(n))
We say: f(n) is ”Big Θ of g(n)”
 In other words, iff two functions have a running time that differs by a constant, we say they have the same growth rate.

We write: f(n) = Θ(g(n))
We say: f(n) is ”Big Θ of g(n)”
 If two functions have a running time that differs by a constant, we say they have the same growth rate.

