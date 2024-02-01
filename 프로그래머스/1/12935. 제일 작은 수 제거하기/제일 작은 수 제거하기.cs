using System.Collections.Generic;
using System.Linq;
public class Solution {
    public int[] solution(int[] arr) {
        
        return arr.Length == 1 ? new int[]{-1} : arr.Except(new int[1] {arr.Min()}).ToArray();
    }
}