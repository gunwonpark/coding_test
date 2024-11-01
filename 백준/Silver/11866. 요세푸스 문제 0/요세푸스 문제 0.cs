using System.Text;

namespace 알고리즘테스트
{
    internal class Program
    {
        class Node
        {
            public Node? next;
            public int value;
            public Node(int _value)
            {
                this.next = null;
                this.value = _value;
            }

            public void SetNext(Node _node)
            {
                next = _node;
            }
        }

        private static void Main(string[] args)
        {
            int[] input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            int n = input[0];
            int k = input[1];

            Node root = new Node(1);
            Node iter = root;
            for (int i = 2; i <= n; i++)
            {
                iter.SetNext(new Node(i));
                iter = iter.next;
            }
            iter.next = root;  // 원형 리스트로 연결

            StringBuilder sb = new StringBuilder();
            sb.Append("<");
            iter = root;

            if(k == 1)
            {
                for (int i = 0; i < n - 1; i++)
                {
                    sb.Append(iter.value + ", ");
                    iter = iter.next;
                }
                sb.Append(iter.value + ">");
                Console.WriteLine(sb.ToString());
                return;
            }

            while (iter.next != iter)
            {
                for (int i = 0; i < k - 2; i++)
                {
                    iter = iter.next;
                }
                sb.Append(iter.next.value + ", ");
                iter.next = iter.next.next;
                iter = iter.next;
            }

            sb.Append(iter.value + ">");
            Console.WriteLine(sb.ToString());
        }
    }
}