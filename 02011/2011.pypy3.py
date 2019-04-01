#MOD = 10**7
MOD = 1000000

#code[i:j+1] 가 평문으로 해독될 수 있는지 판단하는 함수
def can_decode(code:str, i, j)->bool:
    if 0 > i or j > len(code)-1:
        return False
    if code[i] == "0":
        return False 
    return 1 <= int(code[i:j+1]) <= 26

def solve(code:str)->int:

    cache = dict()

    #code[len(code)-2:len(code)] 가 해독가능한 경우 
    cache[len(code)] = 1     
    #code[len(code)-1:len(code)] 가 평문으로 해독되는지 판단
    cache[len(code)-1] = can_decode(code, len(code)-1, len(code)-1)


    for i in range(len(code)-2, -1, -1):
        decode_count = 0
        if can_decode(code, i, i): decode_count += cache[i+1] % MOD
        if can_decode(code, i, i+1): decode_count += cache[i+2] % MOD

        cache[i] = decode_count % MOD

    return cache[0] % MOD

code = input()
print(solve(code))
