import time

initial = time.time()
n1 = 1
for i in range(50):
    n1 += 1

print(initial)
tf = time.time() - initial
print(f'Time Taken by For Loop: {tf} seconds')

print('\n')
initial2 = time.time()

while n1 != 0:
    n1 -= 1

print(initial2)
tw = time.time() - initial2
print(f'Time Taken by While Loop: {tw} seconds')
if tw > tf:
    print(f'\nFor Loop is faster than While Loop by {tw-tf} seconds')

elif tf > tw:
    print(f'\nWhile Loop is faster than FOr Loop by {tf-tw} seconds')

else:
    pass
