#include <iostream>
#include <vector>

using namespace std;

int main() {
    //new variable and input one
    int length;
    cin>>length;
    
    //collect numbers in vector called all
    vector<int> all;
    //initializes outside to cause less memory/time constraints
    int willAdd;
    //checks if the whole list is the same number while initializing it, so as to avoid checking
    bool doesNotRepeat = false;
    //uses for loop to initialize list
    for(int i = 0; i< length; i++){
        cin>>willAdd;
        all.push_back(willAdd);
        //checks if each value is equal to the first one
        if(i>1&&willAdd!=all[0]){
            doesNotRepeat = true;
        }
    }
    
    //only runs if the list is not all one value
    if(doesNotRepeat){
        //declares the clique list outside of for loops
        vector<int> clique;
        //declares the second value which will be used to check for divisibility later on
        int second;
        //establishes that the longest list at this moment is 0
        int longest{0};
        //establishes a checker to check for repeating values later on
        int checker;
        
        //starts the checking process with each value having turns being the first value of the clique
        for(int len:all){
            //the current length of the clique is one, it has one value in it
            length = 1;
            //adds the first value to the clique
            clique.push_back(len);
            
            //runs through entire list of inputs to check for divisibility
            for(int len: all){
                //collects the value at the list
                second = len;
                //checker is zero, important for checking values later on
                checker = 0;
                
                //runs through every element in the clique
                for(int num: clique){
                    //checker is now one greater than before, good for checking repeating values
                    checker ++;
                    //checks to see if the number in the list is divisible by the number in the clique
                    if(num%second == 0 || second%num == 0){
                        //checks to see if we have reached the end of the clique
                        if(checker == length){
                            //adds one to length if it has reached this point
                            length++;
                            //adds the value to clique
                            clique.push_back(second);
                        }
                    }
                    //comes here if the number was not divisible by a certain number in the clique
                    else {
                        break;
                    }
                }
            }
            
            //checks to see if this version of the clique was longer than the longest one in the past
            if(length>longest){
                //longest is subtracted one so as to avoid double counting of the first value
                longest = length - 1;
            }
            //clears the clique in order to establish a new clique in the next iteration
            clique.clear();
        }
        
        //displays the longest length of all the cliques
        cout<<longest;
    }
    //gets here if all the numbers in the list are the same
    else {
        //the longest list of diisibility is the length of the list itself
        cout<<length;
    }
    
    return 0;
}