
def solve(balls:list):

    balls.sort()
    ret = dict() 

    color_sum = dict() 
    same_weight = dict() 

    color_weight = dict()
    weight_sum = 0

    for ball in balls:
        weight, color, idx = ball

        if weight not in same_weight:
            same_weight[weight] = 0

        if color not in color_sum:
            color_sum[color] = 0

        if (color, weight) not in color_weight:
            color_weight[(color,weight)] = 0

        ret[idx] = weight_sum - color_sum[color] - same_weight[weight] + color_weight[(color,weight)]

        weight_sum += weight
        color_sum[color] += weight
        same_weight[weight] += weight
        color_weight[(color,weight)] += weight

    return ret


n = int(input())

balls = []

for i in range(n):
    color, size = map(int, input().split())
    balls.append((size, color, i))

ans = solve(balls)

for i in range(n):
    print(ans[i])