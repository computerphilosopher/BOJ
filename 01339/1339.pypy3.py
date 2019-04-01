from collections import Counter

def get_map(words:list):

    digit_sum = dict()

    for word in words:
        for i, ch in enumerate(word):
            if ch not in digit_sum:
                digit_sum[ch] = 0

            digit_sum[ch] += 10 ** (len(word)-i)

    l = list(digit_sum.items())
    l.sort(key = lambda element: (element[1]), reverse = True)

    ret = dict()

    for i, element in enumerate(l):
        ret[element[0]] = 9 - i

    return ret

def get_num(word:str, map:dict):

    ret = 0
    exp = 1

    for i in range(len(word)-1, -1, -1):
        ret += map[word[i]] * exp
        exp *= 10

    return ret

def solve(words:list):

    map = get_map(words)
    
    ret = 0
    for word in words:
        ret += get_num(word, map)

    return ret


n = int(input())
words = [input() for i in range(n)]

print(solve(words))

'''
a = ['AAA', 'AAA']
b = ['GCF', 'ACDEB']
c = ['AB', 'BA']

print(solve(a))
print(solve(b))
print(solve(c))
'''