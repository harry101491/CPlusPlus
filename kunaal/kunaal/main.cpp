#include <iostream>
#include <string>
#include <random>

using namespace std;

int main()
{
      int combo = rand()%1000;
      bool locked = true;
      bool tryAgain = true;
      string cont;
      cout << "Current Combo: " << combo << endl;
      cout << "Locked: " << boolalpha << locked<<endl;
      string tryUnlock;
      int toUnlock;
      while (tryAgain == true){
            cout << "Enter your combo: " << endl;
            getline(cin, tryUnlock);
            toUnlock = stoi(tryUnlock);
            if(toUnlock == combo){
                    tryAgain = false;
                    locked = false;
                    cout << "Locked: " << boolalpha << locked<<endl;
                    cout<< "Change Combo? "<< endl;
                    getline(cin, cont);
                    if(cont == "yes"){
                            string newCombo;
                            cout<< "Enter the new Combo: " << endl;
                            getline(cin, newCombo);
                            combo = stoi(newCombo);
                            locked = true;
                            cout << "Locked: " << boolalpha << locked<<endl;
                            cout << "Done? "<< endl;
                            getline(cin, cont);
                            if(cont == "no"){
                                    tryAgain = true;
                                }else{
                                        tryAgain = false;
                                    }
                        }else{
                                tryAgain = false;
                            }
                }else{
                        cout<<"Try again?"<<endl;
                        getline(cin, cont);
                        if(cont=="yes"){
                                tryAgain = true;
                            }else{
                                    tryAgain = false;
                                }
                        
                        }    
        
            }
}
