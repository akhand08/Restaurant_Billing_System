





#include <bits/stdc++.h>
using namespace std;

class Restaurant
{
    public:
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];
    int total_tax;
    int table_no;
     map<int, int> mpp;
    
    void input_food_detail();
    void display_menu();
    void customer_input();
    void bill_paper();
   

    
};
int n;
int item_number;


void Restaurant :: input_food_detail()
{
    cout<< "How many items You serve: ";
    
    cin >> n;
    cout<< "Add Food Code, Food Item Name and Food item Price " << endl;
    for(int i=0; i<n;i++)
    {
        cin >> food_item_codes[i];
        cin.ignore();
        getline(cin,food_item_names[i]);
        cin >> food_item_prices[i] ;
    }

}

void Restaurant:: display_menu()
{
    cout << setw(95) << "Menu Bar" << endl;
    cout << setw(112) << "_________________________________________________" << endl;
    cout << setw(30) << "Food Item" << setw(50) << "Item Name" << setw(50) <<  "Item Price"  <<  endl;
    for(int i=0;i<n;i++)
    {
        

        cout << setw(30) << food_item_codes[i] << setw(50) << food_item_names[i] << setw(50) <<  food_item_prices[i]  <<  endl;

    }


}


void Restaurant :: customer_input()
{
    cout << "Dear Sir, Please choice your Food" << endl;
    cout << "Your Table Number: ";
    cin >> table_no;
     
    
    int food_code2;
    int quantity;
    cout  << "Enter Number of Items: ";
    cin >> item_number;

    for(int i=1;i<=item_number;i++)
    {
        again:
        cout << "Enter Item " << i << " Food Code: ";
        
        cin >> food_code2;
        if( food_code2 != 170 && food_code2 != 171 && food_code2 != 172 && food_code2 != 260 && food_code2 != 261 && food_code2 != 262 && food_code2 != 310 && food_code2 != 311 && food_code2 != 450 && food_code2 != 451 && food_code2 != 452 &&  food_code2 != 453)
        {
            cout<< "Sorry Code is Invalid!" << endl << "Enter Again " << endl;
            
            goto again;
            

        }
        cout << "Enter Item " << i << " Quantity: " ;
        cin >> quantity ;
        
        mpp[food_code2] = quantity;
    }



    

}

void Restaurant :: bill_paper()
{
    cout << setw(90) << "Your Bill Summary" << endl;
    cout <<  setw(110) << "________________________________________________" << endl;

    cout << "Table No: " << table_no << endl << endl;
    cout << "Item Code" << setw(30) << "Item Name" << setw(30) << "Item Price" << setw(30) << "Quantity" << setw(30) << "Total" << endl;
    double Net_Total = 0;
    int total=0;
    

    for(auto it=mpp.begin();it!= mpp.end(); it++)
    {
        int findVal = it->first; 
        int ind = find(food_item_codes, food_item_codes +n, findVal ) - food_item_codes;
        total = (it->second) * food_item_prices[ind];
        
        Net_Total += total;

        cout << it->first<< setw(35) << food_item_names[ind] << setw(29) <<  food_item_prices[ind] << setw(30) <<  it->second << setw(33) <<  total << endl;

    }
    double taxi = (Net_Total * 5)/100;
    
    cout << "tax" << setw(127) << taxi << endl ;
    cout << "______________________________________________________________________________________________________________________________________________" << endl;
    Net_Total += taxi;
    cout << "Net_Total" << setw(121) << Net_Total <<  " taka" << endl;

    this->total_tax = taxi;
    

    

}

int main()
{
    
    Restaurant KacchiBhai;
    KacchiBhai.input_food_detail();
    KacchiBhai.display_menu();
    KacchiBhai.customer_input();
    KacchiBhai.bill_paper();
    cout << endl << KacchiBhai.total_tax << endl;







    return 0;
}




