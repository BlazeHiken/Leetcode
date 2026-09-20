class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000) {  // 0 to 999
            return 0;
        }

        long long sum = 0;
        long long low = 1000;
        long long high = 1000000;
        int maxcommas = 5;
        int commas = 1;

        while(commas<maxcommas) {

            if(n<high) { 
                sum += (n-(low-1))*commas;
                return sum;
            } else {
                sum += ((high-1) - (low-1))*commas;
                commas++;
                low *= 1000;
                high *= 1000;
            }
        }
        return sum + maxcommas; //for final value
    }
};

/*

class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000) {  // 0 to 999
            return 0;
        }

        long long sum = 0;

        if(n>=1000 && n<1000000) { // 1,000 to 999,999 1comma
            sum += n-999;
            return sum;
        } else {
            sum += 999999 - 999;
        }
        
        if(n>=1000000 && n<1000000000) { // 1,000,000 to 999,999,999 2comma
            sum += (n-999999)*2;
            return sum;
        } else {
            sum += (999999999 - 999999)*2;
        }

        if(n>=1000000000 && n<1000000000000) { // 1,000,000,000 to 999,999,999,999 3comma
            sum += (n-999999999)*3;
            return sum;
        } else {
            sum += (999999999999 - 999999999)*3;
        }

        if(n>=1000000000000 && n<1000000000000000) { // 1,000,000,000,000 to 999,999,999,999,999 4comma
            sum += (n-999999999999)*4;
            return sum;
        } else {
            sum += (999999999999999 - 999999999999)*4;
        }

        return sum+5;
    }
};

*/