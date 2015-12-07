// test bin sort as member of chain class


#include "studentRecord.h"
#include "chain.h"

int main(void)
{
   studentRecord s;
   chain<studentRecord> theChain;

   int scores[] = { 1, 1, 3, 5, 1, 5, 4, 3, 2 };
   string names[] = { "John", "Henry", "Mike", "Truman", "Bob", "Robert", "Bill", "Howard", "Raymond" };
   for (int i = 0; i < 9; i++)
   {
      s.score = scores[i];
      s.name = new string(names[i]);
      theChain.insert(0,s);
   }
  

   cout << "The unsorted chain is" << endl;
   cout << "  " << theChain << endl;

   theChain.binSort(10);

   cout << "The sorted chain is" << endl;
   cout << "  " << theChain << endl;
}
