#include "my/star.h"
#include <iostream>
#include <sys/sendfile.h>
#include <vector>
#define true  0
#define false 1

int main(int argc, char *argv[]) {
    std::vector<long long> a{1, 2, 6, 4, 3, 5, 7, 5, 9, 4};
    int                    ans = 0;
    std::cout << ans << '\n';
    ans ^= (~ans & -~ans) | ((~ans & -~ans) + ans + ~ans);
    std::cout << ans << '\n';
    return 0;
}
