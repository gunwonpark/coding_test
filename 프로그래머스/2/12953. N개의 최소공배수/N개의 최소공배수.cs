using System.Linq;
using System;
public class Solution {
    public int solution(int[] arr) {
        int result = arr[0];
        for (int i = 1; i < arr.Length; i++) {
            result = Lcm(result, arr[i]);
        }
        return result;
    }

    private int Gcd(int a, int b) {
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    private int Lcm(int a, int b) {
        return Math.Abs(a / Gcd(a, b) * b); 
    }
}