class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int curflo=0, time=0;
        for(int i=0; i<requests.size(); i++){
            if(curflo < requests[i]){
                time += (requests[i] - curflo);
                curflo = requests[i];
            } 
            else if( curflo > requests[i]){
                time += (curflo - requests[i]);
                curflo = requests[i];
            }
        }
        return time;
    }
};