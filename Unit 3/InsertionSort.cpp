#include <iostream>
using namespace std;

/* function declaration */
int * insertionSortInteger(int[], int);
float * insertionSort(float[], int);
void insertionSortString(int);
void swap(int &a, int &b);
void printArray(int[], int);
void printStringArray(string[], int);
float median(float *, int);

int main()
{
  int array[] = {6,2,8,3,1,7,4};

  /* Question #1 */
  cout << "Q1" << endl;

  printArray(array, 7);

   int * arraySorted = insertionSortInteger(array, 7);

  // cout << "6 2 8 3 1 7 4" << endl;
  // cout << "2 6 8 3 1 7 4\n";
  // cout << "2 3 6 8 1 7 4\n";
  // cout << "1 2 3 6 8 7 4\n";
  // cout << "1 2 3 6 7 8 4\n";
  // cout << "1 2 3 4 6 7 8" << endl;

  /* Question #2 */
  // search for elements that are less than the proceding element, and manipulate those

  /* Question #3 */
  cout << "Q3" << endl;
  
  insertionSortString(8);

  /* Question #4 */
  cout << "Q4" << endl;

  int n; cin >> n;
  float * unorderedList = new float[n];
  for(int i = 0; i < n; i++) cin >> unorderedList[i];

  float * orderedList = insertionSort(unorderedList, n);

  float medianList = median(orderedList, n);

  cout << medianList << endl;

  /* Question #5 */
  // this sort is stable as if the condition is not met (<), 
  // the element will not be moved
}

int * insertionSortInteger(int array[], int length)
{
  int sorted;

  for(int i = 1; i < length; i++)
  {
    /* var sorted set to 0 as 0 elements are sorted */
    sorted = i - 1;

    /* var insert is the element that will be inserted into the correct location*/
    int insert = array[i];

    /* 
    while insert is less than the the element before
    move the element before ahead, to make room for insert
    deincrement sorted to continue above step
    */
    while(insert < array[sorted] && ((sorted) >= 0))
    {
      array[sorted + 1] = array[sorted];
      sorted--;
    }
    
    /* place insert into the slot where it is greater than previous element */
    array[sorted + 1] = insert;

    printArray(array, length);
  }

  return array;
}

void insertionSortString(int length)
{
  string array[8] = {"mercury", "venus", "earth", "mars", "jupiter", "saturn", "uranus", "neptune"};

  printStringArray(array, 8);

  int sorted;

  for(int i = 1; i < length; i++)
  {
    /* var sorted set to 0 as 0 elements are sorted */
    sorted = i - 1;

    /* var insert is the element that will be inserted into the correct location*/
    string insert = array[i];

    /* 
    while insert is less than the the element before
    move the element before ahead, to make room for insert
    deincrement sorted to continue above step
    */
    while(insert < array[sorted] && ((sorted) >= 0))
    {
      array[sorted + 1] = array[sorted];
      sorted--;
    }
    
    /* place insert into the slot where it is greater than previous element */
    array[sorted + 1] = insert;

    printStringArray(array, 8);
  }
}

void swap(int &a, int &b)
{
  int c; c = a; a = b; b = c;
}

void printArray(int array[], int length)
{
  for(int i = 0; i < length; i++) cout << array[i] << " ";
  cout << endl;
}

void printStringArray(string array[], int length)
{
  for(int i = 0; i < length; i++) cout << array[i] << " ";
  cout << endl;
}

float median(float * array, int length)
{
  //float lengthFloat = (float) length;
  
  if(length%2 != 0)
  {
    return(array[length/2]);
  }
  else 
  {
    return((array[(int(length)/2) - 1] + array[(int(length)/2)])/2.0);
  }
}

/* 1 2 3 4 5 6 */

float * insertionSort(float array[], int length)
{
  int sorted;

  for(int i = 1; i < length; i++)
  {
    /* var sorted set to 0 as 0 elements are sorted */
    sorted = i - 1;

    /* var insert is the element that will be inserted into the correct location*/
    float insert = array[i];

    /* 
    while insert is less than the the element before
    move the element before ahead, to make room for insert
    deincrement sorted to continue above step
    */
    while(insert < array[sorted] && ((sorted) >= 0))
    {
      array[sorted + 1] = array[sorted];
      sorted--;
    }
    
    /* place insert into the slot where it is greater than previous element */
    array[sorted + 1] = insert;
  }

  return array;
}

