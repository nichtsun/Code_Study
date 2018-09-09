//
//  Solution0003.hpp
//  Code_Study
//
//  Created by nichts on 2018/9/9.
//  Copyright © 2018年 nichts. All rights reserved.
//

#ifndef Solution0003_hpp
#define Solution0003_hpp

#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

class Solution0003 {
    
public:
    
    static int lengthOfLongestSubstring(string s) {
        int start[256];
        int end[256];
        //initialize all element to -1.
        for(int i = 0; i < 256; i++){
            start[i] = -1;
            end[i] = -1;
        }
        if(s.size() == 0) return 0;
        int maxNow = 1;
        start[s.at(0)] = 0;
        end[s.at(0)] = 0;
        for (auto i = 1; i < s.size(); i++) {
            //start[s.at(i - 1)] - end[s.at(i - 1)]
            if(end[s.at(i)] < start[s.at(i - 1)]) {
                start[s.at(i)] = start[s.at(i - 1)];
            } else {
                start[s.at(i)] = end[s.at(i)] + 1;
            }
            end[s.at(i)] = i;
            maxNow = max(maxNow, end[s.at(i)] - start[s.at(i)] + 1);
        }
        return maxNow;
    }
};

#endif /* Solution0003_hpp */
