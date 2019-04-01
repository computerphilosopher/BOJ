from collections import Counter

def solve(nums:list):
    counter = Counter(nums)
    ret = -1
    max_elem = max(nums)

    if len(counter) == 1:
        return 50000 + nums[0]*5000

    if len(counter) == 4:
        return max_elem * 100

    for num in nums:
        
        if counter[num] == 3:
            return 10000 + num*1000

        elif counter[num] == 2:
            if len(counter) == 2:
                ret = 2000

                for c in counter:
                    ret += c * 500

                return ret
            return 1000 + num * 100

    return ret


n = int(input())
answer = -1

for i in range(n):
    nums = list(map(int, input().split()))
    answer = max(answer, solve(nums))

print(answer)