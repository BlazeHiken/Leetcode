class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int cnt = 1; // count of num of tasks having max freq
        int maxfreq = 0; // max occurrences of a task
        vector<int> freq(26,0);
        for(int i=0; i<tasks.size(); i++) { //freq vector
            freq[tasks[i]-'A']++;
        }
        for(int i=0; i<freq.size(); i++) {
            if(freq[i]>maxfreq) {
                maxfreq = freq[i];
                cnt = 1;
            } else if(freq[i]==maxfreq) {
                cnt++;
            }
        }
        return max((maxfreq-1)*(n+1)+cnt,(int)tasks.size());
        // (A,_,_,_,A,_,_,_),A,B,C..
        //  n is num of _ , +1 task char which happens maxfreq-1 times + chars having same freq as max
        // if many tasks that dont fit in gaps, tasks can simply be arranged linearly in tasks.size() len
        // typecast tasks.size() because it returns unsigned int
    }
};

/*
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,char>> pq; // {frequency, task}
        queue<pair<int,char>> q;            // {available time, task}

        unordered_map<char,int> mp;

        for(char task : tasks) { //mp holds the remaining tasks per char
            mp[task]++;
        }

        for(auto& task : mp) { //push it in pq so that highest num of tasks get priority
            pq.push({task.second, task.first});
        }

        int time = 0;
        int completed = 0;

        while(completed < tasks.size()) {

            // Move cooled-down tasks back into PQ
            while(!q.empty() && q.front().first <= time) {
                auto qtop = q.front();
                q.pop();

                pq.push({mp[qtop.second], qtop.second});
            }

            // Nothing available -> idle
            if(pq.empty()) {
                time++;
                continue;
            }

            // Execute highest-frequency task
            auto pqtop = pq.top();
            pq.pop();

            mp[pqtop.second]--;

            // Still has remaining occurrences
            if(mp[pqtop.second] > 0) {
                q.push({time + n + 1, pqtop.second});
            }

            completed++;
            time++;
        }

        return time;
    }
};
*/