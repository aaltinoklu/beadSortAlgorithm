//
//  main.cpp
//  beadSortAlgorithm
//
//  Created by Askin on 21.06.2022.
//

#include <iostream>
#include <vector>
using namespace std;
template < class T >
void printVector(T a){
    
    for (int i=0; i< a.size() ; i++ ) {
        cout << a[i] << '\n';
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

void beadSort(vector<int>& a) {
    
    //vector<int> a= {100,150,32,45,55,69,125,90,57,85};
    vector<int> b(a.size(),0);
    
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
    
    cout << "Before Sorting: ";
    for (int i = 0; i < sumValue.size(); i++) {
        cout << sumValue[i] << " ";
    }
    cout << endl;
    
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
        cout << "Iteration " << i << ":  ";
        a=sumVector2D(vec);
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        
        
    }
    
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> a= {100,150,32,45,55,69,125,90,57,85};
    cout << "Before Sorting" << endl;
    printVector(a);
    cout << "After Sorting" <<endl;
    beadSort(a);
    printVector(a);
    
    
    
    
    
    return 0;
}
