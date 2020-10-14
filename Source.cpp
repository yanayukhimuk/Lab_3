#include <iostream>
#include <Windows.h> 
using namespace std; 

// ������������� ������ ���, ����� ������� ������������� ������������� ��������, � ����� � ������������� (0 ������� �������������) 

class Vector  // 1.	����������� ����� ������� (���������� ������������ ������). 
             // ������ ������: ������������, ���������� � ������ �������������� ������� � ������������ � ���������.  
{
private:
	int size;
	int* arr = 0; 
	int max, min; 
public: 
	Vector (int s) :
		size(s)
	{
		arr = new int[size];
	}

	~Vector()
	{
		delete[] arr;
	}
    void setsize(int newsize)
    {

        arr = new int[newsize];
        size = newsize;
    }
    void setarr(int newsize, int* newarr)
    {

        arr = new int[newsize];
        size = newsize;
        for (int i = 0; i < size; i++)
        {
            arr[i] = newarr[i];
        }
    }

    void getarr()
    {
        if ((size != 0) && (arr != 0))
        {
            for (int i = 0; i < size; i++)
            {
                cout << arr[i] << "  ";
            }
        }
        cout << endl;
    }
    void FirstArray() // 2.	������ 2 ������� �� 10 ���������, ��������� ��������� ������������.
    {
        int firstarr[] = { 0 };  //3.	���� �� �������� ������������� (������ �������� � �� ��������, �������� � �� �����������), 
                                 //����� �����������, ������� � ������������ �������� �������. 
        float sum = 0.00;
        int swch = 0;
        for (int i = 0; i < size; i++)
        {
            sum += static_cast<float>(arr[i]);
        }

        for (int i = 0; i < size; i++)
        {
            for (int j = (size - 1); j >= i + 1; j--)
            {
                if (arr[j] > arr[j - 1])
                {
                    swch = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = swch;
                }
            }
        }

        cout << "Max is " << arr[0] << endl;
        cout << "Min is " << arr[size - 1] << endl;
        cout << "Average is " << sum / 10 << endl;
    }
    int SecondArray() //������������� ������ ���, ����� ������� ������������� ������������� ��������, 
                     // � ����� � ������������� (0 ������� �������������)
    {
        int secondarr[] = {0};
        int length = sizeof(*arr) / sizeof(*arr); //��������� ����� �������
        for (unsigned i = 0; i < length / 2; i++) {
            for (unsigned j = 0; j < length - i - 1; j++) {
                if (arr[j] < 0 && arr[j + 1] > 0) {
                    int tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;
                }
            }
        }
        for (unsigned i = 0; i < length; i++) cout << secondarr[i] << " ";
    }

    int main()
    {
        int firstarr[] = { 3,4,8,-9,100,-20,18,0,32,14 };
        int secondarr[] = { 6, -1, -22, 8, -2, -76, 14, 100, -11, 30, -20, 10, -17, 90, 7 };

        int a;

        Vector first(10);
        Vector second(10);

        second.setarr(10, secondarr);
        first.setarr(10, firstarr);

        first.getarr();
        first.FirstArray();
        first.getarr();

        cout << endl;

        second.getarr();
        second.SecondArray();
        second.getarr();

        cin >> a;
    }
};
