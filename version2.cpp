#include <iostream>
#include "descr.h"
#include "test.h"

#include <sstream>
#include <cmath>
#include <float.h> // for FLT_MAX
#include <limits> //CHAR_MAX and others

using namespace std;

#define PI 3.14
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;

const char correct_ch[] = {CHAR_MAX, CHAR_MIN, '3', 'f', '6'};
const char incorrect_ch[] = {-1, -2};
const uchar correct_uch[] = {'k', 'l', 'm'};
const uchar incorrect_uch[] = {'i', 'r', 'a'};
const short correct_sh[] = {SHRT_MAX, SHRT_MIN, 45, 46};
const short incorrect_sh[] = {-45, -46};
const ushort correct_ush[] = {USHRT_MAX, 56, 57};
const ushort incorrect_ush[] = {66, 67};
const int correct_int[] = {INT_MAX, INT_MIN, 25, 26};
const int incorrect_int[] = {-25, -26};
const uint correct_uint[] = {UINT_MAX, 5};
const uint incorrect_uint[] = {6, 7};
const uint correct_enum[] = {3, 4};
const uint incorrect_enum[] = {5, 6};
const long correct_lg[] = {LONG_MAX, LONG_MIN, 78, 79};
const long incorrect_lg[] = {-78, -79};
const ulong correct_ulg[] = {ULONG_MAX, 22};
const ulong incorrect_ulg[] = {33};
const float correct_fl[] = {0.4f, 5.78f, FLT_MAX , FLT_MIN};
const float incorrect_fl[] = {NAN, 0.f/0.f, 10/0.f};
const double correct_db[] = {DBL_MAX, DBL_MIN, 99, 88};
const double incorrect_db[] = {-88, -99};
const bool correct_bool[] = {1, true};
const bool incorrect_bool[] = {0, false};


