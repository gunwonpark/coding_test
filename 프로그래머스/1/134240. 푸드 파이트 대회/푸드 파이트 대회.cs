using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public string solution(int[] food) {
        LinkedList<int> deque = new LinkedList<int>();
        deque.AddFirst(0);

        int len = food.Length;

        for (int i = len - 1; i > 0 ; --i)
        {
            int temp = food[i] / 2;
            for (int j = 0; j < temp; ++j)
            {
                deque.AddLast(i);
                deque.AddFirst(i);
            }
        }
        return string.Join("", deque);
    }
}