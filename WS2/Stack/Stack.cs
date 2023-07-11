namespace Stack
{
    public class Stack
    {
        public Stack(int size = 10)
        {
            items = new object[size];
            count = 0;
        }
        public void Push(object item)
        {
            items[count++] = item;
        }
        public object Pop()
        {
            return items[--count];
        }
        public object Peek()
        {
            return items[count - 1];
        }
        public bool IsEmpty()
        {
            return count == 0;
        }
        public void Clear()
        {
            count = 0;
        }

        object[] items;
        int count;
    }
}