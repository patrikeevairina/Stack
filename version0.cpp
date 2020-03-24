#include <iostream>
#include "C:\Qt\Descr\descr.h"
#include "C:\Qt\Descr\test.h"

#include <sstream>

using namespace std;

#define PI 3.14

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;

template <class T, class DT>
void printLog(T* msg, string msgName)
{
    cout << msgName << endl;
   /* DT d(msg);
    ostringstream os;
    os << d << endl;
    cout << os.str() << endl;*/

    TDescription *descr = new DT(msg);
   // cout << descr->getName() << endl;
    cout << descr->getFlatFieldCount() << endl;

    for (int ix = 1; ix <= descr->getFlatFieldCount(); ix++)
    {
        cout << "          " << ix << endl;
        EDescrFieldType eFT;
        void *pVA = NULL;
        int iSize = 0;
        char *szName = NULL;
        int iArrayShift = 0;
        char *dest = new char[200];
        int i = 0;
        char *new_prefix = NULL;
        TDescription *pD = NULL;
        double zero = 0;
        short zero1 = 0;
        int resField =  descr->getFlatField(ix, eFT, &pVA, &szName, iArrayShift);
 //       cout << eFT << endl;
        if (resField)
        {
            cout << "return" << endl;
            return;
        }
 //       cout << "Debug" << endl;//заходит в try, все нормально
        try {
            switch (eFT)
            {
            case EFT_CHAR: *(char*)pVA = 'b'; sprintf(dest, "%s=%c", szName, *(char*)pVA); break;
            case EFT_UCHAR: *(uchar*)pVA = -'b'; sprintf(dest, "%s=%c", szName, (int)*(uchar*)pVA); break;
            case EFT_SHORT: *(short*)pVA = -123; sprintf(dest, "%s=%d", szName, (int)*(short*)pVA); break;
            case EFT_USHORT: *(ushort*)pVA = 123; sprintf(dest, "%s=%d", szName, (int)*(ushort*)pVA); break;
            case EFT_INT: *(int*)pVA = -44; sprintf(dest, "%s=%d", szName, *(int*)pVA); break;
            case EFT_UINT: *(uint*)pVA = 1234; sprintf(dest, "%s=%u", szName, *(uint*)pVA); break;
            case EFT_ENUM: *(int*)pVA = -'r'; sprintf(dest, "%s=%d", szName, *(int*)pVA); break;
            case EFT_LONG: *(long*)pVA = -12345; sprintf(dest, "%s=%d", szName, *(long*)pVA); break;
            case EFT_ULONG: *(ulong*)pVA = 12345; sprintf(dest, "%s=%u", szName, *(ulong*)pVA); break;
            case EFT_FLOAT: *(float*)pVA = 1.5; sprintf(dest, "%s=%f", szName, *(float*)pVA); break;
            case EFT_DOUBLE: *(double*)pVA = 0/zero; sprintf(dest, "%s=%.10lf", szName, *(double*)pVA); break;
            //case EFT_BITFIELD: sprintf(dest, "%s=%d", szName, (int)(((DIBitAccessor*)pVA)->getval(getBase()))); break;
            case EFT_STRUCT:
                memset(dest, 0, sizeof(dest));
                new_prefix = new char[strlen(dest) + strlen(szName) + 2];
                sprintf(new_prefix, "%s.", szName);
                cout << "shit" << endl;


                pD -> getDescription(dest, new_prefix, 0);
                break;
            default: break;
            }
          cout << dest << endl;

        } catch (...) {
            cout << "error" << endl;
            return;

        }
        if (new_prefix)
            delete[] new_prefix;
        if (pD)
            delete pD;
    }
    if (descr)
        delete descr;
}

