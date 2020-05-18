def ftimer(fcpu, prescaler, top):
    """
    Given above params, return maximum timer frequency in Hz.
    """
    if top > 65535:
        raise ValueError("top value too big")
    freq = top + 1
    freq *= prescaler
    return int(fcpu / freq)


def ocr(ftimer, desired):
    """
    Calculate TOP value of a counter.

    ftimer: Timer frequency in Hz. That is frequency after applying prescaller.
    desired: Desired frequency in Hz.
    """
    return int((ftimer / desired) - 1)


def calc(fcpu, desired, max_top, prescalers):
    for p in prescalers:
        ftimer = int(fcpu / p)
        top = ocr(ftimer, desired)
        if top <= max_top:
            return p, top
    return 0, 0
