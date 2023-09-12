#include <bits/stdc++.h>
using namespace std;

int cmpr_Strings(const string& v1, const string& v2) {
    int i = 0;
    int j = 0;

    while (i < v1.size() || j < v2.size()) {
        // Extract characters after '.'
        string sub_v1, sub_v2;

        while (i < v1.size() && v1[i] != '.') {
            sub_v1 += v1[i];
            i++;
        }

        while (j < v2.size() && v2[j] != '.') {
            sub_v2 += v2[j];
            j++;
        }

        int sub_v1_len = sub_v1.size();   
        int sub_v2_len = sub_v2.size();

        for (int z = 0; z < max(sub_v1_len, sub_v2_len); ++z) {   
        
        //comparing characters one-by-one
            char char1;
            char char2;
            
			if(z < sub_v1_len){
				char1 = sub_v1[z];
			}else {
				char1 = '0';
			}
			
			if(z < sub_v2_len){
				char2 = sub_v2[z];
			}else{
				char2 = '0';
			}
    

            if (char1 > char2) {
                return 1;  // v1 is greater
            } else if (char1 < char2) {
                return -1; // v2 is greater
            }
        }

        i++;
        j++;
    }

    return 0; 
}

int main() {
    string v1;
    string v2;
    cout<<"enter version 1";
    cin>>v1;
    cout<<"enter version 2";
    cin>>v2;

    int answer = cmpr_Strings(v1, v2);
    
    if(answer==0){
    	cout << "They are same\n";
	}else if(answer == 1){
		cout << "The first one is greater\n";
	}else {
		cout << "The second one is greater\n";
	}

    
    return 0;
}

