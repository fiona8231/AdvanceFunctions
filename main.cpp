#include <iostream>
#include <vector>


using namespace std;

double MultBy2(double num){
    return  num * 2;
}

double MultBy3(double num){
    return num * 3;
}

//function stored as parameter

double doMath( function<double(double)> func, double num){
    return func(num);
}

//----- PROBLEM -----
//function inside
bool isItOdd(int num){
    if(num % 2 != 0){
        return true;
    } else {
        return false;
    }
}
//receive function and a list
vector<int> ChangeList(vector<int> list1, function<bool(int)> func){
    //new a vector
    vector<int> newVector;

    for(auto i: list1){
       if(func(i)){
           newVector.push_back(i);
       }
   }

    return newVector;
}


// -----  PROBLEM 5 -----

vector<char> getHTList(vector<char> vec, int num){
   //new a vector
    vector<char> newVec;
    for(int i=0; i< num; ++i ){
        int randIndex = rand() % 2; // the result going to be 1 or 0
        newVec.push_back(vec[randIndex]);
    }
    return newVec;
}

int GetNumberOfMatches(vector<char> list, char c){
    int counter = 0;
    for(int i: list){
        if(i == c){
            counter++;
        }
    }
    return  counter;
}


int main() {
    cout << doMath(MultBy2, 6) << endl;
//store function in a vector

//new a vector including function
 vector<function <double(double)>> vec(2);
 vec[0] = MultBy2;
 vec[1] = MultBy3;

    cout << "2 * 10 = " << vec[0](10) << "\n";

    //  ----- PROBLEM 4 -----

    // Create a function that receives a list and a function
    // The function passed will return True or False if a list value is odd.
    // The surrounding function will return a list of odd numbers

    vector<int> list {1, 2, 3,4, 5, 6};
    vector<int> oddlist = ChangeList(list, isItOdd);

    cout << "List of odds \n";
    for(auto i: oddlist){
        cout << i << endl;
    }

  // -----  PROBLEM 5 -----
    // Create a function that creates a random list using a limited number of values
    //   Create another function that checks for the number of matches in a list
    //   Create a random list of Hs and Ts and then output how many of each were generated

    vector<char> possibleValues {'H', 'T'};
    //generate 100 rand H or T
    vector<char> HAndTList = getHTList(possibleValues, 100);
    cout << "Number of Heads : " <<  GetNumberOfMatches(HAndTList, 'H')  << "\n";
    cout << "Number of Tails : " << GetNumberOfMatches(HAndTList, 'T')  << "\n"; //Number of Heads : 45  Number of Tails : 56

}






















