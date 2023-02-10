from sympy import lambdify, solve, Eq, Symbol

fin, fout, prescaler, top = Symbol('fin'), Symbol('fout'), Symbol('prescaler'), Symbol('top')

top_equation = Eq(top, (fin / prescaler) / fout)
top_sol = solve(top_equation, top)[0]
top_fun = lambdify((fin, fout, prescaler), top_sol)

prescaler_sol = solve(top_equation, prescaler)[0]
prescaler_fun = lambdify((fin, fout, top), prescaler_sol)

fout_sol = solve(top_equation, fout)[0]
fout_fun = lambdify((fin, prescaler, top), fout_sol)

reqular_result = (16000000 / 8) / 4
solved_result = top_fun(fin=16000000, fout=4, prescaler=8)

assert reqular_result == solved_result
