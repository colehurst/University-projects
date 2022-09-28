//Cole Hurst CS3339 Assignment 4

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

class Tstrng
{
    public:
        Tstrng();
        Tstrng(long* pin, bool real);

        void setPin(long* pin);
        void setReal(bool real);
        long* getPin();
        bool getReal();

    private:
        long* pin;
        bool real;

};

Tstrng::Tstrng(long *pin, bool real)
{
    setPin(pin);
    setReal(real);
}

Tstrng::Tstrng()
{
    Tstrng(new long(0), false);
}

void Tstrng::setPin(long *pin)
{
    this->pin = pin;
}
void Tstrng::setReal(bool real)
{
    this->real = real;
}

long* Tstrng::getPin()
{
    return pin;
}
bool Tstrng::getReal()
{
    return real;
}

class TCache
{
    public:
        TCache(int pin, int index, int offset);

        //read instruction
        void read(long inst);
        //prints the findings
        void print();
        //prints the table
        void printTable();


    private:
        Tstrng* table;

        int indexLength;
        int offsetBits;
        int hNum;
        int cmNum;
        int mNum;

        void fillTable();

};

TCache::TCache(int pin, int index, int offset)
{
    offsetBits = pow(2, offset);
    indexLength = pow(2, index);

    hNum = 0;
    cmNum = 0;
    mNum = 0;

    table = new Tstrng[indexLength];
    //fill array with default Tstrng()

    fillTable();
}

void TCache::read(long inst)
{
    // offsetBits / indexLength = bits = pin value
    // instruction - offset bits = index

    long pin = (inst / offsetBits / indexLength);
    int index = (int) ((inst / offsetBits) % pin);

    //hit
    if(pin == *table[index].getPin())
    {
        hNum++;
    }

    //miss or cm
    else
    {
        if(table[index].getReal() == true)
        {
            mNum++;
        }
        else
        {
            cmNum++;
            table[index].setReal(true);
        }

        table[index].setPin(new long(pin));
    }
}

void TCache::print()
{
    double total = hNum + cmNum + mNum;
    cout << "Hits:               " << hNum << endl;
    cout << "Misses:             " << mNum << endl;
    cout << "Compulsory Misses:  " << cmNum << endl;
    cout << "__________" << endl;
    cout << "Hit ratio:          " << (hNum / total) << endl;
    cout << "CM ratio:           " << (cmNum / total) << endl;
}

void TCache::fillTable()
{
    for(int i = 0; i < indexLength; i++)
    {

        table[i].setPin(new long(0));
        table[i].setReal(false);
    }
}

void TCache::printTable()
{
    for(int i = 0; i < indexLength; i++)
    {
        cout << i + 1 << " " << *table[i].getPin() << endl;
    }
}

long* hexToBit(string* hex)
{
    long* number = new long();
    istringstream iss(*hex);
    iss >> std::hex >> *number;
    return number;
}

int main()
{
    //Creating the two tables
    TCache list1(16, 4, 4);
    // 24 bits in Reference Word - 16 bit pin, 4 bit index, 4 bit offset
    TCache list2(15, 5, 4);
    //24 bits in Reference Word - 15 bit pin, 5 bit index, 4 bit offset
    ifstream TFile;
    TFile.open("Trace.txt");


    //read from file

    if(TFile.is_open())
    {
        string* hex = new string("");

        while(TFile.good() == true)
        {
            //get instruction from file and store in strng
            getline(TFile, *hex);

            if(hex->empty() == false)
            {
                //hex to long and put it into table
                list1.read(*hexToBit(hex));
                list2.read(*hexToBit(hex));
            }
        }
    }
    //print findings
    cout << "_________________________________________________" << endl;
    cout << "Results for Parameter 1: n = 24, m = 4, and l = 4" << endl << endl;
    list1.print();
    cout << endl;
    cout << "__________________________________________________" << endl;
    cout << "Results for Parameter 2: n = 24, m = 4, and  l = 5" << endl << endl;
    list2.print();
    cout << endl;

    return 0;
}
