//
//  Solution0207.hpp
//  Code_Study
//
//  Created by nichts on 2018/9/10.
//  Copyright © 2018年 nichts. All rights reserved.
//

#ifndef Solution0207_hpp
#define Solution0207_hpp

#include <stdio.h>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
    static bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int num = 0;
        map<int, int> rename;
        vector<int> degree(1, 0);
        vector<vector<int> > edges(1, vector<int>());
        for(auto i : prerequisites){
            int n = i.first;
            if(rename[n] == 0){
                rename[n] = ++num;
                edges.push_back(vector<int>());
                degree.push_back(0);
            }
            
            n = i.second;
            if(rename[n] == 0){
                rename[n] = ++num;
                edges.push_back(vector<int>());
                degree.push_back(0);
            }
            
            edges[rename[n]].push_back(rename[i.first]);
            degree[rename[i.first]] += 1;
        }
        
        queue<int> que;
        
        for(int i = 1; i <= num ; i ++){
            if(degree[i] == 0) que.push(i);
        }
        
        for(; que.size() != 0; que.pop()){
            int n = que.front();
            for(auto i : edges[n] ){
                degree[i] -= 1;
                if(degree[i] == 0) que.push(i);
            }
        }
        
        for(auto i = 1; i <= num; i++){
            if(degree[i] != 0) return false;
        }
            
        return true;
    }
};

#endif /* Solution0207_hpp */
