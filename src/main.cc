#include "ComplexMatrix.hh"
#include "Interface.hh"
#include <iostream>
#include <stdlib.h> // rand
#include <time.h>

using namespace ComplexSpace;
using namespace std;

int main()
{
    srand(time(NULL));

    try
    {
        Interface a = Interface();

        cout << "QUAUNTUM PROJECT" << endl
             << endl;

        while (a.main_option())
        {
            switch (a.get_option())
            {
            case 1:
            {
                // Simulate the CNOT gate
                ComplexMatrix result = ComplexMatrix(4, 1);
                result = a.ControlNOT_function();
                cout << result.ToString();
                break;
            }
            case 2:
            {
                // Simulate the Toffoli gate
                ComplexMatrix result2 = ComplexMatrix(8, 1);
                result2 = a.Toffoli_function();
                cout << result2.ToString();

                break;
            }
            case 3:
            {
                // Call the function that performs Deutsch's algorithm
                a.Deutsch();
                break;
            }
            case 4:
            {
                cout << endl
                     << "Program Terminated" << endl;
                return -1;
                break;
            }
            default:
            {
                cout << endl
                     << "Wrong Input: Please Insert either 1, 2, 3 or 4." << endl;
                break;
            }
            }
        }

        return 0;
    }
    catch (const char *e)
    {
        cout << e << endl;
    }
}
