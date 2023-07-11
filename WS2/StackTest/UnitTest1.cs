
namespace StackTest
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod1()
        {
            Stack.Stack s = new Stack.Stack();

            object[] items = { 1, "kuhgkjh", 'i', 4.5 };    

            foreach (object item in items) { s.Push(item); }

            while(! s.IsEmpty())
            {
                Console.WriteLine($"{s.Pop()}");
            }

            foreach (object item in items) { s.Push(item); }
    
            s.Clear();

            Console.WriteLine(s.IsEmpty());

        }
    }
}