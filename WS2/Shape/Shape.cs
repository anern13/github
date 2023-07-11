using System.Reflection.Metadata;

namespace Shape
{
    public abstract class Shape
    {
        string color;
        bool is_filled;
         
        public Shape()
        {
            color = "green";
            is_filled = true;
        }
        public Shape(string color, bool is_filled)
        {
            this.color = color;
            this.is_filled = is_filled;
        }

        public abstract double Area();
        public abstract double Perimeter();

        public override string ToString() 
        {
            string filled = "filled";
            if (!is_filled) { filled = "empty"; }
             
            string ret = " this shape is " + this.color + " and " + filled;
            return ret;
        }

        public string Color
        {
            get { return color; } 
            set { color = value; } 
        }
        
        public bool IsFilled
        {
            get { return is_filled; } 
            set { is_filled = value; }
        }
        
    }
    /*************************************************************************************************/

    public class Circle : Shape
    {
        double radius;
        public Circle(double radius = 1)
        {
            this.radius = radius;
        }

        public Circle(double radius, string color, bool should_fill)
        {
            this.radius = radius;
            Color = color;
            IsFilled = should_fill;
        }
        public override double Area()
        {
            return radius * radius * 3.14;
        }
        public override string ToString()
        {
            string ret = "This is a Circle with radius " + radius + base.ToString();
            return ret;
        }

        public override double Perimeter()
        {
            return radius * 2 * 3.14;
        }
        
        public double Radius
        {
            get { return radius; }
            set { radius = value; }
        }
    }
    /*************************************************************************************************/
    public class Rectangle : Shape
    {
        double width;
        double height;

        static Rectangle()
        {
            Console.WriteLine("Rectangle is initalized");
        }
        public Rectangle(double width, double height)
        {
            this.width = width;
            this.height = height;
        }
        
        public Rectangle(double width, double height, string color, bool should_fill)
        {
            this.width = width;
            this.height = height;
            Color = color;
            IsFilled = should_fill;
        }
        public override double Area()
        {
            return width * height;
        }

        public override double Perimeter()
        {
            return height * 2 + height * 2;
        }

        public override string ToString() 
        {
            string ret = "Rectangle with w" + width + " h" + height + base.ToString();
            return ret;
        }

        public double Width
        {
            get { return width; }
            set { width = value; }
        }
        public double Height
        {
            get { return height; }
            set { height = value; }
        }
    }

}