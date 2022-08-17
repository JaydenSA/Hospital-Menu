// basic preprocessors 
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <sstream>

// mailing service preprocessors
#include <tchar.h>
#include <Windows.h>
#include "EASendMailObj.tlh" // files needed for mailing service

// namespace shortcuts  
using namespace EASendMailObjLib;
using namespace std;

// classes 
class patientOrder {
public:
    // variables 
    string name;
    int patient_number;
    string order_breakfast;
    string order_lunch;
    string order_supper;
    string order_allergens;

    // functions 
    void assigndata(string abreakfast, string alunch, string asupper) { 
        order_breakfast = abreakfast;
        order_lunch = alunch;
        order_supper = asupper;
    }; // using the a to represent the assign in the function name 

    void request_personaldetail() {
        // temporary variables 
        string rname;
        string rpatient_number;
        string rorder_allergens;

        cout << "Please enter your first name: ";
        cin >> rname;
        name = rname; 
        cout << "Please enter your patient number: ";
        cin >> rpatient_number; 
        patient_number = stoi(rpatient_number);
        cout << "Please enter any allergens you may have (NO SPACES, use comma): ";
        cin >> rorder_allergens;
        order_allergens = rorder_allergens;
        cout << "Thank you for the entry, click enter to continue with the order...\n";
        cin.get();
    }; // using the a to represent the assign in the function name 

    void order_review() {
        cout << "\n\nLets review what you've choosen:\n";
        cout << "================================";
        cout << "\nBreakfast: " << order_breakfast;
        cout << "\nLunch: " << order_lunch;
        cout << "\nSupper: " << order_supper;
    };

}; // end of class menu

// parameters needed for the connections to mailing servers
const int ConnectNormal = 0;
const int ConnectSSLAuto = 1;
const int ConnectSTARTTLS = 2;
const int ConnectDirectSSL = 3;
const int ConnectTryTLS = 4;