template <class T, class DT>
void printLog1(T* msg, string msgName)
{
    cout << msgName << endl;
   /* DT d(msg);
    ostringstream os;
    os << d << endl;
    cout << os.str() << endl;*/

    TDescription *descr = new DT(msg);
   // cout << descr->getName() << endl;
    cout << descr->getFieldCount() << endl;

    for (int ix = 1; ix <= descr->getFieldCount(); ix++)
    {
        cout << "          " << ix << endl;
        EDescrFieldType eFT;
        void *pVA = NULL;
        int iSize = 0;
        char *szName = NULL;
        int iArrayShift = 0;
        char *dest = new char[200];

        char *new_prefix = NULL;
        TDescription *pD = NULL;
        double zero = 0;
        short zero1 = 0;
        int resField =  descr->getField(ix, eFT, &pVA, iSize, &szName, &pD, iArrayShift);
 //       cout << eFT << endl;
        if (resField)
        {
            cout << "return" << endl;
            return;
        }
 //       cout << "Debug" << endl;//заходит в try, все нормально
        try {
            switch (eFT)
            {
            case EFT_CHAR: *(char*)pVA = 'b'; sprintf(dest, "%s=%c", szName, *(char*)pVA); break;
            case EFT_UCHAR: *(uchar*)pVA = -'b'; sprintf(dest, "%s=%c", szName, (int)*(uchar*)pVA); break;
            case EFT_SHORT: *(short*)pVA = -123; sprintf(dest, "%s=%d", szName, (int)*(short*)pVA); break;
            case EFT_USHORT: *(ushort*)pVA = 123; sprintf(dest, "%s=%d", szName, (int)*(ushort*)pVA); break;
            case EFT_INT: *(int*)pVA = 0/zero1; sprintf(dest, "%s=%d", szName, *(int*)pVA); break;
            case EFT_UINT: *(uint*)pVA = 1234; sprintf(dest, "%s=%u", szName, *(uint*)pVA); break;
            case EFT_ENUM: *(int*)pVA = -'r'; sprintf(dest, "%s=%d", szName, *(int*)pVA); break;
            case EFT_LONG: *(long*)pVA = -12345; sprintf(dest, "%s=%d", szName, *(long*)pVA); break;
            case EFT_ULONG: *(ulong*)pVA = 12345; sprintf(dest, "%s=%u", szName, *(ulong*)pVA); break;
            case EFT_FLOAT: *(float*)pVA = 1.5; sprintf(dest, "%s=%f", szName, *(float*)pVA); break;
            case EFT_DOUBLE: *(double*)pVA = 0/zero; sprintf(dest, "%s=%.10lf", szName, *(double*)pVA); break;
            //case EFT_BITFIELD: sprintf(dest, "%s=%d", szName, (int)(((DIBitAccessor*)pVA)->getval(getBase()))); break;
            case EFT_STRUCT:{
                memset(dest, 0, sizeof(dest));
                new_prefix = new char[strlen(dest) + strlen(szName) + 2];
                sprintf(new_prefix, "%s.", szName);
                pD -> getDescription(dest, new_prefix, 0);

                iSize = pD -> getFieldCount();
                cout << iSize << " - number of fields in this structure" << endl;
                EDescrFieldType local_eFT;
                void *local_pVA = NULL;
                int ilocalSize = 0;
                char *szlocalName = NULL;
                TDescription *local_pD = NULL;


                for (int i = 1; i <= iSize; i++)
                {
                    pD -> getField(i, local_eFT, &local_pVA, ilocalSize, &szlocalName, &local_pD, 0);

                        switch (local_eFT)
                        {
                        case EFT_CHAR: *(char*)local_pVA = 'b'; sprintf(dest, "%s=%c", szlocalName, *(char*)local_pVA); break;
                        case EFT_UCHAR: *(uchar*)local_pVA = -'b'; sprintf(dest, "%s=%c", szlocalName, (int)*(uchar*)local_pVA); break;
                        case EFT_SHORT: *(short*)local_pVA = -123; sprintf(dest, "%s=%d", szlocalName, (int)*(short*)local_pVA); break;
                        case EFT_USHORT: *(ushort*)local_pVA = 123; sprintf(dest, "%s=%d", szlocalName, (int)*(ushort*)local_pVA); break;
                        case EFT_INT: *(int*)local_pVA = -44; sprintf(dest, "%s=%d", szlocalName, *(int*)local_pVA); break;
                        case EFT_UINT: *(uint*)local_pVA = 1234; sprintf(dest, "%s=%u", szlocalName, *(uint*)local_pVA); break;
                        case EFT_ENUM: *(int*)local_pVA = -'r'; sprintf(dest, "%s=%d", szlocalName, *(int*)local_pVA); break;
                        case EFT_LONG: *(long*)local_pVA = -12345; sprintf(dest, "%s=%d", szlocalName, *(long*)local_pVA); break;
                        case EFT_ULONG: *(ulong*)local_pVA = 12345; sprintf(dest, "%s=%u", szlocalName, *(ulong*)local_pVA); break;
                        case EFT_FLOAT: *(float*)local_pVA = 1.5; sprintf(dest, "%s=%f", szlocalName, *(float*)local_pVA); break;
                        case EFT_DOUBLE: *(double*)local_pVA = 0/zero; sprintf(dest, "%s=%.10lf", szlocalName, *(double*)local_pVA); break;
                        default: break;
                        }
                        cout << dest << endl;


                }
            }
                break;
            default: break;
            }
         if (eFT != EFT_STRUCT)
             cout << dest << endl;

        } catch (...) {
            cout << "error" << endl;
            return;

        }
        if (new_prefix)
            delete[] new_prefix;
        if (pD)
            delete pD;
    }
    if (descr)
        delete descr;


}


int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Russian");
    TestMsg1 *msg1 = new TestMsg1();
    msg1->eToExport = YES;
    printLog1 <TestMsg1, DTestMsg1> (msg1, "TestMsg1");

    TestMsg2 *msg2 = new TestMsg2();
    msg2->numPoint = 5;
    for(int i = 0; i < msg2->numPoint; i++)
        msg2->point[i] = T2d(i*PI, i*2*PI);

    printLog1 <TestMsg2, DTestMsg2> (msg2, "TestMsg2");


    return 0;
}



