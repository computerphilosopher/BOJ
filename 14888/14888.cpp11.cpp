#include <cstdio>
 
 
 
#include <algorithm>
#include <limits.h>
#include <vector>

using namespace std;

enum operation {
    ADD, SUB, MUL, DIV
};

int main() {

    int n = 0;
    scanf("%d", &n);

    vector<int> v;

    for (int i = 0; i < n; i++) {
            int temp = 0;
            scanf("%d", &temp);
            v.push_back(temp);
        }

    int op_count[4] = { 0 };

    for (int i = 0; i < 4; i++) {
            scanf("%d", &op_count[i]);
        }

    vector<int> op;

    for (int i = 0; i < 4; i++) {
        while (op_count[i]--) {
            op.push_back(i);
        }
    }

    long max = -1000000001;
    long min = 1000000001;
     

    do {

        int result = v[0];

        for (int i = 0; i < op.size(); i++) {
             
            switch (op[i]) {
                case ADD:
                    result += v[i + 1];
                    break;
                case SUB:
                    result -= v[i + 1];
                    break;
                case MUL:
                    result *= v[i + 1];
                    break;
                case DIV:
                    result /= v[i + 1];
                    break;
            }
        }


        if (result > max) {
            max = result;
        }

        if (result < min) {
            min = result;
        }

    } while (next_permutation(op.begin(), op.end()));

    printf("%ld\n%ld", max, min);
    return 0;
}