// functions 
void welcome_page() {
    cout << "\n*****************************";
    cout << "\nWelcome to your Hospital Menu";
    cout << "\n*****************************";
    cout << "\nAll the foods available will be listed below. " << "First we need some details about you before we continue.";
    cout << "\nPlease press enter to continue...\n";
    cin.get();
}
string request_info(string meal) {
    system("CLS");

    //initialising variables
    bool menu_chose{ false };
    bool menu_advanced{ false };
    string selection;
    int selection_advanced;
    char second_select;

    //selection section
    if (meal == "breakfast") {
        cout << "\n\n\nBelow are the list of Breakfast items:";
        cout << "\n======================================";
        cout << "\n1). Instant Oatmeal With Cranberries and Pecans";
        cout << "\n2). Roasted Potato and Chorizo Hash";
        cout << "\n3). PB Chocolate Sheet Pan Pancake";
        cout << "\n4). Lemon-Almond Poppy Seed Muffins";
    } //end of if breakfast 
    else if (meal == "lunch") {
        cout << "\n\n\nBelow are the list of Lunch items:";
        cout << "\n======================================";
        cout << "\n1). BBQ rainbow beef salad";
        cout << "\n2). Fresh salmon with Thai noodle salad";
        cout << "\n3). Roasted cauli-broc bowl with tahini hummus";
        cout << "\n4). Tomato penne with avocado";
    } // end of if else lunch 
    else {
        cout << "\n\n\nBelow are the list of Supper items:";
        cout << "\n======================================";
        cout << "\n1). Garlicky fried rice with crisp pork";
        cout << "\n2). Sesame beef with gochujang udon noodles";
        cout << "\n3). Silverbeet fatteh with sumac yoghurt and chickpeas";
        cout << "\n4). Lemon chicken";
    } // end of else for supper

    cout << "\n\nIf you're interested in getting more details on these, please enter *\n";
    cin >> selection;

    //checking if they have selected an item or details panel
    if (selection == "*") {
    select:
        cout << "Which meal would you like more details of?\n";
        cin >> selection_advanced;

        // this will switch between the different food options
        if (meal == "breakfast") {
            switch (selection_advanced) {
            case 1:
                // code block
                cout << "\n\nInstant Oatmeal With Cranberries and Pecans";
                cout << "\n===========================================";
                cout << "\nMake this store-bought staple at home for fresher flavors and add-ins that you can customize.";
                cout << "\n===========================================";
                break;
            case 2:
                // code block
                cout << "\n\nRoasted Potato and Chorizo Hash";
                cout << "\n===========================================";
                cout << "\nThis filling breakfast option is easier than you think. Simply roast your potatoes, cook the spicy chorizo, make your eggs and voila! You've got a hearty and delicious breakfast waiting for you.";
                cout << "\n===========================================";
                break;
            case 3:
                // code block 
                cout << "\n\nPB Chocolate Sheet Pan Pancake";
                cout << "\n===========================================";
                cout << "\nDon't spend all morning flipping pancakes, just make one supersized cake and slice!";
                cout << "\n===========================================";
                break;
            case 4:
                // code block
                cout << "\n\nLemon-Almond Poppy Seed Muffins";
                cout << "\n===========================================";
                cout << "\nThese bright lemon muffins topped with crunchy almonds will put a pep in your step (even on Mondays). Make them the night before so all you have to do is drizzle and enjoy in the morning,";
                cout << "\n===========================================";
                break;
            }// end of switch statements
        } //end of if breakfast 
        else if (meal == "lunch") {
            switch (selection_advanced) {
            case 1:
                // code block
                cout << "\n\nBBQ rainbow beef salad";
                cout << "\n===========================================";
                cout << "\nThe steak in this light salad is cooked on the barbecue, giving it a true taste of summer. It works brilliantly with our tangy soy dressing";
                cout << "\n===========================================";
                break;
            case 2:
                // code block
                cout << "\n\nFresh salmon with Thai noodle salad";
                cout << "\n===========================================";
                cout << "\nIdeal for a quick midweek meal, whip up this nutritious salmon and noodle salad in just 20 minutes. The balance of protein and carbs make it super satisfying";
                cout << "\n===========================================";
                break;
            case 3:
                // code block 
                cout << "\n\nRoasted cauli-broc bowl with tahini hummus";
                cout << "\n===========================================";
                cout << "\nA simple quinoa bowl you can put together in 10 minutes and enjoy al-desko. It's vegan, healthy and gluten-free";
                cout << "\n===========================================";
                break;
            case 4:
                // code block
                cout << "\n\nTomato penne with avocado";
                cout << "\n===========================================";
                cout << "\nGet all five of your 5-a-day in this mildly spiced, healthy pasta dish. It's rich in iron, fibre and vitamin C as well as being low-fat and low-calorie";
                cout << "\n===========================================";
                break;
            }
        } // end of if else lunch 
        else {
            switch (selection_advanced) {
            case 1:
                // code block
                cout << "\n\nGarlicky fried rice with crisp pork";
                cout << "\n===========================================";
                cout << "\nThis dish is also packed with protein, as it contains organic pork mince and eggs, making it a much healthier choice for you and your family.";
                cout << "\n===========================================";
                break;
            case 2:
                // code block
                cout << "\n\nSesame beef with gochujang udon noodles";
                cout << "\n===========================================";
                cout << "\nBeat the midweek dinner rush by whipping up this beef stir-fry with noodles and greens, which is ready to serve in 15 minutes.";
                cout << "\n===========================================";
                break;
            case 3:
                // code block 
                cout << "\n\nSilverbeet fatteh with sumac yoghurt and chickpeas";
                cout << "\n===========================================";
                cout << "\nTry this dish with roast cauliflower, eggplant or roast pumpkin instead of silverbeet for a variation,";
                cout << "\n===========================================";
                break;
            case 4:
                // code block
                cout << "\n\nLemon chicken";
                cout << "\n===========================================";
                cout << "\nA luscious, tangy stir-fry that makes two generous portions for very few calories";
                cout << "\n===========================================";
                break;
            };
        } // end of the else

        // getting second selection
        cout << "\nIs there any other meal you would like to look at? (Y/N)";
        cin >> second_select;

        //checking if they want to look at other options
        if (second_select == 'Y') {
            goto select;
        }
        else {
            goto press_on;
        } // end of if else 

        // pressing on to getting the user input saved 
    press_on:
        cout << "Now that you've had a look, what would you like to choose?\n";
        cin >> selection;
    }// end line for if statement 

    if (meal == "breakfast") {
        switch (stoi(selection)) {
        case 1:
            return("Instant Oatmeal With Cranberries and Pecans");
            break;
        case 2:
            return("Roasted Potato and Chorizo Hash");
            break;
        case 3:
            return("PB Chocolate Sheet Pan Pancake");
            break;
        case 4:
            return("Lemon-Almond Poppy Seed Muffins");
            break;
        } // end of switch for breakfast 
    } // end of if for breakfast 
    else if (meal == "lunch") {
        switch (stoi(selection)) {
        case 1:
            return("BBQ rainbow beef salad");
            break;
        case 2:
            return("Fresh salmon with Thai noodle salad");
            break;
        case 3:
            return("Roasted cauli-broc bowl with tahini hummus");
            break;
        case 4:
            return("Tomato penne with avocado");
            break;
        } // end of switch of lunch 
    } // end of else if of lunch
    else {
        switch (stoi(selection)) {
        case 1:
            return("Garlicky fried rice with crisp pork");
            break;
        case 2:
            return("Sesame beef with gochujang udon noodles");
            break;
        case 3:
            return("Silverbeet fatteh with sumac yoghurt and chickpeas");
            break;
        case 4:
            return("Lemon chicken");
            break;
        } //end of switch of supper
    } // end of else of supper 

    return selection;
} // end line for function request_info 

