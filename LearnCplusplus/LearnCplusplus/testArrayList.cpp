// test the class arrayList that uses STL algorithms

#include "arrayList.h"

using namespace std;

int main()
{
   // test constructor
   linearList<double> *x = new arrayList<double>(20);
   // ����ע�ͺ����𣿻ش��Ǻ��ã�
   // ע��x�Ǻ���ֵģ�����һ��ָ�����linearList��ָ�룬���Ƿ���洢�ռ�ʱ�ְ�������arrayList��size�����䡣
   // �ڻ���linearList�У�ֻ�д��麯������û����������Ҳû��ʵ�庯����û��size���ԡ�
   // �����ڼ���capacity��ʱ��Ҫ��x��ǿ��ת����ָ������arrayList��ָ�룬�ٵ���capacity()�����Ա�����������塣
   arrayList<int> y(2), z;

   // test capacity
   cout << "Capacity of x, y and z = "
        << ((arrayList<double>*) x)->capacity() << ", "
        << y.capacity() << ", "
        << z.capacity() << endl;


   // test size
   // y��z���������ȽϹ淶�����Ƕ�������arrayList�Ĳ�ͬ���������󣩡���debug�����У���������ط���
   // ���ǳ�Ա�������������ͬ�ģ�����y.empty()��z.empty()����0x013f10c3��y.size()��z.size()����0x013f1217
   // ����x->empty()��0x013f17a8��x->size()��0x013f1807

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
   // ��ʵ�ֳ�Ա����insert(index, element)�Ĺ����У������ж�index�Ƿ�Ϸ���Ȼ���ж���������listsize�Ƿ����arrayLength
   // ��������ˣ���Ҫ���ݡ����ݵĹ����Ǽ��������ڵ�2����������debug�����У����Է���element���׵�ַ��arrayLength  
   // ��ֵ���ġ�
   //   
   //
   //
   y.insert(0, 2); // element���׵�ַ��0x005898c8��arrayLength��2
   y.insert(1, 6); // element���׵�ַ��0x005898c8��arrayLength��2
   y.insert(0, 1); // element���׵�ַ��0x00589b10��arrayLength��4
   y.insert(2, 4); // element���׵�ַ��0x00589b10��arrayLength��4
   y.insert(3, 5); // element���׵�ַ��0x00589b60��arrayLength��8
   y.insert(2, 3); // element���׵�ַ��0x00589b60��arrayLength��8
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
