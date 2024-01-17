class Program
{
    static void Main(string[] args)
    {

        // 증가하는 가장 긴 수열을 찾는다 
        // 이 문제에서는 기준점이 처음이여서 구현이 용이하다
        // 그 수열에서 사이의 공간이 가장 긴 공간이 가장 짧은 k 가 된다
        int N = int.Parse(Console.ReadLine());
        int[] arr = Array.ConvertAll(Console.ReadLine().Split(" "), int.Parse);

        // 가장 긴 증가하는 수열 인덱스 저장
        List<int> longestSequence = new List<int>();

        int numTracer = arr[0];
        longestSequence.Add(0);

        for (int i = 0; i < arr.Length; i++)
        {
            if (arr[i] >= numTracer)
            {
                numTracer = arr[i];
                longestSequence.Add(i);
            }
        }

        // k 값 찾기
        int k = 1;
        for (int i = 0; i < longestSequence.Count - 1; i++)
        {
            k = Math.Max(k, longestSequence[i + 1] - longestSequence[i]);
        }

        // 끝에 지점과 비교
        k = Math.Max(k, arr.Length - longestSequence[longestSequence.Count - 1]);
        Console.WriteLine(k);
    }
}