// main function 
int main() {
    // =================================================================================

    ::CoInitialize(NULL);
    IMailPtr oSmtp = NULL;
    oSmtp.CreateInstance(__uuidof(EASendMailObjLib::Mail));
    oSmtp->LicenseCode = _T("TryIt");

    // Set your gmail email address
    oSmtp->FromAddr = _T("senderaccount@gmail.com");
    // Add recipient email address
    oSmtp->AddRecipientEx(_T("receiveraccount@gmail.com"), 0);

    // =================================================================================

    // declaring variables
    string breakfast, lunch, supper;

    // class creation 
    patientOrder c_order;

    // welcome page and wait
    welcome_page();

    // requesting info from the user about breakfast, lunch and supper
    c_order.request_personaldetail();
    breakfast = request_info("breakfast");
    lunch = request_info("lunch");
    supper = request_info("supper");

    // class functions 
    c_order.assigndata(breakfast, lunch, supper);
    c_order.order_review();

    //====================================================================================
  
    // creating of the file
    ofstream outdata; // outdata is like cin
    outdata.open("order#.txt"); // opens the file
    if (!outdata) { // file couldn't be opened
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }

    // printing to the file the order 
    outdata << "Patient Details: ";
    outdata << "\n================================";
    outdata << "\nName: " << c_order.name;
    outdata << "\nNunber: " << c_order.patient_number;
    outdata << "\nAllergens: " << c_order.order_allergens;
    outdata << "\n\nPatient has ordered these:";
    outdata << "\n================================";
    outdata << "\nBreakfast: " << c_order.order_breakfast;
    outdata << "\nLunch: " << c_order.order_lunch;
    outdata << "\nSupper: " << c_order.order_supper;

    outdata.close(); // closing and saving the file 

    // ======================================================================================

    // Set email subject
    oSmtp->Subject = ("Day Patient: Food Order .");
    // Set email body
    oSmtp->BodyText = _T("Hi Team,\n\nAttached you will find the order details of the patient. Please be warry of the allergens noted in the attachment. \n\nKind regards, \nSupport team");
    // Gmail SMTP server address
    oSmtp->ServerAddr = _T("smtp.gmail.com");
    // gmail account 
    oSmtp->UserName = _T("senderaccount@gmail.com");
    // Google app password 
    oSmtp->Password = _T("key_password");
    // Use SSL 465 port,
    oSmtp->ServerPort = 465;
    // detect SSL/TLS automatically
    oSmtp->ConnectType = ConnectSSLAuto;
    // Add attachment from local disk
    if (oSmtp->AddAttachment(_T("\order#.txt")) != 0)
    {
        _tprintf(_T("Failed to add attachment with error: %s\r\n"),
            (const TCHAR*)oSmtp->GetLastErrDescription());
    }

    _tprintf(_T("\n\nStart to send email via gmail account ...\r\n"));

    if (oSmtp->SendMail() == 0)
    {
        _tprintf(_T("email was sent successfully!\r\n"));
        cin.get();
    }
    else
    {
        _tprintf(_T("failed to send email with the following error: %s\r\n"),
            (const TCHAR*)oSmtp->GetLastErrDescription());
    }

    // =========================================================================================

    return 0;
}