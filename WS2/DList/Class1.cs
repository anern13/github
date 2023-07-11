namespace DList
{

    public class DList<T>
    {
        public DList() 
        {
            
        }

        int count;
        Node<T> head;
    }
    internal class Node<T>
    {
        public Node<T> prev;
        public Node<T> next;
        public T val;
    }



}