#include <iostream> 
using namespace std;
 
class Shape {
   protected:
      int width, height;
   public:
      Shape( int a=0, int b=0)
      {
         width = a;
         height = b;
      }
      virtual int area()
      {
         cout << "Parent class area :" <<endl;
         return 0;
      }
};
class Rectangle: public Shape{
   public:
      Rectangle( int a=0, int b=0)
      {
        Shape(a, b); 
      }
      int area ()
      { 
         cout << "Rectangle class area :" <<endl;
         return (width * height); 
      }
};
class Triangle: public Shape{
   public:
      Triangle( int a=0, int b=0)
      {
        Shape(a, b); 
      }
      int area ()
      { 
         cout << "Triangle class area :" <<endl;
         return (width * height / 2); 
      }

      void printTriangle() {
        cout<<"Triangle"<<endl;
      }
};

int main( )
{
   Shape *shapeRec, *shapeTri;
   Rectangle rec(10,7);
   Triangle  tri(10,5);

   shapeRec = &rec;
   shapeRec->area();

   shapeTri = &tri;
   shapeTri->area();
   
   Shape * tri2 = new Triangle(2,3);
   tri2->printTriangle();

   return 0;
}
