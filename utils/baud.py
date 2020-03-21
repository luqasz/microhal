rates = (
    2400,
    4800,
    9600,
    14400,
    19200,
    28800,
    38400,
    57600,
    76800,
    115200,
    230400,
)

F_CPU = 11059200
BAUD = 250000
BAUD_TOL = 2


def calc(freq, divisor, baud):
    value = freq + (8 / divisor) * baud
    value /= (16 / divisor) * baud
    value -= 1
    return int(value)


def u2x(UBRR_VALUE, div=1):
    calc = ((16 / div) * ((UBRR_VALUE) + 1))
    print('calc', calc)
    minus = calc * (100 * (BAUD) - (BAUD) * (BAUD_TOL))
    plus = calc * (100 * (BAUD) + (BAUD) * (BAUD_TOL))
    print('plus', plus)
    print('minus', minus)
    if 100 * F_CPU > plus:
        return True
    if 100 * F_CPU < minus:
        return True
    return False


val = calc(F_CPU, 1, BAUD)
print('UBRR', val)
use2x = u2x(val, 1)
print('use 2x', use2x)
if use2x:
    print('calc again')
    val = calc(F_CPU, 2, BAUD)
    print('UBRR', val)
    if u2x(val, 2):
        print('too high error')

for r in rates:
    if (r % 2400) != 0:
        s = f'{r} is not divisable by 2400'
        print(s)
