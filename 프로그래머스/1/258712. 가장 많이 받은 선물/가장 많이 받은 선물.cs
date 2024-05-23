using System;
using System.Linq;

public class Solution
{
    public int solution(string[] friends, string[] gifts)
    {
        int[,] arr = new int[friends.Length + 1, friends.Length + 1];
        int[] giftIndex = new int[friends.Length];
        int[] recieve = new int[friends.Length];

        // 기록 저장
        for (int i = 0; i < gifts.Length; i++)
        {
            string[] strings = gifts[i].Split(" ");
            string A = strings[0];
            string B = strings[1];

            int first = Array.IndexOf(friends, A);
            int second = Array.IndexOf(friends, B);
            
            arr[first, second] += 1;

            if (arr[second, first] != 0)
            {
                arr[first, second] -= 1;
                arr[second, first] -= 1;
            }
        }

        for(int i = 0; i < friends.Length; i++)
        {
            for(int j = 0; j < friends.Length; j++)
            {
                arr[friends.Length, i] += arr[j, i];
                arr[i, friends.Length] += arr[i, j];
            }
        }

        for(int i = 0; i < friends.Length; i++)
        {
            giftIndex[i] = arr[i, friends.Length] - arr[friends.Length, i];
        }

        for(int i = 0; i < friends.Length; i++)
        {
            for (int j = 0; j < friends.Length; j++)
            {
                if (arr[i,j] > 0)
                {
                    recieve[i] += 1;
                }
                else
                {
                    if (arr[i, j] != 0 || arr[j, i] != 0)
                        continue;

                    if(giftIndex[i] > giftIndex[j])
                    {
                        recieve[i] += 1;
                    }
                    else if (giftIndex[i] < giftIndex[j])
                    {
                        recieve[j] += 1;
                    }

                    arr[i, j] = -1;
                    arr[j, i] = -1;
                }
            }
        }
        

        return recieve.Max();
    }
}