template <class T, class DT>
void printLog(T* msg, bool isData = true)
{
    TDescription *descr = new DT(msg);
    cout << "Name is " << descr->getName() << endl;
    cout << "Flat field count is " << descr->getFlatFieldCount() << endl;

    for(int i = 1; i <= descr->getFlatFieldCount(); i++)
    {
        EDescrFieldType eFT;
        void *pVA = NULL;
//        int iSize = 0;

        char *szName = NULL;
        TDescription *pD = NULL;
        char *new_prefix = NULL;
        int iArrayShift = 0;

        int res = descr->getFlatField(i, eFT, &pVA, &szName, iArrayShift);
        if (res)
            return;
 //       cout <<"eFT - " << eFT << endl;

        try
        {
            switch(eFT)
            {
            case EFT_BOOL:
            {
 //               cout << "hjj" << endl;
                if (isData)
                {
                    int size = sizeof(correct_bool) / sizeof(correct_bool[0]);
                    *(bool*)pVA = correct_bool[rand()%size];
                    cout << *(bool*)pVA << endl;
                }
                else
                {
                    int size = sizeof(incorrect_ch) / sizeof(incorrect_ch[0]);
                    *(bool*)pVA = incorrect_ch[rand()%size];
                    cout << *(bool*)pVA << endl;
                }
                break;
            }
            case EFT_CHAR:
            {
                if (isData)
                {
                    int size = sizeof(correct_ch) / sizeof(correct_ch[0]);
                    *(char*)pVA = correct_ch[rand()%size];
                }
                else
                {
                    int size = sizeof(incorrect_ch) / sizeof(incorrect_ch[0]);
                    *(char*)pVA = incorrect_ch[rand()%size];
                }
                break;
            }
            case EFT_UCHAR:
            {
                if (isData)
                {
                    int size = sizeof(correct_uch) / sizeof(correct_uch[0]);
                    *(uchar*)pVA = correct_uch[rand()%size];
                }
                else
                {
                    int size = sizeof(incorrect_uch) / sizeof(incorrect_uch[0]);
                    *(uchar*)pVA = incorrect_uch[rand()%size];
                }
                break;
            }
            case EFT_SHORT:
            {
                if (isData)
                {
                    int size = sizeof(correct_sh) / sizeof(correct_sh[0]);
                    *(short*)pVA = correct_sh[rand()%size];
                }
                else
                {
                    int size = sizeof(incorrect_sh) / sizeof(incorrect_sh[0]);
                    *(short*)pVA = incorrect_sh[rand()%size];
                }
                break;
            }
            case EFT_USHORT:
            {
                if (isData)
                {
                    int size = sizeof(correct_ush) / sizeof(correct_ush[0]);
                    *(ushort*)pVA = correct_ush[rand()%size];
                }
                else
                {
                    int size = sizeof(incorrect_ush) / sizeof(incorrect_ush[0]);
                    *(ushort*)pVA = incorrect_ush[rand()%size];
                }
                break;
            }
            case EFT_INT:
            {
                if (isData)
                {
                    int size = sizeof(correct_int) / sizeof(correct_int[0]);
                    *(int*)pVA = correct_int[rand()%size];
                }
                else //incorrect data
                {
                    int size = sizeof(incorrect_int) / sizeof(incorrect_int[0]);
                    *(int*)pVA = incorrect_int[rand()%size];
                }
                break;
            }
            case EFT_UINT:
            {
                if (isData)
                {
                    int size = sizeof(correct_uint) / sizeof(correct_uint[0]);
                    *(uint*)pVA = correct_uint[rand()%size];
                }
                else
                {
                    int size = sizeof(incorrect_uint) / sizeof(incorrect_uint[0]);
                    *(uint*)pVA = incorrect_uint[rand()%size];
                }
                break;
            }
            case EFT_ENUM:
            {
                if (isData)
                {
                    int size = sizeof(correct_enum) / sizeof(correct_enum[0]);
                    *(uint*)pVA = correct_enum[rand()%size];
                }
                else
                {
                    int size = sizeof(incorrect_enum) / sizeof(incorrect_enum[0]);
                    *(uint*)pVA = incorrect_enum[rand()%size];
                }
                break;
            }
            case EFT_LONG:
            {
                if (isData)
                {
                    int size = sizeof(correct_lg) / sizeof(correct_lg[0]);
                    *(long*)pVA = correct_lg[rand()%size];
                }
                else
                {
                    int size = sizeof(incorrect_lg) / sizeof(incorrect_lg[0]);
                    *(long*)pVA = incorrect_lg[rand()%size];
                }
                break;
            }
            case EFT_ULONG:
            {
                if (isData) //correct data
                {
                    int size = sizeof(correct_ulg) / sizeof(correct_ulg[0]);
                    *(ulong*)pVA = correct_ulg[rand()%size];
                }
                else //incorrect data
                {
                    int size = sizeof(incorrect_ulg) / sizeof(incorrect_ulg[0]);
                    *(ulong*)pVA = incorrect_ulg[rand()%size];
                }
                break;
            }
            case EFT_FLOAT:
            {
                if (isData) //correct data
                {
                    int size = sizeof(correct_fl) / sizeof(correct_fl[0]);
                    *(float*)pVA = correct_fl[rand()%size];
                }
                else //incorrect data
                {
                    int size = sizeof(incorrect_fl) / sizeof(incorrect_fl[0]);
                    *(float*)pVA = incorrect_fl[rand()%size];
                }
                break;
            }
            case EFT_DOUBLE:
            {
                if (isData)
                {
                    int size = sizeof(correct_db) / sizeof(correct_db[0]);
                    *(double*)pVA = correct_db[rand()%size];
                }
                else
                {
                    int size = sizeof(incorrect_db) / sizeof(incorrect_db[0]);
                    *(double*)pVA = incorrect_db[rand()%size];
                }
                break;
            }
//            case EFT_BITFIELD: break;
//            case EFT_STRUCT:
//                  cout << "struct" << endl;
//               break;
            default: break;
            }

        }
        catch(...)
        {
            cout << "error" << endl;
        }
        if(new_prefix)
            delete [] new_prefix;
        if(pD)
            delete pD;
    }
    if (descr)
        delete descr;
    //output our changed struct
    DT d(msg);
    ostringstream os;
    os << d;
    cout << os.str() << endl;

    cout << endl;
}


int main(int argc, char *argv[])
{
    TestMsg1 *msg1 = new TestMsg1();
    msg1->eToExport = NO;
    printLog <TestMsg1, DTestMsg1> (msg1); //correct
    printLog <TestMsg1, DTestMsg1> (msg1, false); //incorrect

    TestMsg2 *msg2 = new TestMsg2();
    msg2->numPoint = 5;
    for(int i = 0; i < msg2->numPoint; i++)
        msg2->point[i] = T2d(i*PI, i*2*PI);

    printLog <TestMsg2, DTestMsg2> (msg2);
    printLog <TestMsg2, DTestMsg2> (msg2, false);


    TestMsg3 *msg3 = new TestMsg3();
    msg3->bl = true;
    printLog <TestMsg3, DTestMsg3> (msg3);
    printLog <TestMsg3, DTestMsg3> (msg3, false);

    return 0;
}
