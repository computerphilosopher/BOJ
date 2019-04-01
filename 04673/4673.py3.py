def d(N):
    
    n = N
    digit_sum = 0
    while n > 0:
        digit_sum += n%10
        n //= 10

    return N + digit_sum

is_self_num = [True] * 10001

for i in range(1, 10001):
    generated = d(i)
    
    if generated <= 10000:
        is_self_num[generated] = False

for i in range(1, 10001):
    if is_self_num[i] == True:
        print(i)
    




