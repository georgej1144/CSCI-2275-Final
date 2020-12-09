//#include "main.h"
#include <iostream>
#include <string>
#include "DLL.h"
#include "Calc.h"
#include "Field.h"
#include "Queue.h"
#include "Score.h"

int main() {
    Field masterField;
    Score readout;
    Calc calcMachine;

    int uChoice;

    string dmenu = "======Main Menu======\n"
                   "1. Calculate with default master field\n"
                   "2. Input custom master field\n"
                   "3. Modify current master field\n"
                   "4. Print current master field\n"
                   "5. Quit\n";

    while(1) {

        cout << dmenu;
        cin >>uChoice;

        switch (uChoice) {
            case 1:
                cout << "How many moves ahead? (will strain system exponentially)" << endl;
                int n;
                cin >> n;
                calcMachine.moveIterate(masterField, n);
                calcMachine.bestDelta();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                return 0;
            default:
                return 0;
        }
    }

    return 0;
}
