#include <iostream>
using namespace std;

void q1a();
void q1b();
void q1c();
void q2();
void modifyArray (int array[], int);
void modifyElement(int);

int main()
{
  // q1a();
  // q1b();
  // q1c();
  // q2();

  //Q3
  int element[5];
  for(int i = 0; i < 5; i++) element[i] = i;

  cout << "Effects of passing entire array call by reference\n\n";
  cout << "Value of the original array is \n";
  for (int x = 0; x <= 4; x++) cout << element[x] << " ";
  cout << endl;
  modifyArray(element, 5);
  cout << endl << endl;

  cout << "Effects of passing array element call-by-value\n\n";
  cout << "The value of element[3] is " << element[3] << endl;
  modifyElement(element[3]);
  cout << "The value of element[3] is " << element[3] << endl;
  return 0;
}

void q1a()
{
  int row;
  int col;
  cout << "Enter the number of rows followed by height:" << endl;
  cin >> row >> col;

  int * *matrix = new int*[row];
  for (int i = 0; i < row; i++) matrix[i] = new int[col];
  
  cout << "Enter the elements of the array" << endl;
  for (int i = 0; i < row; i++) for (int j = 0; j < col; j++) cin >> matrix[i][j];

  cout << "The 2 Dimensional array:" << endl;
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      cout << matrix[i][j] << "\t";
    }
    cout << endl;
  }

  for (int i = 0; i < row; i++)
  {
    delete[] matrix[i];
  }

  delete[] matrix;
}

void q1b()
{
  srand(time(NULL));
  int row;
  int col;
  cout << "Enter the number of rows followed by height:" << endl;
  cin >> row >> col;

  int * *matrix = new int*[row];
  for (int i = 0; i < row; i++) matrix[i] = new int[col];
  
  int range = 1001;
  for(int i = 0; i < row; i++) for (int j = 0; j < col; j++) matrix[i][j] = rand() % range;

  cout << "The 2 Dimensional array:" << endl;
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      cout << matrix[i][j] << "\t";
    }
    cout << endl;
  }

  for (int i = 0; i < row; i++)
  {
    delete[] matrix[i];
  }

  delete[] matrix;
}

void q1c()
{
  int n;
  cout << "Enter n of nxn grid" << endl;
  cin >> n;

  int * *matrix = new int*[n];
  for (int i = 0; i < n; i++) matrix[i] = new int[n];
  
  cout << "Enter the elements of the array" << endl;
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> matrix[i][j];

  int row = 0, col = 0, count = 0;
  
  for (int i = 0; i < n; i++)
  {
    count += matrix[row][col];
    row++;
    col++;
  }
  

  cout << "The 2 Dimensional array:" << endl;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << matrix[i][j] << "\t";
    }
    cout << endl;
  }

  cout << "Sum of Diagonal is " << count << "!" << endl;

  for (int i = 0; i < row; i++)
  {
    delete[] matrix[i];
  }

  delete[] matrix;
}

void q2()
{
  int row;
  int col;
  cout << "Enter the number of rows followed by height:" << endl;
  cin >> row >> col;

  int * *matrix = new int*[row];
  for (int i = 0; i < row; i++) matrix[i] = new int[col];
  
  cout << "Enter the elements of the array" << endl;
  for (int i = 0; i < row; i++) for (int j = 0; j < col; j++) cin >> matrix[i][j];

  cout << "The 2 Dimensional array:" << endl;
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      cout << matrix[i][j] << "\t";
    }
    cout << endl;
  }

  cout << "Enter the number of rows followed by height:" << endl;
  int row2, col2;
  cin >> row2 >> col2;

  int * *matrix2 = new int*[row2];
  for (int i = 0; i < row2; i++) matrix2[i] = new int[col2];
  
  cout << "Enter the elements of the array" << endl;
  for (int i = 0; i < row2; i++) for (int j = 0; j < col2; j++) cin >> matrix2[i][j];

  cout << "The 2 Dimensional array:" << endl;
  for (int i = 0; i < row2; i++)
  {
    for (int j = 0; j < col2; j++)
    {
      cout << matrix2[i][j] << "\t";
    }
    cout << endl;
  }

  //init
  int combinedRow = row + row2;
  int* *combined = new int*[combinedRow];
  for(int i = 0; i < row; i++) combined[i] = new int[col];
  for(int i = row; i < combinedRow; i++) combined[i] = new int[col2];

  for(int i = 0; i < row; i++)
  {
    for(int j = 0; j < col; j++)
    {
      combined[i][j] = matrix[i][j];
    }
  }
  int a = 0;
  for(int i = row; i < combinedRow; i++)
  {
    for(int j = 0; j < col2; j++)
    {
      combined[i][j] = matrix2[a][j];
    }
    a++;
  }

  cout << "*** Array 2 appended to Array 1 ***" << endl;
  for(int i = 0; i < row; i++)
  {
    for(int j = 0; j < col; j++)
    {
      cout << combined[i][j] << " ";
    }
    cout << endl;
  }
  for(int i = row; i < combinedRow; i++)
  {
    for(int j = 0; j < col2; j++)
    {
      cout << combined[i][j] << " ";
    }
    cout << endl;
  }

  for (int i = 0; i < row; i++)
  {
    delete[] matrix[i];
  }
  for (int i = 0; i < row2; i++)
  {
    delete[] matrix2[i];
  }
  for (int i = 0; i < combinedRow; i++)
  {
    delete[] combined[i];
  }

  delete[] matrix;
  delete[] matrix2;
  delete[] combined;
}

void modifyArray (int array[], int n)
{
  for (int i = 0; i < n; i++) 
  {
    array[i] *= 2;
  }
}

void modifyElement(int n)
{
  n *= 2;
}