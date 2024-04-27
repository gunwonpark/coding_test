using System;

public class Solution {
     public int solution(int[] numbers, int target)
 {
     int answer = 0;
     DFS(numbers, target, 0, 0, ref answer);
     return answer;
 }
 public void DFS(int[] numbers, int target, int index, int num, ref int answer)
 {
     if (index == numbers.Length)
     {
         if (num == target)
         {
             answer += 1;
             return;
         }
         return;
     }
     DFS(numbers, target, index + 1, num + numbers[index], ref answer);
     DFS(numbers, target, index + 1, num - numbers[index], ref answer);
 }
}