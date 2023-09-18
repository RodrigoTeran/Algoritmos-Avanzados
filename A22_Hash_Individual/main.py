a = ord("e") + \
    ord("b") + \
    ord(" ") + \
    ord("n") + \
    ord("n") + \
    ord("i")

b = ord("s") + \
    ord("a") + \
    ord("d") + \
    ord("o") + \
    ord("e") + \
    ord("v")

c = ord("t") + \
    ord("\n") + \
    ord("e") + \
    ord(" ") + \
    ord("r") + \
    ord("o")

d = ord("o") + \
    ord("d") + \
    ord("\n") + \
    ord("s") + \
    ord(" ") + \
    ord("[")


print(a)
print(b)
print(c)
print(d, end="\n\n")

print(hex(a % 256))
print(hex(b % 256))
print(hex(c % 256))
print(hex(d % 256))