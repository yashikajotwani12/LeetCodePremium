There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
    }
};


class Solution {

    public int[] findOrder(int numCourses, int[][] prerequisites) {
        // Topological sort
        // Edge case
        if(numCourses <= 0) return new int[0];
        
        //1. Init Map
        HashMap<Integer, Integer> inDegree = new HashMap<>();
        HashMap<Integer, List<Integer>> topoMap = new HashMap<>();
        for(int i = 0; i < numCourses; i++) {
            inDegree.put(i, 0);
            topoMap.put(i, new ArrayList<Integer>());
        }
        
        //2. Build Map
        for(int[] pair : prerequisites) {
            int curCourse = pair[0], preCourse = pair[1];
            topoMap.get(preCourse).add(curCourse);  // put the child into it's parent's list
            inDegree.put(curCourse, inDegree.get(curCourse) + 1); // increase child inDegree by 1
        }
        //3. find course with 0 indegree, minus one to its children's indegree, until all indegree is 0
        int[] res = new int[numCourses];
        int base = 0;
        while(!inDegree.isEmpty()) {
            boolean flag = false;   // use to check whether there is cycle
            for(int key : inDegree.keySet()) {  // find nodes with 0 indegree
                if(inDegree.get(key) == 0) {
                    res[base ++] = key;
                    List<Integer> children = topoMap.get(key);  // get the node's children, and minus their inDegree
                    for(int child : children) 
                        inDegree.put(child, inDegree.get(child) - 1);
                    inDegree.remove(key);      // remove the current node with 0 degree and start over
                    flag = true;
                    break;
                }
            }
            if(!flag)  // there is a circle --> All Indegree are not 0
                return new int[0];
        }
        return res;
    }
}


vector<int> findOrder(int num, vector<vector<int>>& pre) {
        int n = num;
        vector<vector<int>> adj(num);
        vector<int> deg(num), order;
        for(auto x : pre){
            adj[x[1]].push_back(x[0]);
            deg[x[0]]++;
        }
        queue<int>q;
        for(int i = 0; i<num; i++) {
            if(deg[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int f = q.front();
            q.pop();
            order.push_back(f);
            n--;
            for(auto v : adj[f]){
                if(--deg[v] == 0) q.push(v);
            }
        }
        if(n != 0) return {};
        return order;
    }