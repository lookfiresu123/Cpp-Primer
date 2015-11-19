#include <vector>
#include <iostream>

using namespace std;

int main (void) {
    vector<int> v;
    //cout << "the max_size is : " << v.max_size() << endl;
    unsigned long int max_element = v.max_size();
    for (int i = 0 ; i < 10 ; i++)
        v.push_back(i);
    int elements_count = v.size();
    v.resize(11);
    elements_count = v.size();
    int *data = v.data();
    return 0;
}
