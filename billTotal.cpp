#include <iostream>
#include <sstream>
#include <typeinfo>

using namespace std;


bool isNumeric(string str)
{
   for (int i = 0; i < str.length(); i++)
      if (isdigit(str[i]) == false)
         return false;
      return true;
}

int billCalculation (int);



int main()
{
    int unitT, totalBill;

    cout<<"    Welcome to Electric Bill Calculation    "<<endl;
    cout<<"                  developed by Jikrul Sayeed "<<endl;

Initial:
    string inputData;
    cout<<endl;
    cout<< "Enter total used UNIT or enter 'e' to exit: ";
    cin >> inputData;
    cout<<endl;

    if(inputData =="E" || inputData =="e")
    {
        return 0;
    }

   if (isNumeric(inputData))
   {
        stringstream strToNum (inputData);
        strToNum >> unitT;
       //cout << typeid(inputData).name() << endl;
       //cout << typeid(strToNum).name() << endl;
       //cout << typeid(unitT).name() << endl;

       // go to the loop to calculate the cost
        totalBill = billCalculation(unitT);


        cout<<"==========Bill==============="<<endl;
        cout<<"Total Unit: "<<unitT<<endl<<endl;
        cout<<"Total Bill: "<<totalBill<<" BDT"<<endl;
        cout<<"==========END==============="<<endl;

        goto Initial;
   }

   else
      {
        cout << "Enter a valid Data!"<<endl;
        goto Initial;
      }

}



int billCalculation (int unitTotal)
{
    int demandCharge=30, meterCharge=10;
    int totalOthers = demandCharge+meterCharge;
    int unitFraction,bill=0,TotalBill=0;

    // 0 to 75 unit C75 = 4.19 etc & C600 means unit >600 C600 = 11.46 all are unit prices
	float C75 = 4.19, C200 = 5.72, C300 = 6.0, C400= 6.34, C500= 9.94, C600 =  11.46;


    if (unitTotal > 600)
    {
        //cout<<"it's here  <600"<<endl;
        unitFraction = unitTotal - 600;
        bill = unitFraction*C600 + 200*C500 + 100*C400 + C300*100 + 125*C200 + 75*C75;
    }

    else if (400<unitTotal && unitTotal<=600)
    {
        //cout<<"it's here 401 to 600"<<endl;
        unitFraction = unitTotal - 400;
        bill = unitFraction*C500 + 100*C400 + C300*100 + 125*C200 + 75*C75;
    }

    else if (300<unitTotal && unitTotal<=400)
    {
        //cout<<"it's here 301 to 400"<<endl;
        unitFraction = unitTotal - 300;
        bill = unitFraction*C400 + C300*100 + 125*C200 + 75*C75;
    }

    else if (200<unitTotal && unitTotal<=300)
    {
        //cout<<"it's here 201 to 300"<<endl;
        unitFraction = unitTotal - 200;
        bill = unitFraction*C300+ 125*C200 + 75*C75;
    }

        else if (75<unitTotal && unitTotal<=200)
    {
        //cout<<"it's here 76 to 200"<<endl;
        unitFraction = unitTotal - 75;
        bill = unitFraction*C200 + 75*C75;
    }

        else if (0<unitTotal && unitTotal<=75)
    {
        //cout<<"it's here 0 to 75"<<endl;
        bill = unitTotal*C75;
    }

    else
    {
        //cout<<"it's here 0"<<endl;
        bill = 0;
    }

    TotalBill = bill+totalOthers;
    return TotalBill;
}
