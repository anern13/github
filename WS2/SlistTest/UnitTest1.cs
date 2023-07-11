using Slist;
namespace SlistTest
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod1()
        {
            Slist<int> sl = new Slist<int>();
            int[] vals = { 1, 2, 3, 4, 5 };

            /*foreach (int val in vals) { sl.Push(val); }


            while (!sl.IsEmpty())
            {
                Console.WriteLine(sl.Head());
                sl.Pop();
            }

            sl.Push(8756);

            Console.WriteLine($"{sl.Head()}");

            Console.WriteLine($"{sl.Count()}");

            sl.Clear();

            Console.WriteLine($"{sl.Count()}");*/


            foreach (int val in vals) { sl.Push(val); }
           

            foreach (int val in sl) 
            { 
                Console.WriteLine(val);
            }


        }
    }
}