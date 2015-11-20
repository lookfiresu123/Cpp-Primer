#include <iostream>

using namespace std;

class People {
    public:
        int weight;
        int height;
        void printweight(){
            cout << "weight is :" << weight << endl;
        };
        void printheight() {
            cout << "height is :" << height << endl;
        };
        virtual void printcountry() {
            cout << "no country for people" << endl;
        };
        People() {
            //cout << "call constructor People" << endl;
        };
        virtual ~People() { /* cout << "call destructor People" << endl; */ };
};

class Chinese : public People {
    private:
        string country;
    public:
        void printcountry() {
            cout << "country is :" << country << endl;
        };
        Chinese() {
            //cout << "call constructor Chinese" << endl;
            country = "china";
        };
        ~Chinese() { /* cout << "call destructor Chinese" << endl; */ };
};

class Japanese : public People {
    private:
        string country;
    public:
        void printcountry() {
            cout << "country is :" << country << endl;
        };
        Japanese() {
            //cout << "call constructor Japanese" << endl;
            country = "japan";
        };
        ~Japanese() { /* cout << "call destructor Japanese" << endl; */ };
};

int main () {
    Japanese japanese;
    Chinese chinese;
    /*
     * the order of constructor and destructor pushing into the stack or pulling out of the stack is the same as "Japanese japanese; Chinese chinese;"
     * NOTE: if you allocate memory by calling new, then you should call delete to free memory by yourself, but if you allocate memory just like
     *       "Chinese chinese", then you don't need to call delete and the system will call destructor automatically
     */
    //Japanese *japanese = new Japanese();        // call constructor of class Japanese to allocate memory and initialize it
    //Chinese *chinese = new Chinese();           // call constructor of class Chinese to allocate memory and initialize it
    //delete(chinese);                            // call destructor of class Chinese to free memory of *chinese
    //delete(japanese);                           // call destructor of class Japanese to free memory of *japanese
    People *people1 = &japanese;
    People *people2 = &chinese;
    people1->printcountry();
    people2->printcountry();
    return 0;
}
