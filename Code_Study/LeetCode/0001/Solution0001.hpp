//
//  Solution0001.hpp
//  Code_Study
//
//  Created by nichts on 2018/9/9.
//  Copyright © 2018年 nichts. All rights reserved.
//

#ifndef Solution0001_hpp
#define Solution0001_hpp

#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

class Solution0001{
public:
    
    /**
     judge map whether has the pair with target key
     map.find(key) != map.end();
     */
    
    static vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> ret;
        map<int, int> map;
        for (auto i = 0; i < nums.size(); i++) {
            map[target - nums[i]] = i;
        }
        
        for (auto i = 0; i < nums.size(); i++) {
            if( map.find(nums[i])!= map.end() && i != map[nums[i]]){
                ret.push_back(i);
                ret.push_back(map[nums[i]]);
                break;
            }
        }
        
        return ret;
    }

};

#endif /* Solution0001_hpp */
