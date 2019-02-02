/*
Question :

A hotel manager has to process N advance bookings of rooms for the next season. His hotel has K rooms. Bookings contain an arrival date and a departure date. He wants to find out whether there are enough rooms in the hotel to satisfy the demand. Write a program that solves this problem in time O(N log N) .

Input:


First list for arrival time of booking.
Second list for departure time of booking.
Third is K which denotes count of rooms.

Output:

A boolean which tells whether its possible to make a booking. 
Return 0/1 for C programs.
O -> No there are not enough rooms for N booking.
1 -> Yes there are enough rooms for N booking.
Example :

Input : 
        Arrivals :   [1 3 5]
        Departures : [2 6 8]
        K : 1

Return : False / 0 

At day = 5, there are 2 guests in the hotel. But I have only one room. 
Seen this question in a real interview before
*/

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    if(K >= arrive.size())return 1;
    vector<pair<int,int> > V;
    for(int i = 0;i < arrive.size();i++){
        V.push_back(make_pair(arrive[i],depart[i]));
    }
    sort(V.begin(),V.end());
    
    priority_queue <int> pq;
    
    for(int i = 0;i < K;i++)pq.push(-V[i].second);
    
    //for(int i = 0;i < V.size();i++)cout<<V[i].first<<' '<<V[i].second<<endl;
    //cout<<"Done\n";
    int ctr = 0;
    for(int i = K;i < V.size();i++){
        while(!pq.empty() && (-pq.top()) <= V[i].first){
            ctr++;pq.pop();
        }
        if(V[i].second - V[i].first == 0)continue; //To handle cases, where the person enters and exits the same day and is considered to be invalid.
        if(ctr == 0)return 0;
        ctr--;
        pq.push(-V[i].second);
    }
    return 1;
}
