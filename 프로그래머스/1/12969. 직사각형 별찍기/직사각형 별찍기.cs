using System;

public class Example
{
    public static void Main()
    {
        String[] s;

        Console.Clear();
        s = Console.ReadLine().Split(' ');

        int a = Int32.Parse(s[0]);
        int b = Int32.Parse(s[1]);

        string str = "";
        for(int i = 0; i < b; i++){
            for(int j = 0; j < a; j++){
                str += "*";
            }
            str += "\n";
        }
        
        Console.WriteLine("{0}", str);
    }
}