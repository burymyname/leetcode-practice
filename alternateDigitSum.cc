/*
    NOTES:
        最开始写的版本思路如下：
        取每一位的思路很清晰，就是mod 10然后/10，如此循环。
        但是这种循环是从最低位开始取的，题目要求的是最高位为正，然后依次符号交替。
        所以位数的奇偶性会影响到最终结果，所以我的思路是循环加和的时候计算两个和
        分别为最后一位是负数、正数两种情况，最后根据位数的奇偶性来判断返回哪一个。

*/

#include <iostream>

class Solution {
public:
    int alternateDigitSum(int n) {
        int sum1 = 0;
        int sum2 = 0;
        int sign = 1;
        int k = 0;
        while (n) {
            int i = n % 10;
            sum1 += sign * i;
            sum2 += (-sign) * i;
            sign = -sign;
            n /= 10;
            k++;
        }
        if (k % 2 != 0) {
            return sum1;
        } else {
            return sum2;
        }
    }
};

/*
    NOTES:
        看了题解以后发现有一种新的思路，虽然官方题解没有说清楚。
        假设位数有n位，最高位为第n位的话，那么加和为(n + n-2 + ... ) - (n-1 + ... )
        但是按照遍历的方法，假设第1位为正数，那么当n为奇数时，加和为(1 + ... + n) - (2 + ... + n-2)
        当n位偶数时，加和为(1 + ... + n-1) - (2 + ... + n) = - ((2 + ... + n) - (1 + ... + n-1))
        可见，当n为奇数时，和与真正的和是一致的，但是n位偶数时和与真正和是取负的关系。
        但是不需要计数来判断奇偶性，用sign来判即可
*/

class Solution1 {
public:
    int alternateDigitSum(int n) {
        int sum = 0;
        int sign = 1;
        while (n) {
            int i = n % 10;
            sum += sign * i;
            sign = -sign;
            n /= 10;
        }
        return (-sign) * sum;
    }
};
