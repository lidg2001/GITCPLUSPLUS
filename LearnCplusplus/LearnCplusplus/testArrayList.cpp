// test the class arrayList that uses STL algorithms

#include "arrayList.h"

using namespace std;

int main()
{
   // test constructor
   linearList<double> *x = new arrayList<double>(20);
   // 中文注释好用吗？回答是好用！
   // 注意x是很奇怪的，他是一个指向基类linearList的指针，但是分配存储空间时又按照子类arrayList的size来分配。
   // 在基类linearList中，只有纯虚函数，既没有数据区，也没有实体函数，没有size可言。
   // 所以在计算capacity的时候，要把x先强制转换成指向子类arrayList的指针，再调用capacity()这个成员函数才有意义。
   arrayList<int> y(2), z;

   // test capacity
   cout << "Capacity of x, y and z = "
        << ((arrayList<double>*) x)->capacity() << ", "
        << y.capacity() << ", "
        << z.capacity() << endl;


   // test size
   // y和z的声明都比较规范，它们都是子类arrayList的不同例化（对象）。在debug过程中，可以清楚地发现
   // 它们成员函数的入口是相同的，比如y.empty()和z.empty()都是0x013f10c3，y.size()和z.size()都是0x013f1217
   // 但是x->empty()是0x013f17a8，x->size()是0x013f1807

   cout << "Initial size of x, y, and z = "
        << x->size() << ", "
        << y.size() << ", "
        << z.size() << endl;

   // test empty
   if (x->empty()) cout << "x is empty" << endl;
   else cout << "x is not empty" << endl;
   if (y.empty()) cout << "y is empty" << endl;
   else cout << "y is not empty" << endl;

   // test insert
   // 在实现成员函数insert(index, element)的过程中，首先判断index是否合法，然后判断容量，既listsize是否等于arrayLength
   // 如果等于了，则要扩容。扩容的规则是简单扩成现在的2倍。所以在debug过程中，可以发现element的首地址和arrayLength  
   // 的值会变的。
   //   
   //
   //
   y.insert(0, 2); // element的首地址：0x005898c8；arrayLength：2
   y.insert(1, 6); // element的首地址：0x005898c8；arrayLength：2
   y.insert(0, 1); // element的首地址：0x00589b10；arrayLength：4
   y.insert(2, 4); // element的首地址：0x00589b10；arrayLength：4
   y.insert(3, 5); // element的首地址：0x00589b60；arrayLength：8
   y.insert(2, 3); // element的首地址：0x00589b60；arrayLength：8
   cout << "Inserted 6 integers, list y should be 1 2 3 4 5 6" << endl;
   cout << "Size of y = " << y.size() << endl;
   cout << "Capacity of y = " << y.capacity() << endl;
   if (y.empty()) cout << "y is empty" << endl;
   else cout << "y is not empty" << endl;
   y.output(cout);
   cout << endl << "Testing overloaded <<" << endl;
   cout << y << endl;

   // test indexOf
   int index = y.indexOf(4);
   if (index < 0) cout << "4 not found" << endl;
   else cout << "The index of 4 is " << index << endl;

   index = y.indexOf(7);
   if (index < 0) cout << "7 not found" << endl;
   else cout << "The index of 7 is " << index << endl;

   // test get
   cout << "Element with index 0 is " << y.get(0) << endl;
   cout << "Element with index 3 is " << y.get(3) << endl;

   // test erase
   y.erase(1);
   cout << "Element 1 erased" << endl;
   cout << "The list is "  << y << endl;
   y.erase(2);
   cout << "Element 2 erased" << endl;
   cout << "The list is "  << y << endl;

   cout << "Size of y = " << y.size() << endl;
   cout << "Capacity of y = " << y.capacity() << endl;
   if (y.empty()) cout << "y is empty" << endl;
   else cout << "y is not empty" << endl;

   try {y.insert(-3, 0);}
   catch (illegalIndex e)
   {
      cout << "Illegal index exception" << endl;
      cout << "Insert index must be between 0 and list size" << endl;
      e.outputMessage();
   }

   // test copy constructor
   arrayList<int> w(y);
   y.erase(0);
   y.erase(0);
   cout << "w should be old y, new y has first 2 elements removed" << endl;
   cout << "w is " << w << endl;
   cout << "y is " << y << endl;
   
   // a few more inserts, just for fun
   y.insert(0,4);
   y.insert(0,5);
   y.insert(0,6);
   y.insert(0,7);
   cout << "y is " << y << endl;
   return 0;
}
