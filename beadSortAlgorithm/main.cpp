//
//  main.cpp
//  beadSortAlgorithm
//
//  Created by aaltinoklu on 21.06.2022.
//
//  Last Modified by aaltinoklu on 08.07.2022.
//


#include <iostream>
#include <vector>
#include <chrono>


using namespace std;
template < class T >
void printVector(T a){
    
    for (int i=0; i< a.size() ; i++ ) {
        cout << a[i] << " ";
    }
    
}


int sumVector (vector<int> a) {
    int sumValue=0;
    for (int i=0; i< a.size() ; i++ ) {
         sumValue =sumValue+a.at(i);
    }
    return sumValue;
}
vector<int>  sumVector2D(vector<vector<int>> a) {
    vector<int> sumValue(a.size(),0);
    
    for (int i = 0; i < a.size(); i++)
        {
            for (int j = 0; j < a[i].size(); j++)
            {
                sumValue[i]=sumValue[i]+a[i][j];
                
            }

        }
    return sumValue;
}

vector<int> beadSort(vector<int> a) {
    
    //vector<int> a= {100,150,32,45,55,69,125,90,57,85};
    vector<int> b(a.size(),0);
    vector<int> sortedVec;
    //printVector(b);
    
    int temp;
    vector<vector<int>> vec;
    vector<vector<int>> vec2;
    int col_size=*max_element(a.begin(),a.end());
    
    //cout << col_size;
    for (int i = 0; i < a.size(); i++) {
          // Vector to store column elements
          vector<int> v1;
    
          for (int j = 0; j < col_size; j++) {
              if (j<=(a.at(i)-1)) {
                  v1.push_back(1);
              }
              else {
                  v1.push_back(0);
              }
            
             
          }
        //cout << "Sum is" << sumVector(v1) << endl;
          // Pushing back above 1D vector
          // to create the 2D vector
          vec.push_back(v1);
          vec2.push_back(v1);
          
      }
    vector<int> sumValue=sumVector2D(vec);
    
    //cout << "Before Sorting: ";
    //for (int i = 0; i < sumValue.size(); i++) {
    //    cout << sumValue[i] << " ";
    //}
    //cout << endl;
    
    //int temp;
    for (int i = 0; i < vec.size()-1; i++){
        
    
    for (int i = 1; i < vec.size(); i++)
        {
            for (int j = 0; j < vec[i].size(); j++)
            {
                if (vec[i][j]>vec[i-1][j]) {
                    temp=vec2[i-1][j];
                    vec2[i-1][j]=vec2[i][j];
                    vec2[i][j]=temp;
                }
                //cout << vec[i][j] << " ";
            }
            //cout << endl;
        }
        vec=vec2;
        sortedVec=sumVector2D(vec);
        //cout << "Iteration " << i << ":  ";
        //sumValue=sumVector2D(vec);
        //for (int i = 0; i < sumValue.size(); i++) {
        //    cout << sumValue[i] << " ";
        //}
        //cout << endl;
        
        
    }
    
    return sortedVec;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    //vector<int> a= {100,150,32,45,55,69,125,90,57,85};
    
    // Generate vector involving random numbers in a range [RandMin RandMax]
    int size = 100;
    vector<int> a(size, 0);
    srand(time(NULL));
    generate(a.begin(), a.end(), rand);
    int RandMin= 0;
    int RandMax= 1000;
    for (int i=0; i<a.size(); i++) {
        a[i]=RandMin+a[i]%RandMax;
    }
    
    // Test Algorithms with Created Random Vector
    
    cout << "Before Sorting" << endl;
    printVector(a);
    cout << endl;
    cout << "After Sorting" << endl;
    auto start = std::chrono::high_resolution_clock::now();
    vector<int> a_sorted=beadSort(a);
    auto finish = std::chrono::high_resolution_clock::now();
    printVector(a_sorted);
    cout << endl;
    chrono::duration<double> elapsed = finish - start;
    cout << "Elapsed time: " << elapsed.count() << " s\n";
    
    // Testing In-house implemented algorithm with a build-in one
    start = std::chrono::high_resolution_clock::now();
    sort(a.begin(), a.end(), greater<int>());
    finish = std::chrono::high_resolution_clock::now();
    cout << "After Sorting with stl sort function" << endl;
    printVector(a);
    cout << endl;
    elapsed = finish - start;
    cout << "Elapsed time: " << elapsed.count() << " s\n";
    
    
    return 0;
}
