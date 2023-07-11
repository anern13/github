using System.Collections;
using System.Data;
using System.Runtime.Intrinsics.X86;

namespace Slist
{
    public class Slist<T> : IEnumerable
    {
        internal Node? head;
        internal int cnt;
       

        public void Push(T item)
        {
            Node new_node = new Node(item);
            new_node.next = head;
            head = new_node;
            ++cnt;
        }
        public void Pop()
        {
            if(null == head)
                throw new InvalidOperationException();

            if (null == head.next)
            {
                head = null;
                cnt = 0;
            }
            else
            {
                head = head.next;
                --cnt;
            }
        }
        public bool IsEmpty()
        {
            return head == null;
        }
        public void Clear()
        { 
            head = null;
            cnt = 0;
        }
        public T Head()
        {
            if (null == head)
                throw new InvalidOperationException();

            return head.val;
        }
        public int Count()
        { 
            return cnt; 
        }

        public IEnumerator GetEnumerator()
        {
            return new Iter<T>(this);
        }

        
        internal class Node
        {
            internal Node(T val)
            { 
                this.val = val;     
            }

            internal T? val;

            internal Node? next;
        }
    }

    public class Iter<T> : IEnumerator
    {
        Slist<T>.Node? curr;
        int pos;
        int size;
        public Iter(Slist<T> list)
        {
            curr = list.head;
            pos = 0;
            size = list.cnt;
        }
        
        public object Current => curr.val;

        public bool MoveNext()
        {
            ++pos;
            curr = curr.next;

            return (pos < size);
        }

        public void Reset()
        {
            pos = 0;
        }
    }

}