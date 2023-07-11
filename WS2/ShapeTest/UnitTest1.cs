
using Shape;

namespace ShapeTest
{
    
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod1()
        {
            Circle circle = new Circle(1.5, "black", false);
            Console.WriteLine(circle.Area());
            Console.WriteLine(circle.ToString());
            Console.WriteLine(circle.Perimeter());

            Console.WriteLine();

            Rectangle rectangle = new Rectangle(1.5, 1.5, "pink", true);
            Console.WriteLine(rectangle.Area());
            Console.WriteLine(rectangle.ToString());
            Console.WriteLine(rectangle.Perimeter());
        }
    }